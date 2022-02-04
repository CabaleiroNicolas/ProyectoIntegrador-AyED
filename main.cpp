#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <wincon.h>
#include <cstdlib>
#include <unistd.h>
#include "utiles.h"
using namespace std;

typedef char cadena [40];
int cantLogins =0;

int MenuGeneral()
{
    int opc = 0;
    
	printf("\t\t\t-- Menu Principal --");
    printf("\n\n\t\t\t1.- Modulo Espacios.");
    printf("\n\t\t\t2.- Modulo Recepcionista");
    printf("\n\t\t\t3.- Modulo Administracion");
    printf("\n\t\t\t4.- Acerca de...");
    printf("\n\t\t\t0.- Cerrar Aplicacion");
    printf("\n\n\t\t\tIngrese una Opcion: ");
    scanf("%d", &opc);
	
    return opc;
}

int MenuRecepcion(bool sesionInic)
{
    int opc = 0;

    printf("\n===============================");
    printf("\n     MODULO RECEPCION");
    printf("\n===============================");

    if(sesionInic == false)
	{
		printf("\n1.- Iniciar Sesion");
	}
    printf("\n2.- Registrar Cliente");
    printf("\n3.- Registrar Turno");
    printf("\n4.- Listado de Atenciones por Profesional y Fecha");
    printf("\n0.- Retornar al menu principal");

    printf("\n\nIngrese una Opcion: ");
    scanf("%d", &opc);

    return opc;
}

int MenuEspacios(bool sesionInicProf)
{
    int opc = 0;

    printf("\n===============================");
    printf("\n      MODULO ESPACIOS");
    printf("\n===============================");

   
    if(sesionInicProf == false)
	{
		printf("\n1.- Iniciar Sesion");
	}
    printf("\n2.- Visualizar Lista de Espera de Turnos (informe)");
    printf("\n3.- Registrar Evolucion del tratamiento");
    printf("\n0.- Retornar al menu principal");

    printf("\n\nIngrese una Opcion: ");
    scanf("%d", &opc);

    return opc;
}

int MenuAdministracion()
{
     int opc = 0;

    printf("\n==================================");
    printf("\n      MODULO ADMINISTRACION");
    printf("\n==================================");

    printf("\n1.- Registrar Profesional");
    printf("\n2.- Registrar Usuario Recepcionista");
    printf("\n3.- Atenciones por Profesional");
    printf("\n4.- Ranking de Profesionales por Atenciones");
    printf("\n0.- Retornar al menu principal");

    printf("\n\nIngrese una Opcion: ");
    scanf("%d", &opc);

    return opc;
}

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
};

struct Atenciones
{
	int matriculamedico;
	int cant_atenciones;
};

void RegistrarProfesional(FILE *archProfesional, char contadorProf [200]) //modulo Administracion
{

	Profesional prof;
	FILE *contProf;

	archProfesional = fopen("Profesionales.dat", "r+b");
	contProf = fopen(contadorProf, "r+b");

	if(archProfesional == NULL)
	{
		archProfesional = fopen("Profesionales.dat", "a+b");

		if(archProfesional == NULL)
		{
			printf("\nNo se pudo crear archivo Profesionales.dat");
		}
	}

	fseek(archProfesional, 0, SEEK_END);

	printf("\nID de Profesional: ");
	scanf("%d", &prof.idProfesional);

	printf("\nNombre y Apellido: ");
	_flushall();
	gets(prof.apeNom);

	printf("Contrasenia: ");
	_flushall();
	enterPassword(prof.contrasenia, 12,7,12 ); //lee caracter a caracter la constraseña y la enmascara 
		
	while (checkPassword(prof.contrasenia) != 0) 
	{
	
		printf("\n\n");
		system("pause");
		system("cls");
		printf( "\nContrasenia: ");
		enterPassword(prof.contrasenia, 12,1,11);
	}

	printf("\nDNI: ");
	scanf("%d", &prof.dniProfesional);

	printf("\nTelefono: ");
	_flushall();
	gets(prof.telefono);

	fwrite(&prof, sizeof(Profesional), 1,archProfesional);
	
	//fwrite(&contProf, sizeof(contProf), 1,contProf);

	fclose(archProfesional);
	fclose(contProf);

}

