#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define FICHEROSERVICIOS "ProyectosServicios.dat"
#define FICHEROCLIENTES "ProyectosClientes.dat"
#define FICHEROPRESUPUESTOS "ProyectosPresupuestos.dat"
#define FICHEROFACTURAS "ProyectosFacturas.txt"
#define FICHERORESUMEN "ProyectosResumen.txt"

#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RESET	"\x1b[0m"
#define ANSI_COLOR_WHITE	"\u001b[37m."
#define BG_BLUE				"u\u001b[44m"

#include <stdio.h>
#include <Windows.h>


typedef struct {
	int numero_cliente;
	char nombre[20];
	char domicilio[20];
	char codigo_postal[6];
	char municipio[15];
	char nif[10];
	int estado;
}CLIENTE;

typedef struct {
	int numero_servicio;
	char denominacion[20];
	int precio_coste;
	int pvp;
	int estado;
}SERVICIO;

typedef struct {
	int numero_cliente;
	int numero_servicio;
	int pvp;
	float horas;
}PRESUPUESTO;

typedef struct {
	int numero_factura;
	int numero_cliente;
	float base_imponible;
	float iva;
}FACTURA;

/*COMUNES*/
int MenuPrincipal();
void GotoXY(int x,int y);

/*CLIENTES*/
void Clientes();
void CAltas();
void CBajas();
void CModificaciones();
void CConsultas();

void IntroducirCliente(int ultimo, CLIENTE *reg);
void MostrarCliente(int numcli);
int MenuClientes();

/*SERVICIOS*/
void Servicios();
void SAltas();
void SBajas();
void SModificaciones();
void SConsultas();

void IntroducirServicio(int numser, SERVICIO* reg);
void MostrarServicio(int numser);
int MenuServicios();

/*PRESUPUESTOS*/
void Presupuestos();
void MostrarPantallaPresupuesto();

/*FACTURACION*/
void Facturacion();
