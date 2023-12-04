#include "shell.h"
#include <string.h>
/**
 * parsing_input - Tokenize a command into arguments
 * @command: Command string to be tokenized
 * @args: Array to store the tokenized arguments
 *
 * Description:
 * This function takes a command string and tokenizes it into arguments using
 * the strtok function. The resulting arguments are stored in the provided
 * arguments array, which is null-terminated.
 *
 * Return:
 * No return value.
 */

void parsing_input(char *command, char *args[MAX_ARGUMENTS])
{
	/* Tokenizing the command and extracting arguments*/
	int argc = 0;
	char *token = strtok(command, " ");

	while (token != NULL && argc < MAX_ARGUMENTS - 1)
	{
	args[argc] = token;
	token = strtok(NULL, " ");
	argc++;
	}

	args[argc] = NULL;  /* Null-terminate the arguments array*/
}
