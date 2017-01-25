#include <stdio.h>

int htoi(char s[])
{
    int i, result;
    i = result = 0;

    while (s[i] != '\0') {
        if (s[i] == '0' && i == 0 && (s[1] == 'x' || s[1] == 'X')) {
            i++;
            continue;
        } else if (s[i] >= '0' && s[i] <= '9') {
            result = 16 * result + (s[i] - '0');
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            result = 16 * result + (10 + s[i] - 'a');
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            result = 16 * result + (10 + s[i] - 'A');
        }
        i++;
    }

    return result;
}

main() {
    printf("0x1ff: %d\n", htoi("0x1ff"));
    printf("0Xa6: %d\n", htoi("0Xa6"));
    printf("12b: %d\n", htoi("12b"));
    printf("adjlh: %d\n", htoi("adjlh"));
    printf("1234: %d\n", htoi("1234"));
    printf("09a: %d\n", htoi("09a"));
}
