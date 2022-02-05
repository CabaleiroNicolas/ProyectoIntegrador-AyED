#include "estructuras.h"

void evolucionPacientes(FILE *fp_turno,FILE *cliente, FILE *auxTurn)	
{

	Turnos turn;
	Cliente clie;
	int auxDniClien=0;
	bool centinela=false;
	bool evolucion = false;
    int i=0;
    
	fp_turno=fopen("turnos.dat","r+b");
	cliente=fopen("Clientes.dat","rb");
	
   	fread(&turn,sizeof(Turnos),1,fp_turno);

		while (!feof(fp_turno))
	    {
			   
			i++;
			fread(&turn,sizeof(Turnos),1,fp_turno);

		}

	if(i == 0)
	{
		printf("\nTodavia no se Registro Ningun Paciente...");
	}
	else
	{
		printf("\nDNI del Cliente: ");
		scanf("%d", &auxDniClien);
	
		rewind(cliente);
		fread(&clie, sizeof(Cliente), 1, cliente);
	   
	   	while (!feof(cliente) && centinela == false)
	    {
			   
			if(auxDniClien == clie.dniCliente)
			{
			    centinela = true;
	
		    }
			else
			{
				fread(&clie,sizeof(Cliente),1,cliente);	
			}
		}
		
		printf("\n\n");
		
		if(centinela == true)
		{
			rewind(fp_turno);
	
			fread(&turn,sizeof(Turnos),1,fp_turno);
			
			while(!feof(fp_turno) && 	evolucion  == false)
			{											
			    if( auxDniClien == turn.dniCliente && 	evolucion == false && turn.atendido == false )
				{
					printf("\nRegistre la evolucion del Paciente: ");
					fflush(stdin);
					turn.atendido = true; //Marca que fue atendido el paciente
					gets(turn.detalleDeAtencion);
					fseek(fp_turno, -sizeof(turn),SEEK_CUR);
					fwrite(&turn, sizeof(Turnos), 1,fp_turno);	
					evolucion = true;					
				}   
				else
				{
					fread(&turn, sizeof(Turnos), 1,fp_turno);	
					evolucion = false;							
			   }
			}
			
			if(centinela== true &&  evolucion == false)
			{
			    printf("El paciente esta Registrado\n Pero 'No se Registraron Turnos a su Nombre '...");
			}
		}
		
	}
		
	fclose(cliente);
	fclose(fp_turno);
}
void regiTurnos(FILE *turno, FILE *archProfesional, FILE *cliente) //modulo recepcionista
{
	Turnos turnos;
	Profesional prof;
	Cliente clientes;
	bool bandProf = false;
	bool bandClie = false;

	archProfesional = fopen("Profesionales.dat", "rb");
	cliente = fopen("Clientes.dat", "rb");

	turno = fopen("turnos.dat","a+b");
	if(turno == NULL)
	{
		turno = fopen("turnos.dat", "a+b");
	}
		
	
	printf("\nREGISTRACION DE TURNO\n");
	
	printf("\nID del profesional: ");
	scanf("%d",&turnos.idProfesional);
	
	//Verifica que el id del profesional exista
	fread(&prof,sizeof(Profesional),1,archProfesional);
	
	while(!feof(archProfesional) && bandProf == false)
	{
		if(turnos.idProfesional == prof.idProfesional)
		{
			bandProf = true;
		}
		else
		{
			fread(&prof,sizeof(Profesional),1,archProfesional);
		}		
	} 
		
	printf("\nDNI del cliente: ");
	scanf("%d",&turnos.dniCliente);
	
	fread(&clientes,sizeof(Cliente),1,cliente);
	//Verifica que el DNI del cliente exista
	while(!feof(cliente) && bandClie == false)
	{
		if(turnos.dniCliente == clientes.dniCliente)
		{
			bandClie = true;
		}
		else
		{
			fread(&clientes,sizeof(Cliente),1,cliente);
		}
	}  	

	//Si ambos estan dados de alto, asigna un turno
	if(bandClie == true && bandProf == true)
	{
			
		printf("\nFecha del turno: ");
		
		printf("\n\tDia: ");
		scanf("%d", &turnos.fechaDeTurno.dia);
		printf("\n\tMes: ");
		scanf("%d", &turnos.fechaDeTurno.mes);
		printf("\n\tA%co: ",164);
		scanf("%d", &turnos.fechaDeTurno.anio);
				
		printf("\nDetalle de atencion: ");
		_flushall();
		gets(turnos.detalleDeAtencion);
		
		turnos.atendido = false; //indica que el cliente no fue atendido 
			
		fwrite(&turnos,sizeof(Turnos),1,turno);	
		//fwrite (&contTurn, sizeof(contTurn), 1, contTurn);
	}
	else
	{
		system("cls");
		printf("\n\nNo Se registro Paciente o Profesional con esas Credenciales...");
	}
	
	fclose(turno);
	fclose(archProfesional);
	fclose(cliente);
}

