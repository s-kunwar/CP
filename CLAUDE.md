# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a **competitive programming (CP) repository** containing solutions to problems from Codeforces, CSES, and other competitive programming platforms.

## Build Commands

Compile C++ files using g++:
```bash
g++ -O2 -Wall -o filename.exe filename.cpp
```

For faster I/O (already used in most solutions), include:
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

## Project Structure

Topic-based folders for organized practice:
- **`Arrays/`**: Array-related problems
- **`Strings/`**: String manipulation problems
- **`DP/`**: Dynamic programming problems
- **`Sorting/`**: Sorting algorithm implementations
- **`Trees/`**: Tree-related problems
- **`Graphs/`**: Graph algorithm problems
- **`BinarySearch/`**: Binary search problems
- **`LL/`**: Linked list implementations
- **`Recursion/`**: Recursion practice problems
- **`StackQueue/`**: Stack and queue implementations
- **`_Unsorted/`**: Files awaiting manual classification
- **`contest/`**: Contest-specific submissions
- **`cses/`**: CSES Problem Set solutions
- **`individual/`**: Individual practice files
- **`notes/`**: Reference materials and notes
- **`.cph/`**: Competitive Programming Helper test case files

## Code Conventions

- Standard competitive programming template:
  ```cpp
  #include <bits/stdc++.h>
  using namespace std;

  int main() {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
      // solution code
      return 0;
  }
  ```

- Most problems use test case format: read `t` test cases, process each in a `while (t--)` loop
- Compiled executables (`.exe`) are stored alongside source files

## Environment

- Compiler: g++ from MSYS2 UCRT64 (`C:/msys64/ucrt64/bin/g++`)
- Platform: Windows
- VS Code with C/C++ extension and Competitive Programming Helper extension

# DSA Practice Rules

This folder is a 1,000-hour mastery project.

## Directory Structure

- All completed solutions must be moved from `_Inbox` to their respective topic folder.
- File naming convention: `ProblemName_Source.ext` (e.g., `TwoSum_LeetCode.py`).

## Automated Audit Rules

When auditing code, focus on:
1. Time Complexity (Big O)
2. Space Complexity
3. Edge case handling (null, empty, limits)

**Penalty:** Using built-in "cheats" (like `sort()`) when the goal is to implement the algorithm manually results in 0 "Effective Minutes."