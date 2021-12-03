#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//modulo administracion

int Menu()
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
main()
{
	
	FILE *archivo;
	
	int opc = 0;

	archivo = fopen("ventas.dat", "r+b");
	
	if (archivo == NULL)
	{
		printf("El archivo no existe, se intentara crearlo...");
		
		archivo = fopen("ventas.dat", "w+b");
		
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
					printf("Registrar Profesional");
					break;
				}

			case 2:
				{
					printf("Registrar Usuario Recepcionista\n\n");
					break;
				}

			case 3:
				{
					printf("Atenciones por Profesionales\n");
					break;
				}

			case 4:
				{
					printf("Ranking de Profesionales por Atenciones\n");
					break;
				}

			case 5:
				{
					printf("Cerrar la aplicacion.\n");
					break;
				}
			default:
				{
					printf("Opcion incorrecta...");
					break;
				}	
		}; 
		
		printf("\n\n");
		system("pause");
		
	} while ( opc != 0);
	
