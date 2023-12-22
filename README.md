# Simple Shell

**Echezona Oji and Yichen Cao**


## About the project
The holbertonschool-simple_shell project creates a custom implementation of the shell program in C. A shell is a command-line interface that allows users to interact with an operating system, which allows users to type in commands and receive outputs.

## Table of Contents
<details>
	<summary>Table of Contents</summary>
	<ul>
	<li>
	<a href="#requirements">Requirements</a>
	</li>
	<li>
	<a href="#repository-contents">Repository Contents</a>
	</li>
	<li>
	<a href="#features">Features</a>
	</li>
	<li>
	<a href="#getting-started">Getting Started</a>
			<ul>
			<li><a href="#installation">Installation</a></li>
			<li><a href="#installation">Compilation</a></li>
			<li><a href="#manual-page">Manual Page</a></li>
			</ul>
	</li>
	<li>
	<a href="#usage">Usage</a>
	<ul>
	<li><a href="#Examples-of-commands">Examples of commands</a></li>
	<li><a href="#Flowchart">Flowchart</a></li>
	<li><a href="#interactive-mode">Interactive Mode</a></li>
	<li><a href="#non-interactive-mode">Non-interactive Mode</a></li>
	</ul>
	</li>
	<li>
	<a href="#authors">Authors</a>
	</li>
	</ul>
</details>

## Requirements

<ul>
<li>Ubuntu 20.04 LTS</li>
	<ul>
		<li><a href="https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#1-		overview">Windows 10 or 11</a>
		<li><a href="https://ubuntu.com/download/desktop">Mac</a>
	</ul>
<li>Follows the <a href="https://github.com/alx-tools/Betty/wiki">Betty</a> linter <a href="https://github.com/hs-hq/Betty/blob/main/betty-style.pl">style</a> and <a href="https://github.com/hs-hq/Betty/blob/main/betty-doc.pl">documentation</a></li>
<li>No more than 5 functions per file</li>
</ul>

## Repository Contents

| **File** | **Description**|
|----------|----------------|
|`shell.h`| A header file containing the prototype functions |
|`shell.c`| A `C` program that contains the main function |
|`_execute_command.c`| A function that executes built-in commands |
|`_read_line.c`| A function that reads a line from standard input |
|`_read_stream.c`| A function that reads characters from standard input into a buffer |
|`simple_shell_launch.c`| A function that launches a new process to execute a command |
|`_split_string.c`| A function that splits a string into tokens based on delimiters |


## Features

- Basic error handling
- Implements built-in command `exit` that exits the shell
- Implements built-in commands `env` that prints the environment
- Handles the PATH, 'fork' must not be called if the command doesn’t exist
- Supports both interactive and non-interactive mode

## Getting Started

To access the custom shell, open terminal (on mac) or Windows Terminal (pc).

### Installation

Clone the GitHub repo:
```
git clone https://github.com/yichehnc/holbertonschool-simple_shell
```

Navigate to the folder where you cloned the shell.

### Compilation

Enter this command to compile:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```
### Usage
### Interactive mode
Type into the command line  `./shell` to execute the ***shell*** file in the interactive mode.
```
./shell
```
This will open the simple shell with a prompt `$` and allow the user to input commands. Example:
```
$ /bin/ls
AUTHORS             _read_stream.c          shell
README.md           _simple_shell_launch.c  shell.c
_execute_command.c  _split_string.c         shell.h
_read_line.c        man_1_simple_shell      simple_shell_builtins.c
$ 
```
Commands can then be entered after the `$` and run, if it is a known command, it will execute, otherwise, an error message will appear.

To close the simple shell:

```
$ exit
```
### Non-interactive mode

The simple shell does not need to be opened. Commands can be piped into the simple shell executable using `echo`. For example, to run `/bin/ls` in the simple shell in the non-interactive mode, use the below:

```
echo /bin/ls | ./shell
```
Once the process has been executed, there is no need to `exit` as the simple shell does not open in the non-interactive mode.
### Manual page

Call the manual to read how the `simple shell` works:

```
man ./man_1_simple_shell
```
### Flowchart

## Authors
To contact the authors of this page and to review the code or submit pull requests, please visit:
- [Echezona Oji](https://github.com/zonafrank)
- [Yichen Cao](https://github.com/yichehnc)

 <a href="#top">Back to top</a>