#include <stdio.h>
#include <stdlib.h>

/* tail -n */
int main(int argc, char *argv[])
{
    int lineno = 10;
    int c, flag = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++(argv[0]))) {
            switch (c) {
            case 'n':
                flag = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                break;
            }
        }
    }

    if (flag && argc == 1) {
        lineno = atoi(*argv);
    }

    printf("tail number: %d\n", lineno);
}
