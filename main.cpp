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
    int cantidad;
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
};

struct Turnos
{
    int idProfesional;
    Fecha fechaDeTurno;
    int dniCliente;
    char detalleDeAtencion[380];
};

/*
struct Usuario 
{
	char usuario [10];
	char password [33];
	char ApeNom [60];
	
};

struct Login 
{
	char usuario [10];
};
*/


/*int checkPassword(char clave[32])
{
	 int longitud;
	 int i = 0;
	 int flag = 0;
	 int ascii=0;
	 int aux = 0;
	 int j;
	 int retorno = 0;
	 
	 longitud = strlen(clave);
	 //Valida la longitud de la clave
	 if (longitud <6  || longitud > 32)
	 {
	 	printf("\nLa Clave tiene que tener 6 caracteres como minimo y 32 como maximo.");
	 	retorno = 1;
	 }
	  //Valida que contenga al menos un caracter en mayuscula
	 flag = 0;
	 i=0;
	 while ((clave[i]) && flag == 0)
	  {
	    if (isupper(clave[i])) 
	    {
				flag = 1;
		}	
	    i++;
	  }
	 if (flag == 0)  
	 { 
		printf("\nLa clave debe contener al menos una mayuscula.");
		retorno = 1;
	 }
	 //Valida que contenga al menos un caracter en minuscula
	 flag = 0;
	 i=0;
	 while ((clave[i]) && flag == 0)
	  {
	    if (islower(clave[i])) 
	    {
				flag = 1;
		}	
	    i++;
	  }
	 if (flag == 0)  
	 { 
		printf("\nLa clave debe contener al menos una minuscula.");
		retorno = 1;
	 }
	 
	 //Valida que contenga solo caracteres alfanumericos
	 i=0;
	 flag = 0;
	 while ((clave[i]) && flag == 0)
	  {
	    if (!isalnum(clave[i]) ) 
	    {
			printf("\nLa clave debe tener solo caracteres alfanumericos.");
			flag = 1;
			retorno = 1;
		}	
	    i++;
	  }
	  
	  //Valida que no contenga mas de 3 caracteres numericos consecutivos
	 flag=0;
	 i=0;
	 while (clave[i])
	  {
	    if (isdigit(clave[i])) 
	    {
			flag++;
		}	
		else
		 {
		 	if (flag > 0)
		 	   flag = flag - 1;
		 }
		
	    i++;
	  }
	  
	  if (flag > 3)
	  {
	  	printf("\nLa clave no puede tener mas de 3 numeros consecutivos seguidos.");
	  	retorno = 1;
	  }
	 
	 //Valida que no existan letras consecutivas
	 flag=0;
	 i=0;
	 while ((clave[i]) && flag == 0)
	  {
	    if (isalpha(clave[i])) 
	    {
	    	
	    	aux = (int) toupper(clave[i]); //Obtiene el valor ascii del caracter
	    	j = i+1;
	    	if (j<= longitud)
	    		ascii = (int) toupper(clave[j]);//Obtiene el valor ascii del sgte caracter
	    		if ((aux+1) == ascii)
	    			{
	    				printf("\nLa clave no puede contener caracteres alfabeticos consecutivos.");
	    				flag = 1;
	    				retorno = 1;
					}
		}	
	    i++;
	  }
	  return  retorno;
	 
}*/

