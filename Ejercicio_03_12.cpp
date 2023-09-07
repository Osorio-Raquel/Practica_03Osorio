// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 12

// Problema planteado: Ingresa una matriz de NxN y a continuación:
// a. Elimine una fila ingresada por el usuario.
// b. Elimine una columna ingresada por el usuario.
// c. Inserte una fila por un valor determinado por el usuario.
// d. Inserte una columna por un valor determinado por el usuario.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int rnd(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void smX(const vector<vector<int>>& mat) {
    for (size_t i = 0; i < mat.size(); i++) {
        for (size_t j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int N;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> N;
    vector<vector<int>> M(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] = rnd(1, 100);
        }
    }
    cout << "Matriz:" << endl;
    smX(M);
    int fe, ce;
    cout << "Ingrese el numero de fila a eliminar: ";
    cin >> fe;
    if (fe < 1 || fe > N) {
        cout << "Fila no valida" << endl;
        return 1;
    }
    cout << "Ingrese el numero de columna a eliminar: ";
    cin >> ce;
    if (ce < 1 || ce > N) {
        cout << "Columna no valida"<< endl;
        return 1;
    }
    M.erase(M.begin() + fe - 1);
    for (size_t i = 0; i < M.size(); i++) {
        M[i].erase(M[i].begin() + ce - 1);
    }
    cout << "Matriz:" << endl;
    smX(M);
    int fi, vi;
    cout << "Ingrese el numero de fila donde desea insertar: ";
    cin >> fi;
    if (fi < 1 || fi > N - 1) {
        cout << "Fila no valida" << endl;
        return 1;
    }
    cout << "Ingrese el valor para la nueva fila: ";
    cin >> vi;
    vector<int> nf(N - 1, vi);
    M.insert(M.begin() + fi - 1, nf);
    cout << "Matriz:" << endl;
    smX(M);
    int ci;
    cout << "Ingrese el numero de columna donde desea insertar: ";
    cin >> ci;

    if (ci < 1 || ci > N - 1) {
        cout << "Columna no valida" << endl;
        return 1;
    }
    for (size_t i = 0; i < M.size(); i++) {
        M[i].insert(M[i].begin() + ci - 1, vi);
    }
    cout << "Matriz:" << endl;
    smX(M);

    return 0;
}

