// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 13

// Problema planteado: La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un año entero de cada sucursal y calcule:
// a. Total, de ventas
// b. Total, de ventas por sucursal.
// c. Sucursal que más ha vendido.
// d. Sucursal que menos ha vendido.

#include <iostream>

using namespace std;

int main() {
    int N; 
    cout << "Ingrese la cantidad de sucursales: ";
    cin >> N;
    if (N <= 0) {
        cout << "no valido" << endl;
        return 1; // regressar a un numero valido
    }
    int a = 0, b = -1, c = -1, d = 99999, e = -1;
    for (int i = 0; i < N; i++) {
        int y = 0;
        cout << "Sucursal " << i + 1 << ":" << endl;
        for (int j = 0; j < 12; j++) {
            int x;
            cout << "Ingrese las ventas del mes " << j + 1 << ": ";
            cin >> x;
            y += x;
            a += x;
        }
        if (y > b) {
            b = y;
            c = i + 1;
        }
        if (y < d) {
            d = y;
            e = i + 1;
        }
    }
    cout << "Total: " << a << endl;
    cout << "La sucursal que más ha vendido:  " << c << " con " << b << " ventas" << endl;
    cout << "La sucursal que menos ha vendido: l " << e << " con " << d << " ventas" << endl;

    return 0;
}

