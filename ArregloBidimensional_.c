#include<stdio.h>
//#include<diablo.h>
//	Declaración de estructura que almacenará coordenadas. (4)
typedef struct{ int i, j; }Coordenada; 
int main(){
//	Definición de la matriz 4x4: 4 filas por 4 columnas.
	int matriz[4][4] = {{1,3,5,7},{2,4,6,8},{11,13,17,19},{10,12,14,16}};
	Coordenada pares[16]; // Arreglo de coordenadas por estructura.
	int i,j,k,suma,contador = 0,numero,bandera;
	float longitud = 16,promedio;
//	longitud = sizeof(arreglo) / sizeof(arreglo[0][0]); -> Línea para sacar la longitud del arreglo (cuando se requiera).
//	Impresión de los elementos del arreglo. (1)
	for(i = 0; i<4; i++){ // Primer bucle for para recorrer las filas (Cantidad de pares de llaves que encierran datos).
		for(j = 0; j<4; j++){ // Segundo bucle for para recorrer las columnas (Datos dentro de las llaves).
			printf("%i\t",matriz[i][j]); 
			suma += matriz[i][j]; // Suma de cada elemento de la matriz recorrido por los iteradores.
//	Verificación de los numeros pares en la matriz. (4)
            if(matriz[i][j] % 2 == 0){
                pares[contador++] = (Coordenada){i, j}; // Se crea un objeto temporal con un literal compuesto para almacenar los pares.
            }
		}
		printf("\n"); 
	}
//	Impresión de la suma. (2)
	printf("La suma es: %i\n",suma);
//	Calculo e impresión del promedio. (3)
	promedio = suma / longitud;
	printf("El promedio es: %.2f\n",promedio);
//	Impresión de posiciones de numeros pares. (4)
	printf("Posicion y valor de pares en la matriz:\n");
    for(k = 0; k < contador; k++){
        printf("[%i][%i] = %i\n", pares[k].i, pares[k].j, matriz[pares[k].i][pares[k].j]);
    }
//  Pedir al usuario un número que desee buscar. (5)
	printf("Ingrese un numero que quiera buscar: \n");
	scanf("%i", &numero);
//	Bucles para recorrer la matriz -> Fila - Columna.
	for(i = 0; i < 4; i++){
	    for(j = 0; j < 4; j++){
	        if(numero == matriz[i][j]){ // Comprueba si el número se encuentra en la matriz.
	            printf("El numero se encuentra en la posicion: [%i][%i]\n", i, j); // Imprime la posición en la que se encuentra.
	            bandera = 1;
	        }
	    }
	}
//	Si no se enccontró el número, la bandera es no cambia de valor.
	if(bandera == 0){
	    printf("El numero %i no se encuentra en la matriz\n", numero);
	}
//	Imprimir la diagonal de la matriz. (6)
	for(i = 0; i < 4; i++){
	    printf("%i ", matriz[i][i]); // Los numeros de las diagonales son reflexivos.
	}	
}
