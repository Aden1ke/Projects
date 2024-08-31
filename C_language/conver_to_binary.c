#include "main.h"

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
