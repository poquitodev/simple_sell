#include "shell.h"
/**
* locate_path - locate a path if exist or not
* @name:name of the path
* Return:return path if exist or null if not
*/
char *locate_path(const char *name)
{
char *env_value, *env_value_copy, *token, *file_path;

if (is_exist(name))
return ((char *)name);
env_value = _getenv("PATH");
if (env_value)
{
env_value_copy = _strdup(env_value);
token = strtok(env_value_copy, ":");
if (!token)
return (NULL);
file_path = join_strings(token, name, '/');
if (is_exist(file_path))
{
free(env_value_copy);
return (file_path);
}
free(file_path);
while (token)
{
token = strtok(NULL, ":");
if (!token)
break;
file_path = join_strings(token, name, '/');
if (is_exist(file_path))
{
free(env_value_copy);
return (file_path);
}
free(file_path);
file_path = NULL;
}
free(env_value_copy);


}
return (NULL);
}
/**
* is_exist - check file if exist
* @file_name:name of the file to be checked
* Return:return 1 if the file exist ,0 if not
*/
int is_exist(const char *file_name)
{
struct stat buf;

if (stat(file_name, &buf) == 0)
{
return (1);
}
return (0);
}
/**
* _getenv - getting the value of env
* @name:name of env
* Return:return the value if it exist and null if not
*/
char *_getenv(const char *name)
{
char *env_str;
char *token;
int i = 0;

while (environ[i])
{
env_str = _strdup(environ[i]);
token = strtok(env_str, "=");
if (_strcmp(token, name) == 0)
{
token = strtok(NULL, "=");
return (token);
}
free(env_str);
i++;
}
return (NULL);
}
/**
* join_strings - merge env path with name of command
* @first:env path
* @second:command
* @sep:seperator "/"
* Return:return built string or null if error
*/
char *join_strings(const char *first, const char *second, char sep)
{
int length = 0, i = 0;
char *str;

if (!first || !second || sep == '\0')
return (NULL);
while (first[i])
{
length++;
i++;
}
i = 0;
while (second[i])
{
length++;
i++;
}
str = malloc(sizeof(char) * length + 2);
if (!str)
return (NULL);
length = 0;
i = 0;
while (first[i])
{
str[length] = first[i];
length++;
i++;
}
str[length] = sep;
length++;
i = 0;
while (second[i])
{
str[length] = second[i];
length++;
i++;
}
str[length] = '\0';
return (str);

}
