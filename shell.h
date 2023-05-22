#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define PROMPT "$ "
#define DELIM_PROMPT " \n\t"
extern char **environ;


/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;


void parse_line(char **argv, char *line, size_t n);
void print_char(char c);
void print_string(char *str);
int str_len(char *str);
char *_strdup(char *str);
char **tokenization(char *line);
int count_tokens(char *str_copy);


void free_array_line(char **array_param, char *line);

#endif
