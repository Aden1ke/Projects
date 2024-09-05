#include "main.h"


int handle_width(const char *format, int *i, char specifier, va_list args, flags_t flags) {
	int width = 0, text_length = 0;
	int printed_chars = 0, j, padding_length;

	text_length = get_text_length(specifier, args);
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

	padding_length = width - text_length;


	if (padding_length < 0) {
		padding_length = 0;
	}


	// If left-justified, print the text first, then add spaces
	if (flags.left_justify) {
		printed_chars += handle_specifier(format[*i], args, format[*i + 1]);
		for (j = 0; j < padding_length; j++) {
			add_to_buffer(' ');
			printed_chars++;
		}
	} else {
		// If right-justified or zero-padded, add padding first, then print the text
		if (flags.zero_padding)
		{
			for (j = 0; j < padding_length; j++) {
				add_to_buffer('0');
				printed_chars++;
			}
		}
		else {
			for (j = 0; j < padding_length; j++) {
				add_to_buffer(' ');
				printed_chars++;
			}
		}
		printed_chars += handle_specifier(format[*i], args, format[*i + 1]);
	}


	return printed_chars;
}
