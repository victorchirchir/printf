nclude "main.h"
/**
 * print_char - prints a character
 * @typ: arguments list
 * @w: width of array
 * @buff: array buffer handling print
 * @p: specification of precision
 * @f: calculates the active flags
 * @size: size of the specifier
 * Return: number of printed characters
 */
int print_char(va_list typ, char buff[], int f, int w, int p, int size)
{
	char c = va_arg(typ, int);

	return (handle_write_char(c, buff, f, w, p, size));
}

/**
 * print_str - prints a string
 * @typ: arguments list
 * @buff: array buffer to handle print
 * @f: calculates the active flags
 * @w: find width
 * @p: specification of precision
 * @size: size of the specifier
 * Return: number of printed characters
 */
int print_str(va_list typ, char buff[], int f, int w, int p, int size)
{
	int len = 0, i;
	char *str = va_arg(typ, char*);

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
		{
			str = " ";
		}
	}
	while (str[len] != '\0')
		len++;
	if (p >= 0 && p < len)
	{
		len = p;
	}
	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = w - len; i > 0; i--)
				write(1, "", 1);
			return (w);
		}
		else
		{
			for (i = w - len; i > 0; i--)
				write(1, "", 1);
			write(1, &str[0], len);
			return (w);
		}
	}
	return (write(1, str, len));
}

/**
 * print_perc - prints a precent sign
 * @typ: arguments list
 * @buff: array buffer handling print
 * @f: calculates the active flags
 * @w: find width
 * @p: specification of precision
 * @size: size specifier
 * Return: Number o printed characters
 */
int print_perc(va_list typ, char buff[], int f, int w, int p, int size)
{
	UNUSED(typ);
	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - prints an int
 * @typ: arguments list
 * @buff: array buffer handling print
 * @f: calculates the active flags
 * @w: find width
 * @p: specification of precision
 * @size: size specifier
 * Return: Number o printed characters
 */
int print_int(va_list typ, char buff[], int f, int w, int p, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = convert_size_num(n, size);

	if (n == 0)
	{
		buff[i--] = '0';
	}
	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_num(is_negative, i, buff, f, w, p, size));
}

/**
 * print_binary - prints unsigned number
 * @typ: arguments list
 * @buff: array buffer handling print
 * @f: calculates the active flags
 * @w: find width
 * @p: specification of precision
 * @size: size specifier
 * Return: Number o printed characters
 */
int print_binary(va_list typ, char buff[], int f, int w, int p, int size)
{
	unsigned int a, b, i, sum;
	unsigned int x[32];
	int count;

	UNUSED(buff);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(size);

	a = va_arg(typ, unsigned int);
	b = 2147483648;
	x[0] = a / b;
	for (i = 1; i < 32; i++)
	{
		b /= 2;
		x[i] = (a / b) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum = x[i] + sum;
		if (sum || i == 31)
		{
			char k = '0' + x[i];

			write(1, &k, 1);
			count++;
		}
	}
	return (count);
}
