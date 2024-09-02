#include "main.h"


void handle_length_height(char specifier, va_list args, char next_char){
	long int long_num;
	unsigned long int ulong_num;
	short int short_num;
	unsigned short int ushort_num;
	char num_str[32], buffer[BUFFER_SIZE];

	if (specifier == 'l') {
		if (next_char == 'd' || next_char == 'i') {
			long_num = va_arg(args, long int);
			sprintf(num_str, "%ld", long_num);
		} else if (next_char == 'u') {
			ulong_num = va_arg(args, unsigned long int);
			sprintf(num_str, "%lu", ulong_num);
		} else if (next_char == 'o') {
			ulong_num = va_arg(args, unsigned long int);
			covert_to_base8(ulong_num, buffer);
			itera(buffer);
		} else if (next_char == 'x' || next_char == 'X') {
			ulong_num = va_arg(args, unsigned long int);
			covert_to_hexadecimal(ulong_num, buffer, next_char);
			itera(buffer);
		}
	}
	else if (specifier == 'h') {
		if (next_char == 'd' || next_char == 'i') {
			short_num = (short int)va_arg(args, int);
			sprintf(num_str, "%hd", short_num);
		}
		else if (next_char == 'u') {
			ushort_num = (unsigned short int)va_arg(args, int);
			sprintf(num_str, "%hu", ushort_num);
		}
		else if (next_char == 'o') {
			ushort_num = (unsigned short int)va_arg(args, int);
			covert_to_base8(ushort_num, buffer);
			itera(buffer);
		} else if (next_char == 'x' || next_char == 'X') {
			ushort_num = (unsigned short int)va_arg(args, int);
			covert_to_hexadecimal(ushort_num, buffer, next_char);
			itera(buffer);
		}
	}

                    // Now print the result
                    itera(num_str);
}
