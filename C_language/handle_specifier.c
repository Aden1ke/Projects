#include "main.h"

int handle_specifier(char specifier, va_list args)
{
	int j, num;
	int printed_chars = 0;
	unsigned int u_num;
	char character, num_str[12], *str, binary_str[BUFFER_SIZE];

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
		case 'b':
			num = va_arg(args, int);
			covert_to_binary(num, binary_str);
			for (j = 0; binary_str[j] != '\0'; j++) {
				add_to_buffer(binary_str[j]);
				printed_chars++;
			}
			break;
		case 'u':
			u_num = va_arg(args, unsigned int);
			sprintf(num_str, "%u", u_num);
			for (j = 0; num_str[j] != '\0'; j++) {
				add_to_buffer(num_str[j]);
				printed_chars++;
			}
			break;
		case 'o':
			u_num = va_arg(args, unsigned int);
			covert_to_base8(u_num, binary_str);
			for (j = 0; binary_str[j] != '\0'; j++) {
				add_to_buffer(binary_str[j]);
				printed_chars++;
			}
			break;
		case 'x':
		case 'X':
			u_num = va_arg(args, unsigned int);
			covert_to_hexadecimal(u_num, binary_str, specifier);
			for (j = 0; binary_str[j] != '\0'; j++) {
				add_to_buffer(binary_str[j]);
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
