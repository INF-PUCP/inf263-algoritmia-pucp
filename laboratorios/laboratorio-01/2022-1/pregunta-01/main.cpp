#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

#define FILE_NAME "input.txt"
#define MAX_CARACTER_CANAL 30

typedef struct {
    int codigo;
    char *canal;
    int USD;
    double ROAS;
    double ingresoPorVentas;
    int nivelDeMarca;
} Canal;

void leerArchivos(Canal **canales, int *P, int *N);
void CargarCromosoma(int *cromosoma, int size, int num);
bool EsValido(Canal *canales, int *cromosoma, int size, int P);
void CargarCromosomaFinal(int *cromosoma, int *cromosomaFinal, int size);
void MaxVentas(Canal *canales, int *cromosoma, int size, int *inversion, double *ingresoVentas);
void MaxPublicidad(Canal *canales, int *cromosoma, int size, int *inversion,
        int *recordacionMarca, double *ingresoPublicidad);
double ItemB(double maxIngresoVentasFinal);
void ItemC(Canal *canales,int *cromosoma, int size, double ingresoVentas, int inversionTotal);
void ItemD(Canal *canales, int *cromosoma, int size, int marca, int inversion,double ingreso);

int main(){
    Canal *canales;
    int P, N;
    leerArchivos(&canales, &P, &N);
    // Confirmación de lectura de archivos
    //    std::cout << "P: " << P << " N: " << N << "\n";
    //    for (int i = 0; i < N; i++) {
    //        std::cout << std::left << std::setfill(' ') << std::setw(5) << canales[i].codigo
    //                << std::left << std::setfill(' ') << std::setw(20) << canales[i].canal
    //                << std::setw(15) << canales[i].USD
    //                << std::setw(15) << canales[i].ROAS
    //                << std::setw(15) << canales[i].nivelDeMarca
    //                << std::setw(15) << canales[i].ingresoPorVentas << "\n";
    //    }
    int lim = pow(2, N),
            cromosoma[N],
            cromosomaFinal[N],
            inversionTotal = 0,
            inversionTotalFinal = 0;
    int cromosomaFinalPublicidad[N],
            recordacionMarca = 0,
            recordacionMarcaFinal = 0,
            inversionTotalPublicidad = 0,
            inversionTotalPublicidadFinal = 0;
    double maxIngresoVentas = 0,
            maxIngresoVentasFinal = 0,
            ingresoPublicidad = 0,
            ingresoPublicidadFinal = 0;
    for (int i = 0; i < lim; i++) {
        CargarCromosoma(cromosoma, N, i);
        if (EsValido(canales, cromosoma, N, P)) {
            MaxVentas(canales, cromosoma, N, &inversionTotal, &maxIngresoVentas);
            MaxPublicidad(canales, cromosoma, N, &inversionTotalPublicidad, &recordacionMarca, &ingresoPublicidad);
            if (maxIngresoVentas > maxIngresoVentasFinal) {
                CargarCromosomaFinal(cromosoma, cromosomaFinal, N);
                maxIngresoVentasFinal = maxIngresoVentas;
                inversionTotalFinal = inversionTotal;
            }
            if (recordacionMarca > recordacionMarcaFinal) {
                CargarCromosomaFinal(cromosoma, cromosomaFinalPublicidad, N);
                inversionTotalPublicidadFinal = inversionTotalPublicidad;
                recordacionMarcaFinal = recordacionMarca;
                ingresoPublicidadFinal = ingresoPublicidad;
            }

        }
    }
    ItemB(maxIngresoVentasFinal);
    ItemC(canales, cromosomaFinal, N, maxIngresoVentasFinal, inversionTotalFinal);
    ItemD(canales, cromosomaFinalPublicidad, N, recordacionMarcaFinal, inversionTotalPublicidadFinal, ingresoPublicidadFinal);
}

