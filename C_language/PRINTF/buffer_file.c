#include "main.h"


/* add charactets to buffer and print in once buffer shows new line or it is full
 */
void add_to_buffer(char character) {

	// Append color code to buffer based on character type
	if (isdigit(character))
		// Set color for numbers (e.g., yellow)
		snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%s", YELLOW);
	else if (isalpha(character))
		// Set color for alphabets (e.g., green)
		snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%s", GREEN);
	else if (character == '(' || character == ')' || character == '[' || character == ']' ||
			character == '{' || character == '}' || character == '\\' || character == '|') {
		// Set color for brackets, slashes (e.g., blue)
		snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%s", BLUE);
	} else if (character == '\'' || character == '\"' || character == '.' || character == '+'
			|| character == '-' || character == '%' || character == '=' ||
			character == ',' || character == '!' || character == '?'
			|| character == ';' || character == ':' || character == '*'
			|| character == '_') {
		// Set color for quotes (e.g., red)
		snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%s", MAGENTA);
	} else
		// Reset color (default color for other characters)
		snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%s", RESET);
	buffer_index += strlen(buffer + buffer_index); // Update buffer index after adding color code
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



// Function to get the current buffer content and its length
char* get_buffer(void) {
    return buffer; // Return pointer to the buffer
}


/* iterate through any string passed
 * string : string to iterate through
 * return: amount of characters
 */
int itera_length(char *string) {
        int j, printed_chars = 0;

        for (j = 0; string[j] != '\0'; j++) {
                printed_chars++;
        }
        return printed_chars;
}
