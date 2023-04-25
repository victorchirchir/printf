#include "main.h"
/**
 * get_w - calculates width for printng
 * @format: formatted string
 * @i:list of arguments
 * @args:list of args
 * Return:width
 */
int get_w(const char *format, int *i, va_list args)
{
	int k;
	int w = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (is_digit(format[k]))
		{
			w = w * 10;
			w += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			w = va_arg(args, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = k - 1;
	return (w);
}