void RegistrarUsuario (char userfile[], Login logins [255]) //modulo administracion
{
	FILE *fp;
	struct Usuario reg;
	cadena continua = "S"; 
	int valida =0;

	fp = fopen(userfile, "a+b");

	if(fp == NULL)
	{
		printf("Error al abrir el archivo \n");
		exit(EXIT_FAILURE);
	}
	
	
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(reg.usuario);
	
	valida = ValidUser(reg.usuario, logins, cantLogins);

	while (valida == 1) 
	{
		printf("\n\n");
		system("pause");
		system("cls");
		printf("Registrar a un Usuario.\n\n");
		printf( "\nNombre Usuario: ");
		_flushall();
		gets(reg.usuario);
		valida = ValidUser(reg.usuario, logins, cantLogins);
	}

	printf("\nContrasenia: ");
	_flushall();
	enterPassword(reg.password, 12,5,12);//lee caracter a caracter la constraseña y la enmascara 
		
	while (checkPassword(reg.password)!=0) 
	{
		printf("\n\n");
		system("pause");
		system("cls");
		printf( "\nContrasenia:  ");
		enterPassword(reg.password, 12,5,12);
	}
	
	printf("\nNombre y Apellido del usuario: ");
	_flushall();
	gets(reg.ApeNom);

	fwrite(&reg, sizeof(Usuario), 1,fp);
		

	cantLogins++;

	//al usuario registrado lo agrego al vector de logins para futuras validaciones 
	
	strcpy(logins[cantLogins].usuario,reg.usuario);
	

	fclose(fp);

}

void regiTurnos(FILE *turno, FILE *archProfesional, FILE *cliente, char contadorTurno [200], char contadorProf [200], char contadorClientes [200]) //modulo recepcionista
{
	Turnos turnos;
	Profesional prof;
	Cliente clientes;
	bool bandProf = false;
	bool bandClie = false;
	FILE *contClie; 
	FILE *contTurn;
	FILE *contProf;
	
	contClie = fopen(contadorClientes, "r+b");
	contTurn = fopen(contadorTurno, "r+b");
	contProf = fopen(contadorProf, "r+b");
	turno = fopen("turnos.dat","a+b");
	archProfesional = fopen("Profesionales.dat", "rb");
	cliente = fopen("Clientes.dat", "rb");
	
	if(turno == NULL)
	{
		turno = fopen("turnos.dat", "w+b");

	}
		
	
	printf("\nREGISTRACION DE TURNO\n");
	
	printf("\nID del profesional: ");
	scanf("%d",&turnos.idProfesional);
	
	fread(&prof,sizeof(Profesional),1,archProfesional);
	
	while(!feof(archProfesional) && bandProf == false)
	{
		if(turnos.idProfesional == prof.idProfesional)
		{
			bandProf = true;
		}
		else
		{
			fread(&prof,sizeof(Profesional),1,archProfesional);
		}		
	} 
		
	printf("\nDNI del cliente: ");
	scanf("%d",&turnos.dniCliente);
	
	fread(&clientes,sizeof(Cliente),1,cliente);
	
	while(!feof(cliente) && bandClie == false)
	{
		if(turnos.dniCliente == clientes.dniCliente)
		{
			bandClie = true;
		}
		else
		{
			fread(&clientes,sizeof(Cliente),1,cliente);
		}
	}  	

	if(bandClie == true && bandProf == true)
	{
			
		printf("\nFecha del turno: ");
		
		printf("\n\tDia: ");
		scanf("%d", &turnos.fechaDeTurno.dia);
		printf("\n\tMes: ");
		scanf("%d", &turnos.fechaDeTurno.mes);
		printf("\n\tA%o: ",164);
		scanf("%d", &turnos.fechaDeTurno.anio);
				
		printf("\nDetalle de atencion: ");
		_flushall();
		gets(turnos.detalleDeAtencion);
			
		fwrite(&turnos,sizeof(Turnos),1,turno);	
		
		//fwrite (&contTurn, sizeof(contTurn), 1, contTurn);
	}
	else
	{
		system("cls");
		printf("\n\nNo Se registro Paciente o Profesional con esas Credenciales...");
	}
	
	fclose(turno);
	fclose(archProfesional);
	fclose(cliente);
	fclose(contClie);
	fclose(contTurn);
	fclose(contProf);

}


