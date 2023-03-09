#include "main.h"
/**
 * wildcmp - compares two strings and returns 1 if they can be considered
 *           identical, otherwise returns 0. The `s2` parameter can contain
 *           the special character `*`, which can replace any string
 * @s1: the first string to compare
 * @s2: the second string to compare, which can contain `*`
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
/* If both strings are empty, they are identical */
if (*s1 == '\0' && *s2 == '\0')
{
return (1);
}

/* If the current character of s2 is *, try all possible matches with s1 */
if (*s2 == '*')
{
/* Skip the * in s2 */
s2++;
/* If s2 is now empty, it matches any string */
if (*s2 == '\0')
{
return (1);
}
/* Try all possible matches of s1 with the rest of s2 */
if (*s1 != '\0' && wildcmp(s1 + 1, s2))
{
return (1);
}
/* If there is no match, the strings are not identical */
return (wildcmp(s1, s2));
}

/* If the current character of s2 is not *, compare it with s1 */
if (*s1 != '\0' && (*s1 == *s2 || *s2 == '?'))
{
return (wildcmp(s1 + 1, s2 + 1));
}

/* If none of the above cases match, the strings are not identical */
return (0);
}
