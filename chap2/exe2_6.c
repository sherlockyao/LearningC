#include <stdio.h>

int setbits(int x, int p, int n, int y) {
    x = x & ~(~(~0 << n) << (p + 1 - n));
    y = (y & ~(~0 << n)) << (p + 1 - n);
    return x | y;
}

main() {
    printf("%d\n", setbits(0xff, 3, 2, 0));
    printf("%d\n", setbits(0xff, 6, 2, 02));
    printf("------- should be:\n");
    printf("%d\n", 0xf3);
    printf("%d\n", 0xdf);
}
