#include "Header.h"

void Servicios() {
	int opc;
	void(*funcionesservicio[4])() = { SAltas,SBajas,SModificaciones,SConsultas };
	opc = MenuServicios();
	while (opc != 5)
	{
		(*funcionesservicio[opc - 1])();
		opc = MenuServicios();
	}
}
int MenuServicios() {
	int opc;

	system("cls");
	printf(ANSI_COLOR_CYAN);
	GotoXY(4, 4); printf("      ___           ___           ___                                     ___                       ___           ___     ");
	GotoXY(4, 5); printf("     /\\__\\         /\\__\\         /\\  \\          ___                      /\\__\\                     /\\  \\         /\\__\\    ");
	GotoXY(4, 6); printf("    /:/ _/_       /:/ _/_       /::\\  \\        /\\  \\        ___         /:/  /        ___         /::\\  \\       /:/ _/_   ");
	GotoXY(4, 7); printf("   /:/ /\\  \\     /:/ /\\__\\     /:/\\:\\__\\       \\:\\  \\      /\\__\\       /:/  /        /\\__\\       /:/\\:\\  \\     /:/ /\\  \\  ");
	GotoXY(4, 8); printf("  /:/ /::\\  \\   /:/ /:/ _/_   /:/ /:/  /        \\:\\  \\    /:/__/      /:/  /  ___   /:/__/      /:/  \\:\\  \\   /:/ /::\\  \ ");
	GotoXY(4, 9); printf(" /:/_/:/\\:\\__\\ /:/_/:/ /\\__\\ /:/_/:/__/___  ___  \\:\\__\\  /::\\  \\     /:/__/  /\\__\\ /::\\  \\     /:/__/ \\:\\__\\ /:/_/:/\\:\\__\\ ");
	GotoXY(4, 10); printf(" \\:\\/:/ /:/  / \\:\\/:/ /:/  / \\:\\/:::::/  / /\\  \\ |:|  |  \\/\\:\\  \\__  \\:\\  \\ /:/  / \\/\\:\\  \\__  \\:\\  \\ /:/  / \\:\\/:/ /:/  /");
	GotoXY(4, 11); printf("  \\::/ /:/  /   \\::/_/:/  /   \\::/~~/~~~~  \\:\\  \\|:|  |   ~~\\:\\/\\__\\  \\:\\  /:/  /   ~~\\:\\/\\__\\  \\:\\  /:/  /   \\::/ /:/  / ");
	GotoXY(4, 12); printf("   \\/_/:/  /     \\:\\/:/  /     \\:\\~~\\       \\:\\__|:|__|      \\::/  /   \\:\\/:/  /       \\::/  /   \\:\\/:/  /     \\/_/:/  /  ");
	GotoXY(4, 13); printf("     /:/  /       \\::/  /       \\:\\__\\       \\::::/__/       /:/  /     \\::/  /        /:/  /     \\::/  /        /:/  /   ");
	GotoXY(4, 14); printf("     \\/__/         \\/__/         \\/__/        ~~~~           \\/__/       \\/__/         \\/__/       \\/__/         \\/__/     ");

	printf(ANSI_COLOR_WHITE);
	GotoXY(5, 23);
	printf("1.Altas");
	GotoXY(5, 24);
	printf("2.Bajas");
	GotoXY(5, 25);
	printf("3.Modificaciones");
	GotoXY(5, 26);
	printf("4.Consultas");
	GotoXY(5, 27);
	printf("5.Salir");
	GotoXY(5, 28);
	printf("Introduce Opcion[ ]");

	do
	{
		GotoXY(22, 28);
		scanf("%d", &opc);
		rewind(stdin);
	} while (opc < 1 || opc>5);
	return opc;
}

