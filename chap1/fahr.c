#include <stdio.h>

float fahrFromCelsius(float celsius);

main () {
    printf("%8s %5s\n", "Celsius", "Fahr");

    float celsius;
    for (celsius = 100; celsius >= 0; celsius -= 10) {
        printf("%8.0f %5.1f\n", celsius, fahrFromCelsius(celsius));
    }
}

float fahrFromCelsius(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}
