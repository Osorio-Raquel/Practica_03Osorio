// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 05/09/2023
 
// Número de ejericio: 3

// Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
// • La suma de la última columna
// • El producto total de la última fila
// • Obtener el mayor valor y su posición
// • Obtener la desviación estándar de todos los elementos de la matriz

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int n, A, B;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;
    cout << "Ingrese el limite inferior: ";
    cin >> A;
    cout << "Ingrese el limite superior: ";
    cin >> B;
    srand(time(0));
    int m[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rand() % (B - A + 1) + A;
        }
    }
    cout << "Matriz ----------------------------------.------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    int s = 0; //la suma
    for (int i = 0; i < n; i++) {
        s += m[i][n - 1];
    }
    int p = 1;//la multiplivavion
    for (int j = 0; j < n; j++) {
        p *= m[n - 1][j];
    }
    int g = m[0][0];//las coordenadas
    int q = 0, f = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] > g) {
                g = m[i][j];
                q = i;
                f = j;
            }
        }
    }
    double se = 0;
    double sc = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            se += m[i][j];
            sc += pow(m[i][j], 2);
        }
    }
    double med = se / (n * n);
    double S = sqrt((sc / (n * n)) - pow(med, 2));//formula de la desvciacion
    cout << "La suma de la ultima columna: " << s << endl;
    cout << "Producto total de la ultima fila: " << p << endl;
    cout << "El mayor valor es " << g << " y se encuentra en la posicion (" << q+ 1 << ", " << f+ 1 << ")." << endl;
    cout << "Desviacion estandar de todos los elementos de la matriz: " << S << endl;

    return 0;   
}
