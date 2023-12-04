#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * read_command - Read a command from the user
 * @command: Buffer to store the user input command
 *
 * Description:
 * This function reads a command from the user, using fgets to read from stdin
 * and storing the result in the provided command buffer. It handles the
 * end-of-file condition (Ctrl+D) by printing a goodbye message and exiting
 * the shell.
 *
 * Return: No return value.
 */
void read_command(char *command)
{
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
	/* Handle end of file (Ctrl+D)*/
	printf("\nExiting shell\n");
	exit_shell();  /* Exit the shell*/
	}

	/* Removing the newline character at the end*/
	command[strcspn(command, "\n")] = '\0';
}
