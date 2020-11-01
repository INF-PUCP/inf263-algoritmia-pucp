#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define MAX_DIAS 100

int cantidad_contagiados[MAX_DIAS], intervalo_crecimiento[MAX_DIAS];

int main(void) {
  /* Lectura de datos. */
  int cantidad_dias, dia;
  printf("Ingrese la cantidad de dias: ");
  scanf("%d", &cantidad_dias);

  for (int i = 0; i < cantidad_dias; i++) {
    printf("Ingrese la cantidad de miles de contagiados en el dia %d: ", i);
    scanf("%d", &cantidad_contagiados[i]);
  }

  /*
   * Analisis de Complejidad:
   * Esto se debe a que para cada dia, yo anadire este una unica vez.
   * El while anidado solo puede retroceder mientras cumpla la condicion, y
   * en caso cumplirla remueve a dicho elemento de la pila. Por lo tanto, solo
   * podemos remover un elemento una unica vez. De esta manera, en el peor de los
   * casos, solamente anadimos todos una vez, tratamos de retroceder cuanto podemos
   * y si no se puede, esa ultima pregunta hace que se detenga el while, por lo que
   * la cantidad de pasos esta acotada superiormente menor estricto que 3n.
   * Complejidad en Tiempo: O(n)
   */

  Pila pila;
  CrearPila(&pila);
  for (dia = 0; dia < cantidad_dias; dia++) {
    int cantidad_actual = 1; 
    while (!EstaVacia(pila)) {
      /* Obtengo el dia del ultimo que pudo crecer tanto como fue posible. */
      int cima = Top(pila);
      
      /* Si es que soy mas grande que este, entonces puedo acumular nuestro crecimiento
       * y sigo con este proceso hasta no poder retroceder. En caso no pueda
       * superar al ultimo que pudo crecer, entonces me detengo.
       */
      if (cantidad_contagiados[dia] > cantidad_contagiados[cima]) {
        cantidad_actual += intervalo_crecimiento[cima];
        Pop(&pila);
      } else {
        break;
      }
    }
    
    /*
     * Tras haber retrocedido lo maximo que pude, actualizo el valor de mi
     * intervalo de crecimiento. Asimismo, anado el dia actual a la pila para
     * que los posteriores puedan analizarme dependiendo de su situacion.
     */
    intervalo_crecimiento[dia] = cantidad_actual;
    Push(&pila, dia);
  }

  /* Como tengo las cantidades, los intervalos tienen uno menos */
  for (dia = 0; dia < cantidad_dias; dia++) {
    intervalo_crecimiento[dia]--;
  }

  /* Finalmente, presento el resultado en pantalla. */
  printf("Intervalos de crecimiento:\n");
  for (dia = 0; dia < cantidad_dias; dia++) {
    printf("Dia %d: %d\n", dia, intervalo_crecimiento[dia]);
  }
  return 0;
}
