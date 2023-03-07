#include "main.h"

/**
 * _strcht - Locates a character in a string
 * @s: The string to be searched
 * @c: The character to be searched
 * Return: If c is found - a pointer to the first occurrence
 *         If c is not found - Null
 */

char *_strchr(char *s, char c)
{
int index;

for (index = 0; s[index] >= '\0'; index++)
{
if (s[index] == c)
{
return (s + index);
}
}
return ('\0');
}
