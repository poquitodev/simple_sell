#include "shell.h"
/**
* _strcmp - comparing strings
*@s1:first string to be compared
*@s2:second string to be compared
*Return:return defference between the strings
*/
int _strcmp(const char *s1, const char *s2)
{
int i = 0;

while (s1[i] != '\0' || s2[i] != '\0')
{
if (s1[i] != s2[i])
{
break;
}
i++;
}

return (s1[i] - s2[i]);
}

/**
 * _strcpy - copy a string
 * @dest: dest parameter
 * @src: src parameter
 *
 * Return: return 0 always
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}

dest[i++] = '\0';
return (dest);
}