/*
//Carga en un vector todos los usuarios existentes
int leerLogins (char userfile[], Login logins [255])
{
	FILE *fp; 
	Usuario reg;
	int i =0;
	fp=fopen(userfile,"rb");
	if (fp==NULL)
	{
		printf("Error al abrir el archivo % \n",userfile);
		//exit(EXIT_FAILURE);
		return -1; 
	}

	rewind(fp);
	fread(&reg,sizeof(reg),1,fp);
    strcpy(logins[i].usuario, reg.usuario);
    //printf ("reg usuario: %s", reg.usuario);
	while (!feof(fp))
	{
		if (!feof(fp))
		{
			strcpy(logins[i++].usuario, reg.usuario);
			//printf ("reg usuario: %s\n", reg.usuario);
     }
		fread(&reg,sizeof(reg),1,fp);
	}  
	fclose(fp);
	//system ("pause");
	return i;
}*/
/*
int ValidUser(char usuario[10], Login logins [255], int *cantLogins)
{

 int flag = 0;
 int longitud;
 int mayusculas=0;
 int digitos = 0;
 int espacios=0;
 int i=0;
 int n=0;
	
	n = *cantLogins;
	
	for (int j=0; j<=n; j++)
	{
		if (strcmp (usuario, logins[j].usuario)==0)
		{
			printf ("Usuario ya existente."); 
			flag=1;
			break;	
		}
		 
	}
 
 longitud = strlen(usuario);
 
 //Valida la longitud de la clave
 if (longitud < 6  || longitud > 10)
 {
 	printf ("\nLa longitud del nombre debe estar entre 6 y 10 caracteres.");
 	flag = 1;
 }
  
  //Chequea el nombre del usuario empice con minuscula
 if (islower(usuario[0]) == 0)
  {
     printf("\nEl nombre del usuario debe comenzar con una letra en minuscula.");
     flag = 1;
  }

 //Valida que contenga al 2 menos letras en mayuscula
 
 i=0;
 for(i = 0; i < longitud; i++)
  {
  	
    if (usuario[i] >= 'A' && usuario[i] <= 'Z') 
    {
		mayusculas++;
	}	

  }
  
if (mayusculas < 2)
{
	   printf("\nEl nombre del usuario debe contener al menos 2 letra en mayuscula.");
       flag = 1;
}

 i=0;
 while (usuario[i])
  {
    if (isdigit(usuario[i])) 
    {
		digitos++;
	}	
    i++;
  }
 if (digitos >3)
 {
	   printf("\nEl nombre del usuario no debe contener mas de 3 digitos.");
      flag = 1;
  } 
 
 //Valida que no contenga espacios en blanco

 i=0;
 while (usuario[i])
  {
    if (isspace(usuario[i])) 
    {
		espacios++;
	}	
    i++;
  }
 if (espacios > 0)
 {
	  printf("\nEl nombre del usuario no puede contener espacios.");
      flag = 1;
  } 
  
  return flag; 
	
}*/

/*
void enterPassword(char* verify, short int x, short int y, short int xAux) //Enmascara la contraseña ingresada
{

 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD pos = {x, y};
 char ch;
 int i=0;
 
 do
 {
	  ch=getch();
	  if(ch!=13)
	  {
		x = x+1;
		
		if (ch == 8)
		{
		     if (x > xAux)
	     	{
				 x = x - 1;
				 pos = {x, y};
				 SetConsoleCursorPosition(hConsole, pos);
			 	 WriteConsole(hConsole, " ", 1, NULL, NULL);
		 	     x=x-1;
			     pos = {x, y};
			 	 SetConsoleCursorPosition(hConsole, pos);
			 	 verify[i--];
				  
			 	 if (x <= xAux)
			 	 {
			 	   x = xAux + 1 ;	
			       pos = {x++, y};
			 	   SetConsoleCursorPosition(hConsole, pos);
				  }	
			}	 
		}
		         
       else
        {
	   		verify[i++]=ch; //Va cargando los caracteres ingresados
	   		printf ("*");
	   }
	}
	  else
	  {
	   verify[i++]='\0';
	  }
 }
 while(ch!=13);
 
printf ("\nverify: %s\n", verify);
 system ("pause");	 	
}*/

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
	enterPassword(prof.contrasenia, 12,6,12 ); //lee caracter a caracter la constraseña y la enmascara 
		
	while (checkPassword(prof.contrasenia) != 0) 
	{
	
		printf("\n\n");
		system("pause");
		system("cls");
		printf( "\nContrasenia: ");
		enterPassword(prof.contrasenia, 12,6,12);
	}

	printf("\nDNI: ");
	scanf("%d", &prof.dniProfesional);

	printf("\nTelefono: ");
	_flushall();
	gets(prof.telefono);

	fwrite(&prof, sizeof(Profesional), 1,archProfesional);

	fclose(archProfesional);

}

