#include "main.h"


/* Handle specifiers.
 * specifier: check for what to print.
 * args: arguments.
 * next_char : next character after specifiers.
 */
int handle_specifier(char specifier, va_list args, char next_char/*, flags_t flags*/)
{
	int printed_chars = 0, num;
	unsigned int u_num;
	char character, num_str[12], *str, binary_str[BUFFER_SIZE], nil_str[] = "(nil)";
	void *ptr;

	switch(specifier)
	{
		case 'c':
			character = va_arg(args, int);
			add_to_buffer(character);
			printed_chars++;
			break;
		case 's':
			str = va_arg(args, char*);
			if (str == NULL) str = "(null)";
			itera(str);
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			/*if (flags.plus && num >= 0) {
				add_to_buffer('+');
				printed_chars++;
			}*/
			sprintf(num_str, "%d", num);
			itera(num_str);
			break;
		case 'b':
			num = va_arg(args, int);
			covert_to_binary(num, binary_str);
			itera(binary_str);
			break;
		case 'u':
			u_num = va_arg(args, unsigned int);
			sprintf(num_str, "%u", u_num);
			itera(num_str);
			break;
		case 'o':
			u_num = va_arg(args, unsigned int);
			covert_to_base8(u_num, binary_str);
			itera(binary_str);
			break;
		case 'x':
		case 'X':
			u_num = va_arg(args, unsigned int);
			covert_to_hexadecimal(u_num, binary_str, specifier);
			itera(binary_str);
			break;
		case 'p':
			ptr = va_arg(args, void*);
			if (ptr == NULL) {
				itera(nil_str);
			} else {
					sprintf(num_str, "%p", ptr);
					itera(num_str);
				}
			break;
		case '%':
			add_to_buffer('%');
			printed_chars++;
			break;
		case 'l':
		case 'h':
			handle_length_height(specifier, args, next_char);
			break;
		default:
			add_to_buffer('%');
			add_to_buffer(specifier);
			printed_chars += 2;
			break;
	}
	return printed_chars;
}
