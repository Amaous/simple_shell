#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>

#define MAX_ARGUMENTS 10
#define MAX_COMMAND_LENGTH 100

bool is_interactive(void);
void display_prompt(void);
void read_command(char *command);
void parsing_input(char *command, char *args[MAX_ARGUMENTS]);
void execute_command(char *args[MAX_ARGUMENTS]);
void exit_shell(void);

#endif  /* SHELL_H
