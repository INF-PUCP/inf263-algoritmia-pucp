#include <assert.h>
#include <stdio.h>

const char ASTERISCO = '*';
const char ESPACIO = ' ';

int ContarBits(int n) {
    int bits = 0;
    while (n > 0) {
        if (n & 1) bits++;
        n >>= 1;
    }
    return bits;
}

void Imprimir(char caracter, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("%c ", caracter);
    }
}

void ImprimirFila(int asteriscos, int columna) {
    Imprimir(ESPACIO, columna);
    Imprimir(ASTERISCO, asteriscos);
    printf("\n");
}

void GenerarPatron(int asteriscos, int columna) {
    if (asteriscos == 1) {
        ImprimirFila(asteriscos, columna);
        return;
    }
    int mitad_asteriscos = asteriscos / 2;
    GenerarPatron(mitad_asteriscos, columna);
    ImprimirFila(asteriscos, columna);
    GenerarPatron(mitad_asteriscos, columna + mitad_asteriscos);
}

int main(void) {
    int n;
    scanf("%d", &n);
    // Verificamos que n sea una potencia de 2
    assert(ContarBits(n) == 1);
    GenerarPatron(n, 0);
    return 0;
}