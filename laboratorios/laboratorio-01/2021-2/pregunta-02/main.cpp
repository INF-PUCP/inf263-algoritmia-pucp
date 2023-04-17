#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#define FILE_ARCHIVO "input.txt"

typedef struct{
    double porcentajeDeComision;
    int idCliente;
    int cantAcciones;
}Cliente;

void CargarCromosoma(int *cromosoma, int size, int num);
void LeerClientes(int *T, int *P, int *N, Cliente **clientes);
double CalcularGanancia(Cliente *clientes, int *cromosoma, int N, int P);
bool EsValido(Cliente *clientes, int *cromosoma, int N, int T,int *acciones);
void ImprimirClientes(Cliente *clientes,double ganancia,int *cromosoma,int N,int P,int acciones);

int main(){
    int T, // Cantidad de límite de acciones
            P, // Precio de la acción el día de la compra
            N; // Clientes interesados
    Cliente *clientes;
    LeerClientes(&T, &P, &N, &clientes);

    // Verificacion de la lectura
    //    std::cout << "T: " << T 
    //            << "\nP: " << P
    //            << "\nN: " << N << std::endl;
    //    for (int i = 0; i < N; i++) {
    //        std::cout << "ID: " << clientes[i].idCliente
    //                << "\tCant: " << clientes[i].cantAcciones
    //                << "\tPorcentaje: " << clientes[i].porcentajeDeComision << std::endl;
    //    }

    int combinaciones = pow(2, N),
            cromosoma[N],
           combinacionFinal,
            accionesParciales,
            acciones;
    double ganancia = 0,
            gananciaParcial = 0;
    std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item B"<< "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";
    for (int i = 1; i < combinaciones; i++) {
        CargarCromosoma(cromosoma, N, i);
        gananciaParcial = CalcularGanancia(clientes, cromosoma, N, P);
        if (!EsValido(clientes, cromosoma, N, T, &accionesParciales) || gananciaParcial <= ganancia)continue;
        combinacionFinal = i;
        ganancia = gananciaParcial;
        acciones = accionesParciales;
    }
        CargarCromosoma(cromosoma, N, combinacionFinal);
    ImprimirClientes(clientes, ganancia, cromosoma, N, P, acciones);

    std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item C" << "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";
    for (int i = 1; i < combinaciones; i++) {
        CargarCromosoma(cromosoma, N, i);
        gananciaParcial = CalcularGanancia(clientes, cromosoma, N, P);
       if (!EsValido(clientes, cromosoma, N, T, &accionesParciales) || abs(ganancia - gananciaParcial) > 1.0)continue;
       ImprimirClientes(clientes, ganancia, cromosoma, N, P, accionesParciales);
    }
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

void LeerClientes(int *T, int *P, int *N, Cliente **clientes) {
    std::ifstream archivo(FILE_ARCHIVO, std::ios::in);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << FILE_ARCHIVO << std::endl;
        exit(1);
    }
    archivo >> *T
            >> *P
            >> *N;

    *clientes = new Cliente[*N];
    for (int i = 0; i < *N; i++) {
        archivo >> (*clientes)[i].idCliente
                >> (*clientes)[i].cantAcciones
                >> (*clientes)[i].porcentajeDeComision;
    }
    archivo.close();
}

double CalcularGanancia(Cliente *clientes, int *cromosoma, int N, int P) {
    double ganancia = 0;
    for (int i = 0; i < N; i++) {
        if (!cromosoma[i]) continue;
        ganancia += clientes[i].cantAcciones * clientes[i].porcentajeDeComision * P;
    }
    return ganancia;
}

bool EsValido(Cliente *clientes, int *cromosoma, int N, int T, int *acciones) {
    *acciones = 0; // Cantidad de acciones que se van a vender ese día
    for (int i = 0; i < N; i++) {
        if (!cromosoma[i]) continue;
        *acciones += clientes[i].cantAcciones;
        if (*acciones > T) return false;
    }
    return true;
}

void ImprimirClientes(Cliente *clientes, double ganancia, int *cromosoma, int N, int P, int acciones) {
    std::cout << " La máxima ganancia debido a las comisiones sería de: " << ganancia
            << " dólares por un total de " << acciones << " acciones\n"
            << "Clientes que se deben de elegir para obtener la mayor ganancia son:\n";
    for (int i = 0; i < N; i++) {
        if (!cromosoma[i]) continue;
        double ganaciaCliente = clientes[i].cantAcciones * clientes[i].porcentajeDeComision * P;
        std::cout << "  - El cliente " << clientes[i].idCliente
                << " otorga una ganancia de " << ganaciaCliente
                << " dolares por la compra de" << clientes[i].cantAcciones << " acciones\n";
    }
}
