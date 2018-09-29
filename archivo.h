#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<iostream>
#include <fstream>



bool archivoVacio(FILE *a){ //Retorna si el archivo esta o no vacio
    long desplazamiento = ftell(a);
    fseek(a, 0, SEEK_END);

    if (ftell(a) == 0){
        return true;
    }

    fseek(a, desplazamiento, SEEK_SET);
    return false;
}


void enlazarBenP(bancos **p, perso **q){//Se encarga de enlazar las personas leidas desde archivos
	
	if ((*p)->aba != NULL){
		perso *Auxq=(*p)->aba;
		while(Auxq->prox!=NULL)
			Auxq=Auxq->prox;
		Auxq->prox= *q;
		
	}
	else{
		(*p)->aba= *q;
	}
}

void enlazarPenT(perso **q, tran **b){//Se encarga de enlazar las tran leido desde archivos 
	if((*q)->lado != NULL){
		tran *Auxb=(*q)->lado;
		while(Auxb->sig!=NULL)
			Auxb=Auxb->sig;
		Auxb->sig= *b;
		
	}
	else{
		(*q)->lado= *b;
		
	}
}

bancos* buscarp(bancos *p, char ope[50]){ //Retorna el banco que se eligio para agregar el perso
bancos *Aux=p;
while (Aux){
if (strcmp(Aux->code,ope)==0) break;
        Aux=Aux->prox;
}
return(Aux);
}

perso *buscarq(bancos **p, char ope [50]){ //Retorna   para agregar la transaccion
      
		perso *lo=(*p)->aba;

       while (lo){
            if (strcmp(lo->ncuenta,ope)==0) break;
            lo=lo->prox;
       }
       return (lo);
}



void Archivo(bancos **p){ //Registra toda la informacion en un archivo ".txt
	FILE *archivop, *archivoq, *archivob;
	bancos *Aux=*p;
	perso *q;
	tran *b;
	
	char c[2];
	int contp=0, contq=0, contb=0;
	archivop= fopen("archivop.txt", "w");
	archivoq= fopen("archivoq.txt", "w");
	archivob= fopen("archivob.txt", "w");
	
	while (Aux){
        if(archivoVacio(archivop))
            fprintf(archivop, "pp\n");
        else
            fprintf(archivop, "\npp\n");
            fflush(stdin);
		fprintf(archivop, "%s\n", Aux->name);
		fflush(stdin);
		fprintf(archivop, "%s\n", Aux->code);
		fflush(stdin);
		fprintf(archivop, "%s\n", Aux->dire);
		fflush(stdin);
		
		if (Aux->aba){
			q=Aux->aba;
			while(q){
				if (archivoVacio(archivoq))
                    fprintf(archivoq, "qq\n");
                else
                    fprintf(archivoq, "\nqq\n");
				fflush(stdin);
				fprintf(archivoq, "%s\n", q->code);
				fflush(stdin);
				fprintf(archivoq, "%s\n", q->tcuenta);
				fflush(stdin);
				fprintf(archivoq, "%s\n", q->ncuenta);
				fflush(stdin);
				fprintf(archivoq, "%s\n", q->cedula);
				fflush(stdin);
                fprintf(archivoq, "%d", q->saldo);
                fflush(stdin);
				if (q->lado){
					b=q->lado;
					while(b){
						if (archivoVacio(archivob))
                            fprintf(archivob, "bb\n");
                        else
                           fprintf(archivob, "\nbb\n");
                         fflush(stdin);   
                        fprintf(archivob, "%s\n", b->codigo); 
						fflush(stdin);   
						fprintf(archivob, "%s\n", b->code);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->dia);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->mes);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->ano);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->hora);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->min);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->seg);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->tope);
						fflush(stdin);
						fprintf(archivob, "%d\n", b->monto);
						fflush(stdin);
						fprintf(archivob, "%s\n", b->cedula);
						fflush(stdin);
                        fprintf(archivob, "%s\n", b->nombre);
                        fflush(stdin);
                        fprintf(archivob, "%s\n", b->ncuenta);
                        fflush(stdin);
                         fprintf(archivob, "%s\n", b->ncuenta2);
                        fflush(stdin);
						
							b=b->sig;
					}
					
				}
			q=q->prox;
			}
		}
		Aux=Aux->prox;
	}
	fclose(archivop);
	fclose(archivoq);
	fclose(archivob);
	
}