void RegistrarCliente (FILE *cliente, char contadorClientes [200])//modulo recepcionista
{
	Cliente clientes;
	FILE *contClie; 
	cliente = fopen("Clientes.dat", "r+b");
	contClie = fopen(contadorClientes, "r+b");

	if(cliente == NULL)
	{
		cliente = fopen("Clientes.dat", "a+b");

		if(cliente == NULL)
		{
			printf("\nNo se pudo crear archivo Clientes.dat");
			exit(EXIT_FAILURE);
		}
	}

	printf ("\nApellido y nombre del cliente: ");
	_flushall();
	gets (clientes.apeNom);
	
	printf ("\nDomicilio del cliente: ");
	_flushall();
	gets (clientes.domicilio);	
	
	printf ("\nD.N.I del cliente sin puntos ni espacios: ");
	scanf ("%d", &clientes.dniCliente);
	
	printf ("\nLocalidad a la que pertenece el cliente : ");
	_flushall();
	gets (clientes.localidad);
	
	printf ("\nIngrese el peso del cliente en kg: ");
	scanf ("%f", &clientes.peso);
		
	printf ("\nIngrese la fecha de nacimiento del cliente: ");
	_flushall ();
	printf ("\n\tDia: ");
	scanf("%d" ,&clientes.fechaDeNacimiento.dia);
	printf ("\n\tMes: ");
	scanf("%d" ,&clientes.fechaDeNacimiento.mes);
    printf ("\n\tA%o (el anio debe ser de 4 digitos): ", 164 );
	scanf("%d" ,&clientes.fechaDeNacimiento.anio);
	
	clientes.edad = 2021 - clientes.fechaDeNacimiento.anio;
	
	printf ("Ingrese un Telefono de contacto del cliente: ");
	_flushall();
	gets (clientes.telefono);
	
	fwrite(&clientes, sizeof(Cliente), 1,cliente);
	
	//fwrite(&contClie, sizeof(contClie), 1, contClie); 
	
	printf("\n\nCliente Registrado con Exito!\n\n");
	
	fclose (cliente);
	fclose (contClie);
}


void AtencionPorProf (FILE *turno,FILE *prof) //modulo admin
{
	int i=0;
	bool band = false;
	char auxpro [50];
	Turnos turnos; 
	Profesional profs;
	
	prof=fopen("Profesionales.dat","r+b"); 
	
	turno= fopen("turnos.dat","r+b");

	printf("\nATENCIONES POR PROFESIONALES\n");
	_flushall();
	printf("\nProfesional: ");
	gets(auxpro);
	
	rewind(turno);
	rewind(prof);
	
	fread(&profs,sizeof(Profesional),1,prof);
	
	fread(&turnos,sizeof(Turnos),1,turno);
	while(!feof(prof) && band == false)
	{
		if(strcmp(auxpro , profs.apeNom) == 0)
		{
			while(!feof(turno))
			{
			
				if(profs.idProfesional == turnos.idProfesional)
				{
					
					printf("\n Turno numero %d \n" , i+1);
					printf("\n --------- \n");
					printf("\nFecha:");
					printf("\n\tDia: %d", turnos.fechaDeTurno.dia);
					printf("\n\tMes: %d", turnos.fechaDeTurno.mes);
					printf("\n\tAnio: %d",164, turnos.fechaDeTurno.anio);
					printf("\nDNI del Paciente: %d", turnos.dniCliente);
					printf("\n\nDetalle de Atencion: %s", turnos.detalleDeAtencion);
					printf("\n --------- \n");
					i++;

				}
			
				fread(&turnos,sizeof(Turnos),1,turno);		
			
				
			band = true;
				
			}
	
		}
		else
		{
			
			fread(&profs,sizeof(Profesional),1,prof);
			
		}
							
	}
	
	if(strcmp(auxpro , profs.apeNom) != 0)
	{
		printf("Profesional No Encontrado...");
	}

	fclose (turno);
	fclose (prof);
	
	printf("\n\n");
	
}

