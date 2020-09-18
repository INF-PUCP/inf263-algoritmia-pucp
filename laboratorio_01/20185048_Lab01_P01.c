#include <stdio.h>
#include <math.h>
/* Variable que representara infinito */
#define INF 1000000000.0

/* Estructura que representa un obrero con los datos que necesitamos */
struct Obrero {
  int rotura;
  int salario;
};

/* Proceso que guarda la representacion binaria de numero en arreglo */
void EnteroABinario(int* arreglo, int n, int numero) {
  for (int bit = 0; bit < n; bit++) {
    arreglo[n - 1 - bit] = numero & 1;
    numero >>= 1; 
  }
}

/* Funcion que retorna la cantidad de unos en el arreglo */
int ContarUnos(int* arreglo, int n) {
  int cantidad = 0;
  for (int i = 0; i < n; i++)
    if (arreglo[i]) cantidad++;
  return cantidad;
}

int main() {
  /* Declaro n, m, p y leo sus valores */
  int cantidadObreros, cantidadMinima;
  scanf("%d %d", &cantidadObreros, &cantidadMinima);
  int presupuesto;
  scanf("%d", &presupuesto);

  /* Creo un arreglo con la cantidad de obreros */
  struct Obrero obreros[cantidadObreros];
  for (int i = 0; i < cantidadObreros; i++)
    scanf("%d %d", &obreros[i].rotura, &obreros[i].salario);

  /* Primero quiero hallar el menor promedio que cumple con lo requerido*/
  int combinaciones = 1 << cantidadObreros;
  double menorPromedio = INF;  /* El menor promedio que iremos actualizando en cada estado, comienza en infinito porque todos son menores que el */
  int estadoActual[cantidadObreros];  /* Binario que representara a la combinacion actual */
  for (int i = 0; i < cantidadObreros; i++) estadoActual[i] = 0;
  
  /* Analizare las 2^n - 1 combinaciones porque quitare cuando no uso nadie */
  for (int estado = 1; estado < combinaciones; estado++) {
    /* Obtengo la representacion binaria del estado actual */
    EnteroABinario(estadoActual, cantidadObreros, estado);
    /* Obtengo la cantidad de obreros que trabajan en este estado */
    int cantidadActual = ContarUnos(estadoActual, cantidadObreros);
    /* Chequeo que trabajen al menos la cantidad de obreros solicitados */
    if (cantidadMinima <= cantidadActual && cantidadActual <= cantidadObreros) {
      /* Si cumplen con la cantidad requerida, analizo su suma de roturas para
       * poder hallar el promedio, y la suma de salarios para poder chequear que
       * cumplan con el presupuesto */
      int sumaSalarios, sumaRoturas;
      sumaSalarios = sumaRoturas = 0;
      /* A continuacion realizare la acumulacion */
      for (int bit = 0; bit < cantidadObreros; bit++) {
        /* Si el obrero actual esta siendo utilizado */
        if (estadoActual[bit]) {
          sumaSalarios += obreros[bit].salario;
          sumaRoturas += obreros[bit].rotura;
        }
      }
      if (sumaSalarios > presupuesto) continue;  /* La suma de salarios no puede exceder el presupuesto */
      /* Hallo el promedio actual para saber si es que es menor que el minimo hasta ahora */
      double promedioActual = (double) (sumaRoturas) / cantidadActual;
      if (promedioActual < menorPromedio) menorPromedio = promedioActual;
    }
  }

  int cantidadSoluciones = 0;
  /* Una vez encontrado el menor promedio, buscare todos los que cumplen con las condiciones y los imprimire en el reporte */
  for (int estado = 1; estado < combinaciones; estado++) {
    EnteroABinario(estadoActual, cantidadObreros, estado);
    int cantidadActual = ContarUnos(estadoActual, cantidadObreros);
    if (cantidadMinima <= cantidadActual && cantidadActual <= cantidadObreros) {
      int sumaSalarios, sumaRoturas;
      sumaSalarios = sumaRoturas = 0;
      for (int bit = 0; bit < cantidadObreros;bit++) {
        if (estadoActual[bit]) {
          sumaSalarios += obreros[bit].salario;
          sumaRoturas += obreros[bit].rotura;
        }
      }
      if (sumaSalarios > presupuesto) continue;
      double promedioActual = (double) (sumaRoturas) / cantidadActual;
      /* Si luego de verificar la validez, consigo igualar al menor promedio, eso significa que tengo una solucion */
      if (promedioActual == menorPromedio) {
        cantidadSoluciones++;
        printf("Solucion %d:\n", cantidadSoluciones);
        printf("Obreros:");
        for (int bit = 0; bit < cantidadObreros; bit++)
          if (estadoActual[bit]) printf(" %d", bit + 1);
        printf(". Costo de salarios de %d (miles de soles) y una rotura promedio de %f.\n",
            sumaSalarios, promedioActual);
        printf("\n");
      }
    }
  }
  printf("Cantidad de soluciones: %d.\n", cantidadSoluciones);
  return 0;
}
