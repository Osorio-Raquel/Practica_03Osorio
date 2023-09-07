// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 05/09/2023
 
// Número de ejericio: 2

// Problema planteado: Generar la matriz espiral para un orden n.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese n: ";
    cin >> n;

    int m[n][n]; 
    char s = 'd'; // s es el sentido

    int x = 0, y = n - 1, w = 0, v = n - 1, c = 1;

    while (x <= y && w <= v) {
        if (s == 'd') {
            for (int i = w; i <= v; i++) m[x][i] = c++;
            x++;
        } else if (s == 'b') {
            for (int i = x; i <= y; i++) m[i][v] = c++;
            v--;
        } else if (s == 'i') {
            for (int i = v; i >= w; i--) m[y][i] = c++;
            y--;
        } else if (s == 'a') {
            for (int i = y; i >= x; i--) m[i][w] = c++;
            w++;
        }
        s = (s == 'd') ? 'b' : (s == 'b') ? 'i' : (s == 'i') ? 'a' : 'd';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
