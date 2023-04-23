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
#endif 
