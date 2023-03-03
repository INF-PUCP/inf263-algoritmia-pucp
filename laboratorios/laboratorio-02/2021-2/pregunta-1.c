#include <stdio.h>

const int MAX_NUMERO_CONSULTORAS = 10;

int numero_consultoras;
int numero_fases;
double porcentaje_inversion;
double presupuesto_inicial;
bool elegir_economicas;

double costos[MAX_NUMERO_CONSULTORAS];

// Leemos los costos de las consultoras [consultora_actual .. numero_consultoras - 1]
void LeerCosto(int consultora_actual) {
  if (consultora_actual == numero_consultoras) return;
  scanf("%f", &costos[consultora_actual]);
  // Leemos el costo de la siguiente consultora
  LeerCosto(consultora_actual + 1);
}

// Ordena de menor a mayor costos[i .. numero_consultoras - 1]

bool EsMenorCosto(int posicion_actual, int posicion_candidata) {
  return costos[posicion_actual] < costos[posicion_candidata];
}

void OrdenarCostos(int i) {
  if (i == numero_consultoras  - 1) return;
  int posicion_menor_costo_derecha = ObtenerMinimo(i + 1);
  if (EsMenorCosto(i, posicion_menor_costo_derecha)) {
    OrdenarCostos(i + 1);
  } else {
    swap(costos[])
  }
}

// Analizamos las fases [fase_actual .. numer_fases - 1]
void AnalizarFase(int fase_actual) {
  if (fase_actual == numero_fases) return;
  
  // Leemos los valores asociados a la fase actual
  scanf("%f", &porcentaje_inversion);
  LeerCosto(0);
  scanf("%d", &elegir_economicas);

  // Ordenamos los costos de las consultoras de esta fase
  OrdenarCostos(0);

  // Analizamos la siguiente fase
  AnalizarFase(fase_actual + 1);
}

int main(void) {
  printf("Ingrese el presupuesto inicial: ");
  scanf("%f", &presupuesto_inicial);
  
  printf("Ingrese el numero de fases: ");
  scanf("%d", &numero_fases);
  
  printf("Ingrese el numero de consultoras: ");
  scanf("%d", &numero_consultoras);

  AnalizarFase(0);
  return 0;
}
