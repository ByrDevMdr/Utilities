3#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
class Dado {
private:
    int valor;
public:
    Dado() : valor(1) {}
    void lanzar() {
        valor = rand() % 6 + 1;
    }
    int getValor() const {
        return valor;
    }
    void mostrarCara() const {
        switch (valor) {
            case 1:
                cout << "+-------+\n";
                cout << "¦       ¦\n";
                cout << "¦   *   ¦\n";
                cout << "¦       ¦\n";
                cout << "+-------+\n";
                break;
            case 2:
                cout << "+-------+\n";
                cout << "¦  *    ¦\n";
                cout << "¦       ¦\n";
                cout << "¦    *  ¦\n";
                cout << "+-------+\n";
                break;
            case 3:
                cout << "+-------+\n";
                cout << "¦  *    ¦\n";
                cout << "¦   *   ¦\n";
                cout << "¦    *  ¦\n";
                cout << "+-------+\n";
                break;
            case 4:
                cout << "+-------+\n";
                cout << "¦ *   * ¦\n";
                cout << "¦       ¦\n";
                cout << "¦ *   * ¦\n";
                cout << "+-------+\n";
                break;
            case 5:
                cout << "+-------+\n";
                cout << "¦ *   * ¦\n";
                cout << "¦   *   ¦\n";
                cout << "¦ *   * ¦\n";
                cout << "+-------+\n";
                break;
            case 6:
                cout << "+-------+\n";
                cout << "¦ *   * ¦\n";
                cout << "¦ *   * ¦\n";
                cout << "¦ *   * ¦\n";
                cout << "+-------+\n";
                break;
        }
    }
};
class Cubilete {
private:
    Dado dados[5];
public:
    void lanzar() {
        cout << "\nLanzando los dados...\n\n";
        for (int i = 0; i < 5; i++) {
            dados[i].lanzar();
            cout << "Dado " << i + 1 << " (" << dados[i].getValor() << "):\n";
            dados[i].mostrarCara();
        }
    }
    string analizarResultados() const {
        int conteo[7] = {0};
        for (int i = 0; i < 5; i++) {
            conteo[dados[i].getValor()]++;
        }
        sort(conteo, conteo + 7, greater<int>());
        if (conteo[0] == 5) return "Pokarin (quintilla)";
        if (conteo[0] == 4) return "Poker";
        if (conteo[0] == 3 && conteo[1] == 2) return "Full";
        if (conteo[0] == 3) return "Tercia";
        if (conteo[0] == 2 && conteo[1] == 2) return "Dos pares";
        if (conteo[0] == 2) return "Par";
        return "Nada (sin combinacion)";
    }
};
int main() {
    srand(time(0));
    Cubilete juego;
    int opcion;

    do {
        cout << "\n--- MENU CUBILETE ---\n";
        cout << "1. Lanzar cubilete\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            juego.lanzar();
            cout << "\nCombinacion: " << juego.analizarResultados() << "\n";
        } else if (opcion == 2) {
            cout << "Gracias por jugar!! Hasta la proxima\n";
        } else {
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 2);

    return 0;
}

