#include "Header.h"

void GotoXY(int x, int y)
{
	HANDLE hnd;
	COORD pos;
	pos.X = x;
	pos.Y = y;
	hnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hnd, pos);
}

int MenuPrincipal() 
{
	int opc;
	system("cls");
	printf(ANSI_COLOR_CYAN);
	GotoXY(3, 4); printf("      ___         ___           ___                       ___           ___                         ___           ___     ");
	GotoXY(3, 5); printf("     /\\  \\       /\\  \\         /\\  \\                     /\\__\\         /\\__\\                       /\\  \\         /\\__\\    ");
	GotoXY(3, 6); printf("    /::\\  \\     /::\\  \\       /::\\  \\         ___       /:/ _/_       /:/  /          ___         /::\\  \\       /:/ _/_   ");
	GotoXY(3, 7); printf("   /:/\\:\\__\\   /:/\\:\\__\\     /:/\\:\\  \\       /|  |     /:/ /\\__\\     /:/  /          /\\__\\       /:/\\:\\  \\     /:/ /\\  \\  ");
	GotoXY(3, 8); printf("  /:/ /:/  /  /:/ /:/  /    /:/  \\:\\  \\     |:|  |    /:/ /:/ _/_   /:/  /  ___     /:/  /      /:/  \\:\\  \\   /:/ /::\\  \\ ");
	GotoXY(3, 9); printf(" /:/_/:/  /  /:/_/:/__/___ /:/__/ \\:\\__\\    |:|  |   /:/_/:/ /\\__\\ /:/__/  /\\__\\   /:/__/      /:/__/ \\:\\__\\ /:/_/:/\\:\\__\\ ");
	GotoXY(3, 10); printf(" \\:\\/:/  /   \\:\\/:::::/  / \\:\\  \\ /:/  /  __|:|__|   \\:\\/:/ /:/  / \\:\\  \\ /:/  /  /::\\  \\      \\:\\  \\ /:/  / \\:\\/:/ /:/  / ");
	GotoXY(3, 11); printf("  \\::/__/     \\::/~~/~~~~   \\:\\  /:/  /  /::::\\  \\    \\::/_/:/  /   \\:\\  /:/  /  /:/\\:\\  \\      \\:\\  /:/  /   \\::/ /:/  / \n");
	GotoXY(3, 12); printf("   \\:\\  \\      \\:\\~~\\        \\:\\/:/  /   ~~~~\\:\\  \\    \\:\\/:/  /     \\:\\/:/  /   \\/__\\:\\  \\      \\:\\/:/  /     \\/_/:/  /  ");
	GotoXY(3, 13); printf("    \\:\\__\\      \\:\\__\\        \\::/  /         \\:\\__\\    \\::/  /       \\::/  /         \\:\\__\\      \\::/  /        /:/  /   ");
	GotoXY(3, 14); printf("     \\/__/       \\/__/         \\/__/           \\/__/     \\/__/         \\/__/           \\/__/       \\/__/         \\/__/    ");

	printf(ANSI_COLOR_WHITE);
	GotoXY(5, 23);
	printf("1.Clientes");
	GotoXY(5, 24);
	printf("2.Servicios");
	GotoXY(5, 25);
	printf("3.Presupuestos");
	GotoXY(5, 26);
	printf("4.Facturacion");
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