void listadoAtencionProf (FILE *prof , FILE *turno , FILE *cliente) //modulo recepcionista
{

	char auxpro[40];
	Profesional profs;
	Turnos turnos;
	Cliente clientes;
	
	prof=fopen("Profesionales.dat","r+b");
	turno=fopen("turnos.dat","r+b");
	cliente=fopen("Clientes.dat","r+b");
	
	
	if(prof == NULL)
	{
		printf("\nNo se Registro Ningun Profesional...\n\n");
		system("pause");
	}
	else
	{
	
		printf("LISTADO DE ATENCIONES POR PROFESIONALES Y FECHA\n\n");
		printf("Profesional: ");
		_flushall();
		gets(auxpro);
		
		fread(&profs,sizeof(Profesional),1,prof);
		fread(&turnos,sizeof(Turnos),1,turno);
		fread(&clientes,sizeof(Cliente),1,cliente);
		
		while(!feof(prof)&&!feof(turno)&&!feof(cliente))
		{
			if(strcmp(auxpro,profs.apeNom)==0)
			{
				if(turnos.idProfesional==profs.idProfesional)
				{
					printf("\nNombre del cliente: %s",clientes.apeNom);
					printf("\nFecha de turno:");
					printf("\nDia: %d", turnos.fechaDeTurno.dia);
					printf("\nMes: %d", turnos.fechaDeTurno.mes);
					printf("\nA%co: %d\n",164, turnos.fechaDeTurno.anio);
					printf("\nID: %d\n",profs.idProfesional);
					printf("============================================\n");
					
				}
			
				fread(&profs,sizeof(Profesional),1,prof);
				fread(&turnos,sizeof(Turnos),1,turno);
				fread(&clientes,sizeof(Cliente),1,cliente);		
			}
	
	     }
	 }
	
	fclose(prof);
	fclose (turno);
	fclose (cliente);

}

void listaEspera(FILE *turno, FILE *prof, FILE *cliente) // modulo espacios
{

	turno=fopen("turnos.dat","r+b");
	prof=fopen("Profesionales.dat","r+b");
	cliente=fopen("Clientes.dat","r+b");
	
	Turnos turnos;
	Profesional profs;
	Cliente clientes;
	//int auxId=0;
	int i=0;
    //int op;
            
	if(turno == NULL)
	{
		printf("\nNo hay Turnos...\n\n");
		system("pause");
	}
	else
	{
	
		
		system("cls");
		printf("LISTA DE ESPERA DE CLIENTES");
		
		rewind(turno);
		rewind(prof);
		rewind(cliente);
					
		fread(&profs,sizeof(Profesional),1,prof);
		fread(&turnos,sizeof(Turnos),1,turno);
		fread(&clientes,sizeof(Cliente),1,cliente);
		
		//printf ("Ingrese el id del profesional para ver su lista de espera: ");
		//scanf ("%d", &auxId); 
					
		do
		{
			if(profs.idProfesional==turnos.idProfesional)
			{
						
				printf("\nTurno %d:",i+1);
				printf("\nFecha De Turno :");
				printf("\n\nDia: %d",turnos.fechaDeTurno.dia);
				printf("\nMes: %d",turnos.fechaDeTurno.mes);
				printf("\nA%co: %d",164,turnos.fechaDeTurno.anio);
				printf("\nDNI del cliente: %d", turnos.dniCliente);
				printf("\nNombre y apellido: %s",clientes.apeNom);
				printf("\nEdad: %d a%cos", clientes.edad, 164);
				printf("\nLocalidad: %s", clientes.localidad );
				printf("\nPeso: %.2f",clientes.peso);
							
				fread(&profs,sizeof(Profesional),1,prof);
				fread(&turnos,sizeof(Turnos),1,turno);
				fread(&clientes,sizeof(Cliente),1,cliente);
			}
			
			else
			{
				fread(&profs,sizeof(Profesional),1,prof);
				fread(&turnos,sizeof(Turnos),1,turno);
				fread(&clientes,sizeof(Cliente),1,cliente);
			}
			
			i++;
			
		}while(!feof(prof)&&!feof(turno)&&!feof(cliente));	
		
	}
	
	fclose(prof);
	fclose(turno);
	fclose(cliente);
	
	printf("\n\n");
}

