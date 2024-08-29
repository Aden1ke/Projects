#include "main.h"

int handle_specifier(char specifier, va_list args)
{
	int j, num;
	int printed_chars = 0;
	char character, num_str[12], *str;

	switch(specifier)
	{
		case 'c':
			character = va_arg(args, int);
			add_to_buffer(character);
			printed_chars++;
			break;
		case 's':
			str = va_arg(args, char*);
			for (j = 0; str[j] != '\0'; j++) {
				add_to_buffer(str[j]);
				printed_chars++;
			}
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			sprintf(num_str, "%d", num);
			for (j = 0; num_str[j] != '\0'; j++) {
				add_to_buffer(num_str[j]);
				printed_chars++;
			}
			break;
		case '%':
			add_to_buffer('%');
			printed_chars++;
			break;
		default:
			add_to_buffer('%');
			add_to_buffer(specifier);
			printed_chars += 2;
			break;
	}
	return printed_chars;
}
