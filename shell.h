#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char *_read_line(void);
char *_read_stream();
char **_split_line(char *line);
int run_new_process(char **args);
int _execute_args(char **args);

extern char *builtin_func_list[];

/* Functin declarations for builtin simple shell commands*/
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

#endif