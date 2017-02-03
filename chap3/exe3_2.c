#include <stdio.h>

#define MAX_LINE 1024

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

void escape(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (t[i] != '\0') {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        i++;
    }
    s[j] = '\0';
}

main() {
    char line[MAX_LINE];
    char s[MAX_LINE];

    while (get_line(line, MAX_LINE) > 0) {
        escape(s, line);
        printf("%s\n", s);
    }

    return 0;
}
