#include "shell.h"

/**
* print_string - print string
* @str: parameter char
*/

void print_string(char *str)
{
	if (str == NULL)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return;
	}
	write(STDOUT_FILENO, str, str_len(str));
}

/**
* print_char - print character
* @c: parameter char
*/

void print_char(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
* str_len - get length of string
* @str: string base
* Return: return length
*/

int str_len(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/**
* _strdup - copy string to malloc
* @str: string base
* Return: return pointer to string
*/

char *_strdup(char *str)
{
	int i = 0;
	char *str_copy;

	str_copy = malloc(str_len(str) + 1);
	if (!str_copy)
		return (NULL);
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}
