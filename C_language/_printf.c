#include "main.h"

int _printf(const char *format, ...) {
	int i;
	int printed_chars = 0;

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
			printed_chars += handle_specifier(format[i], args);
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


