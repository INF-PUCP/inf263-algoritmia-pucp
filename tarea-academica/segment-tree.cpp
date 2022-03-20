#include <iostream>
#include <vector>
using namespace std;

typedef long long Long;

struct SegmentTree {
  vector<Long> tree;

  // Complejidad en memoria: O(n)
  SegmentTree(int n) {
    tree.resize(4 * n, 0);
  }

  // Complejidad en tiempo: O(n)
  void Construir(const vector<Long>& arr, int id, int tl, int tr) {
    if (tl == tr) {
      tree[id] = arr[tl];
    } else {
      int tm = (tl + tr) / 2;
      Construir(arr, 2 * id, tl, tm);
      Construir(arr, 2 * id + 1, tm + 1, tr);
      tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
  }

  // Complejidad en tiempo: O(lg(n))
  void Actualizar(int posicion, Long valor, int id, int tl, int tr) {
    if (tl == tr) {
      tree[id] = valor;
    } else {
      int tm = (tl + tr) / 2;
      if (posicion <= tm) {
        Actualizar(posicion, valor, 2 * id, tl, tm);
      } else {
        Actualizar(posicion, valor, 2 * id + 1, tm + 1, tr);
      }
      tree[id] = tree[2 * id] + tree[2 * id + 1];
    }
  }

  // Complejidad en tiempo: O(lg(n))
  Long Consultar(int l, int r, int id, int tl, int tr) {
    if (l <= tl && tr <= r) return tree[id];
    int tm = (tl + tr) / 2;
    if (r <= tm) return Consultar(l, r, 2 * id, tl, tm);
    if (tm < l) return Consultar(l ,r, 2 * id + 1, tm + 1, tr);
    return Consultar(l, r, 2 * id, tl, tm) + Consultar(l, r, 2 * id + 1, tm + 1, tr);
  }
};

struct Consulta {
  int tipo;
  pair<int, int> contenido;

  void Leer(void) {
    cin >> tipo >> contenido.first >> contenido.second;
  }
};

struct Entrada {
  int n_resistencias;
  vector<Long> resistencias;
  int n_consultas;
  vector<Consulta> consultas;

  // Complejidad en tiempo: O(n + q)
  // Complejidad en memoria: O(n + q)
  void Leer(void) {
    cin >> n_resistencias;
    resistencias.resize(n_resistencias);
    for (int i = 0; i < n_resistencias; i++) {
      cin >> resistencias[i];
    }
    cin >> n_consultas;
    consultas.resize(n_consultas);
    for (int i = 0; i < n_consultas; i++) {
      consultas[i].Leer();
    }
  }
};

// Complejidad en tiempo: O(nq)
void ExperimentarConResistenciasIneficientemente(Entrada& entrada) {
  for (int i = 0; i < entrada.n_consultas; i++) {
    if (entrada.consultas[i].tipo == 1) {
      int posicion = entrada.consultas[i].contenido.first;
      int nuevo_valor = entrada.consultas[i].contenido.second;
      entrada.resistencias[posicion] = nuevo_valor;
    } else {
      Long resistencia_equivalente = 0LL;
      int izquierda = entrada.consultas[i].contenido.first;
      int derecha = entrada.consultas[i].contenido.second;
      for (int j = izquierda; j <= derecha; j++) {
        resistencia_equivalente += entrada.resistencias[j];
      }
      cout << resistencia_equivalente << endl;
    }
  }
}

// Complejidad en tiempo: O(n log n)
void ExperimentarConResistenciasEficientemente(const Entrada& entrada) {
  int n_resistencias = entrada.n_resistencias;
  SegmentTree segment_tree(n_resistencias);
  segment_tree.Construir(entrada.resistencias, 1, 0, n_resistencias - 1);
  for (int i = 0; i < entrada.n_consultas; i++) {
    if (entrada.consultas[i].tipo == 1) {
      int posicion = entrada.consultas[i].contenido.first;
      int nuevo_valor = entrada.consultas[i].contenido.second;
      segment_tree.Actualizar(posicion, nuevo_valor, 1, 0, n_resistencias);
    } else {
      int izquierda = entrada.consultas[i].contenido.first;
      int derecha = entrada.consultas[i].contenido.second;
      cout << segment_tree.Consultar(izquierda, derecha, 1, 0, n_resistencias - 1) << endl;
    }
  }
}

// Dados n resistores
// r_1, r_2, ..., r_n
// y q consultas
// cada consulta puede ser de dos tipos:
// 1 posicion valor: cambiar el valor de la resistencia en la posicion especificada
// 2 L R: hallar la resistencia equivalente entre r_L ... r_R
// Restricciones:
// r_i <= 10^9, 1 <= i <= n
// n <= 10^5
// q <= 10^5

int main(void) {
  Entrada entrada;
  entrada.Leer();
  // ExperimentarConResistenciasIneficientemente(entrada);
  ExperimentarConResistenciasEficientemente(entrada);
  return 0;
}
