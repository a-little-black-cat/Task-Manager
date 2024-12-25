# Task Manager

This is a simple C++ task management program that allows you to add, complete, and list tasks. It stores tasks in a text file and supports the following modes of operation:

- **add**: Adds a new task with its name, importance level, and deadline.
- **complete**: Marks a task as completed by removing it from the list.
- **list**: Lists all current tasks.

## Features
- Add tasks with a name, importance (1-4), and a deadline (MM/DD/YY).
- Complete tasks by specifying the task number.
- List all tasks with their respective details.

## Files
- `tasks.txt`: Stores the list of tasks.
- `main.cpp`: The main program file that implements the task manager.

## Requirements
- A C++ compiler (e.g., `g++` or `clang++`).

## How to Compile and Run

1. Clone this repository or download the files.
2. Open a terminal/command prompt and navigate to the directory containing the files.
3. Compile the program using the provided `Makefile` or manually compile with:
   ```bash
   g++ -o task_manager main.cpp
