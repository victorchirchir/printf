#include "main.h"

/**
 * get_p - calculates precision for printing
 * @format: formatted string
 * @i:no of args to be printed
 * @args: list of arguments
 * Return:precision
 */
int get_p(const char *format, int *i, va_list args)
{
	int k = *i + 1;
	int p = -1;

	if (format[k] != '.')
	{
		return (p);
	}
	p = 0;
	for (k += 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			p *= 10;
			p += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			p = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = k - 1;
	return (p);
}
