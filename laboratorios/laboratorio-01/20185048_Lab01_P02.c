#include <stdio.h>
#include <math.h>

/* Estructura que representa a una maquina con los datos que necesitamos*/
struct Maquina {
  int costo;
  int ganancia;
  int tipo;
};

/* Proceso que guarda la representacion binaria de un numero en arreglo */
void EnteroABinario(int* arreglo, int n, int numero) {
  for (int bit = 0; bit < n; bit++) {
    arreglo[n - 1 - bit] = numero & 1;
    numero >>= 1;
  }
}

int main() {
  /* Declaro n, p y leo sus valores */
  int cantidadMaquinas, presupuesto;
  scanf("%d %d", &cantidadMaquinas, &presupuesto);
  /* Creo un arreglo con la cantidad de maquinas y leo sus detalles */
  struct Maquina maquinas[cantidadMaquinas];
  for (int i = 0; i < cantidadMaquinas; i++)
    scanf("%d %d %d", &maquinas[i].costo, &maquinas[i].ganancia, &maquinas[i].tipo);

  /* Primero quiero hallar la mayor ganancia que cumple con lo requerido */
  int combinaciones = 1 << cantidadMaquinas;
  int mayorGanancia = 0;  /* La mayor ganancia que iremos actualizando en cada estado, comienza en cero porque cualquier ganancia valida la superara */
  int estadoActual[cantidadMaquinas];  /* Binario que representara a la combinacion actual */
  for (int i = 0; i < cantidadMaquinas; i++) estadoActual[i] = 0;

  /* Generalizare el problema, donde colocare la cantidad minima que requiere
   * cada tipo de maquina para que la solucion sea valida.
   * En este caso particular, las cantidades minimas son iguales a 1 */
  int cantidadMinima[3];
  for (int i = 0; i < 3; i++) cantidadMinima[i] = 1;

  /* En cada estado guardare cuantas unidades de cada tipo estoy utilizando */
  int cantidadActual[3];

  /* Analizare las 2^n - 1 combinacinoes porque quitare el caso cuando no uso ninguna maquina */
  for (int estado = 1; estado < combinaciones; estado++) {
    /* Obtengo la representacion binaria del estado actual */
    EnteroABinario(estadoActual, cantidadMaquinas, estado);
    /* Limpio el arreglo con cantidades actuales a cero para poder acumular*/
    for (int i = 0; i < 3; i++) cantidadActual[i] = 0;
    int sumaCosto, sumaGanancia;
    sumaCosto = sumaGanancia = 0;
    /* Aculare los costos, ganancia y cantidad utilizadas */
    for (int bit = 0; bit < cantidadMaquinas; bit++) {
      /* Si la maquina actual esta siendo utilizada */
      if (estadoActual[bit]) {
        sumaCosto += maquinas[bit].costo;
        sumaGanancia += maquinas[bit].ganancia;
        /* Le resto uno al tipo porque usare 0 a 2 en vez de 1 a 3 */
        cantidadActual[maquinas[bit].tipo - 1]++;
      }
      /* Verificare que el estado actual representa una solucion valida */
      /* Primero, la suma de costos no puede exceder el presupuesto */
      if (sumaCosto > presupuesto) continue;
      /* Segundo, canda cantidad utilizada debe cumplir al menos con la cantidad minima */
      int cumple = 1;
      for (int i = 0; i < 3; i++)
        if (cantidadActual[i] < cantidadMinima[i]) {
          cumple = 0;
          break;
        }
      if (!cumple) continue;
      /* Si es que estamos en un estado valido, entonces analizo si la ganancia es la mayor posible */
      if (sumaGanancia > mayorGanancia) mayorGanancia = sumaGanancia;
    }
  }

  int cantidadSoluciones = 0;
  /* Una vez encontrada la mayor ganancia, buscare todos los estados que cumplen
   * con las condiciones e igualan la mayor ganancia para imprimirlos */
  for (int estado = 1; estado < combinaciones; estado++) {
    EnteroABinario(estadoActual, cantidadMaquinas, estado);
    for (int i = 0; i < 3; i++) cantidadActual[i] = 0;
    int sumaCosto, sumaGanancia;
    sumaCosto = sumaGanancia = 0;
    for (int bit = 0; bit < cantidadMaquinas; bit++) {
      if (estadoActual[bit]) {
        sumaCosto += maquinas[bit].costo;
        sumaGanancia += maquinas[bit].ganancia;
        cantidadActual[maquinas[bit].tipo - 1]++;
      }
      if (sumaCosto > presupuesto) continue;
      int cumple = 1;
      for (int i = 0; i < 3; i++)
        if (cantidadActual[i] < cantidadMinima[i]) {
          cumple = 0;
          break;
        }
      if (!cumple) continue;
      if (sumaGanancia == mayorGanancia) {
        cantidadSoluciones++;
        printf("Solucion %d:\n", cantidadSoluciones);
        printf("Maquinas:");
        for (int bit = 0; bit < cantidadMaquinas; bit++)
          if (estadoActual[bit]) printf(" %d", bit + 1);
        printf(". Costo de maquinas de %d (millones de soles) y una ganancia de %d (millones de soles).\n", sumaCosto, sumaGanancia);
        printf("\n");
      }
    }
  }
  printf("Cantidad de soluciones: %d.\n", cantidadSoluciones);
  return 0;
}
