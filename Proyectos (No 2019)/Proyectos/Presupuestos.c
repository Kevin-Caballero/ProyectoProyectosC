#include "Header.h"

void Presupuestos() {
	CLIENTE reg1;
	SERVICIO reg2;
	PRESUPUESTO reg3;

	FILE *pf1, *pf2, *pf3;

	int numcli, numser, longitud, ultimocli, ultimoser;

	pf1 = fopen(FICHEROCLIENTES, "rb");
	if (pf1 == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		return;
	}
	pf2 = fopen(FICHEROSERVICIOS, "rb");
	if (pf2 == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		fclose(pf1);
		return;
	}
	pf3 = fopen(FICHEROPRESUPUESTOS, "ab+");
	if (pf3 == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		fclose(pf1);
		fclose(pf2);
		return;
	}
	fseek(pf1, 0, SEEK_END);
	longitud = ftell(pf1);
	if (longitud > 0) {
		fseek(pf1, longitud - sizeof(reg1), SEEK_SET);
		fread(&reg1, 1, sizeof(reg1), pf1);
		ultimocli = reg1.numero_cliente;
	}
	MostrarPantallaPresupuesto();
	GotoXY(3, 25);
	printf("Introduce cliente.");
	do {
		GotoXY(16, 5);
		scanf("%d", &numcli);
		rewind(stdin);
	} while (numcli<0 || numcli>ultimocli);
	while (numcli != 0) {
		fseek(pf1, sizeof(reg1) * (numcli-1), SEEK_SET);
		fread(&reg1, 1, sizeof(reg1), pf1);
		reg3.numero_cliente = numcli;
		GotoXY(18, 5);
		printf("  %s", reg1.nombre);
		/*BUSCAR ULTIMO*/
		fseek(pf2, 0, SEEK_END);
		longitud = ftell(pf2);
		if (longitud > 0) {
			fseek(pf2, longitud - sizeof(reg2), SEEK_SET);
			fread(&reg2, 1, sizeof(reg2), pf2);
			ultimoser = reg2.numero_servicio;
		}
		/*FIN BUSCAR ULTIMO*/
		int y = 9;
		GotoXY(3, 25);
		printf("Introduce servicio.");

		do {
			GotoXY(3, y);
			scanf("%13d", &numser);
			rewind(stdin);
		} while (numser<0 || numser>ultimoser);

		while (numser != 0) {
			fseek(pf2, sizeof(reg2) * (numser - 1), SEEK_SET);
			fread(&reg2, 1, sizeof(reg2), pf2);
			reg3.numero_servicio = numser;
			reg3.pvp = reg2.pvp;
			GotoXY(16, y);
			printf("  %-20s   %-6d", reg2.denominacion, reg2.pvp);
			GotoXY(3, 25);
			printf("Introduce numero de horas.");
			GotoXY(48, y);
			scanf("%f", &reg3.horas);
			rewind(stdin);
			//no hace falta buscar el ultimo presupuesto porque no se pueden borrar van uno tras otro
			fwrite(&reg3, 1, sizeof(reg3), pf3);
			y++;
			do {
				GotoXY(3, y);
				scanf("%13d", &numser);
				rewind(stdin);
			} while (numser < 0 || numser>ultimoser);

		}
		do {
			GotoXY(16, 5);
			scanf("%d", &numcli);
			rewind(stdin);
		} while (numcli<0 || numcli>ultimocli);
	}
	fclose(pf1);
	fclose(pf2);
	fclose(pf3);
}

void MostrarPantallaPresupuesto() {
	system("cls");
	GotoXY(47, 3);
	printf("FICHERO DE PRESUPUESTOS");
	GotoXY(3, 5);
	printf("Nº Cliente: ");
	GotoXY(3, 7);
	printf("%13s  %-20s  %6s  %5s", "Nº Servicio: ", "Denominacion", "P.V.P", "Horas");
}