void LeerArchivob(bancos **p){
FILE *archivo,*ar;
char c[50]; char leer [30]; char leer2 [30]; 
 archivo=fopen("archivob.txt","r");

if ((archivo)&&!(archivoVacio(archivo))){
while(!(feof(archivo))){
fscanf(archivo, " %[^\n]", &c);
	if(!(feof(archivo))){
		if (strcmp(c,"bb\n")){
			tran *b = new tran;
			
			fscanf(archivo, " %s", &(b)->codigo);
			fscanf(archivo, " %s", &(b)->code);
			fscanf(archivo, " %s", &(b)->dia);
			fscanf(archivo, " %s", &(b)->mes);
			fscanf(archivo, " %s", &(b)->ano);
			fscanf(archivo, " %s", &(b)->hora);
			fscanf(archivo, " %s", &(b)->min);
            fscanf(archivo, " %s", &(b)->seg);
            fscanf(archivo, " %s", &(b)->tope);
            fscanf(archivo, " %d", &(b)->monto);
			fscanf(archivo, " %s", &(b)->cedula);
			fscanf(archivo, " %[^\n]", &(b)->nombre);
            fscanf(archivo, " %s", &(b)->ncuenta);
            fscanf(archivo, " %s", &(b)->ncuenta2);
	(b)->sig=NULL;

bancos *pbuscada= buscarp(*p,(b)->codigo);
perso *qbuscada= buscarq(&pbuscada,(b)->ncuenta2);
enlazarPenT(&qbuscada, &b);

}
}
}//del if(archivo)
}
else {		archivo=fopen("archivob.txt", "w+");
		}


fclose(archivo);
}

void LeerArchivoq(bancos **p){//Carga los datos de personas desde el archivo
FILE *archivo3,*ar3;
char c[100];
int x;
archivo3=fopen("archivoq.txt","r+");
if((archivo3)&&(!(archivoVacio(archivo3)))) {
while(!(feof(archivo3))){
fscanf(archivo3, " %[^\n]", &c);
if (strcmp(c, "qq\n")){
perso *q = new perso;
fscanf(archivo3, " %s", &(q)->code);
fscanf(archivo3, " %s", &(q)->tcuenta);
fscanf(archivo3, " %s", &(q)->ncuenta);
fscanf(archivo3, " %s", &(q)->cedula);
fscanf(archivo3, " %d", &(q)->saldo);
(q)->prox=NULL;
(q)->lado=NULL;
bancos *pbuscada= buscarp(*p,(q)->code);

enlazarBenP(&pbuscada, &q);
}
}
}else {		archivo3=fopen("archivoq.txt", "w+");
		}

fclose(archivo3);
}

void LeerArchivoB(bancos **p){//Carga los datos desde el archivo
FILE *archivo2;
char c[100];
archivo2=fopen("archivop.txt", "rb");

if (((archivo2)) && (!(archivoVacio(archivo2)))){
	
while(!(feof(archivo2))){
fscanf(archivo2, " %[^\n]", &c);
if (!(feof(archivo2))){
	if (strcmp(c, "pp\n")&&((*p)==NULL)){
			*p= new bancos;
				fscanf(archivo2, " %[^\n]", &(*p)->name);
				fscanf(archivo2, " %s", &(*p)->code);
				fscanf(archivo2, " %[^\n]", &(*p)->dire);
				(*p)->prox=NULL;
				(*p)->aba=NULL;
		}else if (strcmp(c, "pp\n")&&((*p)!=NULL)){
					bancos *Aux= new bancos, *T=*p;
										while (T->prox!=NULL){
												T=T->prox;
										}
 					 fscanf(archivo2, " %[^\n]", &(Aux)->name);
					fscanf(archivo2, " %s", &(Aux)->code);
					fscanf(archivo2, " %[^\n]", &(Aux)->dire);
					T->prox= Aux;
					Aux->prox=NULL;
					Aux->aba=NULL;
					}
					}
					}
}else {		archivo2=fopen("archivop.txt", "w+");
		}
	
					

fclose(archivo2);
}
