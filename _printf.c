#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * print_char - prints a character to stdout
 * @arg: the argument to print (a character)
 * Return: the number of characters printed (always 1)
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_string - prints a string to stdout
 * @arg: the argument to print (a string)
 * Return: the number of characters printed
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char*);
	int len = 0;

	while (str[len] != '\0')
	len++;
	write(1, str, len);
	return (len);
}

/**
 * print_percent - prints a percent symbol to stdout
 * @arg: unused
 * Return: the number of characters printed (always 1)
 */
int print_percent(va_list arg)
{
	(void)arg;
	write(1, "%", 1);
	return (1);
}
/**
 * _printf - prints a formatted string to stdout
 * @format: the format string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	int (*print_func)(va_list);

	va_start(args, format);
	while (*format != '\0')
	{
	if (*format == '%')
	{
		format++;
		switch (*format)
		{
			case 'c':
				print_func = &print_char;
				break;
			case 's':
				print_func = &print_string;
				break;
			case '%':
				print_func = &print_percent;
				break;
			default:
				print_func = &print_percent;
				format--;
				break;
		}
		count += print_func(args);
	}
	else
	{
		write(1, format, 1);
		count++;
	}
	format++;
	}
	va_end(args);
	return (count);
}
