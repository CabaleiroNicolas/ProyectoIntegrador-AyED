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

using namespace std;

struct Usuario 
{
	char usuario [10];
	char password [33];
	char ApeNom [60];
	
};

struct Login 
{
	char usuario [10];
};


string replicate(string s, int n) 
{
  string repeat;

  for (int i = 0; i < n; i++)
    repeat += s;

  return repeat;
}

void setTextColor(int X)
{
/*
0 = Negro
1= Azul
2= Verde
3= Aguamarina
4= Rojo
5= Púrpura
6= Amarillo
7= Blanco
8= Gris
9= Azul Claro
A= Verde Claro
B= Aguamarina Claro
C= Rojo Claro
D= Púrpura Claro
E= Amarillo Claro
F= Blanco Brillante
*/
	
SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}

void logoutn()
{
	int j=0;	
	int i=0;
	int N = 5;
	string espacio=" ";
	string linea;
	linea =(char)196;
	linea = replicate(linea,100);
	string items[N];
	
	
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,9);

	
	
	printf("\n\n\n\n\n");

	int	 logo[25][80]= 
			
	{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0,1,1,0,0,0,1,0},
    {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,0},
    {0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,0},
    {0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0},
    {0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    }};

							 
					 
					 
					 
		 
		 





	
	
		cout<< "\n";		
		cout<< "";
		cout <<linea+"\n";	


	for(i=0;i < 18;i++){
	
		printf("\n");
		for(j=0;j<80;j++){
		
		
			if( logo[i][j]== 1  )
			{
				if(i>=0 && i<=7)
				{ 
				
						setTextColor(1);
				}
				else 
				{
					setTextColor(9);
				}	
				
				
				
				printf("%c",220);
				
				Sleep(20);
			}
			
			else if(j==0){
				
				printf("\t\t");
			}	
			else{
				
				printf(" ");
				
			}
		}
	
	
	
	
	 }
		cout<< "\n";		
		cout<< "";
		cout <<linea+"\n";	
	
		Sleep(1000);
		cout<< "\n\n";		
		cout<< "\t\t\t\t\tFACULTAD REGIONAL TUCUMAN";
		Sleep(1000);
		cout<< "\n";		
		cout<< "\t\t\t\t\tIngenieria en Sistemas ";
		Sleep(1000);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
void acercaDe ()
{
	int N = 6;
	int M = 31;
	string espacio=" ";
	string linea;
	linea =(char)196;
	linea = replicate(linea,100);
	int items[N][M]= {
					  {1,1,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1},
					  {1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},
			          {1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,1,0,0,0,1,1},
			          {1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,1,1},
			          {1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,1,0,1,1},
			          {1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1}
			          };
	

	setTextColor(6);
	cout <<linea+"\n";	
	cout <<replicate(espacio,40)+"Universidad Tecnologica Nacional\n\n";
	setTextColor(7);
	for (int i=0; i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
		
			if (i>=0  && i<=1)   setTextColor(9);
			if (i>=2  && i<=3)   setTextColor(7); 
	   		if (i>=4  && i<=5)   setTextColor(9);
	   		if ((i==2 ||  i==3) && (j==14 || j== 15)) setTextColor(6);
	   		
	   		
	   		if (items[i][j] == 1)
	   		{
	   			if (j==0)
		    		cout <<replicate(espacio,40)+(char)219;
		    	else	
		    	    cout <<(char)219;
		    }
		    else
		    {
    			if (j==0)
    				cout <<replicate(espacio,40)+(char)32;
    			else
	    			cout <<(char)32;
			}
		    
	    }
  		 cout<<"\n";
	}
	setTextColor(6);
	
	cout << "\n"+replicate(espacio,45)+"Fac. Regional Tucuman\n\n";
	cout <<linea+"\n";
	cout << "\n";
	cout << replicate(espacio,45)+"Comision 1k1 - Integrantes\n";
	cout << replicate(espacio,45)+"--------------------------\n";
	cout << replicate(espacio,45)+"Albornoz Antonella Constanza\n";
	cout << replicate(espacio,45)+"Bugeau Valentina\n";
	cout << replicate(espacio,45)+"Cabaleiro Nicolas \n";
	cout << replicate(espacio,45)+"Camacho Victor David\n";
	cout << replicate(espacio,45)+"Canevaro Rafael\n";
}