void RankingProfesionales()
{
	FILE *Prof;
	FILE *Turno;
    
	Profesional prof[50];
	Turnos turnos[50];
	Atenciones reg_atenciones[50],aux;
	bool band = true,stop;
    int i = 0;
	int num_meds = 0;
	int num_turnos = 0; 
	int contador = 0;

    Prof=fopen("Profesionales.dat","rb");

    if (Prof==NULL)
    {
        printf("\nEl archivo 'Profesionales.dat' no fue creado o se elimino.");
		band = false;
    }
    else
    {
        fread(&prof[i],sizeof(Profesional ),1,Prof);
        while (!feof(Prof))
        {
            i++;
            fread(&prof[i],sizeof(Profesional ),1,Prof);
        }
        num_meds = i;
        i = 0;
        fclose(Prof);
    }

	//Archivo de turnos:
    Turno=fopen("Turnos.dat","rb");

    if (Turno==NULL)
    {
        printf("\nEl archivo 'Turnos.dat' no fue creado o se elimino.");
		band = false;
    }
    else
    {
        fread(&turnos[i],sizeof(Turnos),1,Turno);
        while (!feof(Turno))
        {
            i++;
            fread(&turnos[i],sizeof(Turnos),1,Turno); 
        }
        num_turnos = i;
        i = 0;
        fclose(Turno);
    }

	if (band)
	{
		//Obtiene la cantidad de turnos por Medico:
		for (i = 0; i < num_meds; i++)
		{
			contador = 0;

			for (int k = 0; k < num_turnos; k++)
			{
				if ((prof[i].idProfesional == turnos[k].idProfesional) && (turnos[k].mostrado == 1))
				{
					contador++;
				}
			}
			
			reg_atenciones[i].matriculamedico = prof[i].idProfesional;
			reg_atenciones[i].cant_atenciones = contador;
		}
		
		//Ordena el ranking de mayor a menor:
		do
		{
			stop=false;
			
			for (i = 0 ; i < num_meds-1 ; i++)
			{
				if(reg_atenciones[i].cant_atenciones < reg_atenciones[i+1].cant_atenciones)
				{
					aux=reg_atenciones[i];
					reg_atenciones[i]=reg_atenciones[i+1];
					reg_atenciones[i+1]=aux;
					stop=true;
				}
			}
		}
		while (stop);

		//Muestra el ranking de Medicos:
		for (i = 0; i < num_meds; i++)
		{
			printf("\nPuesto %d:",i+1);
			printf("\nid del profesional: %d",reg_atenciones[i].matriculamedico);
			printf("\nCantidad de atenciones: %d",reg_atenciones[i].cant_atenciones);
			printf("\n--------------------------------\n");
		}
		
	}
}

void borradoFisico(FILE *turno, FILE *auxTurno, bool evolucion)
{
	Turnos turnos;
	Profesional profs; 
	FILE *contTurn; 
	auxTurno = fopen("auxiliar.dat", "w+b");
	turno = fopen("turnos.dat", "r+b");

	
	
	if (auxTurno == NULL)
	{
		printf("\nNo pudo crearse el archivo auxiliar.");
		printf("\nNo se pudo implementar la eliminacion fisica");
		exit(EXIT_FAILURE);
	}	
			
	if (turno == NULL)
	{
		turno = fopen("turnos.dat", "r+b");
		
		if (turno == NULL)
		{
			printf("Error. No se pudo crear el archivo de turnos");
 			exit(EXIT_FAILURE);
		}
	}

	rewind(turno);

	
	fread(&turnos, sizeof(Turnos), 1, turno);
	
	
	while (!feof(turno))
	{
		if (evolucion == false)
		{
			fwrite(&turnos, sizeof(Turnos), 1, auxTurno);
		}
		else 
		{
			fwrite(&contTurn, sizeof(contTurn), -1, contTurn); 
		}
		fread(&turnos, sizeof(Turnos), 1, turno);
		
	}
	
	fclose(turno);
	fclose(auxTurno);
	fclose (contTurn);
	
	remove("turnos.dat");
	rename("auxiliar.dat", "turnos.dat");
	
}

