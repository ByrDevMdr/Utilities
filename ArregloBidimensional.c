#include <stdio.h>
//#include<diablo.h>
// Estructura para almacenar coordenadas
typedef struct { int i, j; } Coordenada;
// Prototipos de funciones
int recorrerArreglo(int _matriz[4][4]);
float calcularPromedio(int _suma, int _total);
void buscarNumero(int _matriz[4][4], int _numero);
void mostrarDiagonal(int _matriz[4][4]);
int main() {
//	Definición del arreglo.
    int matriz[4][4] = { {1, 3, 5, 7}, {2, 4, 6, 8}, {11, 13, 17, 19}, {10, 12, 14, 16} };
    int suma, numero;
    float promedio;
//	Función para mostrar elementos del arreglo.
    printf("Elementos de la matriz y números pares:\n");
    suma = recorrerArreglo(matriz);
//	Impresión de la suma total.
    printf("La suma total es: %i\n", suma);
//	Llamada a la función para calcuar promedio.
    promedio = calcularPromedio(suma, 16);
    printf("El promedio es: %.2f\n", promedio);
//	Llamada a la función para busqueda de un número.
    printf("Ingrese el número que desea buscar: ");
    scanf("%i", &numero);
    buscarNumero(matriz, numero);
//  Llamada a la función para imprimir la diagonal principal.
	printf("La diagloal principal es: \n");
    mostrarDiagonal(matriz);
    return 0;
}
//	Funicón para mostrar la matriz y sus pares.
int recorrerArreglo(int _matriz[4][4]) {
    Coordenada pares[16];
    int contador = 0,i,j,k,suma = 0;
//	Bulcles para recorrer filas y columnas.
	for(i = 0; i<4; i++){ // Primer bucle for para recorrer las filas (Cantidad de pares de llaves que encierran datos).
		for(j = 0; j<4; j++){ // Segundo bucle for para recorrer las columnas (Datos dentro de las llaves).
			printf("%i\t",_matriz[i][j]); 
			suma += _matriz[i][j]; // Suma de cada elemento de la matriz recorrido por los iteradores.
//	Verificación de los numeros pares en la matriz. (4)
            if(_matriz[i][j] % 2 == 0){
                pares[contador++] = (Coordenada){i, j}; // Se crea un objeto temporal con un literal compuesto para almacenar los pares.
            }
		}
		printf("\n"); 
	}
//	Impresión de posiciones de numeros pares. (4)
	printf("Posicion y valor de pares en la matriz:\n");
    for(k = 0; k < contador; k++){
        printf("[%i][%i] = %i\n", pares[k].i, pares[k].j, _matriz[pares[k].i][pares[k].j]);
    }
    return suma;
}
//	Función para calcular el promedio.
float calcularPromedio(int _suma, int _total) {
    return (float)_suma / _total;
}
//	Función para buscar un número.
void buscarNumero(int _matriz[4][4], int _numero) {
    int bandera = 0,i,j,k;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (_matriz[i][j] == _numero) {
                printf("El número %i se encuentra en la posición [%i][%i]\n", _numero, i, j);
                bandera = 1;
            }
        }
    }
    if (!bandera) {
        printf("El número %i no se encuentra en la matriz.\n", _numero);
    }
}
//	Función para mostrar la diagonal.
void mostrarDiagonal(int _matriz[4][4]) {
	int i;
	for(i = 0; i < 4; i++){
	    printf("%i ", _matriz[i][i]); // Los numeros de las diagonales son reflexivos.
	}	
}

