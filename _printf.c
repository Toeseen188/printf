#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * _printf - prints strings and calculate sum
 * @format: character pointer as args
 * Return: this function returns sum to the main function
 */
/* function declaration*/

int (*get_func(char c))(va_list);
int _printf(const char *format, ...)
{
	va_list arg;
	int sum = 0;
	int i = 0;
	int (*func)(va_list);

	if (!format || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	va_start(arg, format);
	while (format[i])
	{
	if (format[i] == '%')
	{
	if (format[i + 1] != '\0')
	func = get_func(format[i + 1]);

	if (func == NULL)
	{
	_putchar(format[i]);
	sum++;
	i++;
	}
	else
	{
	sum += func(arg);
	i = i + 2;
	continue;
	}
	}
	else
	{
	_putchar(format[i]);
	sum++;
	i++;
	}
	}
	va_end(arg);
	return (sum);
}

/**
 * get_func - this function check for the specifier
 * @c: this is a variable arg to the funtion
 * Return: returns the function back to the call routine
*/

int (*get_func(char  c))(va_list arg)
{
	int i = 0;

	specify spec[] = {

		{"c", print_c},
		{"s", print_s},
		{"%", print_percent}
	};
	while (spec[i].c)
	{
	if (c == spec[i].c[0])
	{
	return (spec[i].f);
	}
	i++;
	}
	return (NULL);

}
