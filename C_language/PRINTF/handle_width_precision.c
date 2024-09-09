#include "main.h"


int handle_width_precision(const char *format, int *i, char specifier, va_list args, flags_t flags) {
	int width = 0, text_length = 0, precision = 0;
	int printed_chars = 0, padding_length =0, j;

	// Check if the width is specified using an asterisk
	if (format[*i] == '*') {
		width = va_arg(args, int);
		(*i)++;
	} else {
		// Calculate width if it's a number in the format string
		while (format[*i] >= '0' && format[*i] <= '9') {
			width = width * 10 + (format[*i] - '0'); // Convert the string number into integer
			(*i)++;
		}
	}


	// Check for precision
	if (format[*i] == '.') {
		(*i)++;  // Move to precision
		if (format[*i] == '*') {
			precision = va_arg(args, int);
			(*i)++;
		} else {
			while (isdigit(format[*i])) {
				precision = precision * 10 + (format[*i] - '0');
				(*i)++;
			}
		}
	}

	specifier = format[*i]; //update specifier
	text_length = get_text_length(specifier, args, format[*i + 1]);

	// Precision padding
	if (precision > text_length) {
		padding_length = precision - text_length;
		for (j = 0; j < padding_length; j++) {
			add_to_buffer('0');
			printed_chars++;
		}
	}

	// Width padding after precision
	if (width > text_length + padding_length) {
		padding_length = width - (text_length + padding_length);
		for (j = 0; j < padding_length; j++) {
			add_to_buffer(flags.zero_padding && !flags.left_justify ? '0' : ' ');
			printed_chars++;
		}
	}

	printed_chars += handle_specifier(specifier, args, '\0');

	return printed_chars;
}
