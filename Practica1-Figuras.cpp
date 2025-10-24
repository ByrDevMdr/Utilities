#include <iostream>
#include<limits>
using namespace std;
//	Funci�n para dibujar el cuadrado siendo el argumento el tama�o.
void dibujarCuadroCompleto(int n) {
//	Bucle que se ejecuta y "pinta" las filas del cuadrado.
    for (int i = 0; i < n; i++) {
//  Segundo bucle para "pintar" las filas del cuadrado.
        for (int j = 0; j < n; j++) {
//	"Pintar�" los asteriscos con un espacio.
            cout << "* ";
        }
//	Pasar� un renglon con el "endl".
        cout << endl;
    }
}
//	Funci�n para el contorno del cuadrado.
void dibujarContornoCuadrado(int n) {
//	Imprime las filas.
    for (int i = 0; i < n; i++) {
//   Imprime columnas.
        for (int j = 0; j < n; j++) {
//   Imprime las columnas bajo la condici�n del recorrido.
            if (i == 0 || i == n-1 || j == 0 || j == n-1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar el tri�ngulo superior izquierdo.
void dibujarTrianguloSupIzq(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar el tri�ngulo superior derecho.
void dibujarTrianguloSupDer(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < n - i - 1)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar el tri�ngulo inferior izquierda.
void dibujarTrianguloInfIzq(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar el triangulo inferior derecho.
void dibujarTrianguloInfDer(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar la diagonal derecha.
void dibujarDiagonalIzqDer(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar la diagonal izquierda.
void dibujarDiagonalDerIzq(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
//	Funci�n para dibujar la cruz.
void dibujarCruzX(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}
int main() {
//	Variables para el tama�o y la bifurcaci�n.
    int opcion, tamanio;
//	Bucle do para realizar impresi�n del men�.
    do {
//  Men� de opciones.
        cout << "\n\t\tMENU" << endl;
        cout << "\t1.- Cuadro completo" << endl;
        cout << "\t2.- Contorno del cuadrado" << endl;
        cout << "\t3.- Triangulo superior izquierdo" << endl;
        cout << "\t4.- Triangulo superior derecho" << endl;
        cout << "\t5.- Triangulo inferior izquierdo" << endl;
        cout << "\t6.- Triangulo inferior derecho" << endl;
        cout << "\t7.- Diagonal de izquierda a derecha \\" << endl;
        cout << "\t8.- Diagonal de derecha a izquierda /" << endl;
        cout << "\t9.- Cruz X" << endl;
        cout << "\t10.- Salir" << endl;
        cout << "Seleccione una opcion: ";
//        cin >> opcion;
//	Verifica que la opci�n no sea una letra.
		while (!(cin >> opcion)) {
            cout << "Error: Por favor ingrese un numero valido." << endl;
            cin.clear(); // Limpiar el estado de error.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descartar� entrada incorrecta.
        }
//	Verifica si el numero est� en el rango deseado.
        if (opcion >= 1 && opcion <= 9) {
            cout << "Ingrese el tama�o: ";
            // Validar entrada para tama�o.
            while (!(cin >> tamanio) || tamanio <= 0) {
                cout << "Error: Ingrese proporciones validas, (mayor que 0)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingrese las proporciones: ";
            }
        }
//  Bloque de la bifurcaci�n.
        switch (opcion) {
            case 1:
                dibujarCuadroCompleto(tamanio);
                break;
            case 2:
                dibujarContornoCuadrado(tamanio);
                break;
            case 3:
                dibujarTrianguloSupIzq(tamanio);
                break;
            case 4:
                dibujarTrianguloSupDer(tamanio);
                break;
            case 5:
                dibujarTrianguloInfIzq(tamanio);
                break;
            case 6:
                dibujarTrianguloInfDer(tamanio);
                break;
            case 7:
                dibujarDiagonalIzqDer(tamanio);
                break;
            case 8:
                dibujarDiagonalDerIzq(tamanio);
                break;
            case 9:
                dibujarCruzX(tamanio);
                break;
            case 10:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
//  Condici�n que hace que se repita el bucle.
    } while (opcion != 10);
    return 0;
}
