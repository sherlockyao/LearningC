#import <stdio.h>

void _strcat(char *s, char *t)
{
    while (*s) {
        s++;
    }
    while ((*s++ = *t++)) {
        ;
    }
}

main()
{
    char first[50] = "hello";
    char last[] = " world";
    _strcat (first, last);

    printf ("%s\n", first);
    return 0;
}
