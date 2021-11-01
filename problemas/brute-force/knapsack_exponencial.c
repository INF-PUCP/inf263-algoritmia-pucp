#include <stdio.h>
#include <math.h>

// Funcion que guarda en el arreglo estado[] el numero binario
// que representa al numero guardando sus bits en el arreglo
// O(cantidad_valores)
void entero_a_binario(int numero, int estado[], int cantidad_valores) {
	for (int bit = 0; bit < cantidad_valores; bit++) {
		estado[bit] = numero % 2;
		numero /= 2;
	}
}

// Queremos hallar la maxima suma 
// Complejidad en tiempo: O(n * 2^n)
int main() {
	// Iniciamos los valores y asignamos la capacidad maxima
	int valores[] = {1, 2, 4, 12, 1};
	int cantidad_valores = sizeof(valores) / sizeof(int);
	int capacidad_maxima = 15;

	// Comenzamos a analizar todos los posibles estados
	int estado[cantidad_valores];
	int cantidad_combinaciones = 1 << cantidad_valores; // 2^n
	int estado_actual, posicion, suma_actual;
	int mejor_suma, mejor_combinacion;
	mejor_suma = 0;
	mejor_combinacion = 0;
	for (estado_actual = 0; estado_actual < cantidad_combinaciones; estado_actual++) { // O(2^n)
		entero_a_binario(estado_actual, estado, cantidad_valores); // O(n)
		suma_actual = 0;
		// Analicemos si cada elemento ha sido utilizado o no
		for (int posicion = 0; posicion < cantidad_valores; posicion++) { // O(n)
			// Si el elemento ha sido utilizado, lo acumulamos
			if (estado[posicion]) {
				suma_actual += valores[posicion];
			}
		}
		if (suma_actual <= capacidad_maxima && mejor_suma <= suma_actual) {
			mejor_suma = suma_actual;
			mejor_combinacion = estado_actual;
		}
	}

	// Imprimamos una respuesta
	printf("Mejor suma: %d\n", mejor_suma);
	entero_a_binario(mejor_combinacion, estado, cantidad_valores);
	printf("Solucion optima:");
	for (int posicion = 0; posicion < cantidad_valores; posicion++) {
		if (estado[posicion]) printf(" %d", valores[posicion]);
	}
	printf("\n");
	return 0;
}
