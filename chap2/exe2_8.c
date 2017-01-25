#include <stdio.h>

int rightrot(int x, int n) {
    int y = ~(~0 << n) & x;
    x = x >> n;
    long refer = y;
    if (y == 0) {
        return x;
    }
    while ((y << 1) == (refer << 1)) {
        y = y << 1;
        refer = refer << 1;
    }
    return x | y;
}

/** this solution is way smater than mine

unsigned rightrot(unsigned x, unsigned n)
{
    while (n > 0) {
        if ((x & 1) == 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = (x >> 1);
        n--;
    }
    return x;
}
**/

main() {
    printf("%d\n", rightrot(0x3, 2));
    printf("%d\n", rightrot(0x7, 2));
}