void RegistrarCliente (FILE *cliente)//modulo recepcionista
{
	Cliente clientes;
	cliente = fopen("Clientes.dat", "a+b");

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
	
	printf ("\nIngrese el peso del cliente en kg: ");
	scanf ("%f", &clientes.peso);
		
	printf ("\nIngrese la fecha de nacimiento del cliente: ");
	_flushall ();
	printf ("\n\tDia: ");
	scanf("%d" ,&clientes.fechaDeNacimiento.dia);
	printf ("\n\tMes: ");
	scanf("%d" ,&clientes.fechaDeNacimiento.mes);
    printf ("\n\tAnio (el anio debe ser de 4 digitos): ", 164 );
	scanf("%d" ,&clientes.fechaDeNacimiento.anio);
	
	clientes.edad = 2021 - clientes.fechaDeNacimiento.anio;
	
	printf ("Ingrese un Telefono de contacto del cliente: ");
	_flushall();
	gets (clientes.telefono);
	
	fwrite(&clientes, sizeof(Cliente), 1,cliente);
	
	printf("\n\nCliente Registrado con Exito!\n\n");
	
	fclose (cliente);
}

void listadoAtencionProf (struct Profesional vecProf [TAM], struct Cliente vecCliente [TAM],  FILE *turno) //modulo recepcionista
{

	int auxpro=0;
	Turnos turnos;

	turno=fopen("turnos.dat","rb");


	printf("Ingrese ID del Profesional: ");
	scanf ("%d", &auxpro);
	
	fread(&turnos,sizeof(Turnos),1,turno);

	while(!feof(turno))
		{
			if(turnos.idProfesional==auxpro)
				{
					printf("\nFecha de turno:");
					printf("\nDia: %d", turnos.fechaDeTurno.dia);
					printf("\nMes: %d", turnos.fechaDeTurno.mes);
					printf("\nA%co: %d\n",164, turnos.fechaDeTurno.anio);
					printf("\nDNI de Paciente: %d\n", turnos.dniCliente);
					printf("============================================\n");
					
				}
			fread(&turnos,sizeof(Turnos),1,turno);
	    }

	fclose (turno);
}


