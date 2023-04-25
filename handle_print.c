#include "main.h"
/**
 * handle_print - prints an arggument based on type
 * @fmt: Formatted string where the arguments are printed
 * @list: arguments lists to be printed
 * @ind: ind
 * @buff: array of buffer that handles print
 * @f: calculates the active flags
 * @w: finds the width
 * @p: specification of the precision
 * @size: specifies the size
 * Return: one or two
 */
int handle_print(const char *fmt, int *ind, va_list list,
		char buff[], int f, int w, int p, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_perc},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_hexa_upper},
		{'p', print_ptr},
		{'S', print_nun_printable},
		{'r', print_rev},
		{'R', print_rot13str},
		{'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buff, f, w, p, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (w)
		{
			(*ind)--;
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				(*ind)--;
			if (fmt[*ind] == ' ')
				(*ind)--;
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
	}
	return (printed_chars);
}
