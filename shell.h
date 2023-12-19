#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *_read_line(void);
char **_split_string(char *line);
int simple_shell_launch(char **args);
int _execute_command(char **args);

extern char *builtin_arr[];

/* Fundtin declarations for builtin simple shell commands*/
int simple_shell_cd(char **args);
int simple_shell_help(char **args);
int simple_shell_exit(char **args);

int simple_shell_num_builtins();
int simple_shell_cd(char **args);
int simple_shell_help(char **args);
int simple_shell_exit(char **args);

#endif