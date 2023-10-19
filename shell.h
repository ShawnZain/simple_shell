#ifndef SHELL_H
#define SHELL_H

/* ---LIBRARIES--- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

/* ---MACROS--- */
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/* ---PROTOTYPES--- */
void shell_interactive(void);
void shell_non_interactive(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int exec_non_builtin(char *args[]);
char *read_stream(void);

/*---Builtin func---*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

#endif /* SHELL_H */
