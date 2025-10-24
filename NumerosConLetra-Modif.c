#include <stdio.h>
#include <string.h>
#include <windows.h>
// Prototipo de funciones.
int solicitarNumero();
void convertirALetras(int numero);
void mostrarCentenas(int centena, int decena, int unidad);
void mostrarDecenasYUnidades(int decena, int unidad);

// Arrays bidimensionales globales.
char unidades[10][10] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
char decenas[10][15] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
char especiales[10][15] = {"", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
char centenas[10][15] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

int main() {
	int flag = 1,i;
	do{
	    int numero = solicitarNumero();
	    convertirALetras(numero);
		printf("\n\tDesea continuar? \n\t Ingrese el numero 1 para seguir. || Ingrese el numero 0 para salir: ");
		scanf("%i",&flag);
	}while(flag != 0);
    return 0;
}

// Función para solicitar número con validación y retorno del mismo numero.
int solicitarNumero() {
    int num;
    do {
    	Sleep(200);
    	system("cls");
        printf("Ingrese un número entre 1 y 999: ");
        scanf("%d", &num);
    } while (num < 1 || num > 999);
    return num;
}

// Función principal de conversión.
void convertirALetras(int numero) {
//    if (numero == 100) {
//        printf("cien");
//        return;
//    }
    
    int centena = numero / 100;
    int decena = (numero % 100) / 10;
    int unidad = numero % 10;    
//    printf("Las centenas de este numero son: %i\n",centena);
//    printf("Las decenas de este numero son: %i\n",decena);
//    printf("Las unidades de este numero son: %i\n",unidad);
    mostrarCentenas(centena, decena, unidad);
    mostrarDecenasYUnidades(decena, unidad);
}

// Función para mostrar decenas y unidades
void mostrarDecenasYUnidades(int decena, int unidad) {
    if (decena == 1 && unidad > 0) {
        // Números especiales (11-19)
        printf("%s", especiales[unidad]);
    } else {
        // Decenas normales
        if (decena > 0) {
            // Caso especial: veinte -> veinti
            if (decena == 2 && unidad > 0) {
                printf("veinti");  // Impresión de la forma modificada de la decena por 2.
            } else {
                printf("%s", decenas[decena]);  // Forma normal de la decena por 2.
            }
            // Mostrar "y" solo para decenas que no son 2 con unidades
            if (unidad > 0 && decena != 2) {
                printf(" y ");
            }
        }
        // Unidades
        if (unidad > 0) {
            printf("%s", unidades[unidad]);
        }
    }
}

// Función para mostrar las centenas
void mostrarCentenas(int centena, int decena, int unidad) {
    if(centena == 1 && unidad == 0 && decena == 0){
    	printf("cien");
		centena = 0;	;
	}
    if (centena > 0) {
        printf("%s", centenas[centena]);
        if (decena > 0 || unidad > 0) {
            printf(" ");
        }
    }
}
