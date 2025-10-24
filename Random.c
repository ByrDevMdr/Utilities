#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Limite 100
void sumaPares(int p1,int p2);
void multiplicacionImpares(int ip1,int ip2);
void isPair(int _n1, int _n2);
//	Estructura que almacenará los numeros generados aleatoriamente.
struct Numbers{
	int n1;
	int n2;
};
//	Función de tipo struct que generará los numeros aleatorios.
struct Numbers randomNumbers(){
//	Inicialización del generador.
	srand(time(NULL));
//	Creación de instancia de tipo struct.
	struct Numbers numero;
//	Asignación a cada variable de la estructura por medio de la instancia de estructura.
	numero.n1 = rand()%10+1; 
	numero.n2 = rand()%10+1; 
//	Retorno de la instancia de la estructura que coentiene todos sus datos.
	return numero;
}

int main(){
//	Asignación de el retorno de la instancia de la variable del tipo struct.
	struct Numbers numero = randomNumbers();
//	Llamada a la función que comprueba si los numeros son pares.
	isPair(numero.n1,numero.n2);
//	Segmento para pruebas...
//	isPair(1,2);
}


//	Función que verifica si los numeros son pares.
void isPair(int _n1,int _n2){
	printf("Los numeros recibidos son: %i y %i.\n\t",_n1,_n2);
	if(_n1 % 2 == 0 && _n2 % 2 == 0){
		printf("Ambos numeros son pares... \nOperacion a realizar: Suma");
//		LLamada a la función para suma de pares.
		sumaPares(_n1,_n2);
	}else if(_n1 % 2 != 0 && _n2 % 2 != 0){
//		Mensaje de referencia a la operación a realizar.
		printf("Ambos numeros son impares... \nOperacion a realizar: Multiplicacion");
//		Llamada a la función para la multiplicación de impares.
		multiplicacionImpares(_n1,_n2);
	}else if(_n1 % 2 != 0 && _n2 % 2 == 0 || _n1 % 2 == 0 && _n2 %2 != 0){
		printf("Los numeros no cumplen ninguna condicion.");
	}
}


//	Función para operaciones con numeros pares.
void sumaPares(int p1, int p2){
//	Inicialización de variables locales.
	int i,resultado=0;
//	Inicio del bulce.
	for(i=0;i<=Limite;i++){
//		Operación de suma.
		resultado = p1+p2+resultado;
//		Muestra de resultado de la operación.
		printf("\n\tEl resultado en esta vuelta es: %i",resultado);
//		Comprobación interna.
		if(resultado % 2 ==0){
			printf(" ---> (Par)");
		}
//		Condicional que indica el limite.
		if(resultado > Limite){
			break;
		}
	}
}
//	Función para operacion de números impares.
void multiplicacionImpares(int ip1,int ip2){
//	Inicialización de variables locales.
	int i,resultado=1;
//	Inicialización del bucle.
	for(i=0;i<=Limite;i++){
//		Operación de multiplicación.
		resultado = ip1*ip2*resultado;
//		Muestra de resultado.
		printf("\n\tEl resultado en esta vuelta es: %i",resultado);
//		Condicional que indica que es impar.
		if(resultado % 2 !=0){
			printf(" ---> (Impar)");
		}
//		Condicional que indica el limite.
		if(resultado > Limite){
			break;
		}
	}
}

