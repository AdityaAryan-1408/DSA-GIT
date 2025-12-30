#!/usr/bin/env node

import { input, select } from "@inquirer/prompts";
import { execSync } from "child_process";
import fs from "fs";
import path from "path";
import os from "os";

const CONFIG_FILE = path.join(os.homedir(), ".dsa-cli-config.json");

if (process.argv[2] === "init") {
    console.log("Welcome to DSA CLI Setup!");

    const repoPath = await input({
        message: "Enter the absolute path to your DSA repository:",
    });

    const cleanedPath = repoPath.replace(/['"]/g, "").trim();

    if (!fs.existsSync(cleanedPath)) {
        console.error(`❌ The path "${cleanedPath}" does not exist.`);
        process.exit(1);
    }

    const configData = { repoPath: cleanedPath };
    fs.writeFileSync(CONFIG_FILE, JSON.stringify(configData, null, 2));

    console.log("✅ Configuration saved successfully!");
    console.log(`📂 Repository linked: ${cleanedPath}`);
    process.exit(0);
}

if (!fs.existsSync(CONFIG_FILE)) {
    console.error("❌ Configuration missing. Please run 'dsa init' first to set up your repository path.");
    process.exit(1);
}

let config;
try {
    config = JSON.parse(fs.readFileSync(CONFIG_FILE, "utf-8"));
} catch (err) {
    console.error("❌ Error reading config file. Try running 'dsa init' again.");
    process.exit(1);
}

try {
    process.chdir(config.repoPath);
} catch (err) {
    console.error(`❌ Could not access the repository at: ${config.repoPath}`);
    console.error("Ensure the drive is mounted or the path is correct.");
    process.exit(1);
}



const problemName = await input({
    message: "Problem name:",
});

const platform = await select({
    message: "Select platform:",
    choices: [
        { name: "LeetCode", value: "LeetCode" },
        { name: "Codeforces", value: "Codeforces" },
        { name: "GeeksForGeeks", value: "GeeksForGeeks" },
        { name: "CodeChef", value: "CodeChef" },
        { name: "Other", value: "Other" },
    ],
});

const problemLink = await input({
    message: "Problem link:",
});

const problemType = await select({
    message: "Select type:",
    choices: [
        { name: "POTD", value: "POTD" },
        { name: "Contest", value: "Contest" },
        { name: "Practice", value: "Practice" },
    ],
});

const difficulty = await select({
    message: "Select difficulty:",
    choices: [
        { name: "Easy", value: "Easy" },
        { name: "Medium", value: "Medium" },
        { name: "Hard", value: "Hard" },
    ],
});

console.log("\nCollected Metadata:");
console.log({ problemName, platform, problemLink, problemType, difficulty });

const date = new Date().toISOString().split("T")[0];
const safeProblemName = problemName.trim().replace(/[^a-zA-Z0-9]+/g, "_");

const fileName = `${date}_${platform}_${safeProblemName}.cpp`;
const filePath = path.join(process.cwd(), "Solutions", fileName);

const header = `
/*
Problem Name   : ${problemName}
Platform       : ${platform}
Problem Link   : ${problemLink}
Type           : ${problemType}
Difficulty     : ${difficulty}
Date Solved    : ${date}

*/

`;

if (!fs.existsSync(path.join(process.cwd(), "Solutions"))) {
    console.error("❌ solutions/ folder not found in your configured repo path.");
    console.error(`Checked path: ${path.join(process.cwd(), "Solutions")}`);
    process.exit(1);
}

fs.writeFileSync(filePath, header, { flag: "wx" });
console.log(`\n✅ File created: Solutions/${fileName}`);

try {
    execSync(`code "${filePath}"`, { stdio: "inherit" });
} catch (err) {
    console.error("❌ Failed to open VS Code. Make sure 'code' is available in PATH.");
}

await input({
    message: "Press Enter after you finish writing and saving the solution",
});

try {
    execSync(`git add "${filePath}"`, { stdio: "inherit" });

    execSync(
        `git commit -m "Solved ${platform}: ${problemName}"`,
        { stdio: "inherit" }
    );

    execSync(`git push`, { stdio: "inherit" });

    console.log("✅ Solution committed and pushed successfully.");
} catch (err) {
    console.error("❌ Git operation failed. Check git status manually.");
}