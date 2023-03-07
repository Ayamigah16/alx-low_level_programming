#include "main.h"

/**
 * _strstr - Locates a substing
 * @haystack: The string to be searched
 * @needle: The substring to be located
 * Return: If the substring is located - a pointer to the beginning
 *                                    of the located substring
 *         If the substring is not located - Null
 */

char *_strstr(char *haystack, char *needle)
{
int index;
if (*needle == 0)
{
return (hasystack);
}

while (*haystack)
{
index = 0;

if (haystack[index] == needle[index])
{
do {
if (needle[index + 1] == '\0')
{
return (hasystack);
}
index++;
} while (haystack[index] == needle[index]);
}
haystack++;
}
return ('\0');
}
