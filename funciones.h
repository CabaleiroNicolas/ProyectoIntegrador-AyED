#include "estructuras.h"
//Devuelve los datos del médico
string fGetDatoMedico( int idProfesional)
{
	FILE *prof;
	Profesional profs;
	prof = fopen("Profesionales.dat", "rb");
	string medico;
	bool band = false;
	if(prof == NULL)
	{
		prof = fopen("Profesionales.dat", "rb");
		
		printf("\nNo se pudo crear archivo Profesionales.dat");
		exit(EXIT_FAILURE);
	}
	rewind(prof);
	fread(&profs,sizeof(Profesional),1,prof);
	if (idProfesional == profs.idProfesional)	
	 {
	 	medico = profs.apeNom;
	 	band = true;
	 }
	
	while (!feof(prof) && band == false)
	{
		 if (idProfesional == profs.idProfesional)	
		 {
		 	medico = profs.apeNom;
		 	band = true;
		 }
	 fread(&profs,sizeof(Profesional),1,prof);
	}
	
	fclose (prof);
	return medico;
}

//Devuelve los datos del Cliente
string fGetDatoCliente( int dniCliente)
{
   FILE * fp_cliente;
	Cliente clientes;
	string apeNom;
	bool band = false;
	fp_cliente = fopen("Clientes.dat", "rb");
	
	if(fp_cliente == NULL)
	{
		fp_cliente = fopen("Clientes.dat", "rb");

		printf("\nNo se pudo crear archivo Clientes.dat");
		exit(EXIT_FAILURE);
	}
	
	fread(&clientes,sizeof(Cliente),1,fp_cliente);
	if (dniCliente == clientes.dniCliente)
	{
		apeNom = clientes.apeNom;
		band = true;
	}
	while (!feof(fp_cliente) && band == false)
	{
		if (dniCliente == clientes.dniCliente)
		{
			apeNom = clientes.apeNom;
			band = true;
		}
  	  fread(&clientes,sizeof(Cliente),1,fp_cliente);
	}
	fclose (fp_cliente);
	
	return apeNom;
  	
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
		printf("Error al abrir el archivo %s \n",userfile);
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


void AtencionPorProf (FILE *turno) //modulo admin
{
	string fecha;
	string paciente;
	string dni;
	string detalle;
	string dia;
	string mes;
	int cantidad;
	int auxpro=0;
	Turnos turnos;

	turno=fopen("turnos.dat","rb");
	
	printf("\nAtenciones por Profesionales\n");
	
	printf("Ingrese ID del Profesional a buscar: ");
	scanf ("%d", &auxpro);
	
	cout << replicate("-",85)+"\n";
	fecha ="| Fecha";
	cantidad = 12 - fecha.length(); 
	fecha = fecha + replicate(" ",cantidad);
	
	dni = "| DNI";
	cantidad = 12 - dni.length(); 
	dni = dni + replicate(" ",cantidad);
	
	paciente = "| Cliente";
	cantidad = 30 - paciente.length(); 
	paciente = paciente + replicate(" ",cantidad);
	
	detalle = "| Detalle";
	cantidad = 50 - detalle.length(); 
	detalle = detalle + replicate(" ",cantidad);
	
	cout << fecha+dni+paciente+detalle+"\n";					
	cout << replicate("-",85)+"\n";

	fread(&turnos,sizeof(Turnos),1,turno);
	while(!feof(turno))
	{
		if(turnos.idProfesional==auxpro)
		{	
			dia = replicate("0",2-to_string(turnos.fechaDeTurno.dia).length())+to_string(turnos.fechaDeTurno.dia);
			mes = replicate("0",2-to_string(turnos.fechaDeTurno.mes).length())+to_string(turnos.fechaDeTurno.mes);
			fecha = dia+"/"+mes+"/"+to_string(turnos.fechaDeTurno.anio);
			cantidad = 12 - fecha.length(); 
			fecha = fecha + replicate(" ",cantidad);
			
			dni = to_string(turnos.dniCliente);
			cantidad = 12 - dni.length(); 
			dni = dni + replicate(" ",cantidad);
			
			paciente = fGetDatoCliente(turnos.dniCliente);
			cantidad = 30 - paciente.length(); 
			paciente = paciente + replicate(" ",cantidad);
			
			detalle = turnos.detalleDeAtencion;
			cantidad = 50 - detalle.length(); 
			detalle = detalle + replicate(" ",cantidad);
			
			cout << fecha+dni+paciente+detalle+"\n";			
		}
		fread(&turnos,sizeof(Turnos),1,turno);
    }

	fclose (turno);
	printf("\n\n");
	
}


void listarProf (FILE *prof)
{
	Profesional profs;
	prof = fopen("Profesionales.dat", "rb");
	string medico;
	
	if(prof == NULL)
	{
		prof = fopen("Profesionales.dat", "rb");
		
		printf("\nNo se pudo crear archivo Profesionales.dat");
		exit(EXIT_FAILURE);
	}
	
	fread(&profs,sizeof(Profesional),1,prof);
	
	cout << replicate("-",60)+"\n";
	cout << "Apelliodo y Nombre       |    ID Prof.   |   DNI   \n";
	cout <<replicate("-",60)+"\n";
	
	while (!feof(prof))
	{
	 medico = profs.apeNom;
	 cout<<medico+replicate(" ",23- medico.length())+"  | "+to_string(profs.idProfesional)+replicate(" ",12- to_string(profs.idProfesional).length()) +"  | "+to_string(profs.dniProfesional) + "\n";
	
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
		
	printf("\nRegistro de Turnos\n");
	
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

//Listado de atención por profesional y por fecha
void listadoAtencionProf (struct Profesional vecProf [TAM], struct Cliente vecCliente [TAM],  FILE *turno) //modulo recepcionista
{

	int auxpro=0;
	int auxdia=0;
	int auxmes=0;
	int auxanio=0;
	string mes;
	string dia;
	int cantidad;
	string fecha;
	string cliente;
	Turnos turnos;

	turno=fopen("turnos.dat","rb");

	printf("Ingrese ID del Profesional: ");
	scanf ("%d", &auxpro);
	cout <<"\nDoctor: "+fGetDatoMedico(auxpro)+"\n";
	
	printf("\nIngrese la fecha de consulta\n");
	printf("\t\nD%ca:",161);
	scanf ("%d", &auxdia);
	printf("\t\nMes:");
	scanf ("%d", &auxmes);
	printf("\t\nA%co:",164);
	scanf ("%d", &auxanio);
	
	cout << replicate("-",60)+"\n";
	cout <<"  Fecha    | Paciente                   | DNI\n";
	cout << replicate("-",60)+"\n";

	fread(&turnos,sizeof(Turnos),1,turno);
	while(!feof(turno))
		{
			if((turnos.idProfesional==auxpro) && (turnos.atendido == true)&&(turnos.fechaDeTurno.anio == auxanio)&&(turnos.fechaDeTurno.mes == auxmes)&&(turnos.fechaDeTurno.dia == auxdia))
				{
					cantidad = 2 - to_string(turnos.fechaDeTurno.dia).length();
					dia = replicate("0",cantidad)+to_string(turnos.fechaDeTurno.dia);
					cantidad = 2 - to_string(turnos.fechaDeTurno.mes).length();
					mes = replicate("0",cantidad)+to_string(turnos.fechaDeTurno.mes);
					fecha = dia  +'/'+mes+"/"+to_string(turnos.fechaDeTurno.anio);
					cliente = fGetDatoCliente(turnos.dniCliente);
					cantidad = 30 - cliente.length();
					cliente = cliente + replicate(" ",cantidad);
					cout <<fecha+" | "+cliente+" | "+to_string(turnos.dniCliente)+"\n";
					//cout <<fecha+" | "+to_string(turnos.dniCliente)+"\n";
				}
			fread(&turnos,sizeof(Turnos),1,turno);
	    }

	fclose (turno);
}

void listaEspera(FILE *fp_turno, FILE *prof, FILE *cliente,int idProfesional) // modulo espacios
{

	fp_turno=fopen("turnos.dat","rb");
	
	Turnos turnos;
	Profesional profs;
	Cliente clientes;
	string fecha;
	string mes;
	string dia;
	int auxId=0;
	int cantidad;
	int i=0;
	string turno;
	string dni;
	string paciente;
	string detalle;
	
	bool tengopacientes=false;
            
	if(fp_turno == NULL)
	{
		printf("\nNo fue posible abrir el archivo turnos.dat, en la funcion 'listaEspera'\n\n");
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Lista de Espera de Clientes\n";
		cout << "---------------------------\n";
		
		fread(&turnos,sizeof(Turnos),1,fp_turno);
		
		cout << replicate("-",75)+"\n";
		turno = " Turno";
		cantidad = 10 - turno.length(); 
		turno = turno + replicate(" ",cantidad);
		
		fecha ="| Fecha";
		cantidad = 12 - fecha.length(); 
		fecha = fecha + replicate(" ",cantidad);
		
		dni = "| DNI";
		cantidad = 12 - dni.length(); 
		dni = dni + replicate(" ",cantidad);
		
		paciente = "| Cliente";
		cantidad = 30 - paciente.length(); 
		paciente = paciente + replicate(" ",cantidad);
		
		detalle = "| Detalle";
		cantidad = 50 - detalle.length(); 
		detalle = detalle + replicate(" ",cantidad);
		
		cout << turno+fecha+dni+paciente+detalle+"\n";					
		cout << replicate("-",75)+"\n";
		
		do
		{
			if(idProfesional==turnos.idProfesional && turnos.atendido == false)
			{
				turno = to_string(i+1);
				cantidad = 10 - turno.length(); 
				turno = turno + replicate(" ",cantidad);
				
				dia = replicate("0",2-to_string(turnos.fechaDeTurno.dia).length())+to_string(turnos.fechaDeTurno.dia);
				mes = replicate("0",2-to_string(turnos.fechaDeTurno.mes).length())+to_string(turnos.fechaDeTurno.mes);
				fecha = dia+"/"+mes+"/"+to_string(turnos.fechaDeTurno.anio);
				cantidad = 12 - fecha.length(); 
				fecha = fecha + replicate(" ",cantidad);
				
				dni = to_string(turnos.dniCliente);
				cantidad = 12 - dni.length(); 
				dni = dni + replicate(" ",cantidad);
				
				paciente = fGetDatoCliente(turnos.dniCliente);
				cantidad = 30 - paciente.length(); 
				paciente = paciente + replicate(" ",cantidad);
				
				detalle = turnos.detalleDeAtencion;
				cantidad = 50 - detalle.length(); 
				detalle = detalle + replicate(" ",cantidad);
				
				cout << turno+fecha+dni+paciente+detalle+"\n";					
				
				tengopacientes=true;

			}
			
			fread(&turnos,sizeof(Turnos),1,fp_turno);
			
			i++;	
		}while(!feof(fp_turno));
		
		if (tengopacientes == false)
		{
			printf ("No tiene pacientes en su lista de espera.\n");					
		}		
	}
	
	fclose(fp_turno);
	
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
	int li_puesto;
	int li_cantidad;
	int li_matricula;

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

		cout << replicate("-",40)+"\n";
		cout << "Puesto | Id. Prof.  | Cant. Atenciones \n";
		cout << replicate("-",40)+"\n";
		
		//Muestra el ranking de Medicos:
		for (i = 0; i < num_meds; i++)
		{
			li_puesto    = 6 - to_string(i+1).length();
			li_matricula = 10 - to_string(reg_atenciones[i].matriculamedico).length();
			li_cantidad  = to_string(reg_atenciones[i].cant_atenciones).length();
			cout << to_string(i+1)+replicate(" ",li_puesto)+" | "+ to_string(reg_atenciones[i].matriculamedico)+replicate(" ",li_matricula)+" | "+to_string(reg_atenciones[i].cant_atenciones)+"\n";
			
		}
		
	}
}

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
			printf ("\nNo se Registro Ningun Recepcionista...\n\n");
			system("pause");
	}
	else
	{
		rewind(fp);
	    printf ("Bienvenido - Inicio de Sesion \n") ;
	    printf ("------------------------------\n") ;
	    printf ("Usuario: ") ; 
	    _flushall ();
		gets(usuario);
		 
		printf ("Contrase%ca: ",164); 
		_flushall();
		enterPassword(password, 12,3,12); 
		printf ("\n\n");
		 
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
	}
	
	return flag;
}