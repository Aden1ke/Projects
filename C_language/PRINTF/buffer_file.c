#include "main.h"


/* add charactets to buffer and print in once buffer shows new line or it is full
 */
void add_to_buffer(char character) {
	buffer[buffer_index++] = character;

	if (character == '\n' || buffer_index == BUFFER_SIZE)
		print_buffer();
}

/*print buffer function using write) */
void print_buffer(void) {
	write(1, buffer, buffer_index);
	buffer_index = 0;
}


/* iterate through any string passed
 * string : string to iterate through
 * return: amount of characters
 */
int itera(char *string) {
	int j, printed_chars = 0;

	for (j = 0; string[j] != '\0'; j++) {
		add_to_buffer(string[j]);
		printed_chars++;
	}
	return printed_chars;
}
