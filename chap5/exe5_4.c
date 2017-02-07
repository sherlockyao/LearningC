#include <stdio.h>
#include <string.h>

int _strend(char *s, char *t)
{
    int offset = strlen(s) - strlen(t);
    if (offset < 0) {
        return 0;
    }
    s += offset;
    for ( ; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 1;
        }
    }
    return 0;
}

main()
{
    printf("%d\n", _strend("maycon", "maycon"));
    printf("%d\n", _strend("apple", "aapple"));
    printf("%d\n", _strend("hello world", "ord"));
    printf("%d\n", _strend("good world", "orld"));

    return 0;
}
