# pipex

**pipex** is a project from 42 school focused on reproducing the behavior of piping (`|`) in Unix systems. The goal is to implement a program that mimics the shell's capability to redirect the output of one command as the input to another, utilizing Unix system calls.

## Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Example](#example)
6. [Author](#author)

## Overview

The **pipex** project aims to recreate the Unix pipe functionality, allowing the output of one command to serve as the input to another. This project offers valuable experience with process management, file descriptors, and inter-process communication using pipes.

## Features

- Executes two commands with a pipe, where the output of the first command is redirected to the input of the second.
- Utilizes `pipe()`, `dup2()`, and `fork()` system calls.
- Supports input and output redirection to files.

## Installation

To use `pipex`, start by cloning the repository and compiling the program.

```bash
git clone https://github.com/garcia2/42_pipex
cd 42_pipex
make
```

This will create an executable named `pipex`.

## Usage

The syntax for running the `pipex` program is as follows:

```bash
./pipex infile cmd1 cmd2 outfile
```

- `infile` : The input file for `cmd1`.
- `cmd1` : The first command, which reads from `infile`.
- `cmd2` : The second command, which takes the output of `cmd1` as input.
- `outfile` : The file where the output of `cmd2` will be saved.

## Example

Assuming you have two commands, `cat` and `grep`, you can use `pipex` to replicate the shell behavior of `cat infile | grep "text" > outfile`:

```bash
./pipex infile "cat" "grep text" outfile
```

This command will read from `infile`, apply `cat` to it, then filter the output using `grep "text"`, and finally write the result to `outfile`.

## Author

Project developed by [Nicolas Garcia](https://github.com/garcia2) as part of 42 school.
