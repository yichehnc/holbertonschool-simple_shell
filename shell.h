#ifndef _SHELL_H_
#define _SHELL_H_

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <errno.h>

void run_shell(int interactive);
char *_read_line(void);
char *_read_stream();
char **_split_line(char *line);
int run_new_process(char **args);
int _execute_args(char **args);
char *get_filepath(char *command);
const char *get_filename(const char *path);

extern char *builtin_func_list[];

/* Functin declarations for builtin simple shell commands*/
int shell_cd(char **args);
int shell_help(char **args);
int shell_exit(char **args);

#endif