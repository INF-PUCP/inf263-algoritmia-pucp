#include <stdio.h>

// Estructura que representara cada articulo
struct Articulo {
	int peso;
	int ganancia;
};

void entero_a_binario(int estado_actual, int estado[], int cantidad_articulos) {
	for (int bit = 0; bit < cantidad_articulos; bit++) {
		estado[cantidad_articulos - 1 - bit] = estado_actual % 2;
		estado_actual /= 2;
	}
}

int main() {
	// Creo variables y leo los datos
	int cantidad_articulos, capacidad_maxima;
	scanf("%d %d", &cantidad_articulos, &capacidad_maxima);
	struct Articulo articulos[cantidad_articulos];
	for (int i = 0; i < cantidad_articulos; i++)
		scanf("%d %d", &(articulos[i].peso), &(articulos[i].ganancia));

	// Resolvemos el problema
	int estado[cantidad_articulos];
	int combinaciones = 1 << cantidad_articulos;
	int mejor_combinacion = 0;
	int mejor_ganancia = 0;
	int ganancia_actual, peso_actual;
	for (int estado_actual = 0; estado_actual < combinaciones; estado_actual++) {
		entero_a_binario(estado_actual, estado, cantidad_articulos);
		ganancia_actual = peso_actual = 0;
		for (int articulo = 0; articulo < cantidad_articulos; articulo++) {
			if (estado[articulo]) {
				ganancia_actual += articulos[articulo].ganancia;
				peso_actual += articulos[articulo].peso;
			}
		}
		// Si el peso actual entra en la mochila y es una mejor o igual ganancia
		if (peso_actual <= capacidad_maxima && ganancia_actual >= mejor_ganancia) {
			mejor_ganancia = ganancia_actual;
			mejor_combinacion = estado_actual;
		}
	}
	// Finalmente, imprimimos el resultado
	printf("Ganancia maxima: %d\n", mejor_ganancia);
	printf("Articulos utilizados:");
	entero_a_binario(mejor_combinacion, estado, cantidad_articulos);
	for (int articulo = 0; articulo < cantidad_articulos; articulo++)
		if (estado[articulo]) printf(" %d", articulo + 1);
	printf("\n");
	return 0;
}