//Carga en un vector todos los usuarios existentes
int leerLogins (char userfile[], Login logins [255])
{
	FILE *fp; 
	Usuario reg;
	int i =0;
	fp=fopen(userfile,"rb");
	if (fp==NULL)
	{
		printf("Error al abrir el archivo % \n",userfile);
		//exit(EXIT_FAILURE);
		return -1; 
	}

	rewind(fp);
	fread(&reg,sizeof(reg),1,fp);
    strcpy(logins[i].usuario, reg.usuario);
    //printf ("reg usuario: %s", reg.usuario);
	while (!feof(fp))
	{
		if (!feof(fp))
		{
			strcpy(logins[i++].usuario, reg.usuario);
			//printf ("reg usuario: %s\n", reg.usuario);
     }
		fread(&reg,sizeof(reg),1,fp);
	}  
	fclose(fp);
	//system ("pause");
	return i;
}

int ValidUser(char usuario[10], Login logins [255], int *cantLogins)
{

 int flag = 0;
 int longitud;
 int mayusculas=0;
 int digitos = 0;
 int espacios=0;
 int i=0;
 int n=0;
	
	n = *cantLogins;
	
	for (int j=0; j<=n; j++)
	{
		if (strcmp (usuario, logins[j].usuario)==0)
		{
			printf ("Usuario ya existente."); 
			flag=1;
			break;	
		}
		 
	}
 
 longitud = strlen(usuario);
 
 //Valida la longitud de la clave
 if (longitud < 6  || longitud > 10)
 {
 	printf ("\nLa longitud del nombre debe estar entre 6 y 10 caracteres.");
 	flag = 1;
 }
  
  //Chequea el nombre del usuario empice con minuscula
 if (islower(usuario[0]) == 0)
  {
     printf("\nEl nombre del usuario debe comenzar con una letra en minuscula.");
     flag = 1;
  }

 //Valida que contenga al 2 menos letras en mayuscula
 
 i=0;
 for(i = 0; i < longitud; i++)
  {
  	
    if (usuario[i] >= 'A' && usuario[i] <= 'Z') 
    {
		mayusculas++;
	}	

  }
  
if (mayusculas < 2)
{
	   printf("\nEl nombre del usuario debe contener al menos 2 letra en mayuscula.");
       flag = 1;
}

 i=0;
 while (usuario[i])
  {
    if (isdigit(usuario[i])) 
    {
		digitos++;
	}	
    i++;
  }
 if (digitos >3)
 {
	   printf("\nEl nombre del usuario no debe contener mas de 3 digitos.");
      flag = 1;
  } 
 
 //Valida que no contenga espacios en blanco

 i=0;
 while (usuario[i])
  {
    if (isspace(usuario[i])) 
    {
		espacios++;
	}	
    i++;
  }
 if (espacios > 0)
 {
	  printf("\nEl nombre del usuario no puede contener espacios.");
      flag = 1;
  } 
  
  return flag; 
	
}

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
	 	printf("\nLa Clave tiene que tener 6 caracteres como minimo y 32 como maximo.");
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

void enterPassword(char* verify, short int x, short int y, short int xAux) //Enmascara la contraseña ingresada
{

 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 COORD pos = {x, y};
 char ch;
 int i=0;
 
 do
 {
	  ch=getch();
	  if(ch!=13)
	  {
		x = x+1;
		
		if (ch == 8)
		{
		     if (x > xAux)
	     	{
				 x = x - 1;
				 pos = {x, y};
				 SetConsoleCursorPosition(hConsole, pos);
			 	 WriteConsole(hConsole, " ", 1, NULL, NULL);
		 	     x=x-1;
			     pos = {x, y};
			 	 SetConsoleCursorPosition(hConsole, pos);
			 	 verify[i--];
				  
			 	 if (x <= xAux)
			 	 {
			 	   x = xAux + 1 ;	
			       pos = {x++, y};
			 	   SetConsoleCursorPosition(hConsole, pos);
				  }	
			}	 
		}
		         
       else
        {
	   		verify[i++]=ch; //Va cargando los caracteres ingresados
	   		printf ("*");
	   }
	}
	  else
	  {
	   verify[i++]='\0';
	  }
 }
 while(ch!=13);
 
 system ("pause");	 	
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
			printf ("Error al abrir el archivo \n");
			exit(EXIT_FAILURE);
	}
	
	rewind(fp);
    printf ("Bienvenido - Inicio de Sesion \n") ;
    printf ("------------------------------\n") ;
    printf ("Usuario:") ; 
    _flushall ();
	gets(usuario)  ;
	 
	printf ("Contrasenia: "); 
	enterPassword(password, 12,3,12); 
	printf ("\n"); 
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
	return flag;
}