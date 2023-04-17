#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>

void PopulateGameBoard(int t, char **board);
void ShowGameBoard(int t, char **board);
void SearchWord(char *word, int t, char **board, char *result);
bool SearchRight(char *word, int t, char **board, char *result);
bool SearchLeft(char *word, int t, char **board, char *result);
bool SearchDown(char *word, int t, char **board, char *result);
bool SearchUp(char *word, int t, char **board, char *result);


int main() {
    std::cout << "Ingresar el tamaño de la cuadricula: \n";
    int t, cnt;
    std::cin >> t;
    char **board, **words, result[3];
    board = new char*[t];
    for (int i = 0; i < t; i++) {
        board[i] = new char[t];
    }
    PopulateGameBoard(t, board);
    ShowGameBoard(t, board);
    std::cout << "Ingrese la cantidad de palabras a buscar\n";
    std::cin >> cnt;
    words = new char*[t + 1];
    for (int i = 0; i < t; i++) {
        words[i] = new char[t + 1];
    }
    for (int i = 0; i < cnt; i++) {
        std::cout << "Palabra " << (i + 1) << ":";
        std::cin >> *(words + i);
    }
    for (int i = 0; i < cnt; i++) {
        SearchWord(words[i], t, board, result);
        std::cout << "Palabra " << (i + 1) << " - " << words[i];
        if (result[0] == -1) {
            std::cout << " no encontrada\n";
            continue;
        }
        std::cout << " encontrada en (" << (int) result[0] << "," << (int) result[1] << ")";
        switch (result[2]) {
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

void PopulateGameBoard(int t, char **board) {
    srand(time(NULL));
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            board[i][j] = 65 + rand() % (91 - 65);
        }
    }
}

void ShowGameBoard(int t, char **board) {
    std::cout << "Bienvenido al juego de sopa de letras\n";
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            std::cout << board[i][j];
            if (j != t - 1) {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
    }
}

void SearchWord(char *word, int size, char **board, char *result) {
    for (int i = 0; i < 3; i++) {
        result[i] = -1;
    }
    if (SearchRight(word, size, board, result)) return;
    if (SearchLeft(word, size, board, result)) return;
    if (SearchDown(word, size, board, result)) return;
    if (SearchUp(word, size, board, result)) return;

}

bool SearchRight(char *word, int size, char **board, char *result) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > size - strlen(word)) break;
            int k = 0, l = j;
            bool centinela = false;
            while (word[k] != '\0') {
                if (board[i][l] != word[k]) {
                    centinela = true;
                    break;
                }
                l++;
                k++;
            }
            if (centinela)continue;
            result[0] = (i + 1);
            result[1] = (j + 1);
            result[2] = 'R';
            return true;
        }
    }
    return false;
}

bool SearchLeft(char *word, int size, char **board, char *result) {
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= 0; j--) {
            if (j < strlen(word) - 1) break;
            int k = 0, l = j;
            bool centinela = false;
            while (word[k] != '\0') {
                if (board[i][l] != word[k]) {
                    centinela = true;
                    break;
                }
                l--;
                k++;
            }
            if (centinela)continue;
            result[0] = (i + 1);
            result[1] = (j + 1);
            result[2] = 'L';
            return true;
        }
    }
    return false;
}

bool SearchDown(char *word, int size, char **board, char *result) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (i > size - strlen(word)) break;
            int k = 0, l = i;
            bool centinela = false;
            while (word[k] != '\0') {
                if (board[l][j] != word[k]) {
                    centinela = true;
                    break;
                }
                l++;
                k++;
            }
            if (centinela) continue;
            result[0] = (i + 1);
            result[1] = (j + 1);
            result[2] = 'D';
            return true;
        }
    }
    return false;
}

bool SearchUp(char *word, int size, char **board, char *result) {
    for (int j = 0; j < size; j++) {
        for (int i = size - 1; i >= 0; i--) {
            if (i < strlen(word) - 1) break;

            int k = 0, l = i;
            bool centinela = false;
            while (word[k] != '\0') {
                if (board[l][j] != word[k]) {
                    centinela = true;
                    break;
                }
                l--;
                k++;
            }

            if (centinela)continue;
            result[0] = (i + 1);
            result[1] = (j + 1);
            result[2] = 'U';
            return true;
        }
    }
    return false;
}
