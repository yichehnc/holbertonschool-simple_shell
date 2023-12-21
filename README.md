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

## Features

- Basic error handling

- Implements built-in command `exit` that exits the shell
- Implements built-in commands `env` that prints the environment

- Handles the PATH, 'fork' must not be called if the command doesn’t exist
- Supports both interactive and non-interactive mode

## Getting Started

To access the custom shell, open terminal (on mac) or Windows Terminal (pc).

### Installation

Clone the GitHub repo `https://github.com/yichehnc/holbertonschool-simple_shell`

Navigate to the folder where you cloned the shell.

### Compilation

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o shell
```

Then type into the command line  `./shell` to launch the shell

### Manual page

Call the manual to read how the `simple shell` works:

```
man ./man_1_simple_shell
```
