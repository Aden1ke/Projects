#include "main.h"


/* Handle calculate length.
 * specifier: check for what to print.
 * args: arguments.
 * next_char : next character after specifiers.
 */
int get_text_length(char specifier, va_list args, char next_char) {
	int text_length = 0, num;
	unsigned int u_num;
	char num_str[12], *str, binary_str[BUFFER_SIZE];
	char nil_str[] = "(nil)";
	void *ptr;

	switch(specifier)
	{
		case 'c':
			text_length = 1;
			break;
		case 's':
			str = va_arg(args, char*);
			if (str == NULL) {
				text_length = itera_length(nil_str);
			}
			text_length = itera_length(str);
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			sprintf(num_str, "%d", num);
			text_length = itera_length(num_str);
			break;
		case 'b':
			num = va_arg(args, int);
			covert_to_binary(num, binary_str);
			text_length = itera_length(binary_str);
			break;
		case 'u':
			u_num = va_arg(args, unsigned int);
			sprintf(num_str, "%u", u_num);
			text_length = itera_length(num_str);
			break;
		case 'o':
			u_num = va_arg(args, unsigned int);
			covert_to_base8(u_num, binary_str);
			text_length = itera_length(binary_str);
			break;
		case 'x':
		case 'X':
			u_num = va_arg(args, unsigned int);
			covert_to_hexadecimal(u_num, binary_str, specifier);
			text_length = itera_length(binary_str);
			break;
		case 'p':
			ptr = va_arg(args, void*);
			if (ptr == NULL) {
				text_length = itera_length(nil_str);
			} else {
					sprintf(num_str, "%p", ptr);
					text_length = itera_length(num_str);
				}
			break;
		case '%':
			text_length++;
			break;
		case 'l':
		case 'h':
			handle_length_height(specifier, args, next_char);
			break;
		default:
			text_length+=2;
			break;
	}
	return text_length;
}
