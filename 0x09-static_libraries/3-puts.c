#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

void _puts(char *str)

{
int i = 0;
while (str[i])
{
putchar(str[i]);
i++;
}
putchar('\n');
}
