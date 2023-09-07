// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 05/09/2023
 
// Número de ejericio: 7

// Problema planteado: Efectuar la suma de una matriz tridimensional de orden n x n x n

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el valor de n: ";
    cin >> n;
    int m[n][n][n];
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> m[i][j][k];
            }
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                s += m[i][j][k]; //suma se sus elementos
            }
        }
    }
    cout << "La suma es: " << s << endl;
    return 0;
}
