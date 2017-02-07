#include <stdio.h>

void _strncpy(char *s, char *t, int n)
{
    while (n-- && (*s++ = *t++)) {
        ;
    }
    if (n <= 0) {
        *s = '\0';
    }
}

main()
{
    char s[10];

    _strncpy(s, "hello world", 3);
    printf("%s\n", s);

    _strncpy(s, "world", 5);
    printf("%s\n", s);

    _strncpy(s, "world", 6);
    printf("%s\n", s);

    _strncpy(s, "mei", 6);
    printf("%s\n", s);
}
