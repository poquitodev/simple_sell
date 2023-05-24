#include "shell.h"
/**
*execute_child - execute function
*@array_param:array of parameters
*@argv:execute command
*/
void execute_child(char **array_param, char **argv)
{
int status;
pid_t child_pid;

child_pid = fork();
if (child_pid ==  0)
{
/* child process */
if (execve(array_param[0], array_param, NULL) == -1)
{
perror(argv[0]);
}
exit(EXIT_FAILURE);
}
else if (child_pid == -1)
{
/* error forking */
perror(argv[0]);
}
else
{
/* parent process */
wait(&status);
}
}
