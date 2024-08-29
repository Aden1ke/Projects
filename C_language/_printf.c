#include "main.h"

int _printf(const char *format, ...) {
	int i, j;
	char character;
	char *str;
	int num;
	char num_str[12];

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
			switch(format[i])
			{
				case 'c':
					character = va_arg(args, int);
					add_to_buffer(character);
					break;
				case 's':
					str = va_arg(args, char*);
					for (j = 0; str[j] != '\0'; j++)
					{
						add_to_buffer(str[j]);
					}
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					sprintf(num_str, "%d", num);
					for (j = 0; num_str[j] != '\0'; j++) {
						add_to_buffer(num_str[j]);
					}
					break;
				case '%':
					add_to_buffer('%');
					break;
				default:
					add_to_buffer('%');
					add_to_buffer(format[i]);
					break;
					
			}
		}
		else {
			add_to_buffer(format[i]);
		}
	}
	// Clean up the va_list
	va_end(args);

    return 0;
}


