Custom _printf Function

Overview

This project implements a custom version of the printf function in C, which formats and prints data to the standard output. The custom _printf function supports various specifiers and flags similar to the standard printf, and introduces color formatting for specific types of characters.

Features

Supports standard format specifiers (%d, %i, %u, %x, %o, %s, %c, %p, etc.)
Custom flag handling (+, -, 0, space, #)
Handles width and precision for specifiers
Color-coded output for better readability:
Numbers: Yellow
Alphabets: Green
Brackets, Slashes: Blue
Special characters (e.g., quotes, punctuation): Magenta
Reset color for other characters
How to Compile and Run
Compilation
To compile the code, you can use the following command:


"   gcc -Wall -Werror -Wextra -pedantic *.c -o printf  "
This will generate an executable named printf.

Running the Program
Once compiled, you can test the program by calling _printf like so:

"  ./printf  "

The program will format and print data based on the inputs and provide color-coded output in the terminal (ensure your terminal supports ANSI colors).

Supported Format Specifiers
This custom _printf function currently supports the following format specifiers:

%c : Print a single character
%s : Print a string
%d or %i : Print a signed integer
%u : Print an unsigned integer
%o : Print an unsigned integer in octal (base 8)
%x or %X : Print an unsigned integer in hexadecimal (base 16), lowercase (x) or uppercase (X)
%p : Print a pointer address
%b : Print an integer in binary format
Flags Supported:
+: Print a plus sign before positive numbers.
(space): Adds a space before positive numbers.
#: Alternate form for o, x, X specifiers.
0: Zero-padding for numeric specifiers.
-: Left justify the output.
Width and Precision:
The function handles width and precision modifiers for the following specifiers, adding flexibility in formatting output.

Color Formatting
The output from the _printf function is color-coded based on the type of character being printed:

Yellow: Numbers (e.g., digits, integers)
Green: Alphabetic characters (both uppercase and lowercase letters)
Blue: Brackets ([, ], {, }, (, )), slashes (/, \), and pipes (|)
Magenta: Special symbols (', ", +, -, *, %, =, ., !, ?, etc.)
Default: All other characters revert to the terminal’s default color.
How to Test the Code
You can test the code by compiling and running it with different format specifiers. Here's an example of how to test the different functionalities:
EAMPLE:
_printf("Hello %s!\n", "world");
_printf("Number: %d, Hex: %x, Octal: %o\n", 42, 42, 42);
_printf("Character: %c\n", 'A');
_printf("Pointer: %p\n", &main);
You should see the output formatted with the appropriate colors in a terminal that supports ANSI escape codes.


This custom _printf function serves as a versatile replacement for the standard printf, with added features like color-coded output for better readability and support for a range of format specifiers, flags, width, and precision handling.