void evolucionPacientes(FILE *turno,FILE *cliente, FILE *auxTurn)	
{

	Turnos turn;
	Cliente clie;
	int auxDniClien=0;
	bool centinela=false;
	bool evolucion = false;
    int i=0;
    
	turno=fopen("turnos.dat","r+b");
	cliente=fopen("Clientes.dat","r+b");
	
   	fread(&turn,sizeof(Turnos),1,turno);

		while (!feof(turno))
	    {
			   
			i++;
			fread(&turn,sizeof(Turnos),1,turno);

		}
	printf ("contador de clientes: %d", i);

	if(i == 0)
	{
		printf("\nTodavia no se Registro Ningun Paciente...");
	}
	else
	{
		printf("\nDNI del Cliente: ");
		scanf("%d", &auxDniClien);
	
		rewind(cliente);

		fread(&clie, sizeof(Cliente), 1, cliente);
	   
	   	while (!feof(cliente) && centinela == false)
	    {
			   
			if(auxDniClien == clie.dniCliente)
			{
			    centinela = true;
	
		    }
			else
			{
				fread(&clie,sizeof(Cliente),1,cliente);	
			}
		}
		printf("\n\n");
		
		if(centinela == true)
		{
			rewind(turno);
	
			fread(&turn,sizeof(Turnos),1,turno);
			
			while(!feof(turno))
			{											
			    if( auxDniClien == turn.dniCliente)
				{
												
					//fseek(turno,(long) -sizeof(Turnos),SEEK_CUR);	
									
					printf("\nRegistre la evolucion del Paciente: ");
																
					fflush(stdin);
					gets(turn.detalleDeAtencion);
					fwrite(&turn, sizeof(Turnos), 1,turno);	
					evolucion = true;					
					
				}										
				else
				{
										
				    fread(&turn, sizeof(Turnos), 1,turno);	
					evolucion = false;										
				}																							
			}
			
			if(centinela== true &&  evolucion == false)
			{
			    printf("El paciente esta Registrado\n Pero 'No se Registraron Turnos a su Nombre '...");
			}
			
			borradoFisico(turno, auxTurn, evolucion);
		}
		
	}
		
			

	fclose(cliente);
	fclose(turno);
}

bool login(char userfile[])
{
	FILE *fp;
	struct Usuario reg;
	char usuario[10];
	char password[32];
	bool flag = false;
	int user;
	int pass;
	
	
	fp=fopen(userfile,"rb");
	if (fp==NULL)
	{
			printf ("\nNo se Registro Ningun Recepcionista...\n\n");
			system("pause");
	}
	else
	{
		rewind(fp);
	    printf ("Bienvenido - Inicio de Sesion \n") ;
	    printf ("------------------------------\n") ;
	    printf ("Usuario: ") ; 
	    _flushall ();
		gets(usuario);
		 
		printf ("Contrasenia: "); 
		_flushall();
		enterPassword(password, 12,3,12); 
		printf ("\n\n");
		 
		fread(&reg,sizeof(reg),1,fp);
		//printf ("password ingresada: %s -  otra pass: %s", password, reg.password);
		
		user=strcmp(usuario,reg.usuario);
		pass=strcmp(password,reg.password);
	
		if ((user== 0) && (pass== 0))
			{
				flag = true;
			}
		
		while ((!feof(fp)) && (flag == false))
		{
			if (!feof(fp))
			{	
				user=strcmp(usuario,reg.usuario);
				pass=strcmp(password,reg.password);
				if ((user== 0) && (pass== 0))
				{
					flag = true;
					
				}
		   }
			fread(&reg,sizeof(reg),1,fp);
		}  
		fclose(fp);
		if (flag==true)
		{
			printf ("Inicio de sesion exitosa\n");
			printf("\n\n");
			system("pause");		
		}
		else
		{	printf ("Las credenciales ingresadas son incorrectas\n");
			printf("\n\n");
			system("pause");	
		}
	}
	
	return flag;
}


