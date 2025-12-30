#!/usr/bin/env node

import { input, select } from "@inquirer/prompts";

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

const answers = {
    problemName,
    platform,
    problemLink,
    problemType,
    difficulty,
};

console.log("\nCollected Metadata:");
console.log(answers);


import fs from "fs";
import path from "path";

const date = new Date().toISOString().split("T")[0];
const safeProblemName = problemName
    .trim()
    .replace(/[^a-zA-Z0-9]+/g, "_");


const fileName = `${date}_${platform}_${safeProblemName}.cpp`;
const filePath = path.join(process.cwd(), "solutions", fileName);

const header = `#include <bits/stdc++.h>
using namespace std;

/*
Problem Name   : ${problemName}
Platform       : ${platform}
Problem Link   : ${problemLink}
Type           : ${problemType}
Difficulty     : ${difficulty}
Date Solved    : ${date}

Approach:
- 

Time Complexity:
Space Complexity:
*/

`;

if (!fs.existsSync(path.join(process.cwd(), "solutions"))) {
    console.error("❌ solutions/ folder not found. Run this from repo root.");
    process.exit(1);
}

fs.writeFileSync(filePath, header, { flag: "wx" });
console.log(`\n✅ File created: solutions/${fileName}`);
