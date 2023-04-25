#include "main.h"

/**
 * print_ptr - prints value of a ptr var
 * @typ:list of args
 * @buff:buffer array for print
 * @f:obtaining active flags
 * @w:width
 * @p:specify precision
 * @size:specify size
 * Return:chars printed
 */
int print_ptr(va_list typ, char buff[], int f, int w, int p, int size)
{
	char extra_char = 0, padd = ' ';
	int index = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long nm_adress;
	char map_to[] = "0123456789abcdef";
	void *adress = va_arg(typ, void *);

	UNUSED(w);
	UNUSED(size);
	UNUSED(p);
	if (adress == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_SIZE - 1] = '\0';
	nm_adress = (unsigned long) adress;
	while (nm_adress > 0)
	{
		buff[index--] = map_to[nm_adress % 16];
		nm_adress /= 16;
		len++;
	}
	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f && F_PLUS)
	{
		extra_char = '+', len++;
	}
	else if (f & F_SPACE)
	{
		extra_char = ' ', len++;
	}
	index++;
	return (write_ptr(buff, index, len, w, f,
				padd, extra_char, padd_start));
}

/**
 * print_nun_printable - prints ascii codes of non printable chars in hexa
 *@typ:list of args
 *@buff:buffer array for print
 *@f:obtaining active flags
 *@w:width
 *@p:specify precision
 *@size:specify size
 *Return:chars printed
 */
int print_nun_printable(va_list typ, char buff[], int f,
		int w, int p, int size)
{
	int i = 0, offst = 0;
	char *s = va_arg(typ, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);

	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (s[i] != '\0')
	{
		if (is_printable(s[i]))
		{
			buff[i + offst] = s[i];
		}
		else
		{
			offst += append_hexa_code(s[i], buff, i + offst);
		}
		i++;
	}
	buff[i + offst] = '\0';
	return (write(1, buff, i + offst));
}
/**
 * print_rev - prints a reverse string
 * @typ:list of args
 * @buff:buffer array for print
 * @f:obtaining active flags
 * @w:width
 * @p:specify precision
 * @size:specify size
 * Return:chars printed
 */
int print_rev(va_list typ, char buff[], int f, int w, int p, int size)
{
	char *s;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(size);

	s = va_arg(typ, char *);
	if (s == NULL)
	{
		UNUSED(p);
		s = ")Null(";
	}
	for (i = 0; s[i] ; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char k = s[i];

		write(1, &k, 1);
		count++;
	}
	return (count);
}
/**
 *print_rot13str - prints a string in rot13
 *@typ:list of args
 *@buff:buffer array for print
 *@f:obtaining active flags
 *@w:width
 *@p:specify precision
 *@size:specify size
 *Return:chars printed
 */
int print_rot13str(va_list typ, char buff[], int f, int w, int p, int size)
{
	char x;
	char *s;
	unsigned int i, j;
	int count = 0;
	char s_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char s_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(typ, char *);
	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(AHYY)";
	}
	for (i = 0; s[i]; i++)
	{
		for (j = 0; s_in[j] ; j++)
		{
			if (s_in[j] == s[i])
			{
				x = s_out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!s_in[j])
		{
			x = s[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
