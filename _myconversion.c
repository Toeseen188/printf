#include <stdio.h>
#include "main.h"
#include <stdarg.h>



int print_c (va_list arg)
{
	int i = 0;
	i = va_arg(arg,int);


	return(_putchar(i));
}


int print_s(va_list arg)
{
	int i = 0, count = 0;
	char *str;
	str = va_arg(arg, char*);
	
	if (str == NULL)
	str = "(null)";

	while(*str != '\0')
	{
	_putchar(str[i]);
	i++;
	count++;
	}
	return (count);
}

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
