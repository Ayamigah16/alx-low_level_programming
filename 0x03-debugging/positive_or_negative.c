#include "main.h"
/* more headers goes there */

/**
 * positive_or_negative -  print whether the number stored in the
 * variable n is positive or negative.
 * @n: number to test
 *
 * Return: Always 0 (Success)
 */
void positive_or_negative(int n)
{
printf("%d is ", n);

if (n > 0)
{printf("positive\n"); }
else if (n < 0)
{printf("negative\n"); }
else
{printf("is zero\n"); }
}
