#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
//#define Limite 100
#define Oportunidades 5
//	Prototipos de funciones.
void generar_abecedario();
void reloj_digital();
void numeros_primos();
int generar_numero_random();
void evaluar(int numero_ingresado,int numero_random);
//	Variables auxiliares que indican estados.
int flag = 1,flag_evaluate = 1;
//	Variables secundarias para proceso dentro del programa.
int i,j,contador=0;
//	Constante del limite para el calculo de los numeros primos.
const int Limite = 100;
int main(){
	int num_ing,num_random;
	
//	generar_abecedario();
//	
//	do{
//		system("cls");
//		reloj_digital();
//		sleep(1);
//	}while(flag != 0);

//	numeros_primos(Limite);

	num_random = generar_numero_random();
	do{
		printf("%i\n\t",num_random);
		printf("Ingrese el numero a adivinar (entre 1 y 50): ");
		scanf("%i",&num_ing);
		evaluar(num_ing,num_random);
		printf("\nOportunidades restantes: %i\n",Oportunidades-contador);
//	Condición que indica que el programa ha temrinado (ha evaluado).
		if(flag_evaluate == 0){
			break;
		}
	}while(contador != Oportunidades);
}

//	Función para evaluar el numero ingresado y el numero generado aleatoriamente como argumentos.
void evaluar(int numero_ingresado,int numero_random){
//	Verifica si el numero ingresado por el usuario es menor que el random.
	if(numero_ingresado < numero_random){
		printf("El numero ingresado es menor que el numero digitado.");
//	El contador (variable global), aumenta en uno si es así.
		contador ++;
	}else if(numero_ingresado == numero_random){
		printf("Ha usted adivinado!!");
		flag_evaluate = 0;
	}
}
//	Función para generar un numero aleatorio del 1 - 50.
int generar_numero_random(){
//	Variable para almacenar el numero aleatorio.
	int nRand;
//	Indicador para generar un numero aleatorio.
	srand(time(NULL));
//	Generador de numero aleatorio.
	nRand = rand()%50+1;
//	Retorno del numero generado.
	return nRand;
}
//	Función para los números impares del 1 - 100.
void numeros_primos(int Limite){
	int esPrimo;
    for (i = 2; i <= Limite; i++) { 
        esPrimo = 1;
//	Se verifica el cociente.
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                esPrimo = 0; 
                break;
            }
        }
//	Si esPrimo sigue siendo 1, imprimir el número.
        if (esPrimo == 1) {
            printf("El numero %i es primo\n", i);
        }
    }
}
//	Función para el reloj digital.
void reloj_digital(){
	time_t rawtime;
    struct tm *info_tiempo;
    // Obtiene la hora actual del sistema.
    time(&rawtime);
    info_tiempo = localtime(&rawtime);   
    // Formatea e imprime la hora.
    printf("Hora actual: %s\n", asctime(info_tiempo));
}
//	Función para generar abecedario.
void generar_abecedario() {
    int mayuscula = 'A'; // Carácter 'A' en ASCII es 65
    int minuscula = 'a'; // Carácter 'a' en ASCII es 97
	printf("** Generando abecedario **\n");
    for (i = 0; i < 26; i++) {
        printf("%c%c ", mayuscula + i, minuscula + i);
    }
    printf("\n");
}
