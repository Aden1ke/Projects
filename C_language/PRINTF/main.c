#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    _printf("Len:[%d]\nsarahis beautiful\n", len);
    printf("Len:[%d]\nsarah\n", len2);


    _printf("%b\n", 98);
    printf("%b\n", 98);
    _printf("%b\n", 150);
    printf("%b\n", 150);


    // Test case 1: + flag with integer
    _printf("Custom: [%+d]\n", 42);
    printf("Standard: [%+d]\n\n", 42);

    // Test case 2: space flag with integer
    _printf("Custom: [% d]\n", 42);
    printf("Standard: [% d]\n\n", 42);

    // Test case 3: # flag with octal
    _printf("Custom: [%#o]\n", 42);
    printf("Standard: [%#o]\n\n", 42);

    // Test case 4: # flag with hexadecimal lowercase
    _printf("Custom: [%#x]\n", 42);
    printf("Standard: [%#x]\n\n", 42);

    // Test case 5: # flag with hexadecimal uppercase
    _printf("Custom: [%#X]\n", 42);
    printf("Standard: [%#X]\n\n", 42);

    // Test case 6: 0 flag with integer
    _printf("Custom: [%05d]\n", 42);
    printf("Standard: [%05d]\n\n", 42);

    // Test case 7: - flag with integer (left-justified)
    _printf("Custom: [%-5d]\n", 42);
    printf("Standard: [%-5d]\n\n", 42);



/* test for length and height*/

    _printf("Custom: [%ld]\n", 1234567890L);
    printf("Standard: [%ld]\n", 1234567890L);

    _printf("Custom: [%hd]\n", (short)12345);
    printf("Standard: [%hd]\n", (short)12345);

    _printf("Custom: [%lu]\n", 1234567890UL);
    printf("Standard: [%lu]\n", 1234567890UL);

    _printf("Custom: [%ho]\n", (unsigned short)12345);
    printf("Standard: [%ho]\n", (unsigned short)12345);

    _printf("Custom: [%lx]\n", 0xabcdefL);
    printf("Standard: [%lx]\n", 0xabcdefL);

    return (0);
}
