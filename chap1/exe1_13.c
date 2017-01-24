#include <stdio.h>

#define IN  1
#define OUT 2
#define MAX_WORD 15
#define MAX_HIST 15

main() {
    int c, i, j, state, len;
    int wordLength[MAX_WORD];

    len = 0;
    state = OUT;
    for (i = 0; i < MAX_WORD; i++) {
        wordLength[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                if (len < MAX_WORD) {
                    wordLength[len]++;
                }
                len = 0;
            }
            state = OUT;
        } else {
            len++;
            state = IN;
        }
    }

    int maxLength;
    maxLength = 0;
    for (i = 1; i < MAX_WORD; i++)
    {
        if (wordLength[i] > maxLength) {
            maxLength = wordLength[i];
        }
    }

    for (i = MAX_HIST; i > 0; i--) {
        for (j = 1; j < MAX_WORD; j++) {
            if (0 < wordLength[j]) {
                len = wordLength[j] * MAX_HIST / maxLength;
                if (len <= 0) {
                    len = 1;
                }
            } else {
                len = 0;
            }
            if (len >= i) {
                printf("%3s", "-");
            } else {
                printf("%3s", " ");
            }
        }
        putchar('\n');
    }

    for (j = 1; j < MAX_WORD; j++) {
        printf("%3s", "***");
    }
    putchar('\n');

    for (j = 1; j < MAX_WORD; j++) {
        printf("%3d", j);
    }
    putchar('\n');
}
