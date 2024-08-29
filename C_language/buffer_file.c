#include "main.h"

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
