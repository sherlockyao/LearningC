#include <stdio.h>

#define MAX_LINE 1000

int get_line(char s[], int lim);
void reverse_line(char s[], int len);

main() {
    int len; // current line length
    char line[MAX_LINE]; // current input line

    while ((len = get_line(line, MAX_LINE)) > 0) {
        reverse_line(line, len);
        printf("%s", line);
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

void reverse_line(char s[], int len)
{
    char r[len];

    int i, j;
    for (i = j = 0; i < len; i++) {
        if (s[len - i - 1] != '\n') {
            r[j] = s[len - i - 1];
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        s[i] = r[i];
    }
}
