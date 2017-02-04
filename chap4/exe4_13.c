#include <stdio.h>
#include <string.h>

void do_swap(char s[], int left, int right)
{
    if (left >= right) {
        return;
    }
    char c = s[right];
    s[right] = s[left];
    s[left] = c;
    do_swap(s, left + 1, right - 1);
}

void reverse(char s[])
{
    do_swap(s, 0, strlen(s) - 1);
}

main()
{
    char s[] = "hello world";
    reverse(s);
    printf("%s\n", s);
}
