// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 11

// Problema planteado: Realizar el típico juego del 3 en raya, donde habrá dos jugadores que tengan que hacer el 3 en raya, los signos serán el X y el O, cuando haya una posición vacía
// habrá un – El tablero de juego, será una matriz de 3×3 de char.
// El juego termina cuando uno de los jugadores hace 3 en raya o si no hay más posiciones que poner.
// El juego debe pedir las posiciones donde el jugador actual quiera poner su marca, esta debe ser validada y por supuesto que no haya una marca ya puesta.
// Por último mostrar la matriz del juego y muestra al ganador.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
void tab(char t[3][3]) {
    cout << "Comenzamos!" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            if (t[i][j] == 'X') {
                cout << "X ";
            } else if (t[i][j] == 'O') {
                cout << "O ";
            } else {
                cout << "  "; // Espacio en blanco para cuando es vacio
            }
            cout << "| ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}
bool g(char t[3][3], char j) {
    for (int i = 0; i < 3; i++) {
        if (t[i][0] == j && t[i][1] == j && t[i][2] == j) {
            return true;
        }
        if (t[0][i] == j && t[1][i] == j && t[2][i] == j) {
            return true; 
        }
    }
    if (t[0][0] == j && t[1][1] == j && t[2][2] == j) {
        return true; 
    }
    if (t[0][2] == j && t[1][1] == j && t[2][0] == j) {
        return true; 
    }
    return false;
}

void e(char t[3][3], char A) {
    int fila, columna;
    do {
        fila = rand() % 3;
        columna = rand() % 3;
    } while (t[fila][columna] != '-');
    
    t[fila][columna] = A;
}

int main() {
    srand(time(0));
    char t[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    char A = 'X';
    int O = 0;
    while (O < 9) {
        cout << "Tu turno!!" << A << endl;
        if (A == 'X') {
            tab(t);
            int fila, columna;
            cout << "Elije una casilla del 1 al 9!: ";
            int eleccion;
            cin >> eleccion;
            fila = (eleccion - 1) / 3;
            columna = (eleccion - 1) % 3;
            if (fila < 0 || fila > 2 || columna < 0 || columna > 2 || t[fila][columna] != '-') {
                cout << "Intente de nuevo." << endl;
                continue;
            }
            t[fila][columna] = A;
        } else {
            e(t, A);// Llamo a la maquina
            tab(t);
        }
        if (g(t, A)) {
            tab(t);
            if (A == 'X') {
                cout << "Ganaste!" << endl;
            } else {
                cout << "Perdiste :c" << endl;
            }
            break;
        }
        A = (A == 'X') ? 'O' : 'X';
        O++;
    }
    if (O == 9) {
        tab(t);
        cout << "Empate ^-^" << endl;
    }
    
    return 0;
}