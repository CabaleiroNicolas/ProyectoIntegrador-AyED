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
