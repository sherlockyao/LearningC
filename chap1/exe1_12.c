#include <stdio.h>

#define IN  1
#define OUT 0


main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (IN == state) {
                putchar('\n');
            }
            state = OUT;
        } else {
            putchar(c);
            state = IN;
        }
    }
}
