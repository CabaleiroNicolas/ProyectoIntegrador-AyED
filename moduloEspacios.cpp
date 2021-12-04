#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//modulo espacios

int Menu()
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

main()
{
	
	FILE *archivo;
    
	int opc = 0;
	
	archivo = fopen("espacios.dat", "r+b");
	
	if (archivo == NULL)
	{
		printf("El archivo no existe, se intentara crearlo...");
		
		archivo = fopen("espacios.dat", "w+b");
		
		if (archivo == NULL)
		{
			printf("Error. No se pudo crear el archivo...");
			exit(1);
		}
		
		printf("\nArchivo creado exitosamente...\n\n");
		system("pause");
	}
		
	
	do 
	{
		
		system("cls");
		opc = Menu();
		system("cls");
		
		switch ( opc )
		{
			
			case 1:
				{
					printf("Iniciar Sesión");
					break;
				}

			case 2:
				{
					printf("Visualizar Lista de Espera de Turnos (informes)\n\n");
					break;
				}

			case 3:
				{
					printf("Registrar Evolucion del tratamiento\n");
					break;
				}

			case 4:
				{
					printf("Cerrar la aplicacion\n");	
					break;
				}
			default:
				{
					printf("Opcion incorrecta...");
					break;
				}	
		}; // switch
		
		printf("\n\n");
		system("pause");
	} while ( opc != 0);
	
