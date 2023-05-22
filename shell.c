#include "shell.h"
/**
* main - simple shell
*@argc:number of arguments
*@argv:content of arguments
*Return:return 0
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL;
	size_t n = 0;

	while (1)
	{
		parse_line(argv, line, n);
	}
	return (0);
}
