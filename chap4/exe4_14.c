#include <stdio.h>

#define swap(T, X, Y) { \
    T temp = X; \
    X = Y; \
    Y = temp; \
} \

main()
{
    int x = 123;
    int y = 234;
    swap(int, x, y);

    printf("x: %d\ty: %d\n", x, y);
}