void RegistrarUsuario (char userfile[], Login logins [255], int *cantLogins) //modulo administracion
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
	
	strcpy(logins[*cantLogins].usuario,reg.usuario);
	

	fclose(fp);

}

/*
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
    printf ("Usuario:") ; 
    _flushall ();
	gets(usuario)  ;
	 
	printf ("Contrasenia: "); 
	enterPassword(password, 12,3,12); 
	printf ("\n"); 
	fread(&reg,sizeof(reg),1,fp);
	
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
}*/

void regiTurnos(FILE *turno) //modulo recepcionista
{
	Turnos turnos;
	turno =fopen("turnos.dat","a+b");
	
	if(turno == NULL)
	{
		turno = fopen("turnos.dat", "w+b");

		if(turno == NULL)printf("\nNo se pudo crear archivo Profesionales.dat");
	}

					
	printf("\nREGISTRACION DE TURNO\n");
	
	printf("ID del profesional: ");
	scanf("%d",&turnos.idProfesional);

	printf("Fecha:\n");
	
		printf("\nDia: ");
		scanf("%d", &turnos.fechaDeTurno.dia);
		printf("\nMes: ");
		scanf("%d", &turnos.fechaDeTurno.mes);
		printf("\nA%co: ",164);
		scanf("%d", &turnos.fechaDeTurno.anio);
		
	printf("\nDNI del cliente: ");
	scanf("%d",&turnos.dniCliente);
	
	printf("\nDetalle de atencion: ");
	_flushall();
	gets(turnos.detalleDeAtencion);

	fwrite(&turnos,sizeof(Turnos),1,turno);	
	
	printf("\nEl turno fue guardado correctamente...");
	
	fclose(turno);

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

		printf ("\nIngrese el Apellido y nombre del cliente: ");
		_flushall();
		gets (clientes.apeNom);
		
		printf ("\nIngrese el domicilio del cliente: ");
		_flushall();
		gets (clientes.domicilio);	
		
		printf ("\nIngrese el D.N.I del cliente sin puntos ni espacios: ");
		scanf ("%d", &clientes.dniCliente);
		
		printf ("\nLocalidad a la que pertenece el cliente : ");
		_flushall();
		gets (clientes.localidad);
		
		printf ("\nIngrese el peso del cliente: ");
		scanf ("%.2f", &clientes.peso);
			
		printf ("\nIngrese la fecha de nacimiento del cliente: ");
		_flushall ();
		printf ("\n\tDia: ");
		scanf("%d" ,&clientes.fechaDeNacimiento.dia);
		printf ("\n\tMes: ");
		scanf("%d" ,&clientes.fechaDeNacimiento.mes);
	    printf ("\n\tA%o: ", 164 );
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
	
	prof=fopen("Profesionales.dat","r+b"); // cambio a+b * r+b
	
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
					
					printf("\n Turno numero %d \n" , i);
					printf("\n --------- \n");
					printf("\nFecha:");
					printf("\n\tDia: %d", turnos.fechaDeTurno.dia);
					printf("\n\tMes: %d", turnos.fechaDeTurno.mes);
					printf("\n\tA%co: %d",164, turnos.fechaDeTurno.anio);
					printf("\nDNI del Usuario a registrar: %d", turnos.dniCliente);
					printf("\n --------- \n");
					i=i+1;
					
					fread(&turnos,sizeof(Turnos),1,turno);
				}
				
				else
				{
					fread(&turnos,sizeof(Turnos),1,turno);		
				}
				
				band = true;
				
			}
	
		}
		else
		{
			
			fread(&profs,sizeof(Profesional),1,prof);
			
		}
							
	}

	fclose (turno);
	fclose (prof);
	
	printf("\n\n");
	system("pause");
	system("cls");
	
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
						printf("\nA%co: %d",164, turnos.fechaDeTurno.anio);
						printf("\nNombre del profesional: %s",profs.apeNom);
						printf("\nID: %d",profs.idProfesional);
						
						fread(&profs,sizeof(Profesional),1,prof);
						fread(&turnos,sizeof(Turnos),1,turno);
						fread(&clientes,sizeof(Cliente),1,cliente);
					}	
			}
			else
			{
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
	int i=0;
    int op;
            
	if(turno == NULL)
	{
		printf("No hay Turnos...");
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

void RankingProfesionales(FILE *tur , FILE *pro)
{
	
	Profesional p;
	Turnos t;
	const int TAM = 40;
	int i=0;
	char umay[70];
	Profesional lista[TAM];
	int c= 0;
	int step=0;   
    int size=0;
	
	pro=fopen("Profesionales.dat","r+b");
	
	tur=fopen("turnos.dat","r+b");
	
	if(tur == NULL)
	{
		printf("\nNo se Atendio Ningun Paciente Hata el Momento...\n\n");
	}
	else
	{
	
	
		rewind(tur);
		rewind(pro);
		
		fread(&p,sizeof(Profesional),1,pro);
		fread(&t,sizeof(Turnos),1,tur);
		
		while(!feof(pro))
		{
			while(!feof(tur)){
				
				if(p.idProfesional == t.idProfesional)
				{
				
					i++;
					
					
					fread(&t,sizeof(Turnos),1,tur);
				}
				else
				{
					
					fread(&t,sizeof(Turnos),1,tur);	
				}
			}
			
			p.cantidad=i;
			
			fwrite(&p,sizeof(Profesional),1,pro);
	
	
			rewind(tur);
			i = 0;			
			fread(&p,sizeof(Profesional),1,pro);	
		}						
							
		
		
		rewind(pro);
		fread(&p,sizeof(Profesional),1,pro);
		
		while(!feof(pro))
		{
			
			lista[c] = p;
			c++;
			
			fread(&p,sizeof(Profesional),1,pro);	
		
		}
			
	   size=c;
	   
	  for(step = 0; step < (size-1) ; ++step) 
	  {
	
	    int swapped = 0;
	
	    for(i = 0; i < (size-step-1); ++i) 
	    {
	
	      if(lista[i].cantidad < lista[i+1].cantidad) 
	      {
	
	        Profesional temp = lista[i];
	        lista[i] = lista[i + 1];
	        lista[i + 1] = temp;
	
	        swapped = 1;
	      }
	    }
	
	    if (swapped == 0) 
	    {
	      break;
	    }
	
	  }
	  
	  printf (" cant lista: %d",lista[i].cantidad);
		for(i=0; i<size ;i++)
		{
	
	  	    printf("\n%d-- Profesional %s tiene %d cantidad de pacientes registrados",i+1,lista[i].apeNom,lista[i].cantidad);
		}
	}
}


main()
{
    FILE *recep;
    FILE *prof;
    FILE *cliente;
    FILE *turno;
	char userfile[255] = {"Usuarios.dat"}; //Nombre del archivo de usuarios
	bool sesionInic = false;
	int opcEspacios = 0;
    int opcRecep = 0;
    int opcAdmin = 0;
    int opcion = 0;
    int cantLogins =0;
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
                            	sesionInic = login (userfile );
									
                                break;
                            }

                            case 2:
                            {
								printf("Listado de espera de Turnos.\n\n");
								if(sesionInic == false)
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
                                if(sesionInic == false)
								{
									
									printf("\n=============================================================================");
				                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
				                 	printf("\n=============================================================================\n\n");
									system("pause");
									
								}
								else
								{
								
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
									regiTurnos (turno);	
									printf("\n\nTurno Registrado con Exito!\n\n");
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
								RegistrarUsuario(userfile, logins, &cantLogins);
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
