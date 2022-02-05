#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
const int TAM = 100;
typedef char cadena [60];

struct Fecha
{
    int dia;
    int mes;
    int anio;
};
struct Recepcionista
{
    char usuario[10];
    char contrasenia [10];
    char apeNom[60];
};
struct Profesional
{
    char apeNom[60];
	char contrasenia[10];
    int idProfesional;
    int dniProfesional;
    int cantAtenciones;
    char telefono[25];
};
struct Cliente
{
    char apeNom[60];
    char domicilio[60];
    int dniCliente;
    char localidad[60];
    Fecha fechaDeNacimiento;
    int edad; 
    float peso;
    char telefono[25];
    char envolucionPaciente [380];
};

struct Turnos
{
    int idProfesional;
    Fecha fechaDeTurno;
    int dniCliente;
    char detalleDeAtencion[380];
    bool mostrado;
    bool atendido;
};

struct Atenciones
{
	int matriculamedico;
	int cant_atenciones;
};

struct Profesional vecProf [TAM];
struct Cliente vecCliente [TAM];
