#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - prints anything
 * @format: content to be printed
 * Return: the number of characters printed (always 1)
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, print_c = 0;
	int f, w, p, size, buff_i = 0;
	va_list arg;
	char buff[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg, format);

	for (i = 0; format && format[i] != '\0' i++)
	{
		if (format[i] != '%')
		{
			buff[buff_i++] = format[i];
			if (buff_i == BUFF_SIZE)
			{
				print_buff(buff, &buff_i);
			}
			print_c++;
		}
		else
		{
			print_buff(buff, &buff_i);
			f = get_f(format, &i);
			w = get_w(format, &i, arg);
			p = get_p(format, &i, arg);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, arg, buff, f, w, p, size);
			if (printed == -1)
				return (-1);
			printed_c = printed_c + printed;
		}
	}

	print_buffer(buff, &buff_i);

	va_end(arg);

	return (printed_c);
}

/**
 * print_buffer - Prints contents if there is a buffer
 * @buff: character arrays
 * @buff_i: index where next char is added, representing length.
 */
void print_buffer(char buff[], int *buff_i)
{
	if (*buff_i > 0)
	{
		write(1, &buff[0], *buff_i);
	}
	*buff_i = 0;
}
