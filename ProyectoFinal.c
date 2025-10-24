#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
int i,j,elect;
HANDLE hConsole; // Poner el Handle en global.
//HANDLE hConsole=;
//typedef struct{
//	int nomina;
//	char username[40];
//	char pass[40];
//}personal;
struct personal{
	int nomina;
	char username[40];
	char pass[40];
};
void bienvenidaMenu(int flag, int opc, char user[],struct personal persona[]); // Prototipo de función para la bienvenida y el menú.
void showCr(struct personal persona[],char user[]); // Prototipo de funcion para mostrar credenciales.
int showUs(struct personal persona[]); // Prototipo para mostrar los usuarios existentes.
void changeC(struct personal persona[],char user[]); // Prototipo de función para cambiar credenciales.
void addUs(struct personal persona[]); // Prototipo de función para añadir usuarios.
void delUs(struct personal persona[],int elect); // Prototipi para eliminar usuarios.
int main(){
	struct personal persona[MAX];
	for(i=0;i<MAX;i++){
		persona[i].nomina=0;
		persona[i].username[0]='\0';
		persona[i].pass[0]='\0';	
	}
	// Declaración del usuario admin.
	strcpy(persona[0].username, "Admin");
	persona[0].nomina=1;
	strcpy(persona[0].pass,"Admin123");
	
	strcpy(persona[1].username, "Byro");
	persona[1].nomina=2;
	strcpy(persona[1].pass,"123123");

	char user[]="Admin";
	int flag=1; // Bandera para le menu ciclico.
	int opc; // Variable para la opación del menú.
	
    char username[256]; // Variable para almacenar el nombre de usuario.
    DWORD size = sizeof(username); // Se usa para recibir el noombre de usuario respecto a la salida.
    GetUserNameA(username, &size); // Obtiene el nombre de usuario de la sesión actual.
    printf("Nombre de usuario: %s\n", username); // Se imprime el nombre de usaurio.
//	system("whoami"); Meterlo en una cadena, recorrerla y cuando llege al '/', tomar lo que haya.
	bienvenidaMenu(flag,opc,user,persona);
}

