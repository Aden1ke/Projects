#include "main.h"

/* check for flags.
 * flag: character to check.
 * specifier: the specifier that comes after the flag
 * determines what to print 
 */
int handle_flag(char flag, char specifier, flags_t flags) {
	int printed_chars = 0, i;
	char *prefix;

	switch (flag) {
		case '+':
			if (specifier == 'd' || specifier == 'i' || specifier == 'f') {

				add_to_buffer('+');
				printed_chars ++;
				flags.plus = 1;
			}
			break;
		case ' ':
			if (specifier == 'd' || specifier == 'i' || specifier == 'f') {
				add_to_buffer(' ');
				printed_chars ++;
				flags.right_justify = 1;
			}
			break;
		case '#':
			flags.right_justify = 1;
			if (specifier == 'o') {
				add_to_buffer('0');
				printed_chars++;
			} else if (specifier == 'x') {
				prefix = "0x";
				for (i = 0; prefix[i] != '\0'; i++) {
					add_to_buffer(prefix[i]);
					printed_chars++;
				}
			} else if (specifier == 'X') {
				prefix = "0X";
				for (i = 0; prefix[i] != '\0'; i++) {
					add_to_buffer(prefix[i]);
					printed_chars++;
				}
			} else if (specifier == 'f' || specifier == 'g' || specifier == 'e') {
				printed_chars++;
			}
			break;
		case '-':
			flags.left_justify = 1;
			add_to_buffer('-');
			printed_chars ++;
			break;
		case '0':
			if (!flags.left_justify) {
				flags.zero_padding = 1;
			}
			printed_chars ++;
			break;
		default:
			break;
	}
	return printed_chars;
}
