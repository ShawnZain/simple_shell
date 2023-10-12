#ifndef SHELL_H
#define SHELL_H

/* ---LIBRARIES--- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

/* ---MACROS--- */
#define TOK_DELIM " \t\r\n\a\""

/* ---PROTOTYPES--- */
void shell_interactive(void);
void shell_non_interactive(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);

#endif /* SHELL_H */
