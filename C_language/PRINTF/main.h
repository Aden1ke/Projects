#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* define buffer */
#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buffer_index = 0;


/* Function prototype */
int main(void);
int _printf(const char *format, ...);
void add_to_buffer(char character);
void print_buffer(void);
int handle_specifier(char specifier, va_list args);
void covert_to_binary(int num, char *binary_str);
void covert_to_base8(unsigned int num, char *binary_str);
void covert_to_hexadecimal(unsigned int num, char *hex_str, char specifier);
int handle_flag(char flag, char specifier);

#endif /* MAIN_H */