bool loginProf(FILE *prof)
{
	int idVerificar = 0; 
	char passVerificar[32];
	Profesional reg;
	bool flag = false;
	
	prof=fopen("Profesionales.dat","rb");
	if (prof==NULL)
	{
			printf ("\nNo se Registro Ningun Profesional...\n\n");
			system("Pause");
	}
	else
	{
		
	    printf ("Bienvenido - Inicio de Sesion \n");
	    printf ("------------------------------\n");
	    printf ("ID de Profesional: "); 
		scanf("%d", &idVerificar);
		 
		printf ("Contrasenia: "); 
		_flushall();
		enterPassword(passVerificar, 12,3,12);
		printf("\n\n");
		 
		rewind(prof);
		 
		fread(&reg,sizeof(Profesional),1,prof);
		
		if (idVerificar == reg.idProfesional && strcmp(passVerificar, reg.contrasenia) == 0)
			{
					flag = true;
			}
		
		while(!feof(prof) && flag == false)
		{
	
		
			if (idVerificar == reg.idProfesional && strcmp(passVerificar, reg.contrasenia) == 0)
				{
					flag = true;
				}
				
			fread(&reg,sizeof(Profesional),1,prof);
				
		}
			
			 
		fclose(prof);
		
		if (flag==true)
		{
			printf ("Inicio de sesion exitosa\n");
			printf("\n\n");
			system("pause");		
		}
		else
		{	printf ("Las credenciales ingresadas son incorrectas\n");
			printf("\n\n");
			system("pause");	
		}
	}
	
	return flag;
}


