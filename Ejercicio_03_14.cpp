// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 14

// Problema planteado: Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones por departamento y existirá N candidatos.
// El programa debe pedir la cantidad de votos por departamento y candidato y almacenarlos en una matriz.
// El programa debe calcular lo siguiente:
// • Si un candidato gana con el 50% + 1 voto es ganador absoluto.
// • Si no ningún candidato que logre el 50% + 1 voto el programa debe sacar los dos mas votados para una segunda vuelta.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cout << "numero de candidatos: ";
    cin >> N;
    if (N <= 0) {
        cout << "no valido" << endl;
        return 1;
    }
    int D; 
    cout << "Ingrese la cantidad de departamentos: ";
    cin >> D;
    if (D <= 0) {
        cout << "no valido" << endl;
        return 1;
    }
    vector<vector<int>> v(D, vector<int>(N, 0)); //almacenar los datos

    for (int i = 0; i < D; i++) {
        cout << "departamento " << i + 1 << endl;
        for (int j = 0; j < N; j++) {
            cout << "Ingrese la cantidad de votos: ";
            cin >> v[i][j];
        }
    }
    vector<int> tot(N, 0);
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < N; j++) {
            tot[j] += v[i][j];
        }
    }
    int u = 0;
    for (int i = 0; i < N; i++) {
        u += tot[i];
    }
    int x = -1;
    for (int i = 0; i < N; i++) {
        if (tot[i] > u / 2) {
            x = i + 1;
            break;
        }
    }
    if (x != -1) {
        cout << "El candidato " << x << " ha ganado con mayoría absoluta." << endl;
    } else {
        int p = -1, o = -1;
        int vo = -1, vp = -1;
        for (int i = 0; i < N; i++) {
            if (tot[i] > vo) {
                o = p;
                vp = vo;
                p = i + 1;
                vo = tot[i];
            } else if (tot[i] > vp) {
                o = i + 1;
                vp = tot[i];
            }
        }
        cout << "Se requiere una nueva votacion entre " << p << " y " << o << "." << endl;
    }
    return 0;
}
