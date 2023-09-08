// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 5

// Problema planteado: Generar la matriz para un orden NxN
// Sea n=5
// 1 2 3 4 5
// 3 4 5 6 7
// 5 6 7 8 9
// 7 8 9 10 11
// 9 10 11 12 13

#include <iostream>

using namespace std;

int main()
{
    int n, c=1;
    cin >> n ;
    int a[n][n];
    for (int i = 0; i < n; i++){
        for (int j =0; j < n; j++){
            if (i==0){
                a[i][j] =c;
                c++;
            }
            else{
                if (j == 0){
                    c = a[i-1][n/2]; // tomo l valor de el medio
                }
                a[i][j] =c;
                c++;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j =0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
