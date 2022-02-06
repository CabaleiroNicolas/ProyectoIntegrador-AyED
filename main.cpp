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
#include "funciones.h"
typedef char cadena [60];
int cantLogins =0;
int idProfesional=0;
bool sesionInic = false;
bool sesionInicProf = false; 

int MenuGeneral()
{
    int opc = 0;
    
    cout <<"\n\n\n";
	cout <<replicate(" ",50)+"-- Menu Principal --\n";
	cout <<"\n";
    cout <<replicate(" ",50)+"1.- Modulo Espacios.\n";
    cout <<replicate(" ",50)+"2.- Modulo Recepcionista\n";
    cout <<replicate(" ",50)+"3.- Modulo Administracion\n";
    cout <<replicate(" ",50)+"4.- Acerca de...\n";
    cout <<replicate(" ",50)+"0.- Cerrar Aplicacion\n";
    cout <<"\n";
    cout <<replicate(" ",50)+"  Ingrese una Opcion: ";
    scanf("%d", &opc);
	
    return opc;
}

int MenuRecepcion(bool sesionInic)
{
    int opc = 0;

    printf("\n================================");
    printf("\n       MODULO RECEPCION");
    printf("\n================================\n");

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

    printf("\n================================");
    printf("\n       MODULO ESPACIOS");
    printf("\n================================\n");

   
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

    printf("\n====================================");
    printf("\n       MODULO ADMINISTRACION");
    printf("\n====================================\n");

    printf("\n1.- Registrar Profesional");
    printf("\n2.- Registrar Usuario Recepcionista");
    printf("\n3.- Atenciones por Profesional");
    printf("\n4.- Ranking de Profesionales por Atenciones");
    printf("\n5.- Listado de Profesionales");
    printf("\n6.- Listado de Clientes");
    printf("\n0.- Retornar al menu principal");

    printf("\n\nIngrese una Opcion: ");
    scanf("%d", &opc);

    return opc;
}

int loginProf(FILE *prof)
{
	int idVerificar = 0; 
	int idProfesional=0;
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
			idProfesional=idVerificar;
		}
		
		while(!feof(prof) && flag == false)
		{
			if (idVerificar == reg.idProfesional && strcmp(passVerificar, reg.contrasenia) == 0)
			{
				flag = true;
				idProfesional=idVerificar;
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
	
	return idProfesional;
}

void fespacio(bool sesionInicProf, FILE *prof )
{
	FILE *turno;
	FILE *cliente;
	FILE *auxTurno;
	int opcEspacios;
	  do
	  {
   	    system("cls");	  	
        opcEspacios = MenuEspacios(sesionInicProf);
        system("cls");

        switch(opcEspacios)
        {
            case 1:
            {
            	idProfesional = loginProf(prof);
            	if (idProfesional > 0 )
            	{
            		sesionInicProf = true;
				}
				else
				{
					sesionInicProf = false;
				}
                break;
            }

            case 2:
            {
				if(sesionInicProf == false)
				{
					printf("\n=============================================================================");
                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
                 	printf("\n=============================================================================\n\n");
					system ("pause");
				}
				else
				{
					printf("Listado de espera de Turnos.\n\n");
     				listaEspera(turno, prof, cliente,idProfesional);
					system ("pause");
				}
                break;
            }

            case 3:
            {

                if(sesionInicProf == false)
				{
					
					printf("\n=============================================================================");
                 	printf("\nDebe iniciar sesion para realizar una accion, por favor escoja la opcion 1");
                 	printf("\n=============================================================================\n\n");
					system("pause");
					
				}
				else
				{
                    printf("Registrar evolucion del tratamiento.\n\n");							
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
	            printf("\nEsa opcion no se encuentra en el Menu.\n");
	            printf("\n=======================================\n\n");
	            system("pause");
                break;
            }
    	 }
	} while(opcEspacios !=0);
}

void frecepcion(char userfile[])
{
	FILE *cliente;
	FILE *turno;
	FILE *prof;		
	int opcRecep;
	do
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
					listadoAtencionProf (vecProf, vecCliente, turno);
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
	}	
	while(opcRecep != 0);
}

void fadmin(char userfile[], Login logins [255])
{
  int opcAdmin=0;
  FILE * prof;
  FILE * turno;
  FILE * cliente;
  do{
  
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
					AtencionPorProf(turno);
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
                
                case 5:
                {
					printf("Listado de Profesionales.\n\n");
					listarProf (prof);
					printf("\n\n");
					system("pause");
                    break;
                }
                
                case 6:
                {
					printf("Listado de clientes.\n\n");
					listarClientes (cliente);
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
	}
	while (opcAdmin != 0);
}

main()
{
    FILE *recep;
    FILE *prof;
    FILE *cliente;
    FILE *turno;
    FILE *auxTurno; 
	char userfile[255] = {"Usuarios.dat"}; //Nombre del archivo de usuarios
	int opcEspacios = 0;
    int opcRecep = 0;
    int opcAdmin = 0;
    int opcion = 0;
    Login logins[255];
    
   cantLogins = leerLogins (userfile, logins);//leo inicialmente todos los usuarios existentes
   
   logoutn(); 
    
    do
    {

        system("cls");
        opcion = MenuGeneral();
        system("cls");

       switch(opcion)
       {
           case 1:
				{
				fespacio(sesionInicProf, prof );
				break;
                }
            case 2:
                {
				frecepcion(userfile);
                break;
                }
            case 3:
                {
                	fadmin(userfile,logins);
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
                    printf("\nCerrando Programa...");
                    printf("\n=======================================\n\n");
                    system("pause");
                    break;
                }
            default :
                {
                    printf("\n=======================================");
                    printf("\nEsa Opcion no se encuentra en el Menu.");
                    printf("\n=======================================\n\n");
                    system("pause");
                    break;
                }
              

       }

    } while (opcion != 0);
    
}