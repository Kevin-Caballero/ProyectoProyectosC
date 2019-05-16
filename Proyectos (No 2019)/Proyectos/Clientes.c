#include "Header.h"

void Clientes() {
	int opc;
	void(*funcionescliente[4])() = { CAltas,CBajas,CModificaciones,CConsultas };
	opc = MenuClientes();
	while (opc != 5)
	{
		(*funcionescliente[opc - 1])();
		opc = MenuClientes();
	}
}


int MenuClientes() {
	int opc;
	
	system("cls");
	printf(ANSI_COLOR_CYAN);
	GotoXY(9, 4); printf("      ___                                     ___           ___                         ___           ___     ");
	GotoXY(9, 5); printf("     /\\__\\                                   /\\__\\         /\\  \\                       /\\__\\         /\\__\\    ");
	GotoXY(9, 6); printf("    /:/  /                      ___         /:/ _/_        \\:\\  \\         ___         /:/ _/_       /:/ _/_   ");
	GotoXY(9, 7); printf("   /:/  /                      /\\__\\       /:/ /\\__\\        \\:\\  \\       /\\__\\       /:/ /\\__\\     /:/ /\\  \\  ");
	GotoXY(9, 8); printf("  /:/  /  ___   ___     ___   /:/__/      /:/ /:/ _/_   _____\\:\\  \\     /:/  /      /:/ /:/ _/_   /:/ /::\\  \\ ");
	GotoXY(9, 9); printf(" /:/__/  /\\__\\ /\\  \\   /\\__\\ /::\\  \\     /:/_/:/ /\\__\\ /::::::::\\__\\   /:/__/      /:/_/:/ /\\__\\ /:/_/:/\\:\\__\\");
	GotoXY(9, 10); printf(" \\:\\  \\ /:/  / \\:\\  \\ /:/  / \\/\\:\\  \\__  \\:\\/:/ /:/  / \\:\\~~\\~~\\/__/  /::\\  \\      \\:\\/:/ /:/  / \\:\\/:/ /:/  /");
	GotoXY(9, 11); printf("  \\:\\  /:/  /   \\:\\  /:/  /   ~~\\:\\/\\__\\  \\::/_/:/  /   \\:\\  \\       /:/\\:\\  \\      \\::/_/:/  /   \\::/ /:/  / ");
	GotoXY(9, 12); printf("   \\:\\/:/  /     \\:\\/:/  /       \\::/  /   \\:\\/:/  /     \\:\\  \\      \\/__\\:\\  \\      \\:\\/:/  /     \\/_/:/  /  ");
	GotoXY(9, 13); printf("    \\::/  /       \\::/  /        /:/  /     \\::/  /       \\:\\__\\          \\:\\__\\      \\::/  /        /:/  /   ");
	GotoXY(9, 14); printf("     \\/__/         \\/__/         \\/__/       \\/__/         \\/__/           \\/__/       \\/__/         \\/__/    ");

	printf(ANSI_COLOR_RESET);
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

void CAltas() {
	FILE *pf;
	CLIENTE reg;
	int longitud,numcli=0,ultimo;
	char resp;

	pf = fopen(FICHEROCLIENTES, "ab+");
	if (pf == NULL) {
		system("cls");
		GotoXY(15, 52);
		printf("ERROR DE LECTURA");
		getch();
		return;
	}
	fseek(pf, sizeof(reg)*numcli, SEEK_END);
	longitud = ftell(pf);
	if (longitud > 0) {
		fseek(pf, longitud - sizeof(reg), SEEK_SET);
		fread(&reg, 1, sizeof(reg), pf);
		numcli = reg.numero_cliente;
	}
	numcli++;
	reg.numero_cliente = numcli;
	IntroducirCliente(numcli, &reg);
	GotoXY(5, 25);
	printf("Desea dar de alta a este cliente?\n\ts=si\n\tn=no");
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

void CBajas() {
	int numcli;
	char resp;
	CLIENTE reg;
	FILE* pf;

	do {
		system("cls");
		GotoXY(59, 3);
		printf(ANSI_COLOR_CYAN);
		printf("BAJA CLIENTE");
		printf(ANSI_COLOR_WHITE);
		GotoXY(50, 6);
		printf("N. Cliente");
		GotoXY(50, 8);
		printf("Nombre");
		GotoXY(50, 10);
		printf("Domicilio");
		GotoXY(50, 12);
		printf("Cod. Postal");
		GotoXY(50, 14);
		printf("Municipio");
		GotoXY(50, 16);
		printf("N.I.F");

		GotoXY(72, 6);
		printf(": ");
		scanf("%d", &numcli);
		rewind(stdin);
		MostrarCliente(numcli);
		pf = fopen(FICHEROCLIENTES, "rb+");
		if (pf == NULL) {
			system("cls");
			GotoXY(15, 52);
			printf("ERROR DE LECTURA");
			getch();
			return;
		}
		fseek(pf, sizeof(reg) * (numcli-1), SEEK_SET);
		fread(&reg, 1, sizeof(reg), pf);
		GotoXY(5, 25);
		printf("Desea dar de baja a este cliente?\n\ts=si\n\tn=no");
		GotoXY(5, 28);
		printf("Introduce opcion: ");
		do {
			resp = tolower(getche());
		} while (resp != 's' && resp != 'n');
	} while (resp == 'n');
	reg.estado = 0;
	fseek(pf, sizeof(reg) * --numcli, SEEK_SET);
	fwrite(&reg, 1, sizeof(reg), pf);
	system("cls");
	GotoXY(48, 15);
	printf("La baja se llevo a cabo correctamente");  
	getch();
	fclose(pf);
}

void CModificaciones() {
	FILE* pf;
	CLIENTE reg;
	int numcli;
	char resp;

	pf = fopen(FICHEROCLIENTES, "rb+");
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
		printf("MODIFICACION CLIENTE");
		GotoXY(50, 6);
		printf(ANSI_COLOR_WHITE);
		printf("N. Cliente");
		GotoXY(50, 8);
		printf("Nombre");
		GotoXY(50, 10);
		printf("Domicilio");
		GotoXY(50, 12);
		printf("Cod. Postal");
		GotoXY(50, 14);
		printf("Municipio");
		GotoXY(50, 16);
		printf("N.I.F");

		GotoXY(72, 6);
		printf(": ");
		scanf("%d", &numcli);
		rewind(stdin);
		MostrarCliente(numcli);
		GotoXY(5, 25);
		printf("Desea modificar a este cliente?\n\ts=si\n\tn=no");
		GotoXY(5, 28);
		printf("Introduce opcion: ");
		resp = tolower(getche());
		while (resp != 's' && resp != 'n') {
			system("cls");
			GotoXY(5, 25);
			printf("Desea modificar a este cliente?\n\ts=si\n\tn=no");
			GotoXY(5, 28);
			printf("Introduce opcion: ");
			resp = tolower(getche());
		}
	} while (resp == 'n');
	IntroducirCliente(numcli, &reg);
	GotoXY(5, 25);
	printf("Desea dar de alta a este cliente?\n\ts=si\n\tn=no");
	GotoXY(5, 28);
	printf("Introduce opcion: ");
	do {
		resp = tolower(getche());
	} while (resp != 's' && resp != 'n');
	if (resp == 's') {
		fseek(pf, sizeof(reg) * --numcli, SEEK_SET);
		fwrite(&reg, 1, sizeof(reg), pf);
		system("cls");
		GotoXY(42,15);
		printf("La modificacion se llevo a cabo correctamente");
		getch();
	}
	fclose(pf);
}

void CConsultas() {
	int numcli;
	char resp;
	
	do {
		system("cls");
		GotoXY(57, 3);
		printf(ANSI_COLOR_CYAN);
		printf("CONSULTA CLIENTE");
		GotoXY(50, 6);
		printf(ANSI_COLOR_WHITE);
		printf("N. Cliente");
		GotoXY(50, 8);
		printf("Nombre");
		GotoXY(50, 10);
		printf("Domicilio");
		GotoXY(50, 12);
		printf("Cod. Postal");
		GotoXY(50, 14);
		printf("Municipio");
		GotoXY(50, 16);
		printf("N.I.F");

		GotoXY(72, 6);
		printf(": ");
		scanf("%d", &numcli);
		MostrarCliente(numcli);
		GotoXY(5, 25);
		printf("Desea consultar otro cliente?\n\ts=si\n\tn=no");
		GotoXY(5, 28);
		printf("Introduce opcion: ");
		do {
			resp = tolower(getche());
		} while (resp != 's' && resp != 'n');
	} while (resp == 's');
}

void MostrarCliente(int numcli) {
	FILE *pf;
	CLIENTE reg;

	pf = fopen(FICHEROCLIENTES, "rb+");
	if (pf == NULL) {
		GotoXY(46, 15);
		printf("Error de apertura de fichero");
		getch();
		return;
	}
	fseek(pf, sizeof(reg)*--numcli, SEEK_SET);
	fread(&reg, 1, sizeof(reg), pf);
	if (reg.estado == 0) {
		system("cls");
		GotoXY(52,15);
		printf("Registro borrado");
		fclose(pf);
		return;
	}
	GotoXY(72, 8);
	printf(": ");
	puts(reg.nombre);

	GotoXY(72, 10);
	printf(": %s", reg.domicilio);

	GotoXY(72, 12);
	printf(": %s", reg.codigo_postal);

	GotoXY(72, 14);
	printf(": %s", reg.municipio);

	GotoXY(72, 16);
	printf(": %s", reg.nif);

	fclose(pf);
}

void IntroducirCliente(int numcli, CLIENTE *reg) { //TODO validar longitudes de campo

	system("cls");

	GotoXY(59,3);
	printf(ANSI_COLOR_CYAN);
	printf("ALTA CLIENTE");
	GotoXY(50, 6);
	printf(ANSI_COLOR_WHITE);
	printf("N. Cliente");
	GotoXY(72, 6);
	printf(": %d", numcli);
	GotoXY(50, 8);
	printf("Nombre");
	GotoXY(50, 10);
	printf("Domicilio");
	GotoXY(50, 12);
	printf("Cod. Postal");
	GotoXY(50, 14);
	printf("Municipio");
	GotoXY(50, 16);
	printf("N.I.F");


	do {
		GotoXY(72, 8);
		printf("->");
		gets(reg->nombre);
		GotoXY(72, 8);
		printf(": ");
	} while (strlen(reg->nombre) >= 20);

	do {
		GotoXY(72, 10);
		printf("->");
		gets(reg->domicilio);
		GotoXY(72, 10);
		printf(": ");
	} while (strlen(reg->domicilio) >= 20);

	do {
		GotoXY(72,12);
		printf("->");
		gets(reg->codigo_postal);
		GotoXY(72,12);
		printf(": ");
	} while (strlen(reg->codigo_postal) >= 6);
	
	do {
		GotoXY(72,14);
		printf("->");
		gets(reg->municipio);
		GotoXY(72, 14);
		printf(": ");
	} while (strlen(reg->municipio) >= 15);

	do {
		GotoXY(72, 16);
		printf("->");
		gets(reg->nif);
		GotoXY(72, 14);
		printf(": ");
	} while (strlen(reg->nif) >= 10);

	reg->numero_cliente = numcli;
	reg->estado = 1;
}


