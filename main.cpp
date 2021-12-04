#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


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



int MenuRecepcion()
{

    int opc = 0;

    printf("\n===============================");
    printf("\n     MODULO RECEPCION");
    printf("\n===============================");

    printf("\n\n1.- Iniciar Sesion");
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



int MenuEspacios()
{
    int opc = 0;

    printf("\n===============================");
    printf("\n      MODULO ESPACIOS");
    printf("\n===============================");

    printf("\n\n1.- Iniciar Sesion");
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

void login ()
{
	
}


void ValidUser(char usuario[10])
{
	int longitud = 0;
	int letrasMayusculas = 0;
	int digitos = 0;
	
	longitud = strlen(usuario);
	
	if(longitud > 10)
	{
		printf("\nEl usuario no puede contener mas de 10 caracteres...")
	}
	else
	{
		
		for(int i = 0; i < 10: i++)
		{
			if(usuario[1] >= 'a' && usuario[1] <= 'z')
			{
				if(usuario[i] >= 'A' && usuario[i] <= 'Z')
				{
					letrasMayusculas++;
				}
				
				if(usuario[i] >= 0 && usuario[i] <= 9)
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
                    opcion = MenuEspacios();
                    system("cls");

                        switch(opcion)
                        {
                            case 1:
                            {

                                break;
                            }

                            case 2:
                            {

                                break;
                            }

                            case 3:
                            {

                                break;
                            }

                            case 0:
                            {

                                break;
                            }

                            default:
                            {

                                break;
                            }


                        }

                    break;
                }
            case 2:
                {
                    system("cls");
                    opcion = MenuRecepcion();
                    system("cls");

                        switch(opcion)
                        {
                            case 1:
                            {

                                break;
                            }

                            case 2:
                            {

                                break;
                            }

                            case 3:
                            {

                                break;
                            }

                            case 4:
                            {

                                break;
                            }

                            case 0:
                            {

                                break;
                            }

                            default:
                            {

                                break;
                            }


                        }

                    break;
                }
            case 3:
                {
                     system("cls");
                    opcion = MenuAdministracion();
                    system("cls");

                        switch(opcion)
                        {
                            case 1:
                            {

                                break;
                            }

                            case 2:
                            {

                                break;
                            }

                            case 3:
                            {

                                break;
                            }

                            case 4:
                            {

                                break;
                            }

                            case 0:
                            {

                                break;
                            }

                            default:
                            {

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
