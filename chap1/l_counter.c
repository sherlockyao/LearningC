#include <stdio.h>

main() {
    int c;
    long lineCount, blankCount, tabCount;

    lineCount = blankCount = tabCount = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            lineCount++;
        } else if (c == '\t') {
            tabCount++;
        } else if (c == ' ') {
            blankCount++;
        }
    }

    printf("newline: %ld\nblank: %ld\ntab: %ld\n", lineCount, blankCount, tabCount);
}
