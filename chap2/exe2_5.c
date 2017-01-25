#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}

main() {
    char a1[] = "hello world";
    char a2[] = "the c programming language";
    char a3[] = "K&R C Bible";

    printf("%d\n", any(a1, "eod"));
    printf("%d\n", any(a2, "1234 ue"));
    printf("%d\n", any(a3, "IcrE"));
}
