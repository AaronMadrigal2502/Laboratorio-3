#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

int contar_unos_fila(int m[][SIZE], int fila);
int contar_unos_columna(int m[][SIZE], int col);
int es_identidad(int m[][SIZE]);
int tiene_fila_completa(int m[][SIZE]);
int tiene_columna_completa(int m[][SIZE]);
void imprimir_matriz(int m[][SIZE]);

int main(void) {

    int m[SIZE][SIZE] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1} 
    };

    int aleatoria[SIZE][SIZE];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {

	for (j = 0; j < SIZE; j++) {
	    aleatoria[i][j] = rand() %2;
	}
    }

    printf("Matriz ingresada:\n");
    imprimir_matriz(m);

    printf("Es matriz identidad: %s\n",
	   es_identidad(m) ? "si" : "no");

    printf("Tiene fila completa de unos: %s\n",
	   tiene_fila_completa(m) ? "si" : "no");

    printf("Tiene columna completa de unos: %s\n\n",
	   tiene_columna_completa(m) ? "si" : "no");

    printf("Matriz aleatoria:\n");
    imprimir_matriz(aleatoria);

    printf("Es matriz identidad: %s\n",
	   es_identidad(aleatoria) ? "si" : "no");

    printf("Tiene fila completa de unos: %s\n",
	   tiene_fila_completa(aleatoria) ? "si" : "no");

    printf("Tiene columna completa de unos: %s\n",
	   tiene_columna_completa(aleatoria) ? "si" : "no");

    return 0;
}

void imprimir_matriz(int m[][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {

	for (j = 0; j < SIZE; j++) {
	    printf("%d", m[i][j]);
	}
	printf("\n");
    }
}


int contar_unos_fila(int m[][SIZE], int fila) {
    int j;
    int contador = 0;

    for (j = 0; j < SIZE; j++) {

        if (m[fila][j] == 1) {
            contador++;
        }
    }

    return contador;
}

int contar_unos_columna(int m[][SIZE], int col) {
    int i;
    int contador = 0;

    for (i = 0; i < SIZE; i++) {
        if (m[i][col] == 1) {
            contador++;
        }
    }

    return contador;
}

int es_identidad(int m[][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            if (i == j) {

		if (m[i][j] != 1) {
		    return 0;
		}
            } else {

                if (m[i][j] != 0) {
                return 0;
		}
            }
        }
    }

    return 1;
}

int tiene_fila_completa(int m[][SIZE]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        if (contar_unos_fila(m, i) == SIZE) {
            return 1;
        }
    }

    return 0;
}

int tiene_columna_completa(int m[][SIZE]) {
    int j;

    for (j = 0; j < SIZE; j++) {

        if (contar_unos_columna(m, j) == SIZE) {
            return 1;
        }
    }

    return 0;
}