void listaEspera(FILE *turno, FILE *prof, FILE *cliente) // modulo espacios
{

	turno=fopen("turnos.dat","a+b");
	prof=fopen("Profesionales.dat","a+b");
	cliente=fopen("Clientes.dat","a+b");
	
	Turnos turnos;
	Profesional profs;
	Cliente clientes;
	int auxId=0;
	int i=0;
	bool tengopacientes=false;
    //int op;
            
	if(turno == NULL)
	{
		printf("\nNo hay Turnos...\n\n");
		system("pause");
	}
	else
	{
	
		
		system("cls");
		printf("LISTA DE ESPERA DE CLIENTES\n");
		printf("---------------------------\n");
		
		//rewind(turno);
		//rewind(prof);
		//rewind(cliente);
					
		fread(&turnos,sizeof(Turnos),1,turno);
		
		printf ("\nIngrese su id, para ver su lista de espera: ");
		scanf ("%d", &auxId); 
					
		do
		{
			if(auxId==turnos.idProfesional && turnos.atendido == false)
			{
						
				printf("\nTurno %d:\n",i+1);
				printf("\nFecha De Turno :");
				printf("\n\tDia: %d",turnos.fechaDeTurno.dia);
				printf("\n\tMes: %d",turnos.fechaDeTurno.mes);
				printf("\n\tA%co: %d",164,turnos.fechaDeTurno.anio);
				printf("\nDNI del cliente: %d", turnos.dniCliente);
				fread(&turnos,sizeof(Turnos),1,turno);
				tengopacientes=true;	
				/*
				printf("\nNombre y apellido: %s",clientes.apeNom);
				printf("\nEdad: %d a%cos", clientes.edad, 164);
				printf("\nLocalidad: %s", clientes.localidad );
				printf("\nPeso: %.2f",clientes.peso);
							
				fread(&profs,sizeof(Profesional),1,prof);

				fread(&clientes,sizeof(Cliente),1,cliente);
				*/
			}
			
			else 
			{
				fread(&turnos,sizeof(Turnos),1,turno);
			}
			
			i++;
			
		}while(!feof(turno));
		
		if (tengopacientes == false)
		{
			printf ("No tiene pacientes en su lista de espera.\n");					
		}	
		
	}
	
	fclose(prof);
	fclose(turno);
	fclose(cliente);
	
	printf("\n\n");
}

void RankingProfesionales()
{
	FILE *Prof;
	FILE *Turno;
    
	Profesional prof[50];
	Turnos turnos[50];
	Atenciones reg_atenciones[50],aux;
	bool band = true,stop;
    int i = 0;
	int num_meds = 0;
	int num_turnos = 0; 
	int contador = 0;

    Prof=fopen("Profesionales.dat","rb");

    if (Prof==NULL)
    {
        printf("\nEl archivo 'Profesionales.dat' no fue creado o se elimino.");
		band = false;
    }
    else
    {
        fread(&prof[i],sizeof(Profesional ),1,Prof);
        while (!feof(Prof))
        {
            i++;
            fread(&prof[i],sizeof(Profesional ),1,Prof);
        }
        num_meds = i;
        i = 0;
        fclose(Prof);
    }

	//Archivo de turnos:
    Turno=fopen("Turnos.dat","rb");

    if (Turno==NULL)
    {
        printf("\nEl archivo 'Turnos.dat' no fue creado o se elimino.");
		band = false;
    }
    else
    {
        fread(&turnos[i],sizeof(Turnos),1,Turno);
        while (!feof(Turno))
        {
            i++;
            fread(&turnos[i],sizeof(Turnos),1,Turno); 
        }
        num_turnos = i;
        i = 0;
        fclose(Turno);
    }

	if (band)
	{
		//Obtiene la cantidad de turnos por Medico:
		for (i = 0; i < num_meds; i++)
		{
			contador = 0;

			for (int k = 0; k < num_turnos; k++)
			{
				if ((prof[i].idProfesional == turnos[k].idProfesional) && (turnos[k].atendido == true))
				{
					contador++;
				}
			}
			
			reg_atenciones[i].matriculamedico = prof[i].idProfesional;
			reg_atenciones[i].cant_atenciones = contador;
		}
		
		//Ordena el ranking de mayor a menor:
		do
		{
			stop=false;
			
			for (i = 0 ; i < num_meds-1 ; i++)
			{
				if(reg_atenciones[i].cant_atenciones < reg_atenciones[i+1].cant_atenciones)
				{
					aux=reg_atenciones[i];
					reg_atenciones[i]=reg_atenciones[i+1];
					reg_atenciones[i+1]=aux;
					stop=true;
				}
			}
		}
		while (stop);

		//Muestra el ranking de Medicos:
		for (i = 0; i < num_meds; i++)
		{
			printf("\nPuesto %d:",i+1);
			printf("\nid del profesional: %d",reg_atenciones[i].matriculamedico);
			printf("\nCantidad de atenciones: %d",reg_atenciones[i].cant_atenciones);
			printf("\n--------------------------------\n");
		}
		
	}
}

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
		enterPassword(prof.contrasenia, 12,1,11);
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
	int cantLogins;

	fp = fopen(userfile, "a+b");

	if(fp == NULL)
	{
		printf("Error al abrir el archivo \n");
		exit(EXIT_FAILURE);
	}
	
	
	printf("\nNombre de Usuario: ");
	_flushall();
	gets(reg.usuario);
	
	cantLogins= *(&logins + 1) - logins;
	
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


