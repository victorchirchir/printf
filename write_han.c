#include "main.h"

/**
 * handle_write_char - print a string
 * @c:char type
 * @buff:buffer array for print
 * @f:calc active flags
 * @w:obtains width
 * @p:specifies precision
 * @size:specifies size
 * Return:no of chars printed
 */
int handle_write_char(char c, char buff[], int f, int w,
		int p, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(p);
	UNUSED(size);
	if (f & F_ZERO)
	{
	padd = '0';
	}
	buff[i++] = c;
	buff[i] = '\0';
	if (w > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w; i++)
			buff[BUFF_SIZE - i - 2] = padd;
		if (f & F_MINUS)
			return (write(1, &buff[0], 1) + write(1, &buff[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], w - 1) + write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}
/**
 * write_number - print string
 * @is_neg: list of args
 * @index:index no starts in buff
 * @buff: buffer array for print
 * @f:calcs active flags
 * @w:gets width
 * @p:specifies precison
 * @size:specifies size
 * Return:num of chars
 */
int write_number(int is_neg, int index, char buff[],
		int f, int w, int p, int size)
{
	int len = BUFF_SIZE - index - 1;
	char padd = ' ', ex_ch = 0;

	UNUSED(size);
	if ((f && F_ZERO) && !(f & F_MINUS))
	{
		padd = '0';
	}
	if (is_neg)
	{
		ex_ch = '-';
	}
	else if (f & F_PLUS)
	{
		ex_ch = '+';
	}
	else if (f & F_SPACE)
	{
		ex_ch = ' ';
	}
	return (write_num(index, buff, f, w, p, len, padd, ex_ch));
}
/**
 * write_num - write num usng buffer
 * @index:index which no starts from on bffer
 * @buff: the buffer
 * @f:flags
 * @w:width
 * @p:specifiers precision
 * @len:length of num
 * @padd:padding char
 * @ex_c:extra char
 * Return:num of printed characters
 */
int write_num(int index, char buff[], int f, int w, int p, int len,
		char padd, char ex_c)
{
	int i, padd_s = 1;

	if (p == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && w == 0)
		return (0);
	if (p == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		buff[index] = padd = ' ';
	if (p > 0 && p < len)
		padd = ' ';
	while (p > len)
		buff[--index] = '0', len++;
	if (ex_c != 0)
		len++;
	if (w > len)
	{
		for (i = 1; i < w - len + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			if (ex_c)
				buff[--index] = ex_c;
			return (write(1, &buff[index], len) + write(1, &buff[1], i - 1));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			if (ex_c)
				buff[--index] = ex_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[index], len));
		}
		else if (!(f & F_MINUS) && padd == '\0')
		{
			if (ex_c)
				buff[--padd_s] = ex_c;
			return (write(1, &buff[padd_s], i - padd_s) + write(1,
						&buff[index], len - (1 - padd_s)));
		}
	}
	if (ex_c)
		buff[--index] = ex_c;
	return (write(1, &buff[index], len));
}

/**
 * write_unsgnd - writes unsigned no
 * @is_neg:num indicating whether num is neg
 * @index:index which the no starts in buff
 * @buff:array
 * @f:specifies flags
 * @w:width
 * @p:precision
 * @size:specifies size
 * Return:no of chars wrten
 */
int write_unsgnd(int is_neg, int index, char buff[],
		int f, int w, int p, int size)
{
	int len = BUFF_SIZE - index - 1, i = 0;
	char padd = ' ';

	UNUSED(is_neg);
	UNUSED(size);
	if (p == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
	{
		return (0);
	}
	if (p > 0 && p < len)
	{
		padd = ' ';
	}
	while (p > len)
	{
		buff[--index] = '0';
		len++;
	}
	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (w > len)
	{
		for (i = 0; i < w - len; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (f & F_MINUS)
		{
			return (write(1, &buff[index], len) + write(1, &buff[0], i));
		}
		else
		{
			return (write(1, &buff[0], i) + write(1, &buff[index], len));
		}
	}
	return (write(1, &buff[index], len));
}
	/**
	 * write_ptr - write a memory adress
	 * @buff:array of chrs
	 * @index:index where no starts
	 * @len:length of the no
	 * @w:specifies width
	 * @f:specifies flags
	 * @padd:padding
	 * @ex_c:extra char
	 * @padd_s:index padding starts
	 *Return:Number of written chars
	 */
	int write_ptr(char buff[], int index, int len, int w,
			int f, char padd, char ex_c, int padd_s)
{
		int i;

		if (w > len)
		{
			for (i = 3; i < w - len + 3; i++)
				buff[i] = padd;
			buff[i] = '\0';
			if (f & F_MINUS && padd == ' ')
			{
				buff[--index] = 'x';
				buff[--index] = '0';
				if (ex_c)
					buff[--index] = ex_c;
				return (write(1, &buff[index], len) + write(1, &buff[3], i - 3));
			}
			else if (!(f & F_MINUS) && padd == ' ')
			{
				buff[--index] = 'x';
				buff[--index] = '0';
				if (ex_c)
					buff[--index] = ex_c;
				return (write(1, &buff[3], i - 3) + write(1, &buff[index], len));
			}
			else if (!(f & F_MINUS) && padd == '0')
			{
				if (ex_c)
					buff[--padd_s] = ex_c;
				buff[1] = '0';
				buff[2] = 'x';
				return (write(1, &buff[padd_s], i - padd_s) +
						write(1, &buff[index], len - (1 - padd_s) - 2));
			}
		}
	buff[--index] = 'x';
	buff[--index] = '0';
	if (ex_c)
	{
		buff[--index] = ex_c;
	}
	return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
