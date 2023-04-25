#include "main.h"

/**
 * print_unsigned-prints unsigned no
 * @typ:list of args
 * @buff:buffer arr to hndle print
 * @f:calcls actve flags
 * @w:get width
 * @p:specifies precision
 * @size:specifies size
 * Return:no of chars printed
*/
int print_unsigned(va_list typ, char buff[], int f, int w, int p, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);

	num = convert_size_unsignd(num, size);

	if (num == 0)
	{
		buff[i--] = '0';
	}
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buff, f, w, p, size));
}
/**
 * print_octal-prints an unsigned no in octal notation
 * @typ:list of args
 * @buff:buffer array to jandle print
 * @f:calcs actve flags
 * @w:width
 * @p:specifies precision
 * @size:specifies size
 * Return:num of chars to be printed
*/
int print_octal(va_list typ, char buff[], int f, int w, int p, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int num_temp = num;

	UNUSED(w);
	num = convert_size_unsignd(num, size);
	if (num == 0)
	{
		buff[i--] = '0';
	}
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num = num / 8;
	}
	if (f & F_HASH && num_temp != 0)
	{
		buff[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buff, f, w, p, size));
}
/**
 * print_hexadecimal - prints an unsigned no in octal hexadecimal
 *@typ:list of args
 *@buff:buffer array to jandle print
 *@f:calcs actve flags
 *@w:width
 *@p:specifies precision
 *@size:specifies size
 *Return:num of chars to be printed
*/
int print_hexadecimal(va_list typ, char buff[], int f, int w, int p, int size)
{
	return (print_hexa(typ, "0123456789abcdef", buff, f, 'x', w, p, size));
}
/**
 *print_hexa_upper - prints an unsigned no in upper hexa notation
 *@typ:list of args
 *@buff:buffer array to jandle print
 *@f:calcs actve flags
 *@w:width
 *@p:specifies precision
 *@size:specifies size
 *Return:num of chars to be printed
*/
int print_hexa_upper(va_list typ, char buff[], int f, int w, int p, int size)
{
	return (print_hexa(typ, "0123456789ABCDEF", buff, f, 'X', w, p, size));
}
/**
 *print_hexa -prints an unsigned no in upper or lowa hexadecimal
 *@mp_t:arr of vals  where to map the no
 *@typ:list of args
 *@buff:buffer array to jandle print
 *@f:calcs actve flags
 *@f_ch:cals flags
 *@w:width
 *@p:specifies precision
 *@size:specifies size
 *Return:num of chars to be printed
*/
int print_hexa(va_list typ, char mp_t[], char buff[], int f, char f_ch,
		int w, int p, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int num_temp = num;

	UNUSED(w);
	num = convert_size_unsignd(num, size);
	if (num == 0)
	{
		buff[i--] = '\0';
	}
	buff[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buff[i--] = mp_t[num % 16];
		num = num / 16;
	}
	if (f & F_HASH && num_temp != 0)
	{
		buff[i--] = f_ch;
		buff[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buff, f, w, p, size));
}
