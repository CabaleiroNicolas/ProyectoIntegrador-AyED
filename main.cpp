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

int MenuEspacios(bool sesionInic)
{
    int opc = 0;

    printf("\n===============================");
    printf("\n      MODULO ESPACIOS");
    printf("\n===============================");

   
    if(sesionInic == false)
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
};

void RegistrarProfesional(FILE *archProfesional) //modulo Administracion
{

	Profesional prof;

	archProfesional = fopen("Profesionales.dat", "r+b");

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
		enterPassword(prof.contrasenia, 12,1,12);
	}

	printf("\nDNI: ");
	scanf("%d", &prof.dniProfesional);

	printf("\nTelefono: ");
	_flushall();
	gets(prof.telefono);

	fwrite(&prof, sizeof(Profesional), 1,archProfesional);

	fclose(archProfesional);

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

void regiTurnos(FILE *turno, FILE *archProfesional, FILE *cliente) //modulo recepcionista
{
	Turnos turnos;
	Profesional prof;
	Cliente clientes;
	
	turno = fopen("turnos.dat","a+b");
	archProfesional = fopen("Profesionales.dat", "rb");
	cliente = fopen("Clientes.dat", "rb");
	
	if(turno == NULL)
	{
		turno = fopen("turnos.dat", "w+b");

		if(turno == NULL)printf("\nNo se pudo crear archivo Profesionales.dat");
	}
		
	fread(&prof,sizeof(Profesional),1,archProfesional);
	fread(&clientes,sizeof(Cliente),1,cliente);
	
	printf("\nREGISTRACION DE TURNO\n");
	
	printf("\nID del profesional: ");
	scanf("%d",&turnos.idProfesional);
	
	
	while  (turnos.idProfesional != prof.idProfesional)
	{
		printf ("\nEl id ingresado no fue encontrado, por favor, introduzca el id nuevamente.");
		printf("\n\n");
		system("pause");
		system("cls");
		printf("\nID del profesional: ");
		scanf("%d",&turnos.idProfesional);
		
		fread(&prof,sizeof(Profesional),1,archProfesional);
		
	} 
		
	printf("\nFecha del turno: ");
	
			printf("\n\tDia: ");
			scanf("%d", &turnos.fechaDeTurno.dia);
			printf("\n\tMes: ");
			scanf("%d", &turnos.fechaDeTurno.mes);
			printf("\n\tA%co: ",164);
			scanf("%d", &turnos.fechaDeTurno.anio);
			
	printf("\nDNI del cliente: ");
	scanf("%d",&turnos.dniCliente);
	
	while  (turnos.dniCliente != clientes.dniCliente)
	{
		printf ("\nEl DNI ingresado no fue encontrado, por favor, introduzca el DNI nuevamente.");
		printf("\n\n");
		system("pause");
		system("cls");
		printf("\nDNI del cliente:  ");
		scanf("%d",&turnos.dniCliente);	
	}  
	
	printf("\nDetalle de atencion: ");
	_flushall();
	gets(turnos.detalleDeAtencion);
		
	fwrite(&turnos,sizeof(Turnos),1,turno);	
	
	fclose(turno);
	fclose(archProfesional);
	fclose(cliente);

}

