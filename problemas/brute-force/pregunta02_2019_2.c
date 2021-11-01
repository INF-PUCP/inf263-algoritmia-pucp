#include <stdio.h>

struct Entrega {
	int codigo;
	int prioridad;
	int inicio;
	int duracion;
};

void entero_a_binario(int numero, int binario[], int cantidad) {
	for (int i = 0; i < cantidad; i++) {
		binario[cantidad - 1 - i] = numero % 2;
		numero /= 2;
	}
}

int cantidad_unos(int numero) {
	int cantidad = 0;
	while (numero > 0) {
		if (numero % 2) cantidad++;
		numero /= 2;
	}
	return cantidad;
}

void ordenar_cronologico(struct Entrega entregas[], int cantidad_entregas) {
	for (int i = 0; i < cantidad_entregas - 1; i++) {
		int minimo = i;
		for (int j = i + 1; j < cantidad_entregas; j++)
			if (entregas[j].inicio < entregas[minimo].inicio) minimo = j;
		if (minimo != i) {
			struct Entrega auxiliar = entregas[i];
			entregas[i] = entregas[minimo];
			entregas[minimo] = auxiliar;
		}
	}
}

void ordenar_solucion(struct Entrega entregas[], int cantidad_entregas) {
	for (int i = 0; i < cantidad_entregas - 1; i++) {
		int minimo = i;
		for (int j = i + 1; j < cantidad_entregas; j++)
			if (entregas[j].prioridad < entregas[minimo].prioridad || entregas[j].prioridad == entregas[minimo].prioridad && entregas[j].codigo < entregas[minimo].codigo) minimo = j;
		if (minimo != i) {
			struct Entrega auxiliar = entregas[i];
			entregas[i] = entregas[minimo];
			entregas[minimo] = auxiliar;
		}
	}
}

int main() {
	int cantidad_entregas, cantidad_prioridades;
	scanf("%d %d", &cantidad_entregas, &cantidad_prioridades);
	// Creo un arreglo con la cantidad minima por prioridad
	int minimo_prioridad[cantidad_prioridades];
	for (int prioridad = 0; prioridad < cantidad_prioridades; prioridad++) scanf("%d", &minimo_prioridad[prioridad]);
	// Leo los datos de cada entrega
	struct Entrega entregas[cantidad_entregas];
	for (int pos = 0; pos < cantidad_entregas; pos++) scanf("%d %d %d %d", &entregas[pos].codigo, &entregas[pos].prioridad, &entregas[pos].inicio, &entregas[pos].duracion);
	// Para cada combinacion posible, analizo si es valida, es decir, si cumple con las cantidades minimas y si los horarios de reparto no se sobrelapan
	int combinaciones = 1 << cantidad_entregas;
	int estado[cantidad_entregas];
	int cantidad_soluciones = 0;
	for (int i = 0; i < cantidad_entregas; i++) estado[i] = 0;
	for (int estado_actual = 0; estado_actual < combinaciones; estado_actual++) {
		entero_a_binario(estado_actual, estado, cantidad_entregas);
		// Creo un arreglo con las entregas que manipulare en este estado
		int cantidad_lista = cantidad_unos(estado_actual);
		struct Entrega lista[cantidad_lista];
		int pos_actual = 0;
		for (int bit = 0; bit < cantidad_entregas; bit++) {
			if (estado[bit]) {
				lista[pos_actual] = entregas[bit];
				pos_actual++;
			}
		}
		int valido = 1;
		// Primero chequeare que cumpla con las cantidads minimas establecidas por cada prioridad
		int prioridades[cantidad_prioridades];
		for (int i = 0; i < cantidad_prioridades; i++) prioridades[i] = 0;
		for (int pos = 0; pos < cantidad_lista; pos++) prioridades[lista[pos].prioridad - 1]++;
		for (int i = 0; i < cantidad_prioridades; i++) {
			if (prioridades[i] >= minimo_prioridad[i]) continue;
			valido = 0;
			break;
		}
		if (!valido) continue;
		// Luego chequeare que cumpla con horarios que no se sobrelapen
		ordenar_cronologico(lista, cantidad_lista);
		for (int actual = 1; actual < cantidad_lista; actual++) {
			if (lista[actual - 1].inicio + lista[actual - 1].duracion <= lista[actual].inicio) continue;
			valido = 0;
			break;
		}
		if (!valido) continue;
		// Si cumplio ambas cosas, lo ordeno por prioridad, y de haber empate lo ordeno por codigo
		ordenar_solucion(lista, cantidad_lista);
		// Imprimo la solucion y actualizo mi contador
		cantidad_soluciones++;
		printf("Solucion %d:\n", cantidad_soluciones);
		for (int pos = 0; pos < cantidad_lista; pos++) printf("%d %d\n", lista[pos].codigo, lista[pos].prioridad);
		printf("\n");
	}
	printf("Cantidad de soluciones: %d\n", cantidad_soluciones);
	return 0;
}
