#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_c - function to print char
 * @arg: argument
 * Return: returns int
*/

int print_c(va_list arg)
{
	char c = va_arg(arg, int);

	if (c == '\0')
	{
	return (write(1, &c, 1));
	}
	_putchar(c);
	return (1);
}

/**
 * print_s - function to print string
 * @arg: param
 * Return: returns string;
*/
int print_s(va_list arg)
{
	int i = 0, count = 0;
	char *str;

	str = va_arg(arg, char*);
	if (str == NULL)
	str = "(null)";

	while (*str != '\0')
	{
	_putchar(str[i]);
	i++;
	count++;
	}
	return (count);
}
/**
 * print_percent - function to print
 * @arg: parm
 * Return: return str
*/
int print_percent(va_list arg)
{
	int i = 0;
	char *str;

	i = va_arg(arg, int);
	str = "%";
	if (*str == i)
	return (*str);

	return (*str);
}

/**
 * print_d - print decimal
 * @arg: param
 * Return: int
*/

int print_d(va_list arg)
{

	unsigned int absolute, aux, countnum, count;
	int n;

	count = 0;
	n = va_arg(arg, int);
	if (n < 0)
	{
	absolute = (n * -1);
	count += _putchar('-');
	}
	else
	absolute = n;

	aux = absolute;
	countnum = 1;
	while (aux > 9)
	{
	aux /= 10;
	countnum *= 10;									}
	while (countnum >= 1)
	{
	count += _putchar(((absolute / countnum) % 10) + '0');
	countnum /= 10;
	}
	return (count);
}
/**
 * print_i - prints integer
 * @arg: integer argument
 * Return: the decimal function
*/

int print_i(va_list arg)
{
	return (print_d(arg));
}
