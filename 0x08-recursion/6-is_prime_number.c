#include "main.h"

/**
 * is_prime_helper - checks if a number is prime using recursion
 * @n: the number to check
 * @i: the current factor to test
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 */

int is_prime_helper(int n, int i)
{
if (n < 2)
{
return (0);
}
if (i * i > n)
{
return (1);
}
if (n % i == 0)
{
return (0);
}
return (is_prime_helper(n, i + 1));
}

/**
 * is_prime_number - checks if an input integer is a prime number
 * @n: the input integer
 *
 * Return: 1 if the input integer is a prime number, 0 otherwise
 */

int is_prime_number(int n)
{
return (is_prime_helper(n, 2));
}
