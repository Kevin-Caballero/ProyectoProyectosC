#include "Header.h"

void Facturacion() {
	FILE *pfcli, *pfser, *pfpre, *pffac;
	CLIENTE regcli;
	SERVICIO regser;
	PRESUPUESTO regpre;
	FACTURA regfac;

	pfcli = fopen(FICHEROCLIENTES, "rb");
	if (pfcli == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		return;
	}
	pfser = fopen(FICHEROSERVICIOS, "rb");
	if (pfcli == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		fclose(pfcli);
		return;
	}
	pfpre = fopen(FICHEROPRESUPUESTOS, "rb");
	if (pfcli == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		fclose(pfcli);
		fclose(pfser);
		return;
	}
	pfcli = fopen(FICHERORESUMEN, "ab+");
	if (pfcli == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		fclose(pfcli);
		fclose(pfser);
		fclose(pfpre);
		return;
	}
}


//int a;
//char fac[8] = "Factura";
//strcat(fac, (char)a);