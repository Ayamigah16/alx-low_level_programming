/* 100-times_table.c */

#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: the times table to print
 */
void print_times_table(int n)
{
int i, j, result;

if (n > 15 || n < 0)
return;

for (i = 0; i <= n; i++)
{
for (j = 0; j <= n; j++)
{
result = i * j;

if (j == 0)
printf("%d", result);
else
printf(",%3d", result);
}
printf("\n");
}
}
