#include <stdio.h>

#define MAX_LINE 1024
#define TAB '\t'
#define SPACE ' '
#define TAB_WIDTH 8

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

void put_tab(char s[], int len)
{
    int i, j;

    i = len;
    while (i >= 1) {
        if (s[i - 1] != SPACE) {
            break;
        }
        i--;
    }

    for (j = 0; j < i; j++) {
        putchar(s[j]);
    }
    if (i < len) {
        putchar(TAB);
    }
}

void entab(char s[])
{
    int i, j;
    char buffer[TAB_WIDTH];

    i = j = 0;
    while (s[i] != '\0') {
        if (j < TAB_WIDTH) {
            buffer[j] = s[i];
            j++;
        } else {
            put_tab(buffer, j);
            buffer[0] = s[i];
            j = 1;
        }
        if (s[i] == TAB) {
            put_tab(buffer, j);
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        put_tab(buffer, j);
    }
}

main() {
    char line[MAX_LINE];

    while (get_line(line, MAX_LINE) > 0) {
        entab(line);
    }

    return 0;
}
