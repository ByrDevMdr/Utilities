#include<stdio.h>
int main(){
//	Definición del arreglo.
	int array[10] = {2,3,4,5,6,7,8,9,10,11};
	int i,suma,numero,flag=0;
	float promedio,size;
//	Sacar la distancia de forma automática (buena práctica para evitar el hardcoding y hacer un código más dinámico).
	size = sizeof(array)/sizeof(array[0]);
//	Recorrer el arreglo y mostrarlo.
	printf("\tIndice\t\tValor\n");
	for(i = 0; i < size;i++){
		printf("\t  %i\t\t  %i\n",i,array[i]);
		suma += i;
	}
//	Mostrar la suma de los elementos.
	printf("La suma de todos los elementos es: %i\n",suma);
//	Calculo e impresión del promedio.
	promedio = suma/size;
	printf("El promedio es: %.2f\n",promedio);
//	Impresión de los números pares.
	printf("Poricion de pares: ");
	for(i = 0;i < size;i++){
		if(array[i] % 2 == 0){
			printf("%i, ",i);
		}
	}
//	Pedir al usuario el numero que quiere buscar.
	do{
		printf("\nIngrese el numero que desee buscar: ");
		scanf("%i",&numero);
//	Se inicializa la bancera en 0.
        flag = 0;
		for(i = 0; i < size; i++){
//	Solo ejecuta la busqueda si la bandera sigue siendo 0.
            if (flag == 0) { 
                if(array[i] == numero){
                    printf("El numero se ha encontrado en la posiciones: %i\n",i);
                    flag = 1; // El número fue encontrado y saldrá de bucle.
                }
            }
		}
//	Si después de revisar todo el array, la bandera sigue siendo 0, no se encontró.
        if (flag == 0) {
            printf("El numero no se encontro. Intente de nuevo.\n");
        }
	}while(flag != 1); 
}
