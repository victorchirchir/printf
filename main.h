#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>

#define UNUSED(i) (void)(i)
#define BUFF_SIZE 1024
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int print_char(va_list typ, char buff[], int f, int w, int p, int size);
int print_str(va_list typ, char buff[], int f, int w, int p, int size);
int print_perc(va_list typ, char buff[], int f, int w, int p, int size);
int print_int(va_list typ, char buff[], int f, int w, int p, int size);
int print_binary(va_list typ, char buff[], int f, int w, int p, int size);
int print_ptr(va_list typ, char buff[], int f, int w, int p, int size);
int print_nun_printable(va_list typ, char buff[], int f, int w,
		int p, int size);
int print_rev(va_list typ, char buff[], int f, int w, int p, int size);
int print_rot13str(va_list typ, char buff[], int f, int w, int p, int size);
int get_f(const char *format, int *i);
int get_p(const char *format, int *i, va_list args);
int get_s(const char *format, int *i);
int get_w(const char *format, int *i, va_list args);
int handle_print(const char *fmt, int *ind, va_list list, char buff[],
		int f, int w, int p, int size);
int is_printable(char x);
int append_hexa_code(char ascii_code, char buff[], int i);
int is_digit(char c);
long int convert_size_num(long int num, int size);
long int convert_size_unsignd(unsigned long int num, int size);
int handle_write_char(char c, char buff[], int f, int w,
		int p, int size);
int write_number(int is_neg, int index, char buff[],
		int f, int w, int p, int size);
int write_num(int index, char buff[], int f, int w, int p, int len,
		char padd, char ex_c);
int write_unsgnd(int is_neg, int index, char buff[],
		int f, int w, int p, int size);
int write_ptr(char buff[], int index, int len, int w,
		int f, char padd, char ex_c, int padd_s);
int print_hexa(va_list typ, char mp_t[], char buff[], int f, char f_ch,
		int w, int p, int size);
int print_hexa_upper(va_list typ, char buff[], int f, int w, int p, int size);
int print_octal(va_list typ, char buff[], int f, int w, int p, int size);
int print_unsigned(va_list typ, char buff[], int f, int w, int p, int size);
int print_hexadecimal(va_list typ, char buff[], int f, int w, int p, int size);

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_SHORT 1
#define S_LONG 2
/**
 * struct fmt - struct operator
 * @fmt: format
 * @fn: function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/*
 * typedef struct fmt fmt_t - struct operator
 * @fmt:format
 * @fm_t:function associated
 */
typedef struct fmt fmt_t;
#endif