void SAltas() {
	FILE* pf;
	SERVICIO reg;
	int longitud, numser = 0;
	char resp;

	pf = fopen(FICHEROSERVICIOS, "ab+");
	if (pf == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		return;
	}
	fseek(pf, sizeof(reg) * numser, SEEK_END);
	longitud = ftell(pf);
	if (longitud > 0) {
		fseek(pf, longitud - sizeof(reg), SEEK_SET);
		fread(&reg, 1, sizeof(reg), pf);
		numser = reg.numero_servicio;
	}
	numser++;
	reg.numero_servicio = numser;
	IntroducirServicio(numser, &reg);
	GotoXY(5, 25);
	printf("Desea dar de alta a este servicio?\n\ts=si\n\tn=no");
	GotoXY(5, 28);
	printf("Introduce opcion: ");
	resp = tolower(getche());
	getch();
	if (resp == 's') {
		fseek(pf, 0, SEEK_END);
		fwrite(&reg, 1, sizeof(reg), pf);
		system("cls");
		GotoXY(59, 15);
		printf("Alta exitosa");
		getch();
	}
	else if (resp == 'n') {
		system("cls");
		GotoXY(57, 15);
		printf("Alta cancelada");
		getch();
	}
	else {
		system("cls");
		GotoXY(46, 15);
		printf("Solo se aceptan como validos los caracteres indicados");
		getch();
	}
	fclose(pf);
}

void SBajas() {
	int numser;
	char resp;
	SERVICIO reg;
	FILE* pf;

	do {
		system("cls");
		GotoXY(59, 3);
		printf(ANSI_COLOR_CYAN);
		printf("BAJA SERVICIO");
		printf(ANSI_COLOR_WHITE);
		GotoXY(50, 6);
		printf("N. Servicio");
		GotoXY(50, 8);
		printf("Denominacion");
		GotoXY(50, 10);
		printf("Precio coste");
		GotoXY(50, 12);
		printf("P.V.P");

		GotoXY(72, 6);
		printf(": ");
		scanf("%d", &numser);
		MostrarServicio(numser);
		pf = fopen(FICHEROSERVICIOS, "rb+");
		if (pf == NULL) {
			system("cls");
			GotoXY(15, 52);
			printf("ERROR DE LECTURA");
			getch();
			return;
		}
		fseek(pf, sizeof(reg) * (numser-1), SEEK_SET);
		fread(&reg, 1, sizeof(reg), pf);
		GotoXY(5, 25);
		printf("Desea dar de baja a este servicio?\n\ts=si\n\tn=no");
		GotoXY(5, 28);
		printf("Introduce opcion: ");
		do {
			resp = tolower(getche());
		} while (resp != 's' && resp != 'n');
	} while (resp == 'n');
	reg.estado = 0;
	fseek(pf, sizeof(reg) * --numser, SEEK_SET);
	fwrite(&reg, 1, sizeof(reg), pf);
	system("cls");
	GotoXY(48, 15);
	printf("La baja se llevo a cabo correctamente");
	getch();
	fclose(pf);
}

void SModificaciones() {
	FILE* pf;
	SERVICIO reg;
	int numser;
	char resp;

	pf = fopen(FICHEROSERVICIOS, "rb+");
	if (pf == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		return;
	}
	do {
		system("cls");
		GotoXY(55, 3);
		printf(ANSI_COLOR_CYAN);
		printf("MODIFICACION SERVICIO");
		printf(ANSI_COLOR_WHITE);
		GotoXY(50, 6);
		printf("N. Servicio");
		GotoXY(50, 8);
		printf("Denominacion");
		GotoXY(50, 10);
		printf("Precio coste");
		GotoXY(50, 12);
		printf("P.V.P");

		GotoXY(72, 6);
		scanf("%d", &numser);
		rewind(stdin);
		MostrarServicio(numser);
		GotoXY(5, 25);
		printf("Desea modificar este servicio?\n\ts=si\n\tn=no");
		GotoXY(5, 28);
		printf("Introduce opcion: ");
		resp = tolower(getche());
		while (resp != 's' && resp != 'n') {
			system("cls");
			GotoXY(5, 25);
			printf("Desea modificar este servicio?\n\ts=si\n\tn=no");
			GotoXY(5, 28);
			printf("Introduce opcion: ");
			resp = tolower(getche());
		}
	} while (resp == 'n');
	IntroducirServicio(numser, &reg);
	GotoXY(5, 25);
	printf("Desea guardar los cambios introducidos?\n\ts=si\n\tn=no");
	GotoXY(5, 28);
	printf("Introduce opcion: ");
	do {
		resp = tolower(getche());
	} while (resp != 's' && resp != 'n');
	if (resp == 's') {
		fseek(pf, sizeof(reg) * --numser, SEEK_SET);
		fwrite(&reg, 1, sizeof(reg), pf);
		system("cls");
		GotoXY(42, 15);
		printf("La modificacion se llevo a cabo correctamente");
		getch();
	}
	fclose(pf);
}

