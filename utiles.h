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


struct menu
{
int idmenu;
int nivel;
int padre;
char opcion[50];
};

struct fecha {
   int dia;
   int mes;
   int anio;
};

//Valida la complejidad de la contraseña

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
    	//Obtiene el valor ascii del caracter
    	aux = (int) toupper(clave[i]);
    	j = i+1;
    	if (j<= longitud)
    		//Obtiene el valor ascii del sgte caracter
    		ascii = (int) toupper(clave[j]);
    		
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




//Enmasca la contrasenia ingresada
void enterPassword(char* verify)
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
 }
 while(ch!=13);
}


string getCargo(int idcargo)
{
	string puesto="N/D";
	string cargos[5];
	cargos[1] = "Recepcionista ";
	cargos[2] = "Medico";
	cargos[3] = "Seg. Informatica";
	cargos[4] = "Gerente";
	if (idcargo >=1 && idcargo <=4)
	{
		puesto = cargos[idcargo];
	}
	return puesto;
}

string getEstado(int idestado)	
{
	string estado="N/D";
	string estados[3];
	estados[1] = "Habilitado";
	estados[2] = "Inhabilitado";
	
	if ((idestado >=1) && (idestado <=2))
	{
		estado = estados[idestado];
	}
	return estado;
}

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
		SetConsoleTextAttribute(hConsole,2);

	
	
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
		
		
			if( logo[i][j]== 1  ){
				
				
				printf("%c",220);
				
				Sleep(35);
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

//typedef enum { false, true } boolean;
string intToString(int number)
{

  string str; // a variable of str data type

  // using the stringstream class to insert an int and
  // extract a string
  stringstream ss;  
  ss << number;  
  ss >> str;  
  return str;
  
}

string fillString(string cadena , int longitud, string filler, string direction )
{
	int fill_long;
	int resto;
	string relleno="";
	fill_long = cadena.size();
	longitud = (longitud - fill_long);
	
	if (direction != "C")
	{
		for (int i=1;i<=longitud;i++)
		{
			relleno = relleno + filler;
		}
	    //Left
		if (direction == "L")
		{
			cadena = relleno + cadena;
		}
		//Rigth
		if (direction == "R")
		{
		    cadena = cadena + relleno;
			
		}
    }
    
   	if (direction == "C") //Center
	{
		resto = ( longitud % 2);
		if (resto == 0)
		{
			longitud = (longitud / 2);
		}
		else
		{
			longitud = (longitud-1)  / 2;
		}
		
		for (int i=1;i<=longitud;i++)
		{
			cadena = cadena + filler;
			cadena = filler + cadena;
		}
		if (resto == 1)
		    cadena = cadena + filler;
    }

    
	return cadena;
}

//Retorna la posisición del caracter buscado en la cadena origen
int GetPos(char string[200], char substring[1])
{
	int i;
	int position;
	for (i = 0; i < strlen(substring); i++)
	{
		char *position_ptr = strchr(string, substring[i]);
		position = (position_ptr == NULL ? -1 : position_ptr - string);

	}

   return position;	
}
char* s_duplicate(const char* s) {
    if (s == NULL)
        return NULL;

    size_t len = strlen(s);  /* ensure room for NULL terminated */
    char* buf = (char*)malloc((len + 1) * sizeof(char));
    if (buf == NULL)
        return NULL;
    strcpy(buf, s);
    buf[len] = '\0';
    return buf;
}

//Obtiene una subcadena a partir de una cadena
char* SubString(const char* s, int start, int length) {
    if (s == NULL)
        return NULL;

    int len = strlen(s);
    if (start >= len)
        return NULL;
    if (start + length > len)
        return s_duplicate(s + start);

    char* ret = (char*)calloc(length + 1, sizeof(char));
    return strncpy(ret, s + start, length);
}

