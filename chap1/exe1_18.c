#include <stdio.h>

#define MAX_LINE 1000

int get_line(char s[], int lim);
int trim_line(char s[], int len);

main() {
    int len; // current line length
    char line[MAX_LINE]; // current input line

    while ((len = get_line(line, MAX_LINE)) > 0) {
        len = trim_line(line, len);
        if (len > 1) {
            printf("%s\n", line);
        } else {
            printf("empty line\n");
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

int trim_line(char s[], int len)
{
    int i;
    for (i = len - 2; i >= 0; i--) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            break;
        }
    }
    if (s[len - 1] == '\n' && i >= 0) {
        s[i + 1] = '\n';
        s[i + 2] = '\0';
        len = i + 2;
    } else {
        s[i + 1] = '\0';
        len = i + 1;
    }

    return len;
}
