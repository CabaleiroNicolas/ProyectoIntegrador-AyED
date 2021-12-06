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

int MenuGeneral()
{
    int opc = 0;
    
	printf("-- Menu Principal --");
    printf("\n\n1.- Modulo Espacios.");
    printf("\n2.- Modulo Recepcionista");
    printf("\n3.- Modulo Administracion");
    printf("\n0.- Cerrar Aplicacion");
    printf("\n\nIngrese una Opcion: ");
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
		printf("\n\t1.- Iniciar Sesion");
	}
    printf("\n2.- Registrar Cliente");
    printf("\n3.- Registrar Turno");
    printf("\n4.- Listado de Atenciones por Profesional y Fecha");
    printf("\n0.- Cerrar Aplicacion");

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

    printf("\n\n1.- Registrar Profesional");
    printf("\n2.- Registrar Usuario Recepcionista");
    printf("\n3.- Atenciones por Profesional");
    printf("\n4.- Ranking de Profesionales por Atenciones");
    printf("\n0.- Cerrar Aplicacion");

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
    printf("\n0.- Cerrar Aplicacion");

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
    char telefono[25];
};
struct Cliente
{
    char apeNom[60];
    char domicilio[60];
    int dniCliente;
    char localidad[60];
    Fecha fechaDeNacimiento;
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


int checkPassword(char clave[32])
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
	 	printf("\nLong. invalida de clave.");
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
	 
}

void enterPassword(char* verify) //Enmasca la contrasenia ingresada
{

 char ch;
 int i=0;

 do
 {
	  ch=getch();
	  if(ch!=13)
		{
		   verify[i++]=ch; //Va cargando los caracteres ingresados
		   printf("*");
		}
		  else
		{
		   verify[i++]='\0';
		}
 } while(ch!=13);
}

void ValidUser(char usuario[10])
{
	int longitud = 0;
	int letrasMayusculas = 0;
	int digitos = 0;
	
	longitud = strlen(usuario);
	
	if(longitud > 10 || longitud < 6)
	{
		printf("\nEl usuario no puede contener mas de 10 caracteres...");
	}
	else
	{
		
		for(int i = 0; i < 10; i++)
		{
			if(usuario[1] >= 'a' && usuario[1] <= 'z')
			{
				if(usuario[i] >= 'A' && usuario[i] <= 'Z')
				{
					letrasMayusculas++;
				}
				
				if(usuario[i] >= '0' && usuario[i] <= '9')
				{
					digitos++;
				}
			}
			
		}
		
		if(letrasMayusculas > 1 && digitos < 4)
		{
			printf("\nUsuario Creado correctamente");
		}
		else
		{
			printf("\nEl Nombre de usuario ingresado no cumple con lo terminos indicados...");
		}
					
	}
	
}


void RegistrarProfesional(FILE *archProfesional)
{

	Profesional prof;

	archProfesional = fopen("Profesionales.dat", "r+b");

	if(archProfesional == NULL)
	{
		archProfesional = fopen("Profesionales.dat", "w+b");

		if(archProfesional == NULL)printf("\nNo se pudo crear archivo Profesionales.dat");
	}

	fseek(archProfesional, 0, SEEK_END);

	printf("ID de Profesional: ");
	scanf("%d", &prof.idProfesional);

	printf("Nombre y Apellido: ");
	_flushall();
	gets(prof.apeNom);

	printf("Contrasenia: ");
	_flushall();
	gets(prof.contrasenia);

	printf("DNI: ");
	scanf("%d", &prof.dniProfesional);

	printf("Telefono: ");
	_flushall();
	gets(prof.telefono);

	fwrite(&prof, sizeof(Profesional), 1,archProfesional);

	fclose(archProfesional);

}


