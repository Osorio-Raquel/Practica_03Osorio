// Materia: Programación I, Paralelo 2

// Autor: Raquel Osorio Mamani

// Fecha creación: 05/09/2023

// Fecha modificación: 07/09/2023
 
// Número de ejericio: 10

// Problema planteado: Queremos realizar una encuesta a 10 personas, en esta encuesta indicaremos el sexo (1=masculino, 2=femenino), si trabaja (1=si trabaja, 2= no trabaja) y su
// sueldo (si tiene un trabajo, sino sera un cero) estará entre 600 y 2000 (valor entero). Los valores pueden ser generados aleatoriamente. Calcula y muestra lo siguiente:
// • Porcentaje de hombres (tengan o no trabajo).
// • Porcentaje de mujeres (tengan o no trabajo).
// • Porcentaje de hombres que trabajan.
// • Porcentaje de mujeres que trabajan.
// • El sueldo promedio de las hombres que trabajan.
// • EL sueldo promedio de las mujeres que trabajan

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    double m = 0, f = 0, ht = 0, mt = 0, sph= 0, spm = 0;  //las variables
    int p[10][3];
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0){
                p[i][j] = rand() % (2 - 1 + 1)+ 1 ;
                if (p[i][j] == 1){
                    m+=1;
                }
                if (p[i][j] == 2){
                    f+=1;
                }
            }
            if (j == 1){
                p[i][j] = rand() % (2 - 1 + 1)+ 1 ;
                if (p[i][j] == 1 and p[i][j- 1] == 1){
                    ht+=1;
                }
                if (p[i][j] == 1 and p[i][j- 1] == 2){
                    mt+=1;
                }
            }
            if (j == 2){
                if (p[i][j-1] == 1){
                    p[i][j] = rand() % (2000 - 600 + 1) + 600;
                    if (p[i][j- 1] == 1 and p[i][j-2] == 1){
                        sph+=p[i][j];
                    }
                    if (p[i][j- 1] == 1 and p[i][j-2] == 2){
                        spm+=p[i][j];
                    }
                }
                else{
                    p[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Porcentaje de hombres: " << m * 10 << "%"<< endl;
    cout << "Porcentaje de mujeres: " << f * 10 << "%"<< endl;
    cout << "Porcentaje de hombres con trabajo: " << ht * 10 << "%"<< endl;
    cout << "Porcentaje de mujeres con trabajo: " << mt * 10 << "%"<< endl;
    cout << "Sueldo promedio de hombres que trabajan " << sph/ht << "Bs"<< endl;
    cout << "Sueldo promedio de mujeres que trabajan " << spm/mt << "Bs."<< endl;
    

    return 0;
}