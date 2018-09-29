#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;


bool contadorp (char a[30]){
	
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

bool contadorp2 (char a[30]){

	
	if ((strcmp(a,"01")==0 )||(strcmp(a,"02")==0)||(strcmp(a,"03")==0)|| (strcmp(a,"04")==0)) return false;
	else return true;
	
}
bool contadorp3 (char a[30]){
	
	int x,z,letras=0;
	
	z= strlen(a);
	
	for (x=0; x<=z; x++){
		
		if (a[x] != ' '){
			letras++;
		}
		
	}
	
	if (letras == 11) return false;
	else return true;
	
}
bool contadorp4 (char a[30]){
	
	int x,z,letras=0;
	
	z= strlen(a);
	
	for (x=0; x<=z; x++){
		
		if (a[x] != ' '){
			letras++;
		}
		
	}
	
	if (letras == 9) return false;
	else return true;
	
}
bool buscarbancos(bancos *p,char x[10]){

bancos *t=p;  
int ope=0;


while(t)	{

if (strcmp(t->code,x)==0) {
ope = 1;
return true;
}
t=t->prox;
}

if (ope==0) return false;
};	

bool buscarper(bancos *p,perso *q,char x[30]){

bancos *t=p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if (strcmp(aux->ncuenta,x)==0) {
ope = 1;
return true;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return false;
};	

bool buscarper2(bancos *p,perso *q,char x[30]){

bancos *t=p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if (strcmp(aux->cedula,x)==0) {
ope = 1;
return true;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return false;
};	




void mostrarperso (bancos** p,perso **q){
	perso *aux=NULL;	
	bancos *aux2=*p;
	int ope=0;
	if(*p==NULL){
		printf("No hay Bancos registrados \n");
	}
	else{

while(aux2!=NULL){
	aux=aux2->aba;
	 while(aux!= NULL){
	 ope=1;
	 
		printf(" Banco: %s \n",aux2->name);
		printf(" Codigo de Agencia: %s \n",aux->code);
		printf(" Tipo de cuenta: %s \n",aux->tcuenta);
		printf(" Numero de cuenta: %s \n",aux->ncuenta);
		printf(" Cedula: %s \n",aux->cedula);
		printf(" Saldo : %d \n",aux->saldo);
		printf("\n");
	
		aux=aux->prox;
		
	}
	aux2 = aux2->prox;
	}

}
if (ope==0) printf("---No hay Titulares registrados ---\n");	
	
	
}

void buscarperso (bancos *p,perso *q){
bancos *t=p;
perso *aux=NULL;
char x[30];  int ope=0;
do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));

while(t)	{
	aux=t->aba;


while (aux != NULL) {


if (strcmp(aux->cedula,x)==0) {
ope = 1;
printf ("\n--- Si se encuentra registrada la persona ------\n\n");
	printf(" Banco: %s \n",t->name);
		printf(" Codigo de Agencia: %s \n",t->code);
		printf(" Tipo de cuenta: %s \n",aux->tcuenta);
		printf(" Numero de cuenta: %s \n",aux->ncuenta);
		printf(" Cedula: %s \n",aux->cedula);
		printf(" Saldo : %d \n",aux->saldo);
		printf("\n");

}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) printf ("No se encontro la persona \n\n");
};	
	
bancos* buscarbanco(bancos *p, char ope[30]){ //Retorna el banco que se eligio para agregar el perso
bancos *Aux=p;

while (Aux){
if (strcmp(Aux->code,ope)==0) break;
        Aux=Aux->prox;
}
return(Aux);
}


void insertarCabperso (bancos *pbuscada,perso **q ,char x[5],char o[3],char v [20],char m[20],int s){

    perso *aux;
    bancos *t=pbuscada;	
    
	  aux= new perso; 
	
	strcpy(aux->code,x);
	strcpy(aux->tcuenta,o);
	strcpy(aux->ncuenta,v);
	strcpy(aux->cedula,m);
	aux->saldo=s;

	aux->lado=NULL;
	
	if (t->aba==NULL){
	t->aba=aux;
	aux->prox=NULL;
	}
		else{
		aux->prox=t->aba;
		t->aba=aux;
		
		

}
}


void modificarperso (bancos **p,perso **q){
bancos *t=*p;
perso *aux=*q;
char x[30]; int op=0; char z[30],o[30],m[30],l[30]; int saldo; int ope=0;

	do{	
		printf("Introduzca Numero de Cuenta (10 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp3(x)));	
	

while(t)	{
aux=t->aba;	

if (aux){

while ( (strcmp(aux->ncuenta,x)!=0)&& (aux->prox != NULL)) aux = aux->prox;

if (strcmp(aux->ncuenta,x)==0) {
	ope=1;
printf ("\n Que desea modificar?  \n 1)tipo de cuenta\n 2)Saldo \n");
 
 scanf("%d",&op);
 
 if (op==1){
 	do{
		printf("\n Introduzca Nuevo tipo de Cuenta \n 01 Ahorro \n 02 Corriente \n 03 Tarjeta de Credito \n 04 Pago de Servicios \n\n");
		fflush(stdin);
		cin.getline(z,30,'\n');
		fflush(stdin);
		}while((contadorp2(z)));
	strcpy(aux->tcuenta,z);
 } 

 
 if (op==2){
 	printf ("\n Ingrese nuevo Saldo: \n");
 	scanf("%d",&saldo);
 	aux->saldo=saldo;
 } 
 break;
}
}
t=t->prox;
}
if (ope ==0) printf("\n---- No se encontro la persona -----\n\n");

};	
	
void eliminarperso (bancos **p,perso **q,tran **b){
bancos *t=*p;
perso *aux;
perso *aux2;
tran *z=NULL; int ope=0;

 char x[100];
		
		do{ 
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp3(x)));

while(t)	{
aux=t->aba;	
if(aux!=NULL){
aux2=NULL;
while ( (strcmp(aux->ncuenta,x)!=0)&& aux->prox != NULL) {	
aux2=aux;
aux=aux->prox;

}
if (strcmp(aux->ncuenta,x)==0) {
ope=1;
while (aux->lado != NULL){
 z=aux->lado;
 
 aux->lado=aux->lado->sig;
 delete z;

}

if (aux2 == NULL){
	aux2=aux;
	t->aba=aux->prox;	
  		delete aux2;
  		printf("La cuenta de la persona fue eliminada con exito \n\n");
  	}
  		else {
  			aux2->prox=aux->prox;
			  delete aux;			
  			printf("La cuenta de la persona fue eliminada con exito \n");
  		}

}
}t=t->prox;
}
if(ope==0) printf("----No se encontro la cuenta registrada ---- \n");
};	
  	

void Addperso(bancos*p,perso **q){
	char x[30]; char o[30]; char v[30]; 
	 perso *t= *q;
	char m [30]; int s;
	

			do{
		printf("Introduzca Codigo De Agencia (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
	
		}while((contadorp(x)));	

if (bancos *pbuscada= buscarbanco(p,x)){
			do{
		printf("Introduzca tipo de Cuenta (01 Ahorro,02 Corriente \n 03 Tarjeta de Credito,04 Pago de Servicios): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		}while((contadorp2(o)));
		do{	
		printf("Introduzca Numero de Cuenta (10 Digitos): \n");
		fflush(stdin);
		cin.getline(v,30,'\n');
		fflush(stdin);
		}while((contadorp3(v)));
		if (buscarper(p,*q,v)==NULL){
			do{	
			printf("Introduzca Numero de Cedula (8 Digitos): \n");
			fflush(stdin);
			cin.getline(m,30,'\n');
			fflush(stdin);
			}while((contadorp4(m)));
			printf("Introduzca el saldo a depositar: \n");
			scanf("%d",&s);
		
			insertarCabperso(pbuscada,q,x,o,v,m,s);
		}else printf("\n----El numero de cuenta ya fue registrado ---- \n");
} 
else 
printf ("No se encontro el codigo, el banco no esta registrado.");

}
		
