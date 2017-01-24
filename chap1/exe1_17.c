#include <stdio.h>

#define LIMIT 45
#define MAX_LINE 1000

int get_line(char s[], int lim);

main() {
    int len; // current line length
    char line[MAX_LINE]; // current input line

    while ((len = get_line(line, MAX_LINE)) > 0) {
        if (len > LIMIT) {
            printf("%s\n", line);
        }
    }

    return 0;
}

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
