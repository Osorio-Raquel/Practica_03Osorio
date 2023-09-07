// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 05/09/2023
 
// Número de ejericio: 6

// Problema planteado: Generar una matriz NxN, que se llene con la serie de Fibonacci.

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Ingrese N: ";
    cin >> N;
    long long m[N][N];
    long long x = 0, y = 1;
    for (int i = 0; i < N; i++) { // llena la matriz co fibonacci
        for (int j = 0; j < N; j++) {
            m[i][j] = x;
            long long s = x + y;
            x = y;
            y = s;
        }
    }
    cout << "Matriz con la serie de fibonacci:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
