#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//modulo recepcion

int Menu()
{
	int opcion = 0;
	
	printf("MENU");
	printf("\n----\n");
	
	printf("\n1- Iniciar Sesión");
	printf("\n2- Registrar cliente");
	printf("\n3- Registrar Turno");
	printf("\n4- Listado de Atenciones por Profesional y Fecha");
	printf("\n5- Cerrar la aplicacion");
	
	printf("\n\nPor favor,ingrese una Opcion: ");
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
					printf("Iniciar Sesión");
					break;
				}
				
			case 2:
				{
					printf("Registrar Cliente\n\n");
					break;
				}

			case 3:
				{
					printf("Registrar Turno\n");
					break;
				}

			case 4:
				{
					printf("Listado de Atenciones por Profesional y Fecha\n");
					break;
				}

			case 5:
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
