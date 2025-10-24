#include<stdio.h>
// Macros para los precios.
#define PrecioAzucar 10
#define PrecioArroz 15
#define PrecioHuevo 5
// Macro para el IVA del 16%.
#define IVA 0.16

int main(){
//	Variables de manejo de cantidades.
	int cantidadAzucar, cantidadArroz, cantidadHuevo;
	float unitarioAzucar, unitarioArroz, unitarioHuevo, subtotal, ivaTotal, totalConIVA;
//	Listado de los productos.
	printf("Bienvenido a la tiendita!!\n");
	printf("** Los articulos disponibles son: **\n");
	printf("\tAzucar -- %i$\n",PrecioAzucar);
	printf("\tArroz -- %i$\n",PrecioArroz);
	printf("\tHuevo -- %i$\n",PrecioHuevo);
//	Pedida de la cantidad de productos.
	printf("Ingrese la cantidad (en kilogramos) de azucar: ");
	scanf("%i",&cantidadAzucar);
	printf("Ingrese la cantidad (en kilogramos) de arroz: ");
	scanf("%i",&cantidadArroz);
	printf("Ingrese la cantidad (en kilogramos) de huevo: ");
	scanf("%i",&cantidadHuevo);
//	Calculo de los subtotales.
	unitarioAzucar = cantidadAzucar * PrecioAzucar;
	unitarioArroz = PrecioArroz * cantidadArroz;
	unitarioHuevo = PrecioHuevo * cantidadHuevo;
//	Calculo del subtotal.
	subtotal = unitarioAzucar + unitarioArroz + unitarioHuevo;
//	Calculo del IVA y el total final.
	ivaTotal = subtotal * IVA;
	totalConIVA = subtotal + ivaTotal;
//	Impresión de la nota.
	printf("\n\t ** Nota de venta **\n");
	printf("\t%ikg de azucar ------ %.2f$\n", cantidadAzucar, unitarioAzucar);
	printf("\t%ikg de arroz ------ %.2f$ \n", cantidadArroz, unitarioArroz);
	printf("\t%ikg de huevo ------ %.2f$\n", cantidadHuevo, unitarioHuevo);
	printf("\t\t\tSubtotal: %.2f$\n", subtotal);
	printf("\t\t\t   IVA:   %.2f$\n", ivaTotal);
	printf("\t\t\t  Total:  %.2f$\n", totalConIVA);

	return 0;
}
