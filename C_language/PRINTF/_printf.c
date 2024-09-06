#include "main.h"

int _printf(const char *format, ...) {
	int i;
	int printed_chars = 0;
	flags_t flags = {0};

	// Declare a va_list variable
	va_list args;

	// Initialize the va_list with the number of arguments
	va_start(args, format);

	// Loop through the arguments
	for (i = 0; format[i] != '\0'; i++) {
		// Retrieve the next argument using va_arg
		if (format [i]  == '%' )
		{
			i++;
			while (format[i] == '+' || format[i] == ' ' || format[i] == '#') {
				printed_chars += handle_flag(format[i], format[i + 1], flags);
				i++;
            }
			if (format[i] == 'l' || format[i] == 'h') {
				handle_specifier(format[i], args, format[i + 1]);
				i++;  // Move to the specifier character after 'l' or 'h'
			} else if (isdigit(format[i])) {
				printed_chars += handle_width(format, &i, format[i + 2], args, flags);
			}
			else 
				printed_chars += handle_specifier(format[i], args, format[i + 1]);
		}
		else {
			add_to_buffer(format[i]);
			printed_chars++;
		}
	}
	// Clean up the va_list
	va_end(args);

	if (buffer_index > 0)
		print_buffer();

    return printed_chars;
}