void RegistrarCliente (FILE *cliente)//modulo recepcionista
{
	Cliente clientes;
	cadena continua ; 
	cliente = fopen("Clientes.dat", "r+b");

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
		
		printf ("\nIngrese el peso del cliente: ");
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
	
	printf("\n\nCliente Registrado con Exito!\n\n");
	
	fclose (cliente);
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
	int auxId=0;
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
		
		printf ("Ingrese el id del profesional para ver su lista de espera: ");
		scanf ("%d", &auxId); 
					
		do
		{
			if(auxId == profs.idProfesional && profs.idProfesional==turnos.idProfesional)
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

void RankingProfesionales(FILE *tur , FILE *pro)
{
	
	Profesional p;
	Turnos t;
	
	const int TAM = 40;
	char umay[70];
	Profesional aux;
	
	Profesional vec[TAM];
	
	int i = 0;
	int size = 0;
	bool flag = false;
	int L = 0;
	
	pro=fopen("Profesionales.dat","r+b");
	
	tur=fopen("turnos.dat","r+b");
	
	if(tur == NULL)
	{
		printf("\nNo se Atendio Ningun Paciente Hasta el Momento...\n\n");
	}
	if(pro == NULL)
	{
		printf("\nNo hay ningun profesional registrado hasta el momento Hasta el Momento...\n\n");
	}
	else
	{
	
	
		rewind(tur);
		rewind(pro);
		
		fread(&p,sizeof(Profesional),1,pro);
		fread(&t,sizeof(Turnos),1,tur);
		
		while(!feof(pro))
		{
			while(!feof(tur))
			{
				
				if(p.idProfesional == t.idProfesional)
				{
				
					i++;
				}
				
				fread(&t,sizeof(Turnos),1,tur);	

			}
			
			p.cantAtenciones = i;
			
			fwrite(&p,sizeof(Profesional),1,pro);
	
	
			rewind(tur);
			i = 0;			
			
			fread(&p,sizeof(Profesional),1,pro);
			fread(&t,sizeof(Turnos),1,tur);	
		}						
	
		rewind(pro);
		fread(&p,sizeof(Profesional),1,pro);
		
		i = 0;
		
		while(!feof(pro))
		{
			
			vec[i] = p;
			
			i++;
			size = i;
		}
		
		L = size - 1;
			
		do
		{
			flag = false;
			
			for(int i = 0; i < L; i++)
			{	
				
				if(vec[i].cantAtenciones > vec[i+1].cantAtenciones)
				{
					aux = vec[i];
					vec[i] = vec[i+1];
					vec[i+1] = aux;
						
					flag = true;
				}	
			}
			L--;
			
		}while(flag == true);
		
		
		for(i = 0; i < size; i++)
		{
			if(i == 0)
			{
				printf("\n\nBono Mejor Profesional--> %s, %d Atenciones\n\n", vec[i].apeNom, vec[i].cantAtenciones);
			}
			else
			{
				printf("\n%d--> %s, %d Atenciones\n", i+1, vec[i].apeNom, vec[i].cantAtenciones);
			}
				
		}
	}

fclose(pro);
fclose(tur);


}

void evolucionPacientes (FILE *tur,FILE *client)	
{

	Turnos turn;
	Cliente clie;
	int auxDniClien=0;
	bool centinela=false;

	tur=fopen("turnos.dat","r+b");
	client=fopen("Clientes.dat","r+b");

    centinela=false;


	printf("\nDNI del Cliente: ");
	scanf("%d",&auxDniClien);

	rewind(client);
	fread(&clie,sizeof(Cliente),1,client);
   
   while (!feof(client) && centinela == false && (client != NULL) )
    {
		   

		if(auxDniClien == clie.dniCliente)
		{
		    centinela = true;

	    }
	
		fread(&clie,sizeof(Cliente),1,client);	

	}

	printf("\n\n");
	
	if(centinela == true)
	{
			
 		rewind(tur);

		fread(&turn,sizeof(Turnos),1,tur);
		
		while(!feof(tur) && (tur != NULL) )
		{											
		    if( auxDniClien == turn.dniCliente)
			{
											
				fseek(tur,(long) -sizeof(Turnos),SEEK_CUR);	
								
				printf("\nRegistre la evolucion del cliente: ");
															
				fflush(stdin);
				gets(turn.detalleDeAtencion);
				fwrite(&turn, sizeof(Turnos), 1,tur);
															
				fread(&turn, sizeof(Turnos), 1,tur);								
			}
														
			else
			{
									
			    fread(&turn, sizeof(Turnos), 1,tur);											
			}																							
		}
											
			if(tur == NULL)
			{
			    printf("El paciente esta Registrado\n Pero 'No se Registraron Turnos '...");
			}	
			else if( auxDniClien != turn.dniCliente )
			{
			
				printf("\nlos valores ingresados no coinciden...\n");	
			}
	
	}
	
	
	fclose(client);
	fclose(tur);
}


void BorradoFisico(FILE *turno, FILE *auxTurno)
{
	Turnos turnos;
	Profesional profs; 
	int auxId =0;
	
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
	
	printf ("Para borrar un turno ingrese el id del profesional que atendio al cliente: ");
	scanf ("%d", &auxId);
	
	while (!feof(turno))
	{
		if ( turnos.idProfesional != auxId)
		{
			fwrite(&turnos, sizeof(Turnos), 1, auxTurno);
		}
		
		fread(&turnos, sizeof(Turnos), 1, turno);
	}
	
	fclose(turno);
	fclose(auxTurno);
	
	remove("turnos.dat");
	rename("auxiliar.dat", "turnos.dat");
	
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
			printf ("Error al abrir el archivo \n");
			exit(EXIT_FAILURE);
	}
	
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
			printf ("Error al abrir el archivo \n");
			exit(EXIT_FAILURE);
	}

	
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
	
	
	return flag;
}


main()
{
    FILE *recep;
    FILE *prof;
    FILE *cliente;
    FILE *turno;
    FILE *auxTurno; 
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
                    opcEspacios = MenuEspacios(sesionInic);
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
									evolucionPacientes (turno,cliente);
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
									RegistrarCliente (cliente);
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
									regiTurnos (turno, prof, cliente);	
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
								RegistrarProfesional(prof);
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
								RankingProfesionales(turno, prof);
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
