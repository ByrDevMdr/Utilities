#include<stdio.h>
//#include<diablo.h>
//	Prototipo de función para recorrer arreglo con el mismo siendo referenciado con un puntero.
int recorrerArray(int _size, int *_array);
//	Prototipo de función para calcular el promedio de de la suma del arreglo.
float calculoPromedio(float _size, int suma);
//	Prototipo de función para imprimir los números pares del arreglo.
void impresionPar(int _size, int *_array);
//	Prototipo de función para la busqueda de un numero en el arreglo.
void busqueda(int _size, int *_array);
int main(){
//	Definición del arreglo.
	int array[10] = {2,3,4,5,6,7,8,9,10,11};
	int i,suma,numero,flag=0;
	float promedio,size;
//	Sacar la distancia de forma automática (buena práctica para evitar el hardcoding y hacer un código más dinámico).
	size = sizeof(array)/sizeof(array[0]);
//	Llamada a la función para recorrer el arreglo y mostrarlo junto con su suma.
	suma = recorrerArray(size, array); 
	printf("\nLa suma de todos los elementos es: %i\n", suma);
//	Llamada a la función para el calculo e impresión del promedio.
	printf("El promedio es: %.2f\n", calculoPromedio(size,suma));
//	Llamada a la función para impresión de los números pares.
	impresionPar(size,array);
//	Pedir al usuario el numero que quiere buscar.
	busqueda(size, array);
}
//	Función para recorrer el arreglo.
int recorrerArray(int _size,int *_array){
	int suma,i,size = _size;
	printf("\tIndice\t\tValor\n");
	for(i = 0; i < size;i++){
		printf("\t  %i\t\t  %i\n",i,_array[i]);
		suma += _array[i]; 
	}
	return suma;
}
//	Función para el calculo del promedio.
float calculoPromedio(float _size, int suma){
	float promedio;
//	printf("La suma es: %i",suma);
	promedio = suma/_size;
	return promedio;
}
//	Función para imprimir los números pares del arreglo.
void impresionPar(int _size,int *_array){
	int i;
	for(i = 0;i < _size;i++){
		if(_array[i] % 2 == 0){
			printf("%i, ",i);
		}
	}
}
//	Función para la busqueda de un número en el arreglo.
void busqueda(int _size, int *_array){
	int numero,flag,i;
		do{
		printf("\nIngrese el numero que desee buscar: ");
		scanf("%i",&numero);
//	Se inicializa la bancera en 0.
        flag = 0;
		for(i = 0; i < _size; i++){
//	Solo ejecuta la busqueda si la bandera sigue siendo 0.
            if (flag == 0) { 
                if(_array[i] == numero){
                    printf("El numero se ha bandera en la posicion: %i\n",i);
                    flag = 1; // El número fue bandera y saldrá de bucle.
                }
            }
		}
//	Si después de revisar todo el array, la bandera sigue siendo 0, no se encontró.
        if (flag == 0) {
            printf("El numero no se encontro. Intente de nuevo.\n");
        }
	}while(flag != 1); 
}

