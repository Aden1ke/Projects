#include "main.h"



/* convert a number to base 2.
 * num: is the interger converted.
 * binary_str: is the string to add the numbers.
 */
void covert_to_binary(int num, char *binary_str) {
	int binary[BUFFER_SIZE];
	int i = 0;
	int j;

	//if number = 0, return 0 and null
	if (num == 0) {
		binary_str[i++] = '0';
		binary_str[i] = '\0';
		return;
	}
	// convert to binary
	while (num > 0) {
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (j = 0; j < i; j++) {
		binary_str[j] = binary[i - j - 1] + '0';
	}
	binary_str[j] = '\0';
}


/* convert a number to base 8(octal).
 * num: is the interger converted.
 * binary_str: is the string to add the numbers.
 */
void covert_to_base8(unsigned int num, char *binary_str) {
	int binary[BUFFER_SIZE];
	int i = 0;
	int j;

	//if number = 0, return 0 and null
	if (num == 0) {
		binary_str[i++] = '0';
		binary_str[i] = '\0';
		return;
	}
	// convert to octal
	while (num > 0) {
		binary[i] = num % 8;
		num = num / 8;
		i++;
	}
	for (j = 0; j < i; j++) {
		binary_str[j] = binary[i - j - 1] + '0';
	}
	binary_str[j] = '\0';
}



/* convert a number to base Hexadecimal.
 * num: is the interger converted.
 * hex_str: is the string to add the numbers.
 */
void covert_to_hexadecimal(unsigned int num, char *hex_str, char specifier) {
	int i = 0, index, digit, j;
	char lowercase_chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char uppercase_chars[] = {'A', 'B', 'C', 'D', 'E', 'F'};

	//if number = 0, return 0 and null
	if (num == 0) {
		hex_str[i++] = '0';
		hex_str[i] = '\0';
		return;
	}
	// convert to hexadecimal
	while (num > 0) {
		digit = num % 16;
		if (digit < 10 )
			hex_str[i++] = '0' + digit;
		else {
			index = digit - 10;
			if (specifier == 'x') 
				hex_str[i++] = lowercase_chars[index];
			else if (specifier == 'X')
				hex_str[i++] = uppercase_chars[index];

		}
		num = num / 16;
	}
	// reverse string
	hex_str[i] = '\0';
	for (j = 0; j < i / 2; j++) {
		char temp = hex_str[j];
		hex_str[j] = hex_str[i - j - 1];
		hex_str[i - j - 1] = temp;
	}
}
