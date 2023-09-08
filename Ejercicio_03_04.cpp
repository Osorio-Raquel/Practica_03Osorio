// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 4

// Problema planteado: En la segunda temporada de The Walking Dead, los personajes llegaron a una cárcel para refugiarse. La cárcel estaba rodeada de vallas por lo que los muertos
// vivientes no podían entrar en ella. Sin embargo, dentro de las instalaciones aun existían muertos vivientes que amenazaban a los personajes. Por tanto, Rick y
// otros miembros del grupo decidieron ir a investigar las instalaciones con el fin de determinar cuáles eran los lugares seguros. Para lograr su objetivo construyeron un mapa 
// basado en una matriz que indicaba las zonas seguras. Después de un tiempo, tu grupo llega al mismo complejo y encuentra el mapa hecho por Rick. Para mantener a salvo a tus amigos decides 
// diseñar e implementar un programa que te ayude a determinar las zonas seguras. 

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

const int f = 3;
const int col = 4;
void fa(const char m[f][col]) {
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
void b(const char m[f][col], int& fs, int& cs) {
    fs = 0;
    cs = 0;
    for (int i = 0; i < f; i++) {
        bool t = false;
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 'x') {
                t = true;
                break;
            }
        }
        if (!t) {
            fs++;
        }
    }
    for (int j = 0; j < col; j++) {
        bool t = false;
        for (int i = 0; i < f; i++) {
            if (m[i][j] == 'x') {
                t = true;
                break;
            }
        }
        if (!t) {
            cs++;
        }
    }
}
void c(const char m[f][col], vector<int>& fz, vector<int>& cz) {
    fz.clear();
    cz.clear();
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 'x') {
                fz.push_back(i);
                cz.push_back(j);
            }
        }
    }
}
int d(const char m[f][col]) {
    int tz = 0;

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < col; j++) {
            if (m[i][j] == 'x') {
                tz++;
            }
        }
    }
    return tz;
}
bool e(const char m[f][col]) {
    int zombieCount = 0;

    for (int i = 0; i < f; i++) {
        if (m[i][0] == 'x') {
            zombieCount++;
            if (zombieCount >= 2) { // 2 mas xombies en la primera columna
                return true; 
            }
        }
    }
    return false;
}
int main() {
    srand(time(0));
    char r[f][col];
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < col; j++) {
            r[i][j] = (rand() % 2 == 0) ? 'o' : 'x';
        }
    }
    cout << "a) Mostrar la matriz que describe el área. " << endl;
    fa(r);
    int fs, cs;
    b(r, fs, cs);
    cout << "b) Mostrar el número de filas que no tienen un muerto viviente. " << fs << endl;
    cout << "Mostrar el número columnas que no tienen un muerto viviente. " << cs << endl;
    vector<int> fz, cz;
    c(r, fz, cz);
    cout << "c)  Determinar las coordenadas de los muertos vivientes en la matriz." << endl;
    for (size_t i = 0; i < fz.size(); i++) {
        cout << "   (" << fz[i] << ", " << cz[i] << ")" << endl;
    }
    int tz = d(r);
    cout << "d) Cantidad total de muertos vivientes: " << tz << std::endl;
    cout << "e) ";
    if (e(r)) {
        cout << "No es posible entrar al complejo" << endl;
    } else {
        cout << "Es posible entrar al complejo" << endl;
    }
    return 0;
}
