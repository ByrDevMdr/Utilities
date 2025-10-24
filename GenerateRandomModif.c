#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int main(){
//	Variables.
	int contadorPares=0,contadorImpares=0,resultadoSuma=0,resultadoMultiplicacion=1,n1,flagSuma=1,flagMult=1;	
//	Función para generar numeros aleatorios.
	srand(time(NULL));
	printf("Impares\t\t\tPares\n");
//	Bucle que se evalua en base a las banderas.
while (flagSuma == 1 || flagMult == 1) {
//	Generación de números aleatorios.
    n1 = rand() % 10 + 1;
    // Procesar números pares (suma) solo si la suma está activa
    if (flagSuma == 1 && n1 % 2 == 0) {
//    	Elevar al cuadrado cada numero.
    	int cuadrado = pow(n1,2);
        printf("\t\t\t %i --> %i\n", n1,cuadrado);
//      Contador de numeros pares.
        contadorPares++;
//      Aumento de la suma de los numeros.  
        resultadoSuma += n1;
        // Detener la suma si supera 100
        if (resultadoSuma > 100) {
            flagSuma = 0;
        }
    }
    
    // Procesar números impares (multiplicación) solo si la multiplicación está activa
    if (flagMult== 1 && n1 % 2 != 0) {
//    	Generación de la raiz cuadrada de los numeros.
    	float raiz = sqrt(n1);
        printf("%i --> %.2f\n", n1,raiz);
//      Contador de numeros impares.
        contadorImpares++;
//       Acumulación de la multiplicacion entre numeros impares.
        resultadoMultiplicacion *= n1;
        // Detener la multiplicación si supera 100
        if (resultadoMultiplicacion > 100) {
            flagMult = 0;
        }
    }
}
    printf("\n  %i-", contadorImpares);
    printf("%i\t\t|| ", resultadoMultiplicacion);
    printf("\t%i-", contadorPares);
    printf("%i\n", resultadoSuma);
}
