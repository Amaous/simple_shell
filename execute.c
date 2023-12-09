#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 *execute_command - Execute a command using fork and execvp
 *by Aishat and king
 *@args: Array of command arguments
 *Description:
 * This function forks a child process and executes the specified command using
 * execvp.
 * The execute_command function is responsible for handling PATH and printing
 * an error message if the command execution fails.
 *Return: No return value
 */

void execute_command(char *args[MAX_ARGUMENTS])
{
	/* creating a child process*/
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	/* Child process*/

	/* Execute the command using execvp and handle PATH*/
	execvp(args[0], args);

	/* If execvp fails, print an error message*/
	perror("execvp");

	/* Exit the child process*/
	exit(EXIT_FAILURE);
	}
	else
	{
	/* Parent process*/
	/* Wait for the child to finish*/
	waitpid(pid, NULL, 0);
	}
}
