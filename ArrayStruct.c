#include<stdio.h>
//#include<string.h>
//#include<diablo.h>
//	Estructura de los actores con valores predeterminados. 
typedef struct{
	char nombre[20];
	char apellido[20];
}Actores;
//	Estructura de los directores con valores predeterminados.
typedef struct{
	char nombre[20];
	char apellido[20];
}Directores;
//	Estructura de las peliculas que contiene a los valores de las estructuras anteriores.
typedef struct{
	char nombre[20];
	char director[20];
	char actor1[30];
//	char actor2[30];
	int lanzamiento;
}Peliculas;
//	Prototipo para rellenar a los actores.
void rellenarActores(Actores a[6]);
//	Prototipo para rellenar a los directores.
void rellenarDirectores(Directores d[3]);
void rellenarPeliculas(Peliculas p[3]);
int main(){
	int i;
//	Instancia para la estructura 1.
	Actores a[6];
//	Instancia para la estructura 2.
	Directores d[3];
//	Instancia para la estructura 3.
	Peliculas p[3];
//	Llamada a la función para rellenar los directores.
	rellenarDirectores(d);
//	Llamada a la función para rellenar los actores.
	rellenarActores(a);
	printf("\t**Directores disponibles** \n");
//	Impresión de los directores.
	for (i = 0; i < 3; i++) {
        printf("Director %i: %s %s\n",i+1,d[i].nombre,d[i].apellido);
    }
    printf("\t**Actores disponibles** \n");
//  Impresión de los actores.
	for (i = 0; i < 3; i++) {
        printf("Actor %i: %s %s\n",i+1,a[i].nombre,a[i].apellido);
    }
//  Función para rellenar pelicula.
	rellenarPeliculas(p);
//	Impresión de las peliculas.
	printf("Nombre: \t Actores: \t Director: \t Lanzamiento:\n");
    
    for (i = 0; i < 3; i++) {
//  Impresión con "espaciado especial".
        printf("%-15s %-20s %-15s %-10i\n",
               p[i].nombre,
               p[i].actor1,  
               p[i].director,
               p[i].lanzamiento);
    }
}
void rellenarDirectores(Directores d[3]) {
// Director1
    strcpy(d[0].nombre, "Byron");
    strcpy(d[0].apellido, "Mdr");
// Director2
    strcpy(d[1].nombre, "Jose");
    strcpy(d[1].apellido, "Bobadilla");
// Director3
    strcpy(d[2].nombre, "Rodolfo");
    strcpy(d[2].apellido, "Hernandez");
}
void rellenarActores(Actores a[6]){
//	Proceso de rellenado para actores.
//	Actor1
	strcpy(a[0].nombre,"Byron");
	strcpy(a[0].apellido,"Medrano");
//	Actor2
	strcpy(a[1].nombre,"Javier");
	strcpy(a[1].apellido,"Arellano");
//	Actor3
	strcpy(a[2].nombre,"Andrea");
	strcpy(a[2].apellido,"Guzman");
//	Actor4
	strcpy(a[3].nombre,"Andrea");
	strcpy(a[3].apellido,"Guzman");	
//	Actor5
	strcpy(a[4].nombre,"Steve");
	strcpy(a[4].apellido,"Hydra");	
//	Actor6
	strcpy(a[5].nombre,"Jorge");
	strcpy(a[5].apellido,"Chamorro");	
}
void rellenarPeliculas(Peliculas p[3]){
	int i;
//	Bucle para rellenar la estructura de las peliculas.
	for(i = 0; i < 3; i++){
		printf("\nIngrese el nombre de la pelicula: ");
		scanf("%19[^\n]",&p[i].nombre);
		fflush(stdin);
		printf("Ingrese el director de la pelicula: ");
		scanf("%19[^\n]",&p[i].director);		
		fflush(stdin);
		printf("Ingrese el actor1: ");
		scanf("%19[^\n]",&p[i].actor1);
		fflush(stdin);
		printf("Ingrese el lanzamiento: ");
		scanf("%i",&p[i].lanzamiento);
		fflush(stdin);
	}	
}
