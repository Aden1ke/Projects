#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/* define buffer */
#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buffer_index = 0;

/* struct defination */
typedef struct flags {
	int left_justify;
	int right_justify;
	int zero_padding;
} flags_t;

/* Function prototype */
int main(void);
int _printf(const char *format, ...);
void add_to_buffer(char character);
void print_buffer(void);
char* get_buffer(void);
int handle_specifier(char specifier, va_list args, char next_char);
void covert_to_binary(int num, char *binary_str);
void covert_to_base8(unsigned int num, char *binary_str);
void covert_to_hexadecimal(unsigned int num, char *hex_str, char specifier);
int handle_flag(char flag, char specifier, flags_t flags);
int itera(char *string);
int itera_length(char *string);
void handle_length_height(char specifier, va_list args, char next_char);
int handle_width(const char *format, int *i, char specifier, va_list args, flags_t flags);
int get_text_length(char specifier, va_list args);
void run_width_tests(void);

#endif /* MAIN_H */

