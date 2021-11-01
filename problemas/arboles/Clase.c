#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Informacion que se almacenara en el nodo */
typedef int TInfo;

/* Se define el  tipo de dato TNodo que representa a una estructura autoreferenciada */
typedef struct Nodo {
  TInfo elem;
  struct Nodo* izq;
  struct Nodo* der;
} TNodo;
typedef TNodo* TArbol;


typedef struct NodoPila{
  int valor;
  struct NodoPila* ptrSig;
}TNodoPila;

typedef TNodoPila* TPila;

void crear(TPila*);
void push(TPila*, int);
int pila_vacia(TPila*);
int top(TPila*);
int pop(TPila*);
void finalizar(TPila);

void crear_arbol(TArbol*);
void insertar_nodo(TArbol*, TInfo);
void en_orden(TArbol);
void pre_orden(TArbol);
void pos_orden(TArbol);

/* Al inicio la pila se inicializa con nulo, lo que indica que esta vacia */
void crear(TPila *ptrpila) {
  *ptrpila = NULL;
}

/* Se implementara¡ usando una lista simplemente enlazada.
 * push insertara¡ siempre un nodo al inicio. */
void push(TPila* pila, int valor) {
  TNodoPila* ptrNuevo;
  ptrNuevo = (TNodoPila*) malloc(sizeof (TNodoPila));
  ptrNuevo->valor = valor;
  ptrNuevo->ptrSig = *pila;
  *pila = ptrNuevo;
}

int pila_vacia(TPila* ptrPila){
  return (*ptrPila == NULL);
}


int top(TPila* ptrPila) {
  TNodoPila *ptrrec;
  ptrrec = *ptrPila;
  if (pila_vacia(ptrPila))
    return 0;
  else
    return (ptrrec->valor);
}

/*Dado que se ha realizado una insercion al inicio, para que la estructura se
 comporte como pila, se debe sacar los dados a partir del inicio de la lista.*/

int pop(TPila* Pila) {
  TNodoPila *ptrEliminar;
  int valor = -1;
  if (!pila_vacia(Pila)) {
    ptrEliminar=*Pila;
    valor = ptrEliminar->valor;
    *Pila = ptrEliminar->ptrSig;
    free(ptrEliminar);
  }
  return valor;
}

/*Libera toda la memoria reservada para la lista utilizada en la pila.*/
void finalizar(TPila ptrPila){
  TNodoPila *ptrEliminar;
  ptrEliminar = ptrPila;
  while (ptrEliminar != NULL){
    ptrPila = ptrEliminar->ptrSig;
    free(ptrEliminar);
    ptrEliminar = ptrPila;
  }
}

/*
 ***********************************************************
 *
 * Plantilla de la estructura de datos arbol de Rony Cueva
 *
 **********************************************************
 */

void crear_arbol(TArbol *ptrArbol) {
  *ptrArbol = NULL;
}

/* Implementacion iterariva de la insercion de un nodo en un
 * arbol binario de busqueda (ABB) */
void insertar_nodo(TArbol* ptrArbol, TInfo elem) {
  /* ptrPadre apuntara al padre de la hoja que estoy insertando.
   * Para llegar a esto ptrReccorido lo usaremos como estructura auxiliar,
   * al final ptrRecorrido se hace NULL.
   * Todo esto solo vale en el caso que el arbol no este vacio. */
  TNodo *ptrRecorrido, *ptrPadre;
  
  /* Se esta creando una hoja con el valor del elemento informado en el parametro */
  TNodo* ptrNuevo = (TNodo*) malloc(sizeof(TNodo));
  ptrNuevo->elem = elem;
  ptrNuevo->izq = ptrNuevo->der = NULL;
  
  if (*ptrArbol == NULL) {
    /*si el arbol esta vacio, la nueva hoja sera la raiz del arbol*/
    *ptrArbol = ptrNuevo;
  } else {
    ptrPadre = NULL;
    ptrRecorrido = *ptrArbol;
    while (ptrRecorrido != NULL) {
      ptrPadre = ptrRecorrido;
      if (ptrRecorrido->elem > elem) {
        ptrRecorrido = ptrRecorrido->izq;
      } else {
        ptrRecorrido = ptrRecorrido->der;
      }
    }

    if (ptrPadre->elem > elem) {
      ptrPadre->izq = ptrNuevo;
    } else {
      ptrPadre->der = ptrNuevo;
    }
  }
}

void en_orden(TArbol ptrArbol) {
  if (ptrArbol) {
    en_orden(ptrArbol->izq);
    printf("%d ", ptrArbol->elem);
    en_orden(ptrArbol->der);
  }
}

void pre_orden(TArbol ptrArbol) {
  if (ptrArbol) {
    printf("%d ", ptrArbol->elem);
    pre_orden(ptrArbol->izq);
    pre_orden(ptrArbol->der);
  }
}

void pos_orden(TArbol ptrArbol) {
  if (ptrArbol) {
    pos_orden(ptrArbol->izq);
    pos_orden(ptrArbol->der);
    printf("%d ", ptrArbol->elem);
  }
}

