#include "main.h"
/**
 * is_printable - Evaluates whether a char is printable
 * @x: the character to be evaluated
 * Return: 1 if x is printable, otherwise 0
 */
int is_printable(char x)
{
	if (x >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - append ASCCI in hexadecimal code to buffer
 * @buff: character arrays
 * @i: index at which to start appending
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buff[], int i)
{
	char map_to[] = "0123456789ABCDEF"
		if (ascii_code < 0)
			ascii_code *= -1;

	buff[i++] = '\\';
	buff[i++] = 'x';

	buff[i++] = map_to[ascii_code / 16];
	buff[i] = map_to[ascii_code % 16];

	return (3);
}
/**
 * is_digit - verifies if a char is a digit
 * @c: character to be evaluated
 * Return: if it is a digit 1, otherwise 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/**
 * convert_size_num - Resizes a given integer to the given precision.
 * @num: number to be resized
 * @size: number indicating the type to be resized.
 * Return: resized value of num
 */
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_unsigned - casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 * Return: casted value of num
 */
long int convert_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