void RegistrarRecepcionista(FILE *archRecepcionista)
{

	Recepcionista recep;

	archRecepcionista = fopen("Recepcionistas.dat", "r+b");

	if(archRecepcionista == NULL)
	{
		archRecepcionista = fopen("Recepcionistas.dat", "w+b");

		if(archRecepcionista == NULL)printf("\nNo se pudo crear archivo Profesionales.dat");
	}

	fseek(archRecepcionista, 0, SEEK_END);

	printf("Usuario: ");
	_flushall();
	gets(recep.usuario);

	printf("Contrasenia: ");
	_flushall();
	gets(recep.contrasenia);

	printf("Nombre y Apellido: ");
	_flushall();
	gets(recep.apeNom);

	fwrite(&recep, sizeof(Recepcionista), 1,archRecepcionista);

	fclose(archRecepcionista);

}

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
		
	printf("\nDNI del cliente: ",164);
	scanf("%d",&turnos.dniCliente);
	
	//printf("\nDetalle de atencion: ");
	//_flushall();
	//gets(t.detalle);

	fwrite(&turno,sizeof(Turnos),1,turno);	
	
	printf("\nEl turno fue guardado correctamente...");
	
	fclose(turno);

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
	
	fread(&prof,sizeof(Profesional),1,prof);
	
	fread(&turno,sizeof(Turnos),1,turno);
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
					
					fread(&turno,sizeof(Turnos),1,turno);
				}
				
				else
				{
					fread(&turno,sizeof(Turnos),1,turno);		
				}
				
				band = true;
				
			}
	
		}
		else
		{
			
			fread(&prof,sizeof(Profesional),1,prof);
			
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
	
	printf("LISTADO DE ATENCIONES POR PROFESIONALES Y FECHA\n");
	printf("Profesional: ");
	_flushall();
	gets(auxpro);
	
	fread(&prof,sizeof(Profesional),1,prof);
	fread(&turno,sizeof(Turnos),1,turno);
	fread(&cliente,sizeof(Cliente),1,cliente);
	
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
					
					fread(&prof,sizeof(Profesional),1,prof);
					fread(&turno,sizeof(Turnos),1,turno);
					fread(&cliente,sizeof(Cliente),1,cliente);
				}	
		}
		else
		{
			fread(&prof,sizeof(Profesional),1,prof);
			fread(&turno,sizeof(Turnos),1,turno);
			fread(&cliente,sizeof(Cliente),1,cliente);
		}
	}
	
	fclose(prof);
	fclose (turno);
	fclose (cliente);

}

main()
{
    FILE *recep;
    FILE *prof;
    FILE *cliente;
    FILE *turno;
	char myfile [255]={"Usuarios.dat"}; //Nombre del archivo de usuarios
	bool sesionInic = false;
	int opcEspacios = 0;
    int opcRecep =0;
    int opcAdmin=0;
    int opcion = 0;

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

                                break;
                            }

                            case 2:
                            {
								printf("Listado de espera de Turnos.");
								if(sesionInic == false)
									{
										printf("Debe iniciar sesion para realizar una accion, por favor escoja la opcion 1: ");
									
									}
									else
									{
										
									}
                                break;
                            }

                            case 3:
                            {
                                printf("Registrar evolucion del tratamiento.");
                                if(sesionInic == false)
									{
										printf("Debe iniciar sesion para realizar una accion, por favor escoja la opcion 1: ");
									
									}
								else
								{
										
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
								
								
                                break;
                            }

                            case 2:
                            {
								printf("Registrar a un cliente.");
								if(sesionInic == false)
								{
									printf("Debe iniciar sesion para realizar una accion, por favor escoja la opcion 1: ");
									
								}
								else
								{
									
								}
                                break;
                            }

                            case 3:
                            {
                                printf("Registrar un turno.");
                                if(sesionInic == false)
								{
									printf("Debe iniciar sesion para realizar una accion, por favor escoja la opcion 1: ");
									
								}
								else
								{
									regiTurnos (turno);	
								}  
                                break;
                            }

                            case 4:
                            {
                                printf("Listado de Atenciones por profesional y fecha.");
                                if(sesionInic == false)
								{
									printf("Debe iniciar sesion para realizar una accion, por favor escoja la opcion 1: ");
									
								}
								else
								{
									listadoAtencionProf (prof, turno, cliente);		
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
								printf("Registrar a un recepcionista.\n\n");
								RegistrarRecepcionista(recep);
								printf("\n\nRecepcionista Registrado con Exito!\n\n");
								system("pause");
                                break;
                            }

                            case 3:
                            {
   								printf("Atenciones por profesional.");
   								
                                break;
                            }

                            case 4:
                            {
								printf("Ranking de Profesionales por atencion.");
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
