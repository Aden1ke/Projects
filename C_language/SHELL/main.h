#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

// Function prototypes
int main(void);
void prompt(void);
ssize_t read_input(char **line, size_t *len);
void execute_command(char *line);

#endif /* MAIN_H */