/*
 ******************************************************************************
 *
 * Desde aqui el codigo es de Manuel. Las inconsistencias en notacion se deben
 * a las malas practicas de la plantilla de Rony Cueva.
 *
 ******************************************************************************
 */

/*
 * Metodo: Contar
 * Uso: int cnt = Contar(arbol);
 * ----------------------------
 * Cuenta la cantidad de nodos que tiene un arbol
 */
int Contar(TArbol arbol) {
  if (arbol == NULL) return 0;
  return (1 + Contar(arbol->izq) + Contar(arbol->der));
}

/*
 * Metodo: Buscar
 * Uso: TArbol nodo = Buscar(arbol, objetivo);
 * ---------------------
 * Retorna el puntero a un nodo con el valor objetivo.
 * En caso no exista, retorna NULL.
 */
TArbol Buscar(TArbol arbol, TInfo objetivo) {
  if (arbol == NULL) return NULL;
  if (arbol->elem == objetivo) {
    return arbol;
  } else {
    if (arbol->elem > objetivo) {
      return Buscar(arbol->izq, objetivo);
    } else {
      return Buscar(arbol->der, objetivo);
    }
  }
}

/*
 * Metodo: BuscarMinimo
 * Uso: TArbol nodo = BuscarMinimo(arbol);
 * ---------------------------------------
 * Retorna el puntero al nodo con el minimo valor o NULL en caso no exista.
 */

TArbol BuscarMinimo(TArbol arbol) {
  if (arbol == NULL) return NULL;
  if (arbol->izq == NULL) return arbol;
  return BuscarMinimo(arbol->izq);
}

/*
 * Metodo: BorrarNodo
 * Uso: BorrarNodo(&raiz, objetivo);
 * ---------------------------------
 * Elimina el nodo que tiene el valor objetivo. Imprime en pantalla un mensaje
 * en caso no exista nodo con dicho valor objetivo.
 */
void BorrarNodo(TArbol* ptr_raiz, TInfo objetivo) {
  if (*ptr_raiz == NULL) {
    printf("Valor no encontrado.\n");
    return;
  }
  if (objetivo < (*ptr_raiz)->elem) {
    BorrarNodo(&((*ptr_raiz)->izq), objetivo);
    return;
  }
  if (objetivo > (*ptr_raiz)->elem) {
    BorrarNodo(&((*ptr_raiz)->der), objetivo);
    return;
  }
  if ((*ptr_raiz)->izq == NULL && (*ptr_raiz)->der == NULL) {
    free(*ptr_raiz);
    *ptr_raiz = NULL;
    return;
  }
  if ((*ptr_raiz)->izq == NULL) {
    *ptr_raiz = (*ptr_raiz)->der;
    return;
  }
  if ((*ptr_raiz)->der == NULL) {
    *ptr_raiz = (*ptr_raiz)->izq;
    return;
  }
  TArbol minimo = BuscarMinimo((*ptr_raiz)->der);
  (*ptr_raiz)->elem = minimo->elem;
  BorrarNodo(&((*ptr_raiz)->der), minimo->elem);
}

/*
 * Metodo: max
 * Uso: int maximo = max(a, b);
 * ----------------------------
 * Retorna el maximo entre a y b.
 */
int max(int a, int b) {
  return ((a > b) ? a : b);
}

/*
 * Metodo: Altura
 * Uso: int altura = Altura(arbol);
 * --------------------------------
 * Retorna la altura del arbol.
 */
int Altura(TArbol arbol) {
  if (arbol == NULL) return 0;
  return 1 + max(Altura(arbol->izq), Altura(arbol->der));
}

int main(void) {
  TArbol arbol;
  crear_arbol(&arbol);
  insertar_nodo(&arbol, 10);
  insertar_nodo(&arbol, 8);
  insertar_nodo(&arbol, 6);
  insertar_nodo(&arbol, 4);
  insertar_nodo(&arbol, 9);
  insertar_nodo(&arbol, 15);
  assert(Contar(arbol) == 6);
  assert(Buscar(arbol, 6) != NULL);
  assert(Buscar(arbol, 50) == NULL);
  assert(BuscarMinimo(arbol)->elem == 4);
  assert(Altura(arbol) == 4);

  printf("Arbol original: ");
  en_orden(arbol);
  printf("\n");

  printf("Eliminar 6\n");
  printf("Nuevo arbol: ");
  BorrarNodo(&arbol, 6);
  en_orden(arbol);
  printf("\n");

  printf("Eliminar 10\n");
  printf("Nuevo arbol: ");
  BorrarNodo(&arbol, 10);
  en_orden(arbol);
  printf("\n");
  
  printf("Eliminar 69\n");
  BorrarNodo(&arbol, 69);
  printf("Nuevo arbol: ");
  en_orden(arbol);
  printf("\n");
  
  printf("Eliminar 4\n");
  printf("Nuevo arbol: ");
  BorrarNodo(&arbol, 4);
  en_orden(arbol);
  printf("\n");
  printf("Todos los casos estan OK.\n");
  return 0;
}
