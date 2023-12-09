#include "shell.h"
#include <stdio.h>
#include <unistd.h>
/**
 *is_interactive - check for interactive mode
 *by Aishat and king
 *Return: either true or false
 */
bool is_interactive(void)
{
return (isatty(fileno(stdin)));
}
/**
 *display_prompt - prints prompt on shell based on interactive mode
 *return: No return value
 */
void display_prompt(void)
{
	if (is_interactive())
	{
	printf("($) ");
	}
	else
	{
	printf("$ ");
	}
}
