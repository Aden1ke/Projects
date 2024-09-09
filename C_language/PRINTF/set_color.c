#include "main.h"


void textcolor(const char *color) {
    write(1, color, strlen(color));
}