main()
{
    FILE *recep;
    FILE *prof;
    FILE *cliente;
    FILE *turno;
    FILE *auxTurno; 
	char contadorProf [200] = {"contadorProf.dat"}; 
	char contadorPaciente [200]= {"contadorPaciente.dat"};
	char contadorTurno [200]= {"contadorTurno.dat"};
	char userfile[255] = {"Usuarios.dat"}; //Nombre del archivo de usuarios
	bool sesionInic = false;
	bool sesionInicProf = false; 
	int opcEspacios = 0;
    int opcRecep = 0;
    int opcAdmin = 0;
    int opcion = 0;
    Login logins[255];
    
   cantLogins = leerLogins (userfile, logins);//leo inicialmente todos los usuarios existentes
   
   //logoutn(); 
    
    do
    {

        system("cls");
        opcion = MenuGeneral();
        system("cls");

       switch(opcion)
       {
           case 1:
                {
                    system("cls");
                    opcEspacios = MenuEspacios(sesionInicProf);
                    system("cls");

                        switch(opcEspacios)
                        {
                            case 1:
                            {
                            	printf("Iniciar sesion.");
                            	sesionInicProf = loginProf(prof);
									
                                break;
                            }

                            case 2:
                            {
								printf("Listado de espera de Turnos.\n\n");
								if(sesionInicProf == false)
								{
									printf("\n=============================================================================");
				                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
				                 	printf("\n=============================================================================\n\n");
									system ("pause");
								}
								else
								{
									listaEspera(turno, prof, cliente);
									system ("pause");
								}
								
                                break;
                            }

                            case 3:
                            {
                                printf("Registrar evolucion del tratamiento.\n\n");
                                if(sesionInicProf == false)
								{
									
									printf("\n=============================================================================");
				                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
				                 	printf("\n=============================================================================\n\n");
									system("pause");
									
								}
								else
								{
									evolucionPacientes(turno,cliente, auxTurno);
									printf("\n\n");
									system("pause");		
								}
                                break;
                            }

                            case 0:
                            {
								printf("Salir. ");
                                break;
                            }

                            default:
                            {
							     printf("\n=======================================");
				                 printf("\nEsa Opcion no se encuentra en el Menu.\n");
				                 printf("\n=======================================\n\n");
				                 system("pause");
                                break;
                            }
                        }

                    break;
                }
            case 2:
                {
                    system("cls");
                    opcRecep = MenuRecepcion(sesionInic);
                    system("cls");

                        switch(opcRecep)
                        {
                            case 1:
                            {
								printf("Iniciar sesion.");	
								sesionInic = login (userfile );
								
                                break;
                            }

                            case 2:
                            {
								printf("Registrar a un cliente.\n\n");
								if(sesionInic == false)
								{
									printf("\n=============================================================================");
				                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
				                 	printf("\n=============================================================================\n\n");
									system("pause");
									
								}
								else
								{
									RegistrarCliente (cliente, contadorPaciente);
									system("pause");
								}
                                break;
                            }

                            case 3:
                            {
                                printf("Registrar un turno.\n\n");
                                if(sesionInic == false)
								{
									printf("\n=============================================================================");
				                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
				                 	printf("\n=============================================================================\n\n");
									system("pause");
									
								}
								else
								{
									regiTurnos (turno, prof, cliente, contadorTurno, contadorProf, contadorPaciente);	
									system("pause");
								}  
                                break;
                            }

                            case 4:
                            {
                                printf("Listado de Atenciones por profesional y fecha.\n\n");
                                if(sesionInic == false)
								{
									printf("\n=============================================================================");
				                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
				                 	printf("\n=============================================================================\n\n");
									system("pause");
									
								}
								else
								{
									listadoAtencionProf (prof, turno, cliente);
									system("pause");	
										
								}
                                break;
                            }

                            case 0:
                            {
								printf("Salir.");
                                break;
                            }

                            default:
                            {
 								 printf("\n=======================================");
				                 printf("\nEsa Opcion no se encuentra en el Menu.\n");
				                 printf("\n=======================================\n\n");
				                 system("pause");
                                break;
                            }


                        }

                    break;
                }
            case 3:
                {
                    system("cls");
                    opcAdmin = MenuAdministracion();
                    system("cls");

                        switch(opcAdmin)
                        {
                            case 1:
                            {
								printf("Registrar a un profesioanl.\n\n");
								RegistrarProfesional(prof, contadorProf);
								printf("\n\nProfesional Registrado con Exito!\n\n");
								system("pause");
                                break;
                            }

                            case 2:
                            {
								printf("Registrar a un Usuario.\n\n");
								RegistrarUsuario(userfile, logins);
								
								printf("\n\nUsuario Registrado con Exito!\n\n");
								system("pause");
                                break;
                            }

                            case 3:
                            {
   								AtencionPorProf(turno, prof);
   								system("pause");
                                break;
                            }

                            case 4:
                            {
								printf("Ranking de Profesionales por atencion.\n\n");
								RankingProfesionales();
								printf("\n\n");
								system("pause");
                                break;
                            }

                            case 0:
                            {
								printf("Salir.");
                                break;
                            }
                            default:
                            {
								 printf("\n=======================================");
				                 printf("\nEsa Opcion no se encuentra en el Menu.\n");
				                 printf("\n=======================================\n\n");
				                 system("pause");

                                break;
                            }
                        }
                    break;
                }
                case 4:
                {

                    acercaDe ();
                    setTextColor(9);
                    system("pause");
                    
                    break;
                }
            case 0:
                {

                    printf("\n=======================================");
                    printf("\nCerrando Programa...\n");
                    printf("\n=======================================\n\n");
                    system("pause");
                    
                    break;
                }
            default :
                {
                    printf("\n=======================================");
                    printf("\nEsa Opcion no se encuentra en el Menu.\n");
                    printf("\n=======================================\n\n");
                    system("pause");

                    break;
                }

       }

    } while (opcion != 0);
    
}
