#include "main.h"

void run_width_tests(void) {

    // Test case 1: Width greater than length, positive integer
    printf("Original: |%10d|\n", 123);
    _printf("Custom:   |%10d|\n", 123);

    // Test case 2: Width greater than length, negative integer
    printf("Original: |%10d|\n", -123);
    _printf("Custom:   |%10d|\n", -123);

    // Test case 3: Width less than length, integer
    printf("Original: |%3d|\n", 123456);
    _printf("Custom:   |%3d|\n", 123456);

    // Test case 4: Width with 0 flag, integer
    printf("Original: |%010d|\n", 123);
    _printf("Custom:   |%010d|\n", 123);

    // Test case 5: Width with - flag, integer
    printf("Original: |%-10d|\n", 123);
    _printf("Custom:   |%-10d|\n", 123);

    // Test case 6: Width with + flag, integer
    printf("Original: |%+10d|\n", 123);
    _printf("Custom:   |%+10d|\n", 123);

    // Test case 7: Width for strings
    printf("Original: |%10s|\n", "Hello");
    _printf("Custom:   |%10s|\n", "Hello");

    // Test case 8: Width for strings with left justification
    printf("Original: |%-10s|\n", "Hello");
    _printf("Custom:   |%-10s|\n", "Hello");

    // Test case 9: Width for a single character
    printf("Original: |%5c|\n", 'A');
    _printf("Custom:   |%5c|\n", 'A');

    // Test case 10: Width for hexadecimal number
    printf("Original: |%10x|\n", 255);
    _printf("Custom:   |%10x|\n", 255);

    // Test case 11: Width for pointer address
    printf("Original: |%20p|\n", (void *)0x7ffee1b7d9e0);
    _printf("Custom:   |%20p|\n", (void *)0x7ffee1b7d9e0);

    // Test case 12: Width for unsigned integer
    printf("Original: |%10u|\n", 3000000000U);
    _printf("Custom:   |%10u|\n", 3000000000U);
}
