#!/usr/bin/env node

import { input, select, confirm } from "@inquirer/prompts";
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
    console.error("❌ Configuration missing. Please run 'dsa init' first.");
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
    process.exit(1);
}

if (process.argv[2] === "stats") {
    const solutionsDir = path.join(process.cwd(), "Solutions");

    if (!fs.existsSync(solutionsDir)) {
        console.error("❌ Solutions folder not found.");
        process.exit(1);
    }

    const files = fs.readdirSync(solutionsDir).filter((f) => f.endsWith(".cpp"));

    let totalSolved = 0;
    const platforms = {};
    const difficulties = {};
    const types = {};
    const uniqueDates = new Set();

    console.log("🔄 Analyzing your solutions...\n");

    files.forEach((file) => {
        const content = fs.readFileSync(path.join(solutionsDir, file), "utf-8");
        const header = content.split("\n").slice(0, 15).join("\n");

        const extract = (key) => {
            const match = header.match(new RegExp(`${key}\\s*:\\s*(.*)`));
            return match ? match[1].trim() : "Unknown";
        };

        const p = extract("Platform");
        const d = extract("Difficulty");
        const t = extract("Type");
        const date = extract("Date Solved");

        totalSolved++;
        platforms[p] = (platforms[p] || 0) + 1;
        difficulties[d] = (difficulties[d] || 0) + 1;
        types[t] = (types[t] || 0) + 1;
        if (date !== "Unknown") uniqueDates.add(date);
    });

    const sortedDates = Array.from(uniqueDates).sort().reverse();
    let streak = 0;
    const today = new Date().toISOString().split("T")[0];
    const yesterday = new Date(Date.now() - 86400000).toISOString().split("T")[0];

    if (sortedDates[0] === today || sortedDates[0] === yesterday) {
        streak = 1;
        let checkDate = new Date(sortedDates[0]);
        for (let i = 1; i < sortedDates.length; i++) {
            const prevDate = new Date(checkDate);
            prevDate.setDate(prevDate.getDate() - 1);
            if (sortedDates[i] === prevDate.toISOString().split("T")[0]) {
                streak++;
                checkDate = prevDate;
            } else {
                break;
            }
        }
    }

    console.log("📊 DSA Progress Report");
    console.log("======================");
    console.log(`🔥 Current Streak: ${streak} Days`);
    console.log(`🏆 Total Solved:   ${totalSolved}`);

    console.log("\n📌 By Platform:");
    Object.entries(platforms).forEach(([key, val]) => console.log(`   • ${key.padEnd(14)}: ${val}`));

    console.log("\n📈 By Difficulty:");
    Object.entries(difficulties).forEach(([key, val]) => {
        let icon = "⚪";
        if (key === "Easy") icon = "🟢";
        if (key === "Medium") icon = "🟡";
        if (key === "Hard") icon = "🔴";
        console.log(`   • ${key.padEnd(8)} : ${icon} ${val}`);
    });

    console.log("\n📅 By Type:");
    Object.entries(types).forEach(([key, val]) => console.log(`   • ${key.padEnd(10)} : ${val}`));

    process.exit(0);
}

if (process.argv[2] === "open") {
    const solutionsDir = path.join(process.cwd(), "Solutions");

    if (!fs.existsSync(solutionsDir)) {
        console.error("❌ Solutions folder not found.");
        process.exit(1);
    }

    const query = process.argv.slice(3).join(" ").toLowerCase();

    if (!query) {
        console.error("❌ Please provide a search term. Example: dsa open two sum");
        process.exit(1);
    }

    const files = fs.readdirSync(solutionsDir).filter((f) => f.endsWith(".cpp"));
    const matches = files.filter((file) => {
        const normalizedFile = file.toLowerCase().replace(/_/g, " ");
        return normalizedFile.includes(query);
    });

    if (matches.length === 0) {
        console.log(`❌ No solutions found matching "${query}"`);
        process.exit(0);
    }

    let selectedFile;
    if (matches.length === 1) {
        selectedFile = matches[0];
        console.log(`✅ Found 1 match: ${selectedFile}`);
    } else {
        selectedFile = await select({
            message: `Found ${matches.length} matches. Select one to open:`,
            choices: matches.map((file) => ({ name: file, value: file })),
        });
    }

    const fullPath = path.join(solutionsDir, selectedFile);
    try {
        console.log(`📂 Opening ${selectedFile}...`);
        execSync(`code "${fullPath}"`, { stdio: "inherit" });
    } catch (err) {
        console.error("❌ Failed to open VS Code.");
    }
    process.exit(0);
}

if (process.argv[2] === "review") {
    const solutionsDir = path.join(process.cwd(), "Solutions");

    if (!fs.existsSync(solutionsDir)) {
        console.error("❌ Solutions folder not found.");
        process.exit(1);
    }

    const files = fs.readdirSync(solutionsDir).filter((f) => f.endsWith(".cpp"));

    if (files.length === 0) {
        console.log("❌ No problems solved yet to review!");
        process.exit(0);
    }

    const randomFile = files[Math.floor(Math.random() * files.length)];
    const content = fs.readFileSync(path.join(solutionsDir, randomFile), "utf-8");
    const header = content.split("\n").slice(0, 15).join("\n");

    const extract = (key) => {
        const match = header.match(new RegExp(`${key}\\s*:\\s*(.*)`));
        return match ? match[1].trim() : "Unknown";
    };

    const name = extract("Problem Name");
    const link = extract("Problem Link");
    const difficulty = extract("Difficulty");
    const platform = extract("Platform");
    const date = extract("Date Solved");

    console.log("\n🎲 Time for a Review!");
    console.log("======================");
    console.log(`📌 Problem:    ${name}`);
    console.log(`🏢 Platform:   ${platform}`);
    console.log(`📊 Difficulty: ${difficulty}`);
    console.log(`📅 Solved On:  ${date}`);
    console.log(`🔗 Link:       ${link}\n`);

    const shouldOpen = await confirm({
        message: "Would you like to open this solution to review the code?",
        default: true,
    });

    if (shouldOpen) {
        const fullPath = path.join(solutionsDir, randomFile);
        try {
            execSync(`code "${fullPath}"`, { stdio: "inherit" });
        } catch (err) {
            console.error("❌ Failed to open VS Code.");
        }
    }
    process.exit(0);
}


const problemName = await input({ message: "Problem name:" });

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

const problemLink = await input({ message: "Problem link:" });

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

const header =
    `/*

Problem Name   : ${problemName}
Platform       : ${platform}
Problem Link   : ${problemLink}
Type           : ${problemType}
Difficulty     : ${difficulty}
Date Solved    : ${date}

*/

`;

const cursorLine = header.split("\n").length;

if (!fs.existsSync(path.join(process.cwd(), "Solutions"))) {
    console.error("❌ solutions/ folder not found.");
    process.exit(1);
}

fs.writeFileSync(filePath, header, { flag: "wx" });
console.log(`\n✅ File created: Solutions/${fileName}`);

try {
    execSync(`code -g "${filePath}":${cursorLine}`, { stdio: "inherit" });
} catch (err) {
    console.log("⚠️  Standard open fallback...");
    execSync(`code "${filePath}"`, { stdio: "inherit" });
}

await input({
    message: "Press Enter after you finish writing and saving the solution",
});

try {

    execSync(`git add "${filePath}"`, { stdio: "inherit" });
    execSync(`git commit -m "Solved ${platform}: ${problemName}"`, { stdio: "inherit" });
    execSync(`git push`, { stdio: "inherit" });

    console.log("✅ Solution committed and pushed successfully.");
} catch (err) {
    console.error("❌ Git operation failed.");
}