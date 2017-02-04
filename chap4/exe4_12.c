#include <stdio.h>

int do_itoa(int n, char s[], int i)
{
    char c;

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }

    c = (n % 10) + '0';
    if (n >= 10) {
        i = do_itoa(n / 10, s, i);
    }
    s[i] = c;

    return i + 1;
}

void itoa(char s[], int n)
{
    int i = do_itoa(n, s, 0);
    s[i] = '\0';
}

main()
{
    char s[100];

    itoa(s, -120);
    printf("%s\n", s);
}