void cargarProf (struct Profesional vecProf[TAM], FILE *prof)
{
    int i=0;
    int j=0;
    Profesional profs; 
    prof  = fopen("Profesionales.dat", "r+b");
    
    if(prof == NULL)
	{
		prof = fopen("Profesionales.dat", "rb");
		
		printf("\nNo se pudo crear archivo Profesionales.dat");
		exit(EXIT_FAILURE);
	}
	
	fread(&profs,sizeof(Profesional),1,prof);
	
	while (!feof(prof))
	{
	  vecProf[i].idProfesional = profs.idProfesional;
	  strcpy (profs.apeNom, vecProf[i].apeNom) ;
	  
	 fread(&profs,sizeof(Profesional),1,prof);
	 i=i+1;
	}
	
	fclose (prof);
}
//carga a los clientes en un vec de registros 
void cargarClientes (struct Cliente vecCliente [TAM], FILE *fcliente)
{
    int i=0;
    int j=0;
    Cliente clientes; 
    fcliente = fopen("Clientes.dat", "r+b");
    
    if(fcliente == NULL)
	{
		fcliente = fopen("Clientes.dat", "rb");
		
		printf("\nNo se pudo crear archivo Clientes.dat");
		exit(EXIT_FAILURE);
	}
	
	fread(&clientes,sizeof(Cliente),1,fcliente);
	
	while (!feof(fcliente))
	{
	  vecCliente[i].dniCliente = clientes.dniCliente;
	  strcpy (clientes.apeNom, vecCliente[i].apeNom) ;
	  
	 fread(&clientes,sizeof(Cliente),1,fcliente);
	 i=i+1;
	}
	
	fclose (fcliente);
	
}

void listarProf (FILE *prof)
{
	Profesional profs;
	prof = fopen("Profesionales.dat", "rb");
	
	if(prof == NULL)
	{
		prof = fopen("Profesionales.dat", "rb");
		
		printf("\nNo se pudo crear archivo Profesionales.dat");
		exit(EXIT_FAILURE);
	}
	
	fread(&profs,sizeof(Profesional),1,prof);
	
	while (!feof(prof))
	{
	 printf("\nApellido y Nombre:");
	 puts(profs.apeNom);
	 printf("ID: %d\n",profs.idProfesional);
	
	 fread(&profs,sizeof(Profesional),1,prof);
	}
	
	fclose (prof);
	
}

void listarClientes (FILE *cliente)
{
	Cliente clientes;
	cliente = fopen("Clientes.dat", "rb");
	
	if(cliente == NULL)
	{
		cliente = fopen("Clientes.dat", "rb");

		printf("\nNo se pudo crear archivo Clientes.dat");
		exit(EXIT_FAILURE);
	}
	
	fread(&clientes,sizeof(Cliente),1,cliente);
	
	while (!feof(cliente))
	{
	 
	 printf("Apellido y Nombre:");
	 puts(clientes.apeNom);
	 printf("\nDNI: %d\n\n",clientes.dniCliente);

	 fread(&clientes,sizeof(Cliente),1,cliente);
	}
	
	fclose (cliente);
	
}