void leerArchivos(Canal **canales, int *P_ptr, int *N_ptr) {
    std::ifstream archivo(FILE_NAME, std::ios::in);
    if (!archivo) {
        std::cout << "No se pudo abrir el archivo: " << FILE_NAME << "\n";
        exit(1);
    }
    archivo >> *P_ptr >> *N_ptr;
    if (archivo.fail()) {
        std::cout << "No se pudo leer el presupuesto o la cantidad de empresas\n";
        exit(2);
    }
    *canales = (Canal *) malloc(sizeof (Canal) * (*N_ptr));
    for (int i = 0; i < *N_ptr; i++) {
        (*canales)[i].canal = (char *) malloc(sizeof (char) * MAX_CARACTER_CANAL);
        archivo >> (*canales)[i].codigo // Codigo
                >> (*canales)[i].canal // Nombre del canal
                >> (*canales)[i].USD // Inversion publicitaria
                >> (*canales)[i].ROAS // Retorno de inversion
                >> (*canales)[i].nivelDeMarca; // Recaudación de la marca
        // Ingreso por ventas => ROAS = ingresoPorVentas / USD
        (*canales)[i].ingresoPorVentas = (*canales)[i].ROAS * (*canales)[i].USD;
    }
    archivo.close();
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

bool EsValido(Canal *canales, int *cromosoma, int size, int P) {
    int inversionTotal = 0;
    for (int i = 0; i < size; i++) {
        if (cromosoma[i]) {
            inversionTotal += canales[i].USD;
            if (inversionTotal > P) return false;
        }
    }
    return true;
}

void CargarCromosomaFinal(int *cromosoma, int *cromosomaFinal, int size) {
    for (int i = 0; i < size; i++) {
        cromosomaFinal[i] = cromosoma[i];
    }
}

void MaxVentas(Canal *canales, int *cromosoma, int size, int *inversion, double *ingreso) {
    *ingreso = 0;
    *inversion = 0;
    for (int i = 0; i < size; i++) {
        if (cromosoma[i]) {
            *ingreso += canales[i].ingresoPorVentas;
            *inversion += canales[i].USD;
        }
    }
}

void MaxPublicidad(Canal *canales, int *cromosoma, int size, int *inversion,
        int *marca, double *ingreso) {
    *inversion = 0;
    *marca = 0;
    *ingreso = 0;
    for (int i = 0; i < size; i++) {
        if (cromosoma[i]) {
            *marca += canales[i].nivelDeMarca;
            *inversion += canales[i].USD;
            *ingreso += canales[i].ingresoPorVentas;
        }
    }
}

double ItemB(double ingresoVentas) {
    std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item B"<< "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";
    std::cout << "El máximo ingreso por ventas es de: "
            << std::fixed << std::setprecision(2) << ingresoVentas
            << " dolares\n";
}

void ItemC(Canal *canales, int *cromosoma, int size, double ingresoVentas,int inversionTotal) {
    std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item C" << "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";
    std::cout << "El máximo ingreso por ventas es de: "
            << std::fixed << std::setprecision(2) << ingresoVentas
            << " dolares con una inversion total en publicidad de: "
            << std::fixed << std::setprecision(2) << inversionTotal
            << " dolares.\n";
    std::cout << "Los canales de publicidad que se deben de elegir para obtener el máximo "
            << "ingreso total son: \n";

    for (int i = 0; i < size; i++) {
        if (cromosoma[i]) {
            std::cout << std::setfill(' ') << std::setw(4) << " "
                    << "- Canal " << (i + 1) << " - " << canales[i].canal
                    << ",ingreso = " << canales[i].ingresoPorVentas
                    << " dolares con una inversion publicitaria de "
                    << std::fixed << std::setprecision(2) << canales[i].USD
                    << " dolares\n";
        }
    }
}

void ItemD(Canal *canales, int *cromosoma, int size, int marca, int inversion,double ingreso) {
std::cout << std::setfill('*') << std::setw(30) << "*" << "\n"
            << "Item D" << "\n"
            << std::setfill('*') << std::setw(30) << "*" << "\n";    std::cout << "El nivel máximo de recordación de marca es de " << marca
            << " con una inversion total en publicidad de "
            << std::fixed << std::setprecision(2) << inversion
            << " dolares y un ingreso de "
            << std::fixed << std::setprecision(2) << ingreso << " dolares\n";
    std::cout << "Los canales de publicidad que se deben de elegir para obtener el máximo "
            << "ingreso total son: \n";

    for (int i = 0; i < size; i++) {
        if (cromosoma[i]) {
            std::cout << std::setfill(' ') << std::setw(4) << " "
                    << "- Canal " << (i + 1) << " - " << canales[i].canal
                    << ", recordacion de marca = " << canales[i].nivelDeMarca
                    << ",ingreso = " << canales[i].ingresoPorVentas
                    << " dolares con una inversion publicitaria de "
                    << std::fixed << std::setprecision(2) << canales[i].USD
                    << " dolares\n";
        }
    }
}
