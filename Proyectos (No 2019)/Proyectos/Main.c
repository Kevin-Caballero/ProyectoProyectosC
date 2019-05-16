#include "Header.h"

main()
{
	int opc;
	void(*funciones[3])() = { Clientes,Servicios,Presupuestos/*,Facturacion*/ };

	opc = MenuPrincipal();
	while (opc != 5) {
		(*funciones[opc - 1])();
		opc = MenuPrincipal();
	}
}