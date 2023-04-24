#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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
int print_nun_printable(va_list typ, char buff[], int f,
		                int w, int p, int size);
int print_rev(va_list typ, char buff[], int f, int w, int p, int size);
int print_rot13str(va_list typ, char buff[], int f, int w, int p, int size);
int get_f(const char *format, int *i);
int get_p(const char *format, int *i, va_list args);
int get_s(const char *format, int *i);
int get_w(const char *format, int *i, va_list args);
int handle_print(const char *fmt, int *ind, va_list list,
                char buff[], int f, int w, int p, int size);
int is_printable(char x);
int append_hexa_code(char ascii_code, char buff[], int i);
int is_digit(char c);
long int convert_size_num(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);
#endif 
