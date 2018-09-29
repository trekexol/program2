#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<iostream>
#include <fstream> 
#include "estructuras.h"
#include "funperso.h"
#include "funbancos.h"
#include "funtran.h"
#include "archivo.h"
#include "consultas.h"

using namespace std;



void Menutran (bancos **p,perso **q,tran **b){
	int op = -1;
			
	while(op){
		printf ("1. Realizar una transferencia\n");
		printf ("2. Buscar transferencia \n");
		printf ("3. Modificar transferencia \n");
		printf ("4. Eliminar transferencia  \n");
		printf ("5. Mostrar todas las transferencias \n");
		printf ("0. Salir\n");
		scanf ("%d",&op);
		switch(op){    
			case 1:    
				system("cls");
				Addtran (&(*p),&(*q),&(*b));		
			break;
			case 2: system("cls");
				buscartran(*p,*q,*b);		
			break;
			case 3: system("cls");
				modificartran(*p,*q,&(*b));		
			break;
			case 4: system("cls");
				eliminartran(&(*p),&(*q),&(*b));	
				system("pause");
				system("cls");			
			break;
			
			case 5:    
				system("cls");
				mostrartran(&(*p),&(*q),&(*b));
			break;
		
	
		};
		
	//	Archivo(&(*p));	
		printf("\n\n");
		system("pause");
		system("cls");
    };
}


void Menupersonas (bancos **p,perso **q,tran **b){
	int op = -1;
			
	while(op){
		printf ("1. Registrar Persona \n");
		printf ("2. Buscar Persona \n");
		printf ("3. Modificar Persona \n");
		printf ("4. Eliminar Persona  \n");
		printf ("5. Mostrar todas las Personas \n");
		printf ("0. Salir\n");
		scanf ("%d",&op);
		switch(op){    
			case 1:    
				system("cls");
				Addperso((*p),&(*q));		
			break;
			case 2: system("cls");
				buscarperso(*p,*q);		
			break;
			case 3: system("cls");
				modificarperso(&(*p),&(*q));		
			break;
			case 4: system("cls");
				eliminarperso(&(*p),&(*q),&(*b));	
				system("pause");
				system("cls");			
			break;
			
			case 5:    
				system("cls");
				mostrarperso(&(*p),&(*q));
				system("pause");
				system("cls");	
			break;
		
	
		};
		
		//	Archivo(&(*p));	
		printf("\n\n");
		system("pause");
		system("cls");
    };
}

void Menubancos (bancos **p,perso**q,tran **b){
	int op = -1;
		
	while(op!=0){
		printf ("1. Registrar Entidad Bancaria \n");
		printf ("2. Buscar Entidad Bancaria\n");
		printf ("3. Modificar Entidad Bancaria\n");
		printf ("4. Eliminar Entidad Bancaria \n");
		printf ("5. Mostrar todas las Entidades Bancarias \n");
		printf ("0. Salir\n");
		scanf ("%d",&op);
		switch(op){    
			case 1:    
				system("cls");
				Addbancos(&(*p));		
			break;
			case 2: system("cls");
				buscarbancos(*p);		
			break;
			case 3: system("cls");
				modificarbancos(&(*p));		
			break;
			case 4: system("cls");
				borrartodo(&(*p),&(*q),&(*b));
				system("pause");
				system("cls");
					
			break;
			
			case 5:    
				system("cls");
				mostrar(&(*p));
			break;
			
	
		};
		
			
		printf("\n\n");
		system("pause");
		system("cls");
    };
}



int main (){
	
	bancos *p=NULL;
	perso *q=NULL;
	tran *b=NULL;
	bancos *pbuscada=NULL;
	int op=-1,x;
	titular *o=NULL;
	titular *buscarti=NULL;
	titular2 *opo=NULL;
	titular2 *buscarti3=NULL;


	LeerArchivoB(&(p));
	LeerArchivoq(&(p));
	LeerArchivob(&(p));
	 
	while (op!=0){
		printf ("\n\nBIENVENIDO AL SISTEMA DE CONTROL DE CUENTAS BANCARIAS \n\n");
		printf ("1. Entidades Bancarias \n");
		printf ("2. Cuentas Personales \n");
		printf ("3. Transacciones \n");
		printf ("4. Consultas\n");
		printf ("0. Salir\n");    
		scanf ("%d", &op);
		system("cls");
		printf("\n\n\n        Opcion %i\n\n",op);
		switch (op){
			
			case 1:
				 
				Menubancos(&p,&q,&b);
		
				
				break;
			
			case 2:
			
				Menupersonas(&p,&q,&b);
			
				break;
	  		case 3:
			
				Menutran (&p,&q,&b);
			
				break;
				
			case 4:
				Menuconsulta(opo,o,p,q,b);
				
				break;
		};
		Archivo(&(p));	
		printf("\n\n");
		if (op) system("pause");
		system("cls");
	 };
	 return 0;
}
