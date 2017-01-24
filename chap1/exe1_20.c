#include <stdio.h>

#define MAX_LINE 1000

int get_line(char s[], int lim);
void detab(char s[], int spaceCount); // print detabed line

main() {
    int len; // current line length
    char line[MAX_LINE]; // current input line

    while ((len = get_line(line, MAX_LINE)) > 0) {
        detab(line, 2);
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

void detab(char s[], int spaceCount)
{
    int i, j;

    i = 0;
    while (s[i] != '\0') {
        if (s[i] == '\t') {
            for (j = 0; j < spaceCount; j++) {
                putchar(' ');
            }
        } else {
            putchar(s[i]);
        }
        i++;
    }
}
