// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 05/09/2023
 
// Número de ejericio: 8

// Problema planteado: Multiplique dos matrices una de N x M y la otra de M x N
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cout << "Ingrese el numero de filas y columnas: ";
    cin >> N >> M;
    int m[N][M];
    int n[N][M];
    int r[N][M];
    cout << "Ingrese la primera matriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    cout << "Ingrese la segunda matriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> n[i][j];
        }
    }
    for (int i = 0; i < N; i++) { //multiplicar ambas matrices
        for (int j = 0; j < M; j++) {
            r[i][j] = m[i][j] * n[i][j];
        }
    }
    cout << "Resultado:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

