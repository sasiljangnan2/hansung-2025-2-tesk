# Copilot Instructions for 2025-2----- Codebase

## Overview
This workspace contains assignments and code samples in multiple languages (Java, C, Python, Jupyter Notebook). There is no monolithic architecture; instead, each folder represents a separate subject or language area.

## Folder Structure
- `빅데이터/`: Contains Python and Jupyter Notebook files for data analysis. Example: `Untitled.ipynb`.
- `알고리즘/`: Contains C source files and executables for algorithm exercises.
- `자바/`: Contains Java source code, dependencies, and a README with VS Code Java setup instructions.

## Java Project Conventions
- Source code is in `자바/src/`.
- Dependencies are managed in `자바/lib/`.
- Compiled output is expected in a `bin` folder (not present by default).
- Use the VS Code `JAVA PROJECTS` view for dependency management.
- To customize folder structure, edit `.vscode/settings.json` (if present).

## Python & Jupyter Workflows
- Jupyter Notebooks (e.g., `빅데이터/Untitled.ipynb`) are used for interactive data analysis.
- Python scripts may be present for standalone tasks.
- No requirements.txt or environment files detected; use local Python environment.

## C Programming
- C source files are in `알고리즘/` and `빅데이터/`.
- Executables (e.g., `1.exe`) are generated manually; no build scripts detected.
- Compile using standard commands (e.g., `gcc 1.c -o 1.exe`).

## General Patterns
- Each folder is independent; do not assume cross-folder dependencies.
- No global build or test automation detected.
- README files are sparse; rely on folder/file names for context.

## Example: Adding a Java Class
Place new `.java` files in `자바/src/`. Update `자바/lib/` for external dependencies. Compile using VS Code or standard Java commands.

## Example: Running a C Program
Navigate to `알고리즘/`, compile with `gcc`, and run the resulting `.exe`.

## Example: Editing a Notebook
Open `빅데이터/Untitled.ipynb` in VS Code. Add code/markdown cells as needed.

## Feedback
If any section is unclear or missing, please specify which workflows or conventions need more detail.
