// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 9

// Problema planteado: Traspones una matriz de N x M 
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cout << "Ingrese el numero de filas: ";
    cin >> N;
    cout << "Ingrese el umero de columnas: ";
    cin >> M;
    int m[N][M];

    cout << "Ingrese la matriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> m[i][j];
        }
    }
    int t[M][N];
    for (int i = 0; i < M; i++) { //dotos de la transpuesta
        for (int j = 0; j < N; j++) {
            t[i][j] = m[j][i];
        }
    }
    cout << "Matriz transpuesta:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
