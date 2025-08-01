#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != NULL) {
        putchar(c);
    }
    return 0;
}
