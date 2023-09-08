// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fina n.

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Ingrese el valor de N: "<< endl;
    cin >> n;
    int g[n][n];
    cout << "ingrese los valores";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            cin >> g[i][j];
        }
    }
    for(int i = 0; i >= 0; i--){
        for(int j = 0; j < n; j++){ 
            cout << g[n-1][j] << "\t";
        }
        cout <<endl;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){ 
            if (i==n-1){
                cout << g[0][j] << "\t"; // el cambio de linea
            }
            else{
                cout << g[i][j] << "\t";
            }
        }
        cout <<endl;
    }
    return 0;
}
