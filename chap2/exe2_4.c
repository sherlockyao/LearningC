#include <stdio.h>

void squeeze(char s1[], char s2[])
{
    int i, j, k, match;

    i = j = 0;

    while (s1[i] != '\0') {
        match = 0;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = 1;
                break;
            }
        }
        if (!match) {
            s1[j++] = s1[i];
        }
        i++;
    }
    s1[j] = '\0';
}

main() {
    char a1[] = "hello world";
    char a2[] = "the c programming language";
    char a3[] = "K&R C Bible";

    squeeze(a1, "eod");
    squeeze(a2, "1234 ue");
    squeeze(a3, "ccRE");

    printf("%s\n", a1);
    printf("%s\n", a2);
    printf("%s\n", a3);
}
