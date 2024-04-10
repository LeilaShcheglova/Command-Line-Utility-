# Command Line Utility in C++

This is a simple command line utility written in C++ that allows users to manage files and directories. It includes functions for copying, moving, deleting, and renaming files and directories via the command line.

## Features

- Copying files and directories
- Moving files and directories
- Deleting files and directories
- Renaming files and directories

## Usage Instructions

1. Download and compile the project
2. Open the command line and navigate to the directory containing the executable file
3. Use the following commands to perform operations:
   - `copy <source> <destination>`: Copy files or directories
   - `move <source> <destination>`: Move files or directories
   - `delete <filename>`: Delete files or directories
   - `rename <oldname> <newname>`: Rename files or directories

## Examples

```bash
$ ./my_cli copy file1.txt directory1
$ ./my_cli move directory1/file1.txt directory2
$ ./my_cli delete directory2/file1.txt
$ ./my_cli rename directory2/file2.txt new_file.txt

**Requirements**

C++11 compiler or higher
<filesystem> library (for C++17 standard)
