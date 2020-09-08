#include <stdio.h>
#define MAX_PROYECTOS 12
#define MAX_PREDECESORES 3

struct Proyecto {
	int costo;
	int ganancia;
	int cantidad_predecesores;
	int indice;
};

// predecesores[i][j] : j-esimo predecesor del i-esimo proyecto
int predecesores[MAX_PROYECTOS][MAX_PREDECESORES];

// Funcion que guarda la representacion binaria de estado actual en estado
void entero_a_binario(int estado_actual, int estado[], int cantidad_proyectos) {
	for (int bit = 0; bit < cantidad_proyectos; bit++) {
		estado[cantidad_proyectos - 1 - bit] = estado_actual % 2;
		estado_actual /= 2;
	}
}

// Funcion que calcula la cantidad de bits 1 en el numero
int cantidad_unos(int numero) {
	int cantidad = 0;
	while (numero > 0) {
		if (numero % 2) cantidad++;
		numero /= 2;
	}
	return cantidad;
}

void ordenar_descendiente(struct Proyecto proyectos[], int cantidad_proyectos) {
	for (int i = 0; i < cantidad_proyectos - 1; i++) {
		int mayor = i;
		for (int j = i + 1; j < cantidad_proyectos; j++) {
			if (proyectos[j].ganancia > proyectos[mayor].ganancia) mayor = j;
		}
		if (mayor != i) {
			struct Proyecto auxiliar;
			auxiliar = proyectos[i];
			proyectos[i] = proyectos[mayor];
			proyectos[mayor] = auxiliar;
		}
	}
}

int main() {
	int cantidad_proyectos, presupuesto;
	scanf("%d %d", &cantidad_proyectos, &presupuesto);
	struct Proyecto proyectos[cantidad_proyectos];
	// Leo los datos de cada proyecto
	for (int proyecto = 0; proyecto < cantidad_proyectos; proyecto++) {
		scanf("%d %d %d", &(proyectos[proyecto].costo), &(proyectos[proyecto].ganancia), &(proyectos[proyecto].cantidad_predecesores));
		proyectos[proyecto].indice = proyecto;
		// Para cada proyecto, guardo sus predecesores
		for (int predecesor = 0; predecesor < proyectos[proyecto].cantidad_predecesores; predecesor++) {
			scanf("%d", &(predecesores[proyecto][predecesor]));
			predecesores[proyecto][predecesor]--;
		}
	}

	// Resuelvo el problema, quiero obtener la mayor ganancia al menor costo posible
	int estado[cantidad_proyectos];
	for (int i = 0; i < cantidad_proyectos; i++) estado[i] = 0;
	int costo_actual, ganancia_actual, mejor_combinacion, mayor_ganancia, menor_costo;
	mejor_combinacion = menor_costo = mayor_ganancia = 0;
	int combinaciones = 1 << cantidad_proyectos;
	
	// Para cada combinacion posible, analizare su costo, su ganancia y su validez
	for (int estado_actual = 0; estado_actual < combinaciones; estado_actual++) {
		costo_actual = ganancia_actual = 0;
		entero_a_binario(estado_actual, estado, cantidad_proyectos);		
		
		// Chequeare que la combinacion actual sea valida
		// Para eso cada elemento utilizado, sus predecesores deben aparecer en la combinacion
		int valido = 1;
		for (int proyecto = 0; proyecto < cantidad_proyectos; proyecto++) {
			if (estado[proyecto]) {
				costo_actual += proyectos[proyecto].costo;
				ganancia_actual += proyectos[proyecto].ganancia;
				for (int predecesor = 0; predecesor < proyectos[proyecto].cantidad_predecesores; predecesor++) {
					// Si hemos utilizado aquel proyecto del cual este depende, entonces no pasa nada
					if (estado[predecesores[proyecto][predecesor]]) continue;
					// En otro caso, la combinacion es invalida
					valido = 0;
					break;
				}
			}
			if (!valido) break;
		}

		// Si la solucion es valida, recien analizo si es que es una optima hasta ahora
		if (valido) {
			if (costo_actual <= presupuesto && ganancia_actual >= mayor_ganancia) {
				if (ganancia_actual > mayor_ganancia || ganancia_actual == mayor_ganancia && costo_actual < menor_costo) {
					mejor_combinacion = estado_actual;
					mayor_ganancia = ganancia_actual;
					menor_costo = costo_actual;
				}
			}
		}
	}

	// Finalmente imprimimos la respuesta como nos la solicitan
	printf("Mayor ganancia: %d millones de $\n", mayor_ganancia);
	// Hallo cuantos proyectos elegimos y creo un arreglo de estos
	entero_a_binario(mejor_combinacion, estado, cantidad_proyectos);
	int cantidad_elegidos = cantidad_unos(mejor_combinacion);
	struct Proyecto elegidos[cantidad_elegidos];
	int pos_actual = 0;
	for (int pos = 0; pos < cantidad_proyectos; pos++) {
		if (estado[pos]) {
			elegidos[pos_actual] = proyectos[pos];
			pos_actual++;
		}
	}

	// Ordeno los proyectos elegidos descendente a la ganancia
	ordenar_descendiente(elegidos, cantidad_elegidos);
	printf("Proyectos elegidos:");
	for (int pos = 0; pos < cantidad_elegidos; pos++) printf(" %d", elegidos[pos].indice + 1);
	printf("\n");
	return 0;
}
