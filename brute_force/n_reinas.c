#include <stdio.h>
#include <stdlib.h>
#define N 30

int n = 8; // numero de reinas en el tablero de n x n
int cantidad_soluciones = 0;
int tablero[N][N], fila_reina[N], fila_usada[N];

void imprimir_tablero() {
	for (int fila = 0; fila < n; fila++)
		for (int columna = 0; columna < n; columna++)
			tablero[fila][columna] = 0;
	for (int columna = 0; columna < n; columna++) tablero[fila_reina[columna]][columna] = 1;
	printf("Solucion %d:\n", cantidad_soluciones);
	for (int fila = 0; fila < n; fila++) {
		for (int columna = 0; columna < n; columna++) {
			if (columna > 0) printf(" ");
			printf("%d", tablero[fila][columna]);
		}
		printf("\n");
	}
	printf("\n");
}

int check(int columna_actual) {
	for (int columna = columna_actual - 1; columna >= 0; columna--) {
		int dx = abs(columna_actual - columna);
		int dy = abs(fila_reina[columna_actual] - fila_reina[columna]);
		if (dx == dy) return 0; // Si existen anteriores en una misma diagonal
	}
	return 1;
}

void brutar(int columna_actual) {
	if (columna_actual == n) {
		cantidad_soluciones++;
		imprimir_tablero();
		return;
	}
	for (int fila = 0; fila < n; fila++) {
		if (!fila_usada[fila]) {
			fila_reina[columna_actual] = fila;
			fila_usada[fila] = 1;
			if (check(columna_actual)) brutar(columna_actual + 1);
			fila_usada[fila] = 0;
		}
	}
}

int main() {
	brutar(0);
	printf("Cantidad de soluciones: %d\n", cantidad_soluciones);
	return 0;
}
