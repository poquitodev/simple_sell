#include "shell.h"

/**
* free_array_line - free array and line
* @array_param: array of tokens
* @line: command line
*/

void free_array_line(char **array_param, char *line)
{
	int i = 0;

	free(line);
	while (array_param[i])
	{
		free(array_param[i]);
		i++;
	}
	free(array_param);
}
