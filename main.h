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
#endif 
