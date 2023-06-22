/* 100-operations.c */

/*
 * This is a C file that defines various mathematical operations.
 * It includes functions for addition, subtraction, multiplication,
 * division, and modulo operation.
 */

#include <stdio.h>

/**
 * add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of the two integers.
 */
int add(int a, int b)
{
    return a + b;
}

/**
 * sub - Subtracts two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The difference of the two integers.
 */
int sub(int a, int b)
{
    return a - b;
}

/**
 * mul - Multiplies two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The product of the two integers.
 */
int mul(int a, int b)
{
    return a * b;
}

/**
 * div - Divides two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of the division.
 *         If the second integer is 0, it prints an error message
 *         and returns 0 to avoid division by zero.
 */
int div(int a, int b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

/**
 * mod - Computes the modulo operation of two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The result of the modulo operation.
 *         If the second integer is 0, it prints an error message
 *         and returns 0 to avoid modulo by zero.
 */
int mod(int a, int b)
{
    if (b != 0)
    {
        return a % b;
    }
    else
    {
        printf("Error: Modulo by zero!\n");
        return 0;
    }
}
