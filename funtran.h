#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


using namespace std;
							

bool contadorpo2 (char a[30]){

	
	if ((strcmp(a,"01")==0 )||(strcmp(a,"02")==0)||(strcmp(a,"03")==0)|| (strcmp(a,"04")==0)|| (strcmp(a,"05")==0)) return false;
	else return true;
	
}
bool contadordi (char a[30]){
	
	int x,z,letras=0;
	
	z= strlen(a);
	
	for (x=0; x<=z; x++){
		
		if (a[x] != ' '){
			letras++;
		}
		
	}
	
	if (letras == 3) return false;
	else return true;
	
}

bool buscartran(bancos *p,perso *q,tran *b,char x[30]){

bancos *t=p;
perso *aux=NULL;  
tran *aux2=NULL;
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {

aux2=aux->lado;
while (aux2 != NULL) {
	if (strcmp(aux2->code,x)==0) {
		ope = 1;
		return true;
		}
	aux2=aux2->sig;	
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return false;
};	


void mostrartran (bancos** p,perso**q,tran **b){
	bancos *aux=*p;
	perso *t=NULL;
	tran *m=NULL;	
	int pro=0;
	if(*p==NULL){
		printf("No hay Bancos registrados \n");
	}
	else{
	
while(aux!=NULL){
	 t=aux->aba;
	 while (t!= NULL){  
	  m=t->lado;
	 while (m!= NULL){
	 	
	 	if ((strcmp(m->tope,"01")==0)|| ((strcmp(m->tope,"02")==0))){
							
								printf ("\n----------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de cedula  : %s \n",m->ncuenta);
								printf(" Numero de cuenta Destino: %s \n",m->ncuenta2);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
								}
								else if (strcmp(m->tope,"03")==0){
								printf ("\n--------------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de Tarjeta de Credito Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
									}
								else if (strcmp(m->tope,"04")==0){
									printf ("\n--------------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Servicio: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de Cuenta del Servicio: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
								}else if (strcmp(m->tope,"05")==0){
								printf ("\n--------------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de Cuenta Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
									}
		pro=1;
			m=m->sig;
	}
	t = t->prox;
		
	}
	aux=aux->prox;
	}


}
	if (pro==0)	printf ("No existen transacciones");
	
	
}

void buscartran (bancos *p,perso *q,tran *b){
bancos *aux=p;
perso *t=q;
tran *m;
char x[30]; char ncuenta[30];
char codetran[30]; int ope=0; int ope2=-1;
		do{
		
		printf("Consultar por :\n 1)Numero de cuenta \n 2)Numero de Transaccion \n 3)Monto \n 0)volver \n");	
		scanf("%d",&ope2);
		}while((ope2<=0) && (ope2>=3));
	
	
	if (ope2 == 1){
	
	do{ 
		printf("Introduzca numero de cuenta o tarjeta de credito  (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta)));

while(aux)	{
t=aux->aba;	
  while(t !=NULL){
  	m=t->lado;
				while (m) {
							
						if (strcmp(m->ncuenta2,ncuenta)==0) {
							ope =1;
								if ((strcmp(m->tope,"01")==0)|| ((strcmp(m->tope,"02")==0))){
							
								printf ("\n----------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de cedula  : %s \n",m->ncuenta);
								printf(" Numero de cuenta Destino: %s \n",m->ncuenta2);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
								}
								else if (strcmp(m->tope,"03")==0){
								printf ("\n--------------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de Tarjeta de Credito Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
									}
								else if (strcmp(m->tope,"04")==0){
									printf ("\n--------------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Servicio: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de Cuenta del Servicio: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
								}else if (strcmp(m->tope,"05")==0){
								printf ("\n--------------------------------------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de Cuenta Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
									}
							}
								
								m = m->sig;
							}
							t=t->prox;
				}
			aux=aux->prox;	
			}
	
}

if (ope2 == 2){
	
	do{
						printf("Introduzca Codigo de la Transaccion (4 DIGITOS): \n");
						fflush(stdin);
						cin.getline(codetran,30,'\n');
						fflush(stdin);
	
						}while((contadorp(codetran)));	
	
	while(aux)	{
t=aux->aba;	
  while(t !=NULL){
  	m=t->lado;
				while (m) {
							
						if (strcmp(m->code,codetran)==0) {
							ope =1;
							
							if ((strcmp(m->tope,"01")==0)|| ((strcmp(m->tope,"02")==0))){
							
								printf ("\n--- Si se encuentra registrada la Transferencia ------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de cedula  : %s \n",m->ncuenta2);
								printf(" Numero de cuenta Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
								}
								else {
								printf ("\n--- Si se encuentra registrada la Transferencia ------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de cuenta Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
									
								}
							}
								
							
								m = m->sig;
							}
							t=t->prox;
				}
			aux=aux->prox;	
			}
	
}

if (ope2 == 3){
	int mont=0;
	
	printf("---- Introduzca el monto de la transaccion -----\n");
	scanf("%d",&mont);

while(aux)	{
t=aux->aba;	
  while(t !=NULL){
  	m=t->lado;
				while (m) {
							
						if (m->monto==mont) {
							ope =1;
								if ((strcmp(m->tope,"01")==0)|| ((strcmp(m->tope,"02")==0))){
							
								printf ("\n--- Si se encuentra registrada la Transferencia ------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de cedula  : %s \n",m->ncuenta2);
								printf(" Numero de cuenta Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
								}
								else {
								printf ("\n--- Si se encuentra registrada la Transferencia ------\n\n");
								printf(" Banco: %s \n",aux->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Cliente: %s \n",m->nombre);
								printf(" Numero de Cuenta  : %s \n",m->ncuenta2);
								printf(" Numero de cuenta Destino: %s \n",m->ncuenta);
								printf(" Codigo de Transaccion: %s \n",m->code);
								printf(" Fecha: %s/%s/%s \n",m->dia,m->mes,m->ano);
								printf(" Hora: %s:%s:%s \n",m->hora,m->min,m->seg);
								printf(" Tipo de operacion: %s \n",m->tope);
								printf(" Cedula de cuenta Destino: %s \n",m->cedula);
								printf(" Monto : %d \n",m->monto);
								printf("\n");
									
								}
							}
								
								m = m->sig;
							}
							t=t->prox;
				}
			aux=aux->prox;	
			}
	
}

	



if (ope == 0) printf ("\n----No se encontro la transaccion ---- \n");
};	


void insertarCabtran (bancos **p,perso** qbuscada2,tran** b,char lo [10],char x[20],char o[20],char dia[2],char mes[2],char ano[2],char hora[2],char min[2],char seg[2],char tope[20],char v[20],char ncuenta[20],char ncuenta2 [30],int s){

    bancos *aux=*p;
    perso *t=*qbuscada2;
    tran *j=NULL;
    
while(strcmp(aux->code,lo)!=0) aux=aux->prox;
		t=aux->aba;
		while(strcmp(t->ncuenta,ncuenta2)!=0) t=t->prox;					
						
								j = new tran; 
								
								strcpy(j->codigo,lo);
								strcpy(j->cedula,x);
								strcpy(j->code,o);
								strcpy(j->ncuenta,ncuenta);
								strcpy(j->ncuenta2,ncuenta2);
								strcpy(j->dia,dia);	
								strcpy(j->mes,mes);
								strcpy(j->ano,ano);
								strcpy(j->hora,hora);
								strcpy(j->min,min);
								strcpy(j->seg,seg);
								strcpy(j->tope,tope);
								strcpy(j->nombre,v);
							
								j->monto=s;	
								
								
								if (t->lado== NULL){
																
								t->lado = j;
								j->sig = NULL;
							
							}
							else {
								j->sig=t->lado;
								t->lado=j;
								
							}
							
				}
				
void insertarCabtran2 (bancos **p,perso** qbuscada2,tran** b,char lo [10],char x[20],char o[20],char dia[2],char mes[2],char ano[2],char hora[2],char min[2],char seg[2],char tope[20],char v[20],char ncuenta2[20],char ncuenta[20],int s){

    bancos *aux=*p;
    perso *t=*qbuscada2;
    tran *j=NULL;
    
while(strcmp(aux->code,lo)!=0) aux=aux->prox;
		t=aux->aba;
		
		while((strcmp(t->ncuenta,ncuenta2)!=0)&&(t!=NULL)) t=t->prox;					
						
								j = new tran; 
								
								strcpy(j->codigo,lo);
								strcpy(j->cedula,x);
								strcpy(j->code,o);
								strcpy(j->ncuenta,ncuenta);
								strcpy(j->ncuenta2,ncuenta2);
								strcpy(j->dia,dia);	
								strcpy(j->mes,mes);
								strcpy(j->ano,ano);
								strcpy(j->hora,hora);
								strcpy(j->min,min);
								strcpy(j->seg,seg);
								strcpy(j->tope,tope);
								strcpy(j->nombre,v);
							
								j->monto=s;	
								
								
								if (t->lado== NULL){
																
								t->lado = j;
								j->sig = NULL;
							
							}
							else {
								j->sig=t->lado;
								t->lado=j;
								
							}
							
				}				
				

void modificartran (bancos *p,perso *q,tran **b){

char x[30]; int op=0; char z[5],o[20],m[5]; int saldo;

	char dia[5];char mes[5]; char ano[5]; char hora[5]; 
	char min[5];char seg[5]; int ope=0; char name[50];

char codetran [5];
			do{
								printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
								fflush(stdin);
								cin.getline(codetran,30,'\n');
								fflush(stdin);
		
								}while((contadorp(codetran)));	

bancos *aux=p;
perso *t=q;
tran *w=NULL;
while(aux)	{
	t=aux->aba;
		
		while(t!=NULL){
				w=t->lado; 
							if(w !=NULL){
								
								
								while ( (strcmp(w->code,codetran)!=0)&& w->sig != NULL) w = w->sig;
							
								if (strcmp(w->code,codetran)==0)
								{ ope=1;
									printf ("Que desea modificar? \n 1) Tipo de Operacion \n");
									 printf (" 2)Monto \n 3)Fecha \n 4) Hora \n 5)Nombre \n 0)Regresar \n");
									 scanf("%d",&op);
									 
									 if (op==1){
									 	do{
										printf ("Ingrese nuevo Tipo de Operacion: \n");
										fflush(stdin);
										cin.getline(z,5,'\n');
										fflush(stdin);
										}while((contadorpo2(z)));
										strcpy(w->tope,z);
											 } 
									 if (op==2){
								 		printf ("Ingrese nuevo monto: \n");
										scanf("%d",&saldo);
		 								w->monto=saldo;
											 } 
									 if (op==3){
									 	do{	
											printf("Introduzca dia: \n");
											fflush(stdin);
											cin.getline(dia,5,'\n');
											fflush(stdin);
											}while((contadordi(dia)));
										strcpy(w->dia,dia);
										do{	
											printf("Introduzca mes: \n");
											fflush(stdin);
											cin.getline(mes,5,'\n');
											fflush(stdin);
											}while((contadordi(mes)));
										strcpy(w->mes,mes);
										do{
											printf("Introduzca ano: \n");
											fflush(stdin);
											cin.getline(ano,5,'\n');
											fflush(stdin);
											}while((contadorp(ano)));	
										strcpy(w->ano,ano);
									 } 
									  if (op==4){
									  	do{
									 	printf ("Ingrese Hora: \n");
									 	fflush(stdin);
										cin.getline(hora,5,'\n');
										fflush(stdin);
										}while((contadordi(hora)));
										strcpy(w->hora,hora);
										do{
										
										printf ("Ingrese Minutos: \n");
									 	fflush(stdin);
										cin.getline(min,5,'\n');
										fflush(stdin);
										}while((contadordi(min)));
										strcpy(w->min,min);
										do{
										
										printf ("Ingrese Segundos: \n");
									 	fflush(stdin);
										cin.getline(seg,5,'\n');
										fflush(stdin);
										}while((contadordi(seg)));
										strcpy(w->seg,seg);
									 } 
									   if (op==5){
										do{
										printf ("Ingrese nuevo Nombre: \n");
										fflush(stdin);
										cin.getline(name,50,'\n');
										fflush(stdin);
										}while(vacios(name));
										strcpy(w->nombre,name);
											 } 
										if (op==0);				
													 break;
								}	
				}
				t=t->prox;	
			}
	aux=aux->prox;
	};	
		if (ope == 0) printf("----No se encontro la transferencia----\n");
}

void eliminartran (bancos **p,perso **q,tran **b){
bancos *aux=*p;
perso *aux2;  
tran *t=NULL;
tran *m=NULL;
int ope =0;

	char z[30];
 char x[30];
	do{
					printf("Introduzca Codigo de la transaccion (4 DIGITOS): \n");
					fflush(stdin);
					cin.getline(z,30,'\n');
					fflush(stdin);
	
					}while((contadorp(z)));	
		

while(aux)	{
	 aux2=aux->aba;
while(aux2!=NULL){
	t=aux2->lado;
	while (t){
	
				if (strcmp(t->code,z)==0) {
					
							t=aux2->lado;
							while ( (strcmp(t->code,z)!=0)&& t->sig != NULL) {
							m=t;	
							t =  t->sig;
							}
							if (m == NULL){
								ope=1;
								m=aux2->lado;	
								aux2->lado=aux2->lado->sig;	
 					 			delete m;
  							printf("La transaccion de la persona fue eliminada con exito \n\n");
 						 	}
 						 	
  							else { ope=1;
							   m->sig=t->sig;
									  delete t;			
  								printf("La transaccion de la persona fue eliminada con exito \n");
  							}
							break;
				}
			t=t->sig;	
			}
aux2=aux2->prox;
}
aux=aux->prox;
}
if (ope == 0) printf("---No se encontro la transferencia--- \n");
}




perso* buscarperso2(bancos **p,perso **q,char cedu[10] ,char ope[40],int s){ 

bancos *Aux = *p;
perso *t=NULL; int ope2=0;
while (Aux){
	t=Aux->aba;
while ((t))	{

	if (strcmp(t->ncuenta,ope)==0){
		
	 return(t);
     } 
	   t=t->prox;
    }
    Aux=Aux->prox;
}if (ope2==0) return NULL;

}

perso* buscarperso7(bancos **p,perso **q ,char ope[40]){ 

bancos *Aux = *p;
perso *t=NULL; int ope2=0;
while (Aux){
	t=Aux->aba;
while ((t))	{

	if (strcmp(t->ncuenta,ope)==0){
		ope2=1;
	 return(t);
     } 
	   t=t->prox;
    }
    Aux=Aux->prox;
}
if (ope2==0) return NULL;
}

perso* buscarperso3(bancos **p,perso **q,char cedu[10] ,char ope[40]){ 

bancos *Aux=*p;
perso *t=NULL;
while (Aux){
	t=Aux->aba;
while ((t))	{

	if ((strcmp(t->ncuenta,ope)==0)&&(strcmp(t->tcuenta,"03")==0)){
		
	 return(t);
     } 
	   t=t->prox;
    }
    Aux=Aux->prox;
}
if (ope==0) return NULL;
}

bool buscarper2(bancos **p,perso **q,char x[30],int s){

bancos *t=*p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if ((strcmp(aux->ncuenta,x)==0)&&(aux->saldo>=s)) {
ope = 1;

	return false;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return true;
};	


perso* buscarper3 (bancos **p,perso **q,char x[30]){

bancos *t=*p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if ((strcmp(aux->ncuenta,x)==0)&&(strcmp(aux->tcuenta,"03")!=0)) {
ope = 1;


	return aux;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return NULL;
};	


perso* buscarperso4(bancos **p,perso **q,char cedu[10] ,char ope[40]){ 

bancos *Aux = *p;
perso *t=NULL; 
int ope2=0;
while (Aux){
	t=Aux->aba;
while ((t))	{

	if ((strcmp(t->ncuenta,ope)==0)&&(strcmp(t->tcuenta,"04")==0)){
		ope2=1;
	 return(t);
     } 
	   t=t->prox;
    }
    Aux=Aux->prox;
}
if(ope2==0) return NULL;
}

bool buscarper5(bancos **p,perso **q,char x[30],int s){

bancos *t=*p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if ((strcmp(aux->ncuenta,x)==0)&&(aux->saldo>=s)) {
ope = 1;

	return false;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return true;
};	

perso* buscarper6(bancos **p,perso **q,char x[30]){

bancos *t=*p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if ((strcmp(aux->ncuenta,x)==0)&&(strcmp(aux->tcuenta,"04")!=0)) {
ope = 1;


	return aux;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return NULL;
};	



bool buscarper7(bancos **p,perso **q,char x[30]){

bancos *t=*p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if ((strcmp(aux->ncuenta,x)==0)&&(strcmp(aux->tcuenta,"04")!=0)&&(strcmp(aux->tcuenta,"03")!=0)) {
ope = 1;


	return true;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return false;
};	
void transferir (bancos**p,perso **q,tran **b,char tope [5]){
char x[30]; char o[30]; char v[50]; 
	char dia[20];char mes[20]; char ano[20]; char hora[20]; 
	char min[20];char seg[20];  char ncuenta[30]; 
	 char ncuenta2[30]; 
	 int s; 
		
		
		
		do{	printf("---Datos de la cuenta que realiza la transferencia: ---\n");
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta2,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta2)));
		
		if (buscarper7(&(*p),&(*q),ncuenta2)){ 

		printf("Introduzca el monto a transferir: \n");
		scanf("%d",&s);
		
		if (perso *qbuscada2= buscarperso2 (&(*p),&(*q),x,ncuenta2,s)){	//busca el puntero de la cuenta
		
		if (buscarper2(&(*p),&(*q),ncuenta2,s)==NULL){  //Indica si el saldo es mayor al que se esta pidiendo
		
		do{ printf("----Datos a la cuenta que se transfiere ---- \n");
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta)));
		
		if (buscarper7(&(*p),&(*q),ncuenta)){ 

		if (perso *qbuscada= buscarperso2 (&(*p),&(*q),x,ncuenta,s)){	
	
				
			printf ("---Datos de la transferencia --- \n");
			do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));
		
		if ((strcmp(qbuscada->cedula,x)==0)){
		
		do{
		printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		}while((contadorp(o)));	
		
		if	((buscartran(*p,*q,*b,o)==NULL)){
		
		do{	
		printf("Introduzca dia: \n");
		fflush(stdin);
		cin.getline(dia,5,'\n');
		fflush(stdin);
		}while((contadordi(dia)));
		do{
		printf("Introduzca mes : \n");
		fflush(stdin);
		cin.getline(mes,3,'\n');
		fflush(stdin);
		}while((contadordi(mes)));
		do{
		printf("Introduzca ano: \n");
		fflush(stdin);
		cin.getline(ano,5,'\n');
		fflush(stdin);
		}while((contadorp(ano)));	
		do{
		printf("Introduzca hora: \n");
		fflush(stdin);
		cin.getline(hora,3,'\n');
		fflush(stdin);
		}while((contadordi(hora)));
		do{
		printf("Introduzca minutos: \n");
		fflush(stdin);   
		cin.getline(min,3,'\n');
		fflush(stdin);
		}while((contadordi(min)));
		do{
		printf("Introduzca segundos: \n");
		fflush(stdin);
		cin.getline(seg,3,'\n');
		fflush(stdin);
		}while((contadordi(seg)));
		
		do{
		printf("Introduzca nombre del cliente: \n");
		fflush(stdin);
		cin.getline(v,50,'\n');
		fflush(stdin);
		}while(vacios(v));

		qbuscada2->saldo-=s;
		qbuscada->saldo+=s;
		
			insertarCabtran2(p,&qbuscada2,b,qbuscada2->code,x,o,dia,mes,ano,hora,min,seg,tope,v,ncuenta2,ncuenta,s);
			fflush(stdin);
			
			
			}else printf("\n *** El codigo de transaccion ya fue usado *** \n");
		}
		else printf ("----La cedula introducida no es la misma a la cuenta ingresada ----\n");
		}else printf("\n----El numero de cuenta NO se encontro ---- \n");
		}else printf ("--- No se puede transferir a una tarjeta de credito o pago de servicios --- \n");
		}else printf ("---- El saldo es insuficiente ---- \n");
	}else printf ("No se encontro la cuenta, o el saldo es insuficiente. \n");
		}else printf ("--- No se puede transferir desde una tarjeta de credito o pago de servicios --- \n\n *** Puede que no se Encontro la cuenta *** \n ");
}

void deposito (bancos**p,perso **q,tran **b,char tope [5]){
	char x[30]; char o[30]; char v[50]; 
	char dia[20];char mes[20]; char ano[20]; char hora[20]; 
	char min[20];char seg[20];  char ncuenta[30]; 
	 char cedu[30];
	
	bancos *aux=*p;
perso *aux2=NULL;  

tran *m=NULL;

int dep=0;

	do{	
		printf("Introduzca Numero de Cedula del Depositante (8 Digitos): \n");
		fflush(stdin);
		cin.getline(cedu,30,'\n');
		fflush(stdin);
		}while((contadorp4(cedu)));
		
		printf("Introduzca Montro a Depositar : \n");
		scanf("%d",&dep);


do{	
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta)));
		
	if (perso *qbuscada2= buscarperso2 (&(*p),&(*q),x,ncuenta,dep)){
		
		
		
			
			printf ("--- Datos del Deposito --- \n");
			do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));
		
		if (strcmp(qbuscada2->cedula,x)==0){
		
		do{
		printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		
		}while((contadorp(o)));	
			
		if	((buscartran(*p,*q,*b,o)==NULL)){	
		
		do{	
		printf("Introduzca dia: \n");
		fflush(stdin);
		cin.getline(dia,5,'\n');
		fflush(stdin);
		}while((contadordi(dia)));
	
		
		do{
		printf("Introduzca mes : \n");
		fflush(stdin);
		cin.getline(mes,3,'\n');
		fflush(stdin);
		}while((contadordi(mes)));
	
		
		do{
		printf("Introduzca ano: \n");
		fflush(stdin);
		cin.getline(ano,5,'\n');
		fflush(stdin);
		}while((contadorp(ano)));	

		do{
		printf("Introduzca hora: \n");
		fflush(stdin);
		cin.getline(hora,3,'\n');
		fflush(stdin);
		}while((contadordi(hora)));
	
		
		do{
		printf("Introduzca minutos: \n");
		fflush(stdin);   
		cin.getline(min,3,'\n');
		fflush(stdin);
		}while((contadordi(min)));

		
		do{
		printf("Introduzca segundos: \n");
		fflush(stdin);
		cin.getline(seg,3,'\n');
		fflush(stdin);
		}while((contadordi(seg)));

		do{
		printf("Introduzca nombre del cliente: \n");
		fflush(stdin);
		cin.getline(v,50,'\n');
		fflush(stdin);
		}while(vacios(v));
		
		
					
		qbuscada2->saldo+=dep;
		
			insertarCabtran(p,&qbuscada2,b,qbuscada2->code,x,o,dia,mes,ano,hora,min,seg,tope,v,cedu,ncuenta,dep);
			fflush(stdin);
			
	}else printf("\n *** El codigo de transaccion ya fue usado *** \n");	
		}
		else printf ("----La cedula introducida no es la misma a la cuenta ingresada ----\n");
		
	}
	else printf("\n----El numero de cuenta NO se encontro ---- \n");
}
			
void tarjetas (bancos**p,perso **q,tran **b,char tope [5]) {
char x[30]; char o[30]; char v[50]; 
	char dia[20];char mes[20]; char ano[20]; char hora[20]; 
	char min[20];char seg[20];  char ncuenta[30]; 
	 char ncuenta2[30]; 
	 int s; 
		
		
		
		do{	printf("--- Datos de la cuenta que realiza El Pago : ---\n");
		printf("Introduzca numero de cuenta (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta2,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta2)));

		if (buscarper7(&(*p),&(*q),ncuenta2)){ 
		
		if (perso* bus= buscarperso7(&(*p),&(*q),ncuenta2)){
		
		printf("Introduzca el monto a transferir: \n");
		scanf("%d",&s);
		
	
		
		if (buscarper5(&(*p),&(*q),ncuenta2,s)==NULL){
		
		do{ printf("----Datos a la cuenta que se transfiere ---- \n");
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta)));
		
		
		
		if (perso *qbuscada2= buscarperso3 (&(*p),&(*q),x,ncuenta)){

			if (buscarper5(&(*p),&(*q),ncuenta,s)==NULL){
				
			printf ("---Datos de la transferencia --- \n");
			do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));
		
		if ((strcmp(qbuscada2->cedula,x)==0)){
		
		do{
		printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		}while((contadorp(o)));	
		
		if	((buscartran(*p,*q,*b,o)==NULL)){
		
		do{	
		printf("Introduzca dia: \n");
		fflush(stdin);
		cin.getline(dia,5,'\n');
		fflush(stdin);
		}while((contadordi(dia)));
		do{
		printf("Introduzca mes : \n");
		fflush(stdin);
		cin.getline(mes,3,'\n');
		fflush(stdin);
		}while((contadordi(mes)));
		do{
		printf("Introduzca ano: \n");
		fflush(stdin);
		cin.getline(ano,5,'\n');
		fflush(stdin);
		}while((contadorp(ano)));	
		do{
		printf("Introduzca hora: \n");
		fflush(stdin);
		cin.getline(hora,3,'\n');
		fflush(stdin);
		}while((contadordi(hora)));
		do{
		printf("Introduzca minutos: \n");
		fflush(stdin);   
		cin.getline(min,3,'\n');
		fflush(stdin);
		}while((contadordi(min)));
		do{
		printf("Introduzca segundos: \n");
		fflush(stdin);
		cin.getline(seg,3,'\n');
		fflush(stdin);
		}while((contadordi(seg)));
		
		qbuscada2->saldo-=s;  //Aqui realiza el descuento de ambas cuentas
		bus->saldo-=s;
		do{
		printf("Introduzca nombre del cliente: \n");
		fflush(stdin);
		cin.getline(v,50,'\n');
		fflush(stdin);
		}while(vacios(v));
		
			insertarCabtran(p,&bus,b,bus->code,x,o,dia,mes,ano,hora,min,seg,tope,v,ncuenta,ncuenta2,s);
			fflush(stdin);
			
			}else printf("\n *** El codigo de transaccion ya fue usado *** \n");
		}else printf ("----La cedula introducida no es la misma a la cuenta ingresada ----\n");
		
			}else printf (" \n--- El monto transferido es MAYOR al saldo que debe La Tarjeta ----  \n\n ** Puede que el numero de Cuenta sea diferente al de una Tarjeta de Credito ** \n");

		}else printf("\n----El numero de cuenta NO se encontro o es diferente a Credito ---\n \n");
		
		}else printf (" \n--- El monto transferido es MAYOR al saldo de la Cuenta ----  \n");
	
	}else printf ("-------- No se Encontro la cuenta  ---------- \n");
	}else printf ("--- No se puede Pagar desde una tarjeta de credito o pago de servicios --- \n\n *** Puede que no se Encontro la cuenta *** \n ");
}		
		
void tarjetas2 (bancos**p,perso **q,tran **b,char tope [5]) {
char x[30]; char o[30]; char v[50]; 
	char dia[20];char mes[20]; char ano[20]; char hora[20]; 
	char min[20];char seg[20];  char ncuenta[30]; 
	 char ncuenta2[30]; 
	 int s; 
	 perso *aux3=*q;
		
		
		
		do{	printf("--- Datos de la cuenta que realiza El Pago : ---\n");
		printf("Introduzca numero de cuenta (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta2,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta2)));

		if (buscarper7(&(*p),&(*q),ncuenta2)){ 
		
		if (perso* bus= buscarperso7(&(*p),&(*q),ncuenta2)){
		
		printf("Introduzca el monto a transferir: \n");
		scanf("%d",&s);
		
	
		
		if (buscarper5(&(*p),&(*q),ncuenta2,s)==NULL){
		
					
		
		
		do{
		printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		}while((contadorp(o)));	
		
		if	((buscartran(*p,*q,*b,o)==NULL)){
		
		do{	
		printf("Introduzca dia: \n");
		fflush(stdin);
		cin.getline(dia,5,'\n');
		fflush(stdin);
		}while((contadordi(dia)));
		do{
		printf("Introduzca mes : \n");
		fflush(stdin);
		cin.getline(mes,3,'\n');
		fflush(stdin);
		}while((contadordi(mes)));
		do{
		printf("Introduzca ano: \n");
		fflush(stdin);
		cin.getline(ano,5,'\n');
		fflush(stdin);
		}while((contadorp(ano)));	
		do{
		printf("Introduzca hora: \n");
		fflush(stdin);
		cin.getline(hora,3,'\n');
		fflush(stdin);
		}while((contadordi(hora)));
		do{
		printf("Introduzca minutos: \n");
		fflush(stdin);   
		cin.getline(min,3,'\n');
		fflush(stdin);
		}while((contadordi(min)));
		do{
		printf("Introduzca segundos: \n");
		fflush(stdin);
		cin.getline(seg,3,'\n');
		fflush(stdin);
		}while((contadordi(seg)));
		
		aux3->saldo-=s;  //Aqui realiza el descuento de ambas cuentas
		bus->saldo-=s;
		do{
		printf("Introduzca nombre del cliente: \n");
		fflush(stdin);
		cin.getline(v,50,'\n');
		fflush(stdin);
		}while(vacios(v));
		
			insertarCabtran(p,&bus,b,bus->code,aux3->cedula,o,dia,mes,ano,hora,min,seg,tope,v,aux3->ncuenta,ncuenta2,s);
			fflush(stdin);
			
			
		
			}else printf (" \n--- El monto transferido es MAYOR al saldo que debe La Tarjeta ----  \n\n ** Puede que el numero de Cuenta sea diferente al de una Tarjeta de Credito ** \n");

		
		
		}else printf (" \n--- El monto transferido es MAYOR al saldo de la Cuenta ----  \n");
	
	}else printf ("-------- No se Encontro la cuenta  ---------- \n");
	}else printf ("--- No se puede Pagar desde una tarjeta de credito o pago de servicios --- \n\n *** Puede que no se Encontro la cuenta *** \n ");
}				


void tarpropias(bancos **p,perso **q, tran **b,char tope[5]){

	bancos *t=*p;
	perso *aux=NULL;		int op=0,pago=0,ope=0;	char y[20];
	perso *aux2=NULL;		char x [30];
	
		do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));

		if (*p==NULL){
		
		printf("-- No hay bancos Registrados --");
		}else{
			while(t!=NULL){
				aux=t->aba;
				while(aux!=NULL){
					
					if((strcmp(aux->cedula,x)==0)&&(strcmp(aux->tcuenta,"03")==0)&&(op==0)){
						
						op=1; ope=1;
						aux2=aux;
					}else if ((strcmp(aux->cedula,x)==0)&&(strcmp(aux->tcuenta,"03")==0)&&(op==1)){
						op=0;
						system("cls");
						printf("\n-- Usted posee mas de una tarjeta de Credito -- \n ");
						system("pause");
						tarjetas(p,q,b,tope);

					}
					aux=aux->prox;
					}
				t=t->prox;
			}
		}

		if((aux2)&&(op==1)){
			
			tarjetas2(p,&aux2,b,tope);
		}else;

if (ope==0)printf("--- No se encontro la tarjeta de Credito --- \n");


}


void retiro (bancos**p,perso **q,tran **b,char tope [5]){
char x[30]; char o[30]; char v[50]; 
	char dia[20];char mes[20]; char ano[20]; char hora[20]; 
	char min[20];char seg[20];  char ncuenta[30]; 
	char cedu[30];
	  
	 int s; 
	 
	 	do{	
		printf("Introduzca Numero de Cedula de quien realiza el Retiro (8 Digitos): \n");
		fflush(stdin);
		cin.getline(cedu,30,'\n');
		fflush(stdin);
		}while((contadorp4(cedu)));
		
		
		
		do{	
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta)));
		
		if (buscarper7(&(*p),&(*q),ncuenta)){ 

		printf("Introduzca el monto a retirar: \n");
		scanf("%d",&s);
		
		if (perso *qbuscada2= buscarperso2 (&(*p),&(*q),x,ncuenta,s)){
		
		
		if (buscarper2(&(*p),&(*q),ncuenta,s)==NULL){
				
			printf ("---Datos de la transferencia --- \n");
			do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));
		
		if ((strcmp(qbuscada2->cedula,x)==0)){
		
		do{
		printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		}while((contadorp(o)));	
		
		if	((buscartran(*p,*q,*b,o)==NULL)){
		
		do{	
		printf("Introduzca dia: \n");
		fflush(stdin);
		cin.getline(dia,10,'\n');
		fflush(stdin);
		}while((contadordi(dia)));
		do{
		printf("Introduzca mes : \n");
		fflush(stdin);
		cin.getline(mes,10,'\n');
		fflush(stdin);
		}while((contadordi(mes)));
		do{
		printf("Introduzca ano: \n");
		fflush(stdin);
		cin.getline(ano,10,'\n');
		fflush(stdin);
		}while((contadorp(ano)));	
		do{
		printf("Introduzca hora: \n");
		fflush(stdin);
		cin.getline(hora,10,'\n');
		fflush(stdin);
		}while((contadordi(hora)));
		do{
		printf("Introduzca minutos: \n");
		fflush(stdin);   
		cin.getline(min,10,'\n');
		fflush(stdin);
		}while((contadordi(min)));
		do{
		printf("Introduzca segundos: \n");
		fflush(stdin);
		cin.getline(seg,10,'\n');
		fflush(stdin);
		}while((contadordi(seg)));
		do{
		printf("Introduzca nombre del cliente: \n");
		fflush(stdin);
		cin.getline(v,50,'\n');
		fflush(stdin);
		}while(vacios(v));
		qbuscada2->saldo-=s;
		
			insertarCabtran(p,&qbuscada2,b,qbuscada2->code,x,o,dia,mes,ano,hora,min,seg,tope,v,cedu,ncuenta,s);
			fflush(stdin);
			
		}else printf("\n *** El codigo de transaccion ya fue usado *** \n");	
		}
		else printf ("----La cedula introducida no es la misma a la cuenta ingresada ----\n");
		}
		
		else printf ("--- El saldo es insuficiente ---- \n");
		
	}
	else printf("\n----El numero de cuenta NO se encontro ---- \n");
	}else printf ("--- No se puede Retirar desde una tarjeta de credito o pago de servicios --- \n\n *** Puede que no se Encontro la cuenta *** \n ");
}





void servicios (bancos**p,perso **q,tran **b,char tope [5])	{
	char x[30]; char o[30]; char v[50]; 
	char dia[20];char mes[20]; char ano[20]; char hora[20]; 
	char min[20];char seg[20];  char ncuenta[30]; 
	 char ncuenta2[30]; 
	 int s; 
		
		
		
		do{	printf("--- Datos de la cuenta que realiza El Pago del Servicio : ---\n");
		printf("Introduzca numero de cuenta (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta2,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta2)));

		if (buscarper7(&(*p),&(*q),ncuenta2)){ 
		
		printf("Introduzca el monto a pagar: \n");
		scanf("%d",&s);
		
	if (perso* bus= buscarper6(&(*p),&(*q),ncuenta2)){	
		
	if (buscarper5(&(*p),&(*q),ncuenta2,s)==NULL){
		
		
		
		do{ printf("----Datos a la cuenta que se transfiere ---- \n");
		printf("Introduzca numero de cuenta o tarjeta de credito (10 Digitos): \n");
		fflush(stdin);
		cin.getline(ncuenta,30,'\n');
		fflush(stdin);
		}while((contadorp3(ncuenta)));
		
		
		
		if (perso *qbuscada2= buscarperso4 (&(*p),&(*q),x,ncuenta)){

			if (buscarper5(&(*p),&(*q),ncuenta,s)==NULL){
				
			printf ("---Datos de la transferencia --- \n");
			do{	
		printf("Introduzca Numero de Cedula (8 Digitos): \n");
		fflush(stdin);
		cin.getline(x,30,'\n');
		fflush(stdin);
		}while((contadorp4(x)));
		
		if ((strcmp(qbuscada2->cedula,x)==0)){
		
		do{
		printf("Introduzca Codigo de Transaccion (4 DIGITOS): \n");
		fflush(stdin);
		cin.getline(o,30,'\n');
		fflush(stdin);
		}while((contadorp(o)));	
		
		if	((buscartran(*p,*q,*b,o)==NULL)){
		
		
		do{	
		printf("Introduzca dia: \n");
		fflush(stdin);
		cin.getline(dia,5,'\n');
		fflush(stdin);
		}while((contadordi(dia)));
		do{
		printf("Introduzca mes : \n");
		fflush(stdin);
		cin.getline(mes,3,'\n');
		fflush(stdin);
		}while((contadordi(mes)));
		do{
		printf("Introduzca ano: \n");
		fflush(stdin);
		cin.getline(ano,5,'\n');
		fflush(stdin);
		}while((contadorp(ano)));	
		do{
		printf("Introduzca hora: \n");
		fflush(stdin);
		cin.getline(hora,3,'\n');
		fflush(stdin);
		}while((contadordi(hora)));
		do{
		printf("Introduzca minutos: \n");
		fflush(stdin);   
		cin.getline(min,3,'\n');
		fflush(stdin);
		}while((contadordi(min)));
		do{
		printf("Introduzca segundos: \n");
		fflush(stdin);
		cin.getline(seg,3,'\n');
		fflush(stdin);
		}while((contadordi(seg)));
		
		do{
		printf("Introduzca nombre del Servicio: \n");
		fflush(stdin);
		cin.getline(v,50,'\n');
		fflush(stdin);
		}while(vacios(v));
		
		qbuscada2->saldo-=s;
		bus->saldo-=s;
		
		
			insertarCabtran(p,&bus,b,bus->code,x,o,dia,mes,ano,hora,min,seg,tope,v,ncuenta,ncuenta2,s);
			fflush(stdin);
		}else printf("\n *** El codigo de transaccion ya fue usado *** \n");
		}else printf ("----La cedula introducida no es la misma a la cuenta ingresada ----\n");
		
		}else printf (" \n--- El monto transferido es MAYOR al saldo que debe El Servicio ----  \n");

		}else printf("\n--El numero de cuenta NO se encontro o es diferente al de tipo Pago de servicios ---\n");
		
	}else printf (" \n--- El monto transferido es MAYOR al saldo de la Cuenta ----  \n");
	
	}else printf ("\n---- No se encontro la cuenta ----\n");
	}else printf ("--- No se puede Pagar desde una tarjeta de credito o pago de servicios --- \n\n *** Puede que no se Encontro la cuenta *** \n ");
	
}


void tarjetasmenu(bancos **p,perso **q, tran **b,char tope[5]){

	int ope;
	do{
	printf("1)Propias \n2)terceros \n0)regresar\n");
	scanf("%d",&ope);
	}while((ope<=0)&&(ope>=2));

	if(ope==1)tarpropias(p,q,b,tope);
	if(ope==2)tarjetas(p,q,b,tope);
	if(ope==0);
	
}
void Addtran (bancos**p,perso **q,tran **b){

	char tope[20]; 
	 int s; 
		
			do{
		printf("Introduzca tipo de Operacion :\n 01 Deposito\n 02 Retiro \n 03 Pago de Tarjetas \n 04 Pago de Servicios \n 05 transferencias \n 0 Regresar \n");
		fflush(stdin);
		cin.getline(tope,30,'\n');
		fflush(stdin);
		}while((contadorpo2(tope))&&(strcmp(tope,"0")!=0));
		
		if(strcmp(tope,"01")==0) deposito (p,q,b,tope);
		
		else if(strcmp(tope,"02")==0) retiro (p,q,b,tope);
		
		else if(strcmp(tope,"03")==0) tarjetasmenu (p,q,b,tope);
		
		else if(strcmp(tope,"04")==0) servicios (p,q,b,tope);
		
		else if(strcmp(tope,"05")==0) transferir(p,q,b,tope);
		
		else if(strcmp(tope,"0")==0);
		
		else printf("** Opcion Invalida **\n ");
}
		
