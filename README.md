Here is a clean, professional `README.md` for your CLI tool. You can place this file inside `Tools/dsa-cli/` or at the root of your `DSA-GIT` repo.

---

# 🚀 DSA CLI Automation Tool

A personal command-line interface tool designed to streamline the workflow of solving Data Structures and Algorithms problems. It automates file creation, boilerplate generation, metadata tracking, and Git synchronization.

## ✨ Features

* **⚡ Automated Workflow:** Collects metadata, creates the file with a C++ template, opens VS Code, and handles `git push` automatically.
* **📂 Repo Agnostic:** Works from any terminal location; always saves to your configured DSA repository.
* **📊 Progress Tracking:** View stats like current streak, total solved, and difficulty breakdown.
* **🔍 Smart Search:** Fuzzy search to quickly find and open old solutions (e.g., `two sum` finds `Two_Sum.cpp`).
* **🧠 Spaced Repetition:** Randomly picks old problems for you to review.

## 🛠️ Installation & Setup

1. **Navigate to the tool directory:**
```bash
cd Tools/dsa-cli

```


2. **Install dependencies:**
```bash
npm install

```


3. **Link the command globally:**
```bash
npm link

```


4. **Initialize the repository:**
Run this once to link your DSA repository path (e.g., `D:\Code\DSA-GIT`).
```bash
dsa init

```



## 📖 Usage Commands

### 1. Solve a New Problem

Running `dsa` without arguments starts the interactive wizard.

```bash
dsa

```

* Asks for Problem Name, Platform, Link, Type, and Difficulty.
* Creates a file with a timestamped filename (e.g., `2024-12-30_LeetCode_Two_Sum.cpp`).
* Opens the file in **VS Code** with the cursor ready at the correct line.
* After you finish and save, pressing `Enter` automatically commits and pushes the code.

### 2. View Statistics

Check your consistency and progress.

```bash
dsa stats

```

* **Displays:** Current Streak, Total Problems Solved.
* **Breakdown:** By Platform, Difficulty (🟢 Easy, 🟡 Medium, 🔴 Hard), and Type.

### 3. Open a Solution

Quickly find and open a specific problem without browsing folders.

```bash
dsa open <keyword>

```

* **Example:** `dsa open knapsack`
* **Example:** `dsa open two sum`
* If multiple files match, a selection list will appear.

### 4. Review Mode

Practice spaced repetition by reviewing a random past problem.

```bash
dsa review

```

* Shows metadata (Problem Name, Difficulty, Date Solved).
* Asks if you want to open the code to review your approach.

## ⚙️ Configuration

The tool stores your repository path in a hidden config file in your home directory:

* **Windows:** `C:\Users\<User>\.dsa-cli-config.json`
* **Mac/Linux:** `~/.dsa-cli-config.json`

To change the repo path, simply run `dsa init` again.

## 📝 Directory Structure

Your solutions will be organized as:

```text
DSA-GIT/
└── Solutions/
    ├── 2024-12-01_LeetCode_Two_Sum.cpp
    ├── 2024-12-05_Codeforces_Watermelon.cpp
    └── ...

```