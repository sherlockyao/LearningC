#include <stdio.h>

#define MAX_LINE 1024
#define LINE_LIM 6
#define SPACE ' '

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void fold_line(char s[], int lim)
{
    int i, j, count, offset, spaceOffset;

    i = count = offset = 0;
    spaceOffset = -1;

    while (s[i] != '\0') {
        count++;

        if (s[i] == SPACE) {
            spaceOffset = i;
            i++;
            continue;
        }

        if (count > lim) {
            if (spaceOffset == -1) { // long word, no space before
                i++;
                continue;
            } else {
                for (j = offset; j <= spaceOffset; j++) {
                    putchar(s[j]);
                }

                if (spaceOffset == (i - 1)) { // trim trailing spaces
                    offset = i;
                    spaceOffset = -1;
                    count = 0;
                } else { // stop before current word
                    offset = i = (spaceOffset + 1);
                    spaceOffset = -1;
                    count = 0;
                }

                putchar('\n');
            }
        } else {
            i++;
        }
    }

    // print the rest of the line
    i = offset;
    while (s[i] != '\0') {
        putchar(s[i]);
        i++;
    }
}

main() {
    char line[MAX_LINE];

    while (get_line(line, MAX_LINE) > 0) {
        fold_line(line, LINE_LIM);
    }

    return 0;
}
