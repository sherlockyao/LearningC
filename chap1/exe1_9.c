#include <stdio.h>

main() {
    int c, blankCount;

    blankCount = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            blankCount++;
            if (1 < blankCount) {
                continue;
            }
        } else {
            blankCount = 0;
        }
        putchar(c);
    }
}
