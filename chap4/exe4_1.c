#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int str_index(char source[], char searchfor[]);

char patten[] = "ould";

main() {
    char line[MAXLINE];
    int found = 0;

    while (get_line(line, MAXLINE) > 0) {
        if (str_index(line, patten) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

int get_line(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* return the position of the rightmost occurrence of t in s */
int str_index(char s[], char t[])
{
    int i, j, k;
    for (i = (strlen(s) - 1); i >= 0; i--) {
        for (j = i, k = strlen(t) - 1; s[j] == t[k] && k >= 0; j--, k--) {
        }
        if (k < 0) {
            return j + 1;
        }
    }
    return -1;
}