void SConsultas() {
	int numser;
	char resp;

	do {
		system("cls");
		GotoXY(57, 3);
		printf(ANSI_COLOR_CYAN);
		printf("CONSULTA SERVICIO");
		printf(ANSI_COLOR_WHITE);
		GotoXY(50, 6);
		printf("N. Servicio");
		GotoXY(50, 8);
		printf("Denominacion");
		GotoXY(50, 10);
		printf("Precio coste");
		GotoXY(50, 12);
		printf("P.V.P");

		GotoXY(72, 6);
		scanf("%d", &numser);
		MostrarServicio(numser);
		GotoXY(5, 25);
		printf("Desea consultar otro servicio?\n\ts=si\n\tn=no");
		GotoXY(5, 28);
		printf("Introduce opcion: ");
		do {
			resp = tolower(getche());
		} while (resp != 's' && resp != 'n');
	} while (resp == 's');
}

void MostrarServicio(int numser) {
	FILE* pf;
	SERVICIO reg;

	pf = fopen(FICHEROSERVICIOS, "rb+");
	if (pf == NULL) {
		GotoXY(46, 15);
		printf("Error de apertura de fichero");
		getch();
		return;
	}
	fseek(pf, sizeof(reg) * --numser, SEEK_SET);
	fread(&reg, 1, sizeof(reg), pf);
	if (reg.estado == 0) {
		system("cls");
		GotoXY(52, 15);
		printf("Registro borrado");
		fclose(pf);
		return;
	}
	GotoXY(72, 8);
	printf(": ");
	puts(reg.denominacion);

	GotoXY(72, 10);
	printf(": %d", reg.precio_coste);

	GotoXY(72,12);
	printf(": %d", reg.pvp);

	fclose(pf);
}

void IntroducirServicio(int numser, SERVICIO * reg) { 

	system("cls");
	GotoXY(59, 3);
	printf(ANSI_COLOR_CYAN);
	printf("ALTA SERVICIO");
	printf(ANSI_COLOR_WHITE);
	GotoXY(50, 6);
	printf("N. Servicio");
	GotoXY(50, 8);
	printf("Denominacion");
	GotoXY(50, 10);
	printf("Precio coste");
	GotoXY(50, 12);
	printf("P.V.P");
	
	GotoXY(72, 6);
	printf(": %d", numser);

	do {
		GotoXY(72, 8);
		printf("->");
		gets(reg->denominacion);
		GotoXY(72, 8);
		printf(": ");
	} while (strlen(reg->denominacion) >= 20);

	do{
		GotoXY(72, 10);
		printf("->");
		scanf("%d", &reg->precio_coste);
		GotoXY(72, 10);
		printf(": ");
	} while (reg->precio_coste<0);

	do {
		GotoXY(72, 12);
		printf("->");
		scanf("%d", &reg->pvp);
		GotoXY(72, 12);
		printf(": ");
	} while (reg->pvp<0);

	reg->numero_servicio = numser;
	reg->estado = 1;
}