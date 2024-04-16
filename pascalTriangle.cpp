// imprimir un triangulo de pascal
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string rowInput;
string numbers = "0123456789";
unsigned int rows = 0;
void getRows() {
    bool isvalid = false;
    while (isvalid == false) {
        cout << "Introduzca el numero de filas\n";
        getline(cin, rowInput);
        bool check = false;
        for (int i = 0; i < rowInput.length(); i++) {
            check = false;
            for (int e = 0; e < 10; e++) {
                if (rowInput[i] == numbers[e]) {
                    check = true;
                }
            }
            if (!check) {
                break;
            }
        }
        if (!check) {
            continue;
        }
        else {
            isvalid = true;
        }
    }
    stringstream ss;
    ss << rowInput;
    ss >> rows;
}
void drawTriangle() {
    unsigned int lastRow[rows]{};
    unsigned int thisRow[rows]{};
    for (unsigned int i = 1; i <= rows; i++) {
        for (unsigned int e = 1; e <= i; e++) { // calcular fila
            if (e == 1 || e == i) {
                thisRow[e] = 1;
            }
            else {
                thisRow[e] = (lastRow[e - 1] + lastRow[e]);
            }
        }
        for (unsigned int e = 1; e <= i; e++) { // imprimir fila con formato pirámide
            if (e == 1 && e == i) {             // caso especial para primera fila donde el primer número es también el último
                for (unsigned int n = 1; n <= (rows - i); n++) {
                    cout << " ";
                }
                cout << thisRow[e] << "\n";
            }
            else if (e == 1) {
                for (unsigned int n = 1; n <= (rows - i); n++) { // agregar tantos espacios como la diferencia entre las filas totales y la fila actual
                    cout << " ";
                }
                cout << thisRow[e] << " ";
            }
            else if (e == i) {
                cout << thisRow[e] << "\n";
            }
            else {
                cout << thisRow[e] << " ";
            }
        }
        for (unsigned int e = 1; e <= i; e++) { // mover los valores de la fila actual a lastRow para usarlos en la próxima
            lastRow[e] = thisRow[e];
        }
    }
    cout << "done\n";
}
int main() {
    getRows();
    drawTriangle();
    system("pause");
    return 0;
}