// Lupi.Giuliano.ANCORA_MATRICI.cpp
//

#include <iostream>
#define max 100
using namespace std;
int dimensionamento(int matrice[max][max]) {
    int grandezza = 2;
    do {
        if (grandezza<1 || grandezza>max) { cout << "Inserisci un numero comreso fra " << 1 << " e " << max<<endl; }
        cout << "Quanto vuoi grande la matrice?: ";
        cin >> grandezza;
    } while (grandezza<1 || grandezza>max);
    return grandezza;
}
void caricaMatrice(int matrice[max][max], int grandezza) {
    for (int i = 0; i < grandezza; i++) {
        for (int j = 0; j < grandezza; j++) {
            cout << "Inserisci l'elemento della " << i + 1 << " riga e della " << j + 1 << " colonna: ";
            cin >> matrice[i][j];
            cout << endl;
        }
        cout << endl;
    }
}
int sommaDiagonale (int matrice[max][max], int grandezza) {
    int cont = 0;
    for (int i = 0; i < grandezza; i++) {
         cont += matrice[i][i];
    }
    return cont;
}
int sommadiagonale(int matrice[max][max], int grandezza) {
    int cont = 0;
    for (int i = 0; i < grandezza; i++) {
         cont += matrice[i][grandezza-i-1];
    }
    return cont;
}

bool simmetria(int matrice[max][max], int grandezza) {
    for (int i = 0; i < grandezza; i++) {
        for (int j = 0; j < grandezza; j++) {
            if (matrice[i][j] != matrice[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void visualizza(int matrice[max][max], int grandezza) {
    cout << endl;
    for (int i = 0; i < grandezza; i++) {
        for (int j = 0; j < grandezza; j++) {
            cout << matrice[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{
    int matrice[max][max];
    int grandezza=dimensionamento(matrice);
    caricaMatrice(matrice,grandezza);
    if (grandezza == 1) { cout << "L'elemento della matrice è " << sommaDiagonale(matrice, grandezza); }
    else {
        visualizza(matrice, grandezza);
        cout << "La somma degli elementi della diagonale principale \x8a " << sommaDiagonale(matrice, grandezza) << endl;
        cout << "La somma degli elementi della diagonale secondarie \x8a " << sommadiagonale(matrice, grandezza) << endl;
        if (simmetria(matrice, grandezza)) { cout << "La matrice \x8a simmetrica\n"; }
        else { cout << "La matrice non \x8a simmetrica"; }
    }
   
    //return 0;
}
