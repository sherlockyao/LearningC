#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum ctype { NONE, DIGIT, LOWER, UPPER };

int get_type(char c) {
    if (isdigit(c)) {
        return DIGIT;
    } else if (islower(c)) {
        return LOWER;
    } else if (isupper(c)) {
        return UPPER;
    } else {
        return NONE;
    }
}

void expand(char s1[], char s2[]) // assume s2 has enough space for expanding
{
    char c;
    int i, j, type;

    i = j = 0;
    while (s1[i] != '\0') {
        s2[j++] = s1[i];

        type = get_type(s1[i]);
        if (DIGIT == type || LOWER == type || UPPER == type) {
            while (s1[i + 1] == '-' && get_type(s1[i + 2]) == type && (s1[i] < s1[i + 2])) {
                for (c = s1[i] + 1; c <= s1[i + 2]; c++) {
                    s2[j++] = c;
                }
                i += 2;
            }
        }

        i++;
    }
    s2[j] = '\0';
}

main() {
    char s[1024];

    expand("a-z", s);
    printf("%s\n", s);

    expand("3-6adfA-B", s);
    printf("%s\n", s);

    expand("-a-z8-7b-g-a", s);
    printf("%s\n", s);

    expand("a-b-d088a-9", s);
    printf("%s\n", s);
}
