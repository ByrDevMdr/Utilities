#include<stdio.h>
#include<windows.h>
//	Macros para los sueldos.
#define SueldoProfesor 200
#define SueldoSecretaria 100
#define SueldoMozo 50
//	Macros para la bifurcación.
#define Profesor 1
#define Secretaria 2
#define Mozo 3
#define Salir 4
//	Macro para las prestaiciones (10%).
#define Prestacion .10
//	Macros para las deducciones.
#define SueldoBajo 8
#define SueldoMedio 12
#define SueldoAlto 15
//	Macro para el bono.
#define Bono 25
//	Prototipos de funciones.
void procesoProfesor(int horasLaboradas);
void procesoSecretaria(int horasLaboradas);
void procesoMozo(int horasLaboradas);
void calculoDeduccion(float sueldo);
int main(){
//	Variables para las horas y la operacion.
	int opc,horas;
//	Mostrado de listado de puestos.
	printf("  *** Listado de puestos ***");
	printf("\n\t 1. Profesor. \n\t 2. Secretaria. \n\t 3. Mozo. \n");
//	Ingreso del puesto.
	printf("Ingrese el numero del puesto al que pertenece. Si desea salir presione 4: ");
	scanf("%i",&opc);
	system("cls");
//	Inicio de la bifurcacón.
	switch(opc){
		case Profesor:
			printf("Empleado seleccionado: Profesor.\n\n\t");
			printf("Ingrese el numero de horas que usted ha laborado (sin numeros con decimales): ");
			scanf("%i",&horas);
			procesoProfesor(horas);
			break;
			case Secretaria:
				printf("Empleado seleccionado: Secretaria.\n\n\t");
				printf("Ingrese el numero de horas que usted ha laborado (sin numeros con decimales): ");
				scanf("%i",&horas);
				procesoSecretaria(horas);
				break;
				case Mozo:
					printf("Empleado seleccionado: Mozo.\n\n\t");
					printf("Ingrese el numero de horas que usted ha laborado (sin numeros con decimales): ");
					scanf("%i",&horas);
					procesoMozo(horas);
					break;
					case Salir:
						printf("\tSaliendo...");
						Sleep(1000);
						break;
						default:
							printf("Opcion no valida.\nSaliendo...");
							Sleep(1000);
							break;
	}
}
//	Función para el profesor.
void procesoProfesor(int horasLaboradas){
//	Variables para los calculos.
	float prestaciones,deducciones,sueldo,auxiliar,bono=0.0;
//	Muestra de las horasa trabajadas.
	printf("Las horas laboradas son: %i.",horasLaboradas);
//	Calculo del bono.
	if(horasLaboradas > 30){
		int horario = horasLaboradas - 30;
		bono = (float)horario * (float)Bono;
		printf("\n\tUsted tiene un bono de: %.2f$\n",bono);
	}
//	Impresión de lal nomina.
	printf("\n\t  *** Nomina de profesor ***\n");
//	Pago normal.
	if(horasLaboradas > 0 && horasLaboradas < 41){
		sueldo = horasLaboradas * SueldoProfesor;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono+sueldo);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);

	}
	
//	Pago doble.
	if(horasLaboradas > 41 && horasLaboradas < 49){
		sueldo = 2 * horasLaboradas * SueldoProfesor;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);
	}
	
//	Pago tirple.
	if(horasLaboradas > 48){
		sueldo = 3 * horasLaboradas * SueldoProfesor;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
//	Calculo de la deducción.
		calculoDeduccion(sueldo);

	}
}
//	Función para la secretaria.
void procesoSecretaria(int horasLaboradas){
//	Variables para los calculos.
	float prestaciones,deducciones,sueldo,auxiliar,bono=0.0;
//	Muestra de las horasa trabajadas.
	printf("Las horas laboradas son: %i.",horasLaboradas);
//	Calculo del bono.
	if(horasLaboradas > 30){
		int horario = horasLaboradas - 30;
		bono = (float)horario * (float)Bono;
		printf("\n\tUsted tiene un bono de: %.2f$\n",bono);
	}
//	Impresión de lal nomina.
	printf("\n\t  *** Nomina de secretaria ***\n");
//	Pago normal.
	if(horasLaboradas > 0 && horasLaboradas < 41){
		sueldo = horasLaboradas * SueldoSecretaria;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono+sueldo);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);
	}
