// En el siguiente codigo se generara un cuadrado magico dentro del parametro  
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "ingrese el tamaño: " ;
    cin >>n;
    int ms[n][n];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ms[i][j]=0;
        }
    }
    int f = 0, c = n / 2, x = 1;
    while (x <= n * n) {
        ms[f][c] = x;
        x++;
        int nf = (f - 1 + n) % n;
        int nc = (c + 1) % n;
        if (ms[nf][nc] != 0) {
            f = (f + 1) % n;
        }
        else {
            f = nf;
            c = nc;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ms[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


