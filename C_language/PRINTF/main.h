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

// ANSI color codes
#define RESET       "\x1b[0m"  // Reset to default color
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"
/*#define COLOR_RESET "\033[0m"
#define COLOR_NUMBER "\033[0;33m"     // Yellow for numbers
#define COLOR_ALPHABET "\033[0;32m"   // Green for alphabets
#define COLOR_BRACKETS "\033[0;34m"   // Blue for brackets
#define COLOR_QUOTES "\033[0;31m"     // Red for quotes*/

static char buffer[BUFFER_SIZE];
static int buffer_index = 0;

/* struct defination */
typedef struct flags {
	int left_justify;
	int right_justify;
	int zero_padding;
	int plus;
} flags_t;

/* Function prototype */
int main(void);
int _printf(const char *format, ...);
void add_to_buffer(char character);
void print_buffer(void);
char* get_buffer(void);
int handle_specifier(char specifier, va_list args, char next_char/*, flags_t flags*/);
void covert_to_binary(int num, char *binary_str);
void covert_to_base8(unsigned int num, char *binary_str);
void covert_to_hexadecimal(unsigned int num, char *hex_str, char specifier);
int handle_flag(char flag, char specifier, flags_t flags);
int itera(char *string);
int itera_length(char *string);
void handle_length_height(char specifier, va_list args, char next_char);
int handle_width_precision(const char *format, int *i, char specifier, va_list args, flags_t flags);
int get_text_length(char specifier, va_list args, char next_char);
void run_width_tests(void);
void test_printf_precision(void);
char* apply_color(const char *str);
void set_color(char character);
void reset_color(void);
void textcolor(const char *color);

#endif /* MAIN_H */

