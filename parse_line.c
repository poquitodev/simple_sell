#include "shell.h"
/**
*parse_line -parsing command
*@argv:content of arguments
*@line:command line
*@n:length
*/
void parse_line(char **argv, char *line, size_t n, int *command_count)
{
	ssize_t check;
	char **array_param;
	char *file_path;

	if (isatty(STDIN_FILENO))
		print_string(PROMPT);

	check = getline(&line, &n, stdin);
	if (check == -1)
	{
		exit(1);
	}
	array_param = tokenization(line);
	if (built_in(array_param, line))
	{
		free_array_line(array_param, line);
		return;
	}
	file_path = locate_path(array_param[0]);
	if (file_path)
	{
		if (file_path != array_param[0])
		{
			free(array_param[0]);
			array_param[0] = file_path;
		}
		execute_child(array_param, argv);
	}
	else
	{
		print_string(argv[0]);
		print_string(": ");
		print_int(*command_count);
		print_string(": ");
		print_string(array_param[0]);
		print_string(": ");
		print_string("not found\n");
	}

	(*command_count)++;

	free_array_line(array_param, line);
}

/**
 * tokenization - split string into tokens
 * @line: string base
 * Return: return array of tokens
 */


char **tokenization(char *line)
{
	char *str_copy;
	char **array_param;
	char *token;
	int length = 0;
	int i = 0;

	str_copy = _strdup(line);
	length = count_tokens(str_copy);
	array_param = malloc((sizeof(char *)) * length + 1);
	token = strtok(str_copy, DELIM_PROMPT);

	while (token != NULL)
	{
		array_param[i] = _strdup(token);
		token = strtok(NULL, DELIM_PROMPT);
		i++;
	}
	array_param[i] = NULL;
	free(str_copy);
	return (array_param);
}

/**
* count_tokens - get number of tokens in string
* @str_copy: string base
* Return: return number of tokens
*/

int count_tokens(char *str_copy)
{
	char *token, *str_copy_up;
	int length = 0;

	str_copy_up = _strdup(str_copy);
	token = strtok(str_copy_up, DELIM_PROMPT);

	while (token != NULL)
	{
		token = strtok(NULL, DELIM_PROMPT);
		length++;
	}
	free(str_copy_up);
	return (length);
}
