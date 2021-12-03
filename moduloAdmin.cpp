#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//modulo administracion

int Menu()
{
	int opcion = 0;
	
	printf("MENU");
	printf("\n----\n");
	
	printf("\n1- Registrar Profesional");
	printf("\n2- Registrar Usuario Recepcionista");
	printf("\n3- Atenciones por Profesional");
	printf("\n4- Ranking de Profesionales por Atenciones");
	printf("\n5- Cerrar la aplicacion.");
	printf("\n\nIngrese una opcion: ");
	scanf("%d", &opcion);
	
	return opcion;
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
	
