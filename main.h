#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
typedef struct specifier
{
	char *c;
	int (*f)(va_list);
} specify;

int (*get_func(char c))(va_list);
int _putchar(char c);
int _printf(const char *format, ...);
int print_s(va_list arg);
int print_c(va_list arg);
int print_percent(va_list arg);

#endif
