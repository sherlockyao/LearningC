#include <stdio.h>

#define MAX_LINE 1000

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1; i++) {
        if ((c = getchar()) == EOF) {
            break;
        }
        if (c == '\n') {
            break;
        }
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

main() {
    int len; // current line length
    char line[MAX_LINE]; // current input line

    while ((len = get_line(line, MAX_LINE)) > 0) {
        printf("%s", line);
    }

    return 0;
}
