#include "shell.h"
/**
* main - simple shell
*@argc:number of arguments
*@argv:content of arguments
*Return:return 0
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL;
	size_t n = 0;
	int command_count = 1;

	while (1)
	{
		parse_line(argv, line, n, &command_count);
	}
	return (0);
}
