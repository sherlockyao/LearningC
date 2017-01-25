#include <stdio.h>

int invert(int x, int p, int n)
{
    int y = (~x & (~(~0 << n) << (p + 1 - n)));
    x = x & ~(~(~0 << n) << (p + 1 - n));

    return x | y;
}

main() {
    printf("%d\n", invert(0xff, 5, 4));
    printf("%d\n", invert(0x99, 6, 6));
    printf("------- should be:\n");
    printf("%d\n", 0xc3);
    printf("%d\n", 0xe7);
}
