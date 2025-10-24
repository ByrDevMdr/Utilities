#include<stdio.h>
#include<string.h>
void arregloUnidimensional();
void arregloBidimensional();
//	Estructura sin usar el typedef.
struct Persona{
	char nombre[10];
	int edad;
	float altura;
};
//	Estructura usando el typedef (alumno).
typedef struct{
	char nombre[10];
	int edad;
	float altura;	
}Alumno;
//	Función con arreglo como argumento.
void lectura(int *array, int size);
//	Función coon matriz como argumento.
void lecturaB(int (*matriz)[3], int filas);
//	Estructura para leer (animal).
typedef struct{
	char especie[20];
	int edad;
}Animal;
//	Prototipo de la función para actualizar los datos.
Animal actualizarDatos(Animal a);
//	Función para leer estructura.
void leerEstructura(Animal a);
//Persona actualizarDatos(Persona p);
int main(){
//	Función para el areglo unidimensional.
//	arregloUnidimensional();
//	Función para el arreglo bidimensional.
//	arregloBidimensional();
//	Ejemplo para Struct (sin typedef).
//	struct Persona p1 = {"Byron",19,1.78};
//	struct Persona p2 = {"Javier",20,1.74};
//	printf("Los datos de la persona 1, son: %s, %i, %.2f\n",p1.nombre,p1.edad,p1.altura);
//	printf("Los datos de la persona 2, son: %s, %i, %.2f\n",p2.nombre,p2.edad,p2.altura);
//	Ejemplo para Struct (con tyoedef).
//	Alumno a1 = {"Byro",19,1.78};
//	Alumno a2 = {"Javier",20,1.80};
//	printf("Los datos del alumno 1, son: %s, %i, %.2f\n",a1.nombre,a1.edad,a1.altura);
//	printf("Los datos del alumno 2, son: %s, %i, %.2f\n",a2.nombre,a2.edad,a2.altura);
//	Arreglo para lectura.
	int array[]={1,5,7,8};
//	Matriz para la lectura.
	int matriz[2][3] = {{1,2,3},{4,5,6}};
//	Tamaño del arrglo.
	int size = sizeof(&array)/sizeof(&array[0]);
//	lectura(array,size);
	int sizeColumnas = sizeof(matriz[0])/sizeof(int);
	int sizeFilas = sizeof(matriz)/sizeof(matriz[0]);
//	printf("La longitud es: %i\n",sizeFilas);
//	printf("La longitud es: %i\n",sizeColumnas);
//	lecturaB(matriz,sizeFilas);
	Animal a1 = {"Leon",20};
//	Llamada a la función que lee la estructura.
	leerEstructura(a1);
//	Llamada a la función que actualiza la estructura.
	Animal a2 = actualizarDatos(a1);
    printf("\nDevuelta: %s, edad: %i\n", a2.especie, a2.edad);
}
void arregloUnidimensional(){
//	Arreglo de caracteres.
	char string[6] = "Byron";
//	Para imprimir el arreglo completo se usa el %s.
	printf("%s\n",string);
//	Para imprimir solo un elemento del arreglo se utiliza el %c y el índice del caracter que querramos imprimir.
	printf("%c\n",string[2]);
//	Arreglo de numeros.
	int pares[] = {2,4,6,8};
//	Para imprimir un elemento del arreglo, dependiendo de que tipo sea el arreglo, se utiliza
	printf("El elemento 2 del arreglo es: %i",pares[2]);
}
void arregloBidimensional(){
//	Definición del arreglo bidimensional por inicializacion líneal de 3 filas con 2 clolumnas.
	int numeros[2][3] = {1,2,3,4,5,6};
//	Acceso a los elemntos del arrglo.
	printf("%i\n",numeros[1][2]); // -> Accediendo a la fila 2 al elemento 2 (6).
//	Definicon del arreglo bidimensional explicitamente de 3 filas con 2 columnas.
	int numeros2[2][3] = {{1,2,3},{4,5,6}};
//	Acceso a los elementos del arreglo.
	printf("%i\n",numeros2[0][2]); // -> Accediendo a la fila 1 al elemento 2 (3).
}
void lectura(int *array,int size){
	printf("La longitud del arrelgo es: %i\n",size);
	printf("La posición 2 del arreglo es: %i",array[1]);	
}
void lecturaB(int (*matriz)[3],int filas){
	printf("El elemento 1 de la matriz, es: %i",matriz[1][0]);
}
void leerEstructura(Animal a){
	printf("Nombre: %s, Edad: %i",a.especie,a.edad);
}
Animal actualizarDatos(Animal a){
	a.edad = 19;
	strcpy(a.especie,"Byro");
	return a;
} 
