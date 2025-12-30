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
