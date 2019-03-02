#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    float celsius, fahr;

    fahr = LOWER;

    printf("\nFahrenheit-Celsius table:\n");

    while (fahr <= UPPER) {
        celsius = (5.0/9.0)*(fahr - 32);
        printf("%4.0f %6.1f\n",fahr, celsius);
        fahr = fahr + STEP;
    }

    celsius = LOWER;

    printf("\nCelsius-Fahrenheit table:\n");

    while (celsius <= UPPER) {
        fahr = ((9.0/5.0)*celsius) + 32;
        printf("%4.0f %6.1f\n",celsius, fahr);
        celsius = celsius + STEP;
    }

    printf("\nFahrenheit-Celsius table reversed:\n");

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - 20)
        printf("%4.0f %6.1f\n",fahr, (5.0/9.0)*(fahr - 32));

    printf("\nCelsius-Fahrenheit table reversed:\n");

    for (celsius = UPPER; celsius >= LOWER; celsius = celsius - 20)
        printf("%4.0f %6.1f\n",celsius, ((9.0/5.0)*celsius) + 32);

    return 0;
}