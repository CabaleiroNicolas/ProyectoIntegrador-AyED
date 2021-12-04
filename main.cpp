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
    setTextColor(9);
    printf("-- Menu Principal --");
    printf("\n\n1.- Modulo Espacios.");
    printf("\n2.- Modulo Recepcionista");
    printf("\n3.- Modulo Administracion");
    printf("\n0.- Cerrar Aplicacion");
    printf("\n\nIngrese una Opcion: ");
    scanf("%d", &opc);
	setTextColor(7);
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
    printf("\n2.- Registrar Usuario");
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
		printf("\n\t1.- Iniciar Sesion");
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


struct Usuario
{
    char usuario[10];
    char contra [10];
    char apeNom[60];
};

struct Profesional
{
    char apeNom[60];
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
	 	cout << "\nLong. invalida de clave.";
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
		cout << "\nLa clave debe contener al menos una mayuscula.";
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
		cout << "\nLa clave debe contener al menos una minuscula.";
		retorno = 1;
	 }
	 //Valida que contenga solo caracteres alfanumericos
	 i=0;
	 flag = 0;
	 while ((clave[i]) && flag == 0)
	  {
	    if (!isalnum(clave[i]) ) 
	    {
			cout << "\nLa clave debe tener solo caracteres alfanumericos.";
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
	  	cout << "\nLa clave no puede tener mas de 3 numeros consecutivos seguidos.";
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
	    				cout << "\nLa clave no puede contener caracteres alfabeticos consecutivos.";
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
		   cout<<"*";
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


main()
{
    FILE *usuario;
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
				printf("Registrar a un profesioanl.");
                                break;
                            }

                            case 2:
                            {
				printf("Registrar a un recepcionista.");
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
