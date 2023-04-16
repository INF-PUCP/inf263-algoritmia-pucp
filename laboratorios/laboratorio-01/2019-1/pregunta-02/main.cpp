#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>

void PopulateGameBoard(int t, char **tablero);
void ShowGameBoard(int t, char **tablero);
void SearchWord(char *word, int t, char **tablero, char *res);
bool SearchRight(char *word, int t, char **tablero, char *res);
bool SearchLeft(char *word, int t, char **tablero, char *res);
bool SearchDown(char *word, int t, char **tablero, char *res);
bool SearchUp(char *word, int t, char **tablero, char *res);


int main() {
    std::cout << "Ingresar el tamaño de la cuadricula: \n";
    int t, cant;
    std::cin >> t;
    char **tablero, **word, res[3];
    // Inicializamos el tablero
    tablero = new char*[t];
    for (int i = 0; i < t; i++) {
        tablero[i] = new char[t];
    }
    PopulateGameBoard(t, tablero);
    ShowGameBoard(t, tablero);
    std::cout << "Ingrese la cantidad de palabras a buscar\n";
    std::cin >> cant;
    word = new char*[t + 1];
    for (int i = 0; i < t; i++) {
        word[i] = new char[t + 1];
    }
    //Lectura de las palabras
    for (int i = 0; i < cant; i++) {
        std::cout << "Palabra " << (i + 1) << ":";
        std::cin >> *(word + i);
    }

    //Busqueda de las palabras
    for (int i = 0; i < cant; i++) {
        SearchWord(word[i], t, tablero, res);
        std::cout << "Palabra " << (i + 1) << " - " << word[i];
        if (res[0] == -1) {
            std::cout << " no encontrada\n";
            continue;
        }
        std::cout << " encontrada en (" << (int) res[0] << "," << (int) res[1] << ")";
        switch (res[2]) {
            case 'U':
                std::cout << " - arriba\n";
                break;
            case 'D':
                std::cout << " - abajo\n";
                break;
            case 'L':
                std::cout << " - izquierda\n";
                break;
            case 'R':
                std::cout << " - derecha\n";
                break;
        }
    }
}

void PopulateGameBoard(int t, char **tablero) {
    srand(time(NULL));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            tablero[i][j] = 65 + rand() % (91 - 65);
        }
    }
}

void ShowGameBoard(int t, char **tablero) {
    std::cout << "Bienvenido al juego de sopa de letras\n";
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            std::cout << tablero[i][j];
            if (j != t - 1) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
    }
}

void SearchWord(char *word, int size, char **tablero, char *res) {
    for (int i = 0; i < 3; i++) {
        res[i] = -1;
    }
    if (SearchRight(word, size, tablero, res)) return;
    if (SearchLeft(word, size, tablero, res)) return;
    if (SearchDown(word, size, tablero, res)) return;
    if (SearchUp(word, size, tablero, res)) return;

}

bool SearchRight(char *word, int size, char **tablero, char *res) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > size - strlen(word)) break;
            int k = 0, l = j;
            bool centinela = false;
            while (word[k] != '\0') {
                if (tablero[i][l] != word[k]) {
                    centinela = true;
                    break;
                }
                l++;
                k++;
            }
            if (centinela)continue;
            res[0] = (i + 1);
            res[1] = (j + 1);
            res[2] = 'R';
            return false;
        }
    }
    return true;
}

bool SearchLeft(char *word, int size, char **tablero, char *res) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (j < strlen(word) - 1) break;
            int k = 0, l = j;
            bool centinela = false;
            while (word[k] != '\0') {
                if (tablero[i][l] != word[k]) {
                    centinela = true;
                    break;
                }
                l--;
                k++;
            }
            if (centinela)continue;
            res[0] = (i + 1);
            res[1] = (j + 1);
            res[2] = 'L';
            return true;
        }
    }
    return false;
}

bool SearchDown(char *word, int size, char **tablero, char *res) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (i > size - strlen(word)) break;
            int k = 0, l = i;
            bool centinela = false;
            while (word[k] != '\0') {
                if (tablero[l][j] != word[k]) {
                    centinela = true;
                    break;
                }
                l++;
                k++;
            }
            if (centinela) continue;
            res[0] = (i + 1);
            res[1] = (j + 1);
            res[2] = 'D';
            return true;
        }
    }
    return true;
}

bool SearchUp(char *word, int size, char **tablero, char *res) {
    for (int j = 0; j < size; j++) {
        for (int i = size - 1; i >= 0; i--) {
            if (i < strlen(word) - 1) break;

            int k = 0, l = i;
            bool centinela = false;
            while (word[k] != '\0') {
                if (tablero[l][j] != word[k]) {
                    centinela = true;
                    break;
                }
                l--;
                k++;
            }

            if (centinela)continue;
            res[0] = (i + 1);
            res[1] = (j + 1);
            res[2] = 'U';
            return true;
        }
    }
    return false;
}