void bienvenidaMenu(int flag,int opc,char user[],struct personal persona[]){
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE); // Inicializacion del hConsole.
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("\t\tBienvenido al banco");
	SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("\n\tSeleccione la opcion que desea realizar como administrador: \n");
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	do{
		printf("1. Ver credenciales.\n2. Ver usuarios registrados. \n3. Cambiar credenciales.\n4. Dar de alta usuarios.\n5. Eliminar usuarios. \n6. Salir\n");
		scanf("%i",&opc);
		switch(opc){
			case 1:
				system("cls");
				showCr(persona,user);
				break;
				case 2:
					system("cls");
					showUs(persona);
					break;
					case 3:
						system("cls");
						changeC(persona,user);
						break;
						case 4:
							system("cls");
							addUs(persona);
							break;
							case 5:
								system("cls");
								showUs(persona);
								printf("Digite la nomina del usuario que desea eliminar: ");
								scanf("%i",&elect);
								delUs(persona,elect);
								break;
								case 6:
									system("cls");
									printf("Saliendo...");
									Sleep(500);
									flag=0;
									system("cls");
									break;
									default:
										break;
		}
	}while(flag!=0);
}
void showCr(struct personal persona[],char user[]){
	
    for(i=0;i<MAX;i++){
        if(strcmp(persona[i].username,user)==0){
            system("cls");
            printf("Credenciales del usuario %s:\n",user);
            printf("Nomina: %i\n",persona[i].nomina);
            printf("Usuario: %s\n",persona[i].username);
            printf("Contrasenya: %s\n",persona[i].pass);
            for(i=0;i<30;i++){
        		printf("-");
			}
			printf("\n");
            break;
        }else{
        	printf("El usuario %s, no existe.\n",user);
        	for(i=0;i<30;i++){
        		printf("-");
			}
			printf("\n");
        	break;
		}
    }
}
int showUs(struct personal persona[]) {
    int ultimoIndice = -1;  

    printf("Las personas registradas son:\n");

    for (i = 0; i < MAX; i++) {
        if (persona[i].nomina != 0 || strlen(persona[i].username) > 0 || strlen(persona[i].pass) > 0) {
            printf("Persona [%i]:\n", i + 1);
            if (persona[i].nomina != 0)
                printf("  Nomina: %i\n", persona[i].nomina);
            if (strlen(persona[i].username) > 0)
                printf("  Nombre de usuario: %s\n", persona[i].username);
            if (strlen(persona[i].pass) > 0)
                printf("  Password: %s\n", persona[i].pass);

            for (j = 0; j < 30; j++) {
                printf("-");
            }
            printf("\n");

	    	ultimoIndice = i+1;  
        }
    }

    return ultimoIndice;
}
void changeC(struct personal persona[],char user[]){
	int opc;
	char passwd1[40],passwd2[40];
	printf("Su usuario es: %s ",user);
	for(i=0;i<MAX;i++){
        if(strcmp(persona[i].username,user)==0){
            system("cls");
            printf("Credenciales del usuario %s:\n",user);
            printf("Nomina: %i\n",persona[i].nomina);
            printf("Usuario: %s\n",persona[i].username);
            printf("Contrasenya: %s\n",persona[i].pass);
			printf("Que desea cambiar? \n\t1) Nombre de usuario.\n\t2) Contrasenya.\n");
			scanf("%i",&opc);
			switch(opc){
				case 1:
					system("cls");
					printf("Usted ha elegido cambiar el del usuario %s\n",persona[i].username);
					printf("Escriba el nuevo nombre que desea tener: ");
					scanf("%s",persona[i].username);
					system("cls");
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					printf("Su nuevo nombre es: %s\n",persona[i].username);
					SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					for(i=0;i<30;i++){
						printf("-");
					}
					printf("\n");
					break;
					case 2:
						system("cls");
						printf("Usted ha elegido cambiar la contraseña del usuario %s (%s)\n",persona[i].username,persona[i].pass);
						fflush(stdin);
						do{							
							printf("Escriba la nueva contraseña: ");
							fgets(passwd1,sizeof(passwd1),stdin);
							
							printf("Escriba de nuevo la contraseña: ");
							fgets(passwd2,sizeof(passwd2),stdin);
							
							if(strcmp(passwd1,passwd2)==0){
	//							strcpy(passwd2,passwd1);
								strcpy(persona[i].pass,passwd1);
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
								 printf("Su nueva contraseña es: %s\n", persona[i].pass);
								 SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							}else{
								SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
								printf("No hay coincidencia entra las claves.\n");
								SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);	
							}
						}while(strcmp(passwd1,passwd2)!=0);
						printf("\n");
						for(i=0;i<30;i++){
							printf("-");
						}
//						system("cls");
						printf("\n");
						break;
							default:
								printf("Opcion no disponible.");
								break;
			}
			printf("\n");
            break;
        }
    }

	
}
void addUs(struct personal persona[]){
	int nU=0;
	char newName[40],newPass1[40],newPass2[40];
//	printf("Los usuarios que hay existentes son: \n");
	showUs(persona);
	printf("Usted ha entrado al menú para agragar un usuario.\n");
	printf("Cuantos usuarios desea agregar: ");
	scanf("%i",&nU);
	fflush(stdin);
	int inicio=showUs(persona);
	int cant=inicio+1;
	for(i=cant;i< cant+nU;i++){
		system("cls");
		printf("Datos del usuario [%i]\n",i);
		for(j=0;j<30;j++){
			printf("-");
		}
		printf("\n");
		persona[i].nomina=i;
		printf("Nombre de usuario: ");
		fgets(newName,sizeof(newName),stdin);
		strcpy(persona[i].username,newName);
		do{
			printf("Clave de acceso: ");
			fgets(newPass1,sizeof(newPass1),stdin);
			
			printf("Repita la clave de acceso: ");
			fgets(newPass2,sizeof(newPass2),stdin);
			if(strcmp(newPass1,newPass2)==0){
				strcpy(persona[i].pass,newPass1);
				
			}else{
				SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("No coinciden las claves.\n");
				SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
		}while(strcmp(newPass1,newPass2)!=0);
//		printf("\nLos usuarios son: \n");
		showUs(persona);
	}
}
void delUs(struct personal persona[],int elect){
	char election;
	int found,uI;
	uI=showUs(persona);
//	printf("El ultimo indice es: %i\n",uI);
	fflush(stdin);
//	printf("Usted ha elegido eliminar al usuario con la nomina %i",elect);
	for(i=0;i<=uI;i++){
		if(persona[i].nomina==elect){
			printf("\nEl inice es: %i",i);
			found=i;
		}
		break;
	}
		printf("\nSeguro que desea eliminar el usuario (S/N): ");
		scanf("%c",&election);
		fflush(stdin);
		if(election=='S'){
			persona[found].nomina=0;
			persona[found].username[0]='\0';
			persona[found].pass[0]='\0';
		}
		
}
