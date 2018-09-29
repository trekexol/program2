#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

bool contador2 (char a[30]){
	
	int x,z,letras=0;
	
	z= strlen(a);
	
	for (x=0; x<=z; x++){
		
		if (a[x] != ' '){
			letras++;
		}
		
	}
	
	if (letras == 5) return false;
	else return true;
	
}




bool vacios (char a[30]){
	
	if(strcmp(a,"")==0) return true;
	else return false;
	
}



void borrartodo(bancos **p,perso **q,tran **b){
 bancos *t=*p;
 bancos *aux=NULL;
 perso *j=NULL;
 tran *aux2=NULL;   
 int ope=0;
 
 char x[30];
		do{
		printf("Introduzca Codigo Nacional (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
	
		}while((contador2(x)));

if(*p==NULL)printf("-- No hay bancos registrados --\n");

else{
		
while ( (strcmp(t->code,x)!=0)&& (t->prox != NULL)) {
    aux=t;
    t = t->prox;
	
}
 
if ((strcmp(t->code,x)==0)) {
 ope =1;
 
  	while(t->aba){
  		 
  		 j=t->aba;
  		 		while (j->lado){
  		 		
				   aux2=j->lado;
				   j->lado=j->lado->sig;
				   delete aux;	
  		 		}
  		 		t->aba=t->aba->prox;
  		 		delete j;
  	}
  	if (*p == t){
  		(*p) = (*p)->prox;
  		delete t;
  	}
	else {
		aux->prox=t->prox;
		delete t;
	}
  printf ("--- Se ha eliminado el banco y sus cuentas con exito ----\n\n");
}

if (ope == 0)  {
printf ("----No se encontro el banco---\n"); 

}

}

}
void mostrar(bancos **p){
	bancos *t=*p;
	
	if(*p==NULL){
		printf("No hay Bancos registrados \n");
	}
	else{
	
	while(t){
		printf(" Banco: %s \n",t->name);
		printf(" Codigo Nacional: %s \n",t->code);
		printf(" Direccion: %s \n",t->dire);
		printf("\n");
		t = t->prox;
	}

}
		
}



void insertarCabban (bancos **p,char banco[50],char codigo[5],char dire[50]){
bancos *t=*p;
      t= new bancos; 
      
	t->aba=NULL;
	strcpy(t->name,banco);
	strcpy(t->code,codigo);
	strcpy(t->dire,dire);
	
if (*p==NULL){
	*p=t;
	t->prox=NULL;
}
else{
t->prox=*p;
*p=t;

		
}

}

bool buscarban(bancos *p,char z[10]){
	bancos *aux=p;

if (p==NULL) return true;

while ( (strcmp(aux->code,z)!=0) && (aux->prox != NULL)) aux = aux->prox;

if (strcmp(aux->code,z)==0) return false;

else return true;

	
}

void Addbancos(bancos **p){
	char x[50]; char z[30];char n[50];
	

	do{
		printf("Introduzca el Nombre del Banco: ");
    	fflush(stdin);
		cin.getline(x,50,'\n');
		fflush(stdin);	
		}while(vacios(x));
		
			
		do{
		printf("Introduzca Codigo Nacional (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(z,30,'\n');
		fflush(stdin);	
		}while(contador2(z));
		
		if (buscarban(*p,z)){
			
		do{
		printf("Introduzca Direccion (Sede Principal): \n");
		fflush(stdin);
		cin.getline(n,50,'\n');
		fflush(stdin);
		}while(vacios(n));

		insertarCabban(p,x,z,n);
		}
		else printf("---El codigo del banco ya fue registrado--- \n");

}


void buscarbancos (bancos *p){
bancos *aux=p;
char x[30];
	do{
printf("Ingrese el Codigo del banco  (4 DIGITOS):");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);	
		aux->aba=NULL;
		}while((contador2(x)));
		
while ( (strcmp(aux->code,x)!=0)&& aux->prox != NULL) aux = aux->prox;

if (strcmp(aux->code,x)==0){
 printf ("----Si se encuentra registrado el banco -----\n\n");
		printf(" Banco: %s \n",aux->name);
		printf(" Codigo Nacional: %s \n",aux->code);
		printf(" Direccion: %s \n",aux->dire);
		printf("\n");


}
else printf ("No se encontro el banco \n\n");


};	
	

void modificarbancos (bancos **p){
bancos *aux=*p;
char x[30]; int op=0; char z[50];
do{
printf("Ingrese el Codigo del banco  (4 DIGITOS):");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);	
		aux->aba=NULL;
		}while((contador2(x)));
		
while ( (strcmp(aux->code,x)!=0)&& aux->prox != NULL) aux = aux->prox;

if (strcmp(aux->code,x)==0){
do{
 
 printf ("Que desea modificar? \n 1)Nombre \n 2)Direccion \n 0)Regresar al menu \n");
 scanf("%d",&op);
} while (!((op>=0) && (op<=2)));

 if (op==1){
	 do{
 	printf ("Ingrese nuevo nombre: \n");
 	fflush(stdin);
	cin.getline(z,50,'\n');
	fflush(stdin);
	}while(vacios(z));
	 strcpy(aux->name,z);
 } 
 
 if (op==2){
	 do{
 	printf ("Ingrese nueva direccion: \n");
 	fflush(stdin);
	cin.getline(z,50,'\n');
	fflush(stdin);
	}while(vacios(z));
	strcpy(aux->dire,z);
 } 

 if(op==0);
 
 
}
else printf ("----- No se encontro el banco ------\n\n");
	
	
}


