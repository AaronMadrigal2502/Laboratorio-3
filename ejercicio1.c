#include <stdio.h>


int potencia(int base, int exp);

int main(void) {
    int base;
    int exp;
    int resultado;

    do {
        printf("Ingrese la base (distinta de cero): ");
        scanf("%d", &base);
    } while (base == 0);

    do {
        printf("Ingrese el exponente (no negativo): ");
        scanf("%d", &exp);
    } while (exp < 0);

    resultado = potencia(base, exp);

    printf("%d^%d = %d\n", base, exp, resultado);

    return 0;
}

int potencia(int base, int exp) {
    int resultado = 1;

    while (exp > 0) {
        resultado = resultado * base;
        exp = exp - 1;
    }

    return resultado;
}
