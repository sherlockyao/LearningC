#include <stdio.h>

#define MAX_HIST 15

main() {
    int c, i, j, count;
    int charCount[26];

    count = 0;
    for (i = 0; i < 26; i++) {
        charCount[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 'a' || c <= 'z') {
            charCount[c - 'a']++;
        } else if (c >= 'A' || c <= 'Z') {
            charCount[c - 'A']++;
        }
    }

    int maxCount;
    maxCount = 0;
    for (i = 0; i < 26; i++)
    {
        if (charCount[i] > maxCount) {
            maxCount = charCount[i];
        }
    }

    for (i = MAX_HIST; i > 0; i--) {
        for (j = 0; j < 26; j++) {
            if (0 < charCount[j]) {
                count = charCount[j] * MAX_HIST / maxCount;
                if (count <= 0) {
                    count = 1;
                }
            } else {
                count = 0;
            }
            if (count >= i) {
                printf("%3s", "-");
            } else {
                printf("%3s", " ");
            }
        }
        putchar('\n');
    }

    for (j = 0; j < 26; j++) {
        printf("%3s", "***");
    }
    putchar('\n');

    for (j = 0; j < 26; j++) {
        printf("%3c", 'a' + j);
    }
    putchar('\n');
}
