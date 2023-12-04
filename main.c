#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * main - Entry point for a simple shell program
 *
 * Description:
 * This function initializes a simple interactive shell that repeatedly
 * prompts the user for input, processes commands, and executes them.
 * It uses helper functions to display the shell prompt, read user input,
 * tokenize the input into arguments, and handle specific commands.
 *
 * Return:
 * The function returns 0, indicating successful.
 * The shell runs  until the "exit" command or an eof condition is encountered.
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGUMENTS];
	char **environ;

	while (1)
	{
	/* Displaying prompt and waiting for user input*/
	display_prompt();
	read_command(command);

	/* Splitting the command into arguments*/
	parsing_input(command, args);

	/* Check if the command is "exit"*/
	if (strcmp(args[0], "exit") == 0)
	{
	exit_shell();  /* Exit the shell*/
	}

	/* Check if the command is "env"*/
	if (strcmp(args[0], "env") == 0)
	{
	/* Print the current environment variables*/
	char **env = environ;

	while (*env != NULL)
	{
	printf("%s\n", *env);
	env++;
	}
	continue;
	}

	/* Execute the command*/
	execute_command(args);
	}

	return (0);
}