//	Pago doble.
	if(horasLaboradas > 41 && horasLaboradas < 49){
		sueldo = 2 * horasLaboradas * SueldoSecretaria;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);	
	}
//	Pago tirple.
	if(horasLaboradas > 48){
		sueldo = 3 * horasLaboradas * SueldoSecretaria;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);
	}
}
//	Función para el mozo.
void procesoMozo(int horasLaboradas){
//	Variables para los calculos.
	float prestaciones,deducciones,sueldo,auxiliar,bono=0.0;
//	Muestra de las horasa trabajadas.
	printf("Las horas laboradas son: %i.",horasLaboradas);
//	Calculo del bono.
	if(horasLaboradas > 30){
		int horario = horasLaboradas - 30;
		bono = (float)horario * (float)Bono;
		printf("\n\tUsted tiene un bono de: %.2f$\n",bono);
	}
//	Impresión de lal nomina.
	printf("\n\t  *** Nomina de mozo ***\n");
//	Pago normal.
	if(horasLaboradas > 0 && horasLaboradas < 41){
		sueldo = horasLaboradas * SueldoMozo;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono+sueldo);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);
	}
//	Pago doble.
	if(horasLaboradas > 41 && horasLaboradas < 49){
		sueldo = 2 * horasLaboradas * SueldoMozo;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);	
	}
//	Pago tirple.
	if(horasLaboradas > 48){
		sueldo = 3 * horasLaboradas * SueldoMozo;
		printf("\tSueldo de nomina ---- %.2f$",sueldo);
//	Si no hay bono, no se muestra tal mensaje.
		if(bono!=0){
			printf("\n\tSueldo con bono ---- %.2f",bono);
		}
//	Calculo del sueldo con prestaciones.
		auxiliar = sueldo*Prestacion;
		sueldo = auxiliar+sueldo;
		printf("\n\tSueldo con prestaciones ---- %.2f$",sueldo);
		
//	Calculo de la deducción.
		calculoDeduccion(sueldo);
	}
}
//	Calculo de la deducción dependiendo las horas laboradas.
void calculoDeduccion(float sueldo){
	float deducciones;
	//	Calculo del sueldo final con deducciones.	
		if(sueldo < 1000){
			deducciones = (float)SueldoBajo / 100 * sueldo;
			sueldo -= deducciones;
			printf("\n\tDeducciones ---- %.2f$",deducciones);
			printf("\n\tSalario con deducciones ---- %.2f$",sueldo);
			printf("\n\tSueldo con deducciones (%i) es de: %.2f$",SueldoBajo,sueldo);
		}
//	Calculo del sueldo final con deducciones.
		if(sueldo > 1000 && sueldo < 1500){
			deducciones = (float)SueldoMedio / 100 * sueldo;
			sueldo -= deducciones;
			printf("\n\tDeducciones ---- %.2f$",deducciones);
			printf("\n\tSalario con deducciones ---- %.2f$",sueldo);
			printf("\n\tSueldo con deducciones (%i) es de: %.2f$",SueldoMedio,sueldo);
		}	
//	Calculo del sueldo final con deducciones.
		if(sueldo > 1500){
			deducciones = (float)SueldoAlto / 100 * sueldo;
			sueldo -= deducciones;
			printf("\n\tDeducciones ---- %.2f$",deducciones);
			printf("\n\tSalario con deducciones ---- %.2f$",sueldo);
			printf("\n\tSueldo con deducciones (%i) es de: %.2f$",SueldoAlto,sueldo);
		}
}
