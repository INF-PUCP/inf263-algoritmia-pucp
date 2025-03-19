#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define FILE_PESO "input-peso.txt"
#define FILE_PRECIO "input-precio.txt"
#define CANT_PISOS 4 

void CargarCromosoma(int *cromosoma, int size, int num);
void LeerDatos(int *N, int *peso,int **almacen);
void CalcularPeso(int *almacen, int *cromosoma, int size, int *peso);
void ImprimirPedido(int *almacen, int *cromosoma, int size, int resultado);
void LeerPrecio(int *precio, int size);
void CalcularGanancia(int *precioAlmacen, int *cromosoma, int size, int *ganancia);
void ImprimirGanancia(int *precio,int *cromosoma,int size,int ganancia,int resultado);

int main(){
    int N, peso, *almacen;
    LeerDatos(&N, &peso, &almacen);
    // Prueba de lectura de archivos
    //    std::cout << "N: " << N << std::endl;
    //    std::cout << "Peso: " << peso << std::endl;
    //    for (int i = 0; i < N * CANT_PISOS; i++) {
    //        std::cout << almacen[i] << " ";
    //        if (i % 4 == 3) std::cout << std::endl;
    //    }
    int size = N * CANT_PISOS,
            combinaciones = pow(2, size),
            cromosoma[size],
            pesoParcial = 0,
            resultado = 1;
    std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item B" << "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";
    for (int i = 1; i < combinaciones; i++) {
        CargarCromosoma(cromosoma, size, i);
        CalcularPeso(almacen, cromosoma, size, &pesoParcial);
        if (peso != pesoParcial) continue;
        ImprimirPedido(almacen, cromosoma, size, resultado);
        resultado++;
    }
    std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item C" << "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";
    int *precioAlmacen = new int[size];
    resultado = 1;
    LeerPrecio(precioAlmacen, size);   
    // Verificar lectura de los precios
    //    for (int i = 0; i < size; i++) {
    //        std::cout << precio[i] << " ";
    //        if (i % 4 == 3) std::cout << std::endl;
    //    }
    int ganancia = 0, gananciaParcial = 0,combinacionFinal;
    for (int i = 0; i < combinaciones; i++) {
        CargarCromosoma(cromosoma, size, i);
        CalcularPeso(almacen, cromosoma, size, &pesoParcial);
        if (peso < pesoParcial) continue;
        CalcularGanancia(precioAlmacen, cromosoma, size, &gananciaParcial);
        if(ganancia > gananciaParcial) continue;
        combinacionFinal = i;
        ganancia = gananciaParcial;
    }
    CargarCromosoma(cromosoma,size,combinacionFinal);
    ImprimirGanancia(almacen,cromosoma,size,ganancia,resultado);
}

void CargarCromosoma(int *cromosoma, int size, int num) {
    int i = size - 1;
    while (num != 0) {
        cromosoma[i] = num % 2;
        num /= 2;
        i--;
    }
    for (int j = 0; j <= i; j++) {
        cromosoma[j] = 0;
    }
}

void LeerDatos(int *N, int *peso, int **almacen) {
    std::ifstream archivo(FILE_PESO, std::ios::in);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << FILE_PESO << std::endl;
        exit(1);
    }
    archivo >> *N;
    archivo >> *peso;
    int size = (*N) * CANT_PISOS;
    *almacen = new int[size];

    for (int i = 0; i < size; i++) {
        archivo >> (*almacen)[i];
    }
    archivo.close(); // cerramos el archivo
}

void CalcularPeso(int *almacen, int *cromosoma, int size, int *peso) {
    *peso = 0;
    for (int i = 0; i < size; i++) {
        if (!cromosoma[i]) continue;
        *peso += almacen[i];
    }
}

void ImprimirPedido(int *almacen, int *cromosoma, int size, int resultado) {
    std::cout << "Resultado " << resultado << ":";
    for (int i = 0; i < size; i++) {
        if (!cromosoma[i]) continue;
        std::cout << almacen[i] << "k ";
    }
    std::cout << "\tUbicaciones:";
    for (int i = 0; i < size; i++) {
        if (!cromosoma[i]) continue;
        switch ((i + 1) % 4) {
            case 1:
                std::cout << "IA";
                break;
            case 2:
                std::cout << "IB";
                break;
            case 3:
                std::cout << "DA";
                break;
            case 0:
                std::cout << "DB";
                break;
        } 
        if ( (i+1)%4 == 0)
            std::cout << (i+1)/4 << " ";
        else
            std::cout << (i+1)/4 + 1 << " ";
    }
    std::cout << "\n";
}

void LeerPrecio(int *precio, int size) {
    std::ifstream archivo(FILE_PRECIO, std::ios::in);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << FILE_PRECIO << std::endl;
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        archivo >> precio[i];
    }
    archivo.close();
}
void CalcularGanancia(int *precioAlmacen, int *cromosoma, int size, int *ganancia) {
    *ganancia = 0;
    for (int i = 0; i < size; i++) {
        if(!cromosoma[i]) continue;
        *ganancia += precioAlmacen[i];
    }
}

void ImprimirGanancia(int *almacen,int *cromosoma,int size,int ganancia,int resultado){
    std::cout << "Ganancia: " <<ganancia << "\t";
    ImprimirPedido(almacen,cromosoma,size,resultado);
}


