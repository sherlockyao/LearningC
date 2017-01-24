#include <stdio.h>

main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%4s %8s\n", "Fahr", "Celsius");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9) * (fahr - 32);
        printf("%4.0f %8.1f\n", fahr, celsius);
        fahr += step;
    }
}
