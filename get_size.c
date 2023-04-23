#include "main.h"

/**
 * get_s- calculates the size to cast
 * @format: formatted string
 * @i:list of args to be printed
 * Return:precision
 */
int get_s(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
	{
		size = S_LONG;
	}
	else if (format[k] == 'h')
	{
		size = S_SHORT;
	}
	if (size == 0)
	{
		*i = k - 1;
	}
	else
	{
		*i = k;
	}
	return (size);
}

