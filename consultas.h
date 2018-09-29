bool buscarbancos2(bancos *p,char x[10]){

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
void consulta1(bancos **p, perso **q, char y[30]){
	bancos *t=*p;
	perso *aux=NULL;
    int ope=0,total=0;

while(t)	{
	aux=t->aba;


while (aux != NULL) {


if (strcmp(aux->cedula,y)==0) {
ope = 1;
printf ("\n---------------------------------------\n\n");
	printf(" Banco: %s \n",t->name);
		printf(" Codigo de Agencia: %s \n",aux->code);
		printf(" Tipo de cuenta: %s \n",aux->tcuenta);
		printf(" Numero de cuenta: %s \n",aux->ncuenta);
		printf(" Cedula: %s \n",aux->cedula);
		printf(" Saldo : %d \n",aux->saldo);
		printf("\n");
		total+=aux->saldo;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) printf ("No se encontro la persona \n\n");
else printf("Saldo Total de las cuentas : %d",total);
};	
	
void consulta21(bancos *p, perso*q,char y[30]){
	bancos *aux1=p; perso *aux2=q;int cap=0;
	while (aux1){
		if (strcmp(aux1->code,y)==0){
			aux2=aux1->aba;
			while (aux2){
				cap+=aux2->saldo;
				aux2=aux2->prox;
			}
		}
		aux1=aux1->prox;
	}
	printf("\n---El Total General de Capital del Banco Es: %d ---\n",cap);
}

void consulta12(bancos **p, perso **q, char x[5],char y[10]){
	bancos *aux1=*p; perso *aux2=*q; 
	int total=0; int ope=0;
	
	while ((strcmp(aux1->code,x)!=0)&& (aux1->prox!=NULL)) aux1=aux1->prox;
	
		if (strcmp(aux1->code,x)==0) {
			aux2=aux1->aba;
			while (aux2!=NULL){
				if (strcmp(aux2->cedula,y)==0) {
					ope=1;
					printf("/n-----------------------------\n");
					printf(" Banco: %s \n",aux1->name);
					printf(" Codigo de Agencia: %s \n",aux1->code);
					printf(" Tipo de cuenta: %s \n",aux2->tcuenta);
					printf(" Numero de cuenta: %s \n",aux2->ncuenta);
					printf(" Cedula: %s \n",aux2->cedula);
					printf(" Saldo : %d \n",aux2->saldo);
					printf("\n");
					
					total+=aux2->saldo;
				}
				aux2=aux2->prox;
			}
		}
       if (ope==0)printf("----No Existe la persona registrada dentro de este banco ----\n") ;
       else printf ("Total del saldo de las cuentas : %d",total);
    }


void consulta22(bancos*p, perso *q, char y[30]){
	bancos *aux=p; perso *aux2=q,*aux3,*t; int suma=0; int ope=0;
	
	while ((aux)&& (strcmp(aux->code,y)!=0)) aux=aux->prox;
	
	if (strcmp(aux->code,y)==0) {
		aux2=aux->aba;
	
		
		while (aux2 != NULL){
			t=aux3;
			aux3=aux2->prox;
	
			
			while (aux3 != NULL){
				
				if ((strcmp(aux2->cedula,aux3->cedula)==0) && (ope==0)) {
			 	suma+=aux3->saldo;
			 	suma+=aux2->saldo;
			 	t->prox=aux3->prox;
			 	
			 	delete aux3;
			 	aux3=t;
			 	
			 }if ((strcmp(aux2->cedula,aux3->cedula)==0) && (ope==1)){
			 	suma+=aux3->saldo;
			 	t->prox=aux3->prox;
			 	
			 	delete aux3;
			 	aux3=t;
			 }  ope=1;
				 aux3=aux3->prox;
			
			}
			if(ope == 0) {
				printf("\n------------------------------------------------------------\n");
				printf ("El Titular de la cedula %s su saldo total es : %d \n\n",aux2->cedula,aux2->saldo);
			}
			if (ope == 1){
				printf("\n--------------------------------------------------------------\n");
				printf ("El Titular de la cedula %s su saldo total es : %d\n\n",aux2->cedula,suma);
			}
			aux2=aux2->prox;
			ope=0;
	}
	
	
	
}else printf("----No se encontro el banco ----\n");
	
}

struct titular {
		char cedula[10];
		int valor;
		int total;
		titular *prox;
	};
       

   
   titular *buscarti2 (titular *o,char x[10]){ //Retorna   para agregar el titular
       titular *aux=o;
       if (o==NULL) return (NULL);
       
       else {
       
       while ((aux)&&(strcmp(aux->cedula,x)!=0)) aux=aux->prox;
       
       if ((aux)&&(strcmp(aux->cedula,x)==0)) {
     
	    return(aux);
        
    	}
       
       if (aux==NULL){
	  
	   return (NULL);
   		}
   }
}

void titulares (titular *o){
		titular *t=o;
	
	if(o==NULL){
		printf("No hay cuentas registradas \n");
	}
	else{
	
	while(t){printf("\n-----------------------------\n");
		printf(" Cedula del Titular: %s \n",t->cedula);
		printf(" Monto Total de las Cuentas: %d \n",t->total);
		printf("\n");
		t = t->prox;
	}

}
		
}




void mostrartitulares(titular **o,bancos *p,perso *q, char *CodeN) {
	bancos *t = p;
	perso *aux= NULL;	int ope=0;
	titular *w=NULL;

while ((t->prox)&& ((strcmp(t->code,CodeN)!=0))) t=t->prox;

if((strcmp(t->code,CodeN)==0)){
	ope=1;
	aux=t->aba;

	printf(" -- codigo del banco %s -- \n",t->code);
		while (aux!=NULL){
	
			titular *buscarti = buscarti2(*o,aux->cedula);
				if (buscarti !=NULL)	{
						buscarti->total += aux->saldo;
					}
				else {
				
				if (*o==NULL){
					
 			      	titular *w=new titular;
 			      	w->valor=aux->saldo;
 			      	w->total=aux->saldo;
  			     	strcpy(w->cedula,aux->cedula);
  			     	*o=w;
  			     	w->prox=NULL;
  			     	
  				     }
  				     
  			     else {
  			     	titular *w=new titular;
  			     	w->valor=aux->saldo;
 			      	w->total=aux->saldo;
  			     	strcpy(w->cedula,aux->cedula);
  			     	titular *m=*o;
  			     	while (m->prox!=NULL) m=m->prox;
            		m->prox=w;
            		w->prox=NULL;
  				     }
			
			}
				
			aux=aux->prox;
		}
}
	
	titulares(*o);

if (ope==0)printf("----No esta registrado el banco ----\n") ;

}


void consulta13(bancos *p, perso *q, tran *b, char y[30], char x[30], char z[30]){
	 perso *t=q; tran *m=b; bancos *aux=p; int cont=1; int ope=0;
	int saldo=0;
			

while(aux)	{
t=aux->aba;	
  while(t !=NULL){
  	m=t->lado;
				while (m) {
							
						if ((strcmp(m->ncuenta2,z)==0)&&(strcmp(aux->code,x)==0)&& (strcmp(m->cedula,y)==0)) {
							ope =1;
						saldo=t->saldo;
						
							if (cont <=5) {
							 
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
								}
								else if (strcmp(m->tope,"05")==0){
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

								cont ++;
							}
						
						}
							m = m->sig;
							}
							t=t->prox;
				}
			aux=aux->prox;	
			}
			
	
	if (ope == 0) printf("--- No se encontraron transacciones --- \n");
	else printf ("\n --- Saldo de la cuenta %d --- \n",saldo);
}




void pagoservicios (bancos *p,perso *q,tran *b,char y[10]){
	
	bancos *t=p;
	perso *aux=NULL;
	int ope=0;
	tran *m=NULL;

while(t){		 
aux=t->aba;

while (aux != NULL) {

	m=aux->lado;
	while (m!=NULL){
		
		if (strcmp(m->cedula,y)==0) {
		if ((strcmp(m->tope,"04")==0)) { 
		ope = 1;
										
								printf ("\n-----------------------------\n\n");
								printf(" Banco: %s \n",t->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Servicio: %s \n",m->nombre);
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
		m=m->sig;
	}
aux = aux->prox;

}
t=t->prox;
}

if (ope==0) printf ("\n---- El titular no ha realizado Pagos de Servicios ----\n\n");
};	

	
struct titular2{
	
	
	char tcuenta[5];
	char ncuenta[50];
	char cedula [50];
	int saldo;
	titular2 *prox;
	
};	

void titulares2 (titular2 *opo){
		titular2 *t=opo;
	
	if(opo==NULL){
		printf("No hay cuentas registradas \n");
	}
	else{
	
	while(t){printf("\n--------------------------------\n");
		printf(" Numero de cuenta: %s \n",t->ncuenta);
		printf(" Tipo de cuenta: %s \n",t->tcuenta);
		printf(" Cedula: %s \n",t->cedula);
		printf(" Saldo : %d \n",t->saldo);
		printf("\n");
		t = t->prox;
	}

}
		
}


   titular2 *buscarti3 (titular2 *opo,char x[10]){ //Retorna   para agregar el titular
       titular2 *aux=opo;
       if (opo==NULL) return (NULL);
       
       else {
       
       while ((aux)&&(strcmp(aux->cedula,x)!=0)) aux=aux->prox;
       
       if ((aux)&&(strcmp(aux->cedula,x)==0)) {
     
	    return(aux);
        
    	}
       
       if (aux==NULL){
	  
	   return (NULL);
   		}
   }
}

	
	
void capitalxcuenta (titular2 **opo,bancos *p,perso *q,char x[10]){
	bancos *t = p;
	perso *aux= NULL;	int ope=0;
	titular2 *w=NULL; titular2 *m=NULL; 

while ((t->prox)&& ((strcmp(t->code,x)!=0))) t=t->prox;

if((strcmp(t->code,x)==0)){
	ope=1;
	aux=t->aba;

	printf(" *** codigo del banco %s *** \n",t->code);
		while (aux!=NULL){
	
			titular2 *buscarti= buscarti3(*opo,aux->cedula);
				if (buscarti !=NULL)	{
					
						m = buscarti->prox;
						titular2 *w=new titular2;
  			     		w->saldo=aux->saldo;
 			      		strcpy(w->cedula,aux->cedula);
 			      		strcpy(w->tcuenta,aux->tcuenta);
 			      		strcpy(w->ncuenta,aux->ncuenta);
 			      		buscarti->prox=w;
 			      		w->prox=m;
					}
				else {
				
				if (*opo==NULL){
					
 			      	titular2 *w=new titular2;
 			      		w->saldo=aux->saldo;
 			      		strcpy(w->cedula,aux->cedula);
 			      		strcpy(w->tcuenta,aux->tcuenta);
 			      		strcpy(w->ncuenta,aux->ncuenta);
  			     	*opo=w;
  			     	w->prox=NULL;
  			     	
  				     }
  				     
  			     else {
  			     
  			     	titular2 *w=new titular2;
 			      	w->saldo=aux->saldo;
 			   		strcpy(w->cedula,aux->cedula);
 			   		strcpy(w->tcuenta,aux->tcuenta);
 		      		strcpy(w->ncuenta,aux->ncuenta);
 		      		m=*opo;
  			     	while (m->prox!=NULL) m=m->prox;
            		m->prox=w;
            		w->prox=NULL;
  				     }
			
			}
				
			aux=aux->prox;
		}
}
	
	titulares2(*opo);

if (ope==0)printf("----No esta registrado el banco ----\n") ;

	
}

void consulta (bancos *p,perso *q,tran *b,char y[10],char x[10],char z[30]){
	 perso *t=q; tran *m=b; bancos *aux=p; int cont=1; int ope=0;
	int saldo=0;
			

while(aux)	{
t=aux->aba;	
  while(t !=NULL){
  	m=t->lado;
				while (m) {
							
						if ((strcmp(m->ncuenta2,z)==0)&&(strcmp(aux->code,x)==0)&& (strcmp(m->cedula,y)==0)) {
							ope =1;
								saldo=t->saldo;
							 
								if ((strcmp(m->tope,"01")==0)|| ((strcmp(m->tope,"02")==0))){
							
								printf ("\n-----------------------------------------------\n\n");
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
								else {
								printf ("\n-----------------------------------------------------\n\n");
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
								cont ++;
							
						
						}
							m = m->sig;
							}
							t=t->prox;
				}
			aux=aux->prox;	
			}
			
	
	if (ope == 0) printf("--- No se encontraron transacciones --- \n");
	
}	
	
	
void consulta33 (bancos *p,perso *q,tran *b,char y[10],char x[10],char z[30]){
 perso *t=q; tran *m=b; bancos *aux=p; int cont=1; int ope=0;
	int saldo=0;
			

while(aux)	{
t=aux->aba;	
  while(t !=NULL){
  	m=t->lado;
				while (m) {
							
						if ((strcmp(m->ncuenta2,z)==0)&&(strcmp(aux->code,x)==0)&& (strcmp(m->cedula,y)==0)) {
							ope =1;
					
							 
								if ((strcmp(m->tope,"03")==0)|| ((strcmp(m->tope,"04")==0))){
							
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
			
	
	if (ope == 0) printf("--- No se encontraron transacciones --- \n");

}

	
bool buscarperconsul(bancos *p,perso *q,char x[15],char y[10]){

bancos *t=p;
perso *aux=NULL;  
int ope=0;


while(t)	{
	aux=t->aba;


while (aux != NULL) {


if (strcmp(aux->ncuenta,x)==0) {
	if (strcmp(aux->cedula,y)==0) {
ope = 1;
return true;
	}else return false;
}
aux = aux->prox;
}
t=t->prox;
}
if (ope==0) return false;
};	
	
void pagoservi (bancos *p,perso *q,tran *b,char y[10]){

	
	bancos *t=p;
	perso *aux=NULL;
	int ope=0;
	tran *m=NULL;

while(t){		 
aux=t->aba;

while (aux != NULL) {

	m=aux->lado;
	while (m!=NULL){
		
		
		if ((strcmp(m->tope,"04")==0)) { 
		
					if(buscarperconsul(p,q,m->ncuenta2,y)){	
						ope = 1;
								printf ("\n-----------------------------\n\n");
								printf(" Banco: %s \n",t->name);
								printf(" Codigo de Agencia: %s \n",t->code);
								printf(" Nombre del Servicio: %s \n",m->nombre);
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
		m=m->sig;
	}
aux = aux->prox;

}
t=t->prox;
}

if (ope==0) printf ("\n---- El titular no ha realizado Pagos de Servicios ----\n\n");
};	






void Menuconsulta1(bancos **p, perso **q, tran **b,char y[30]){
	int op=-1;
	char x[10];
	char z[30];
	while(op!=0){
		printf ("1. Mostrar Su Estado Consolidado Total \n");
		printf ("2. Un Banco Dado Su Estado Consolidado Total\n");
		printf ("3. Un Banco Dado y Una Cuenta Dada\n");
		printf ("0. Salir\n");
		scanf ("%d",&op);
		switch(op){    
		
			case 1:    
				system("cls");
				consulta1(p,q,y);	
			break;
			
			case 2: 
			system("cls");
			do{
			printf("Ingrese el Codigo del Banco: (4 DIGITOS) ");
			scanf("%s",&x);
			}while((contadorp(x)));	
			consulta12(p,q,x,y);		
			break;
			
			case 3: system("cls");	
			do{
			printf("Ingrese el Codigo del Banco: (4 DIGITOS)");
			scanf("%s",&x);
			}while((contadorp(x)));	
			if (buscarbancos(*p,x)){
			
			do{
			printf("Ingrese El Numero De Cuenta : (10 Digitos)");
			scanf("%s",&z);
			}while((contadorp3(z)));
			system("cls");
			
			if(buscarper(*p,*q,z)){
			
			int op=-1;
			do{
			printf ("1)Mostrar sus ultimas cinco (05) transacciones y el saldo de la cuenta\n");
			printf ("2)Mostrar todas sus transacciones \n");
			printf ("3)Mostrar sus pagos de servios o tajetas de credito \n");
			printf ("0)Regresar \n");
			scanf("%d",&op);
			}while((op <= 0)&& (op>=3));
	
				if(op == 1) {
					consulta13(*p,*q,*b,y,x,z);
					}
				if(op == 2){
					consulta (*p,*q,*b,y,x,z);
				}
				if(op == 3){
					consulta33 (*p,*q,*b,y,x,z);
				}
				if(op == 0);
			}
			else 	printf("----No se encontro La Cuenta registrada ----\n");
			
		}else printf("----No se encontro el Banco ----\n");
			break;
	
		};
			
		printf("\n\n");
		system("pause");
		system("cls");
    };
}

void Menuconsulta2(titular2 *opo,titular *o,bancos *p, perso *q, char y[30]){
	int op=-1;
	
	while(op!=0){
		printf ("1. Total General De Capital \n");
		printf ("2. Total Capital Por Cada Cliente\n");
		printf ("3. Total Capital Por Cada Cliente y Cada Cuenta\n");
		printf ("0. Salir\n");
		scanf ("%d",&op);
		switch(op){    
			case 1:    
				system("cls");
				consulta21(p,q,y);
			break;
			case 2:
			    system("cls");
			  
			    mostrartitulares(&o,p,q,y);
						
			break;
			case 3: system("cls");	
			capitalxcuenta(&opo,p,q,y);
			break;
	
		};
			
		printf("\n\n");
		system("pause");
		system("cls");
    };
}

void Menuconsulta(titular2 *opo, titular *o,bancos *p, perso *q, tran *b){
	int op=-1; char y[30]; char x[30];
	while(op!=0){
		printf ("1. Dada La Cedula \n");
		printf ("2. Dado Un Banco\n");
		printf ("3. Dada una Cedula mostrar Pago De Servicios (Cedula del Servicio) \n");
		printf ("4. Dada una Cedula mostrar Pago De Servicios (Cedula del Titular del pago)\n");
		printf ("0. Salir\n");
		scanf ("%d",&op);
		switch(op){    
			case 1:    
				system("cls");
				do{
				printf("Ingrese La Cedula: ");
				scanf("%s",&y);			
				}while((contadorp4(y)));
				if(buscarper2(p,q,y))	
				Menuconsulta1(&(p),&(q),&(b),y);
				else printf("----No se encontro la Persona Registrada ----\n")	;	
			break;
			case 2:
			do{	
			 system("cls");
			 printf("Ingrese el Codigo del Banco: (4 DIGITOS)");
			 scanf("%s",&x);
			 }while((contadorp(x)));	
			
			if (buscarbancos2(p,x)){
			 Menuconsulta2(opo,o,p,q,x);
			}
			else printf("----No se encontro el banco registrado ----\n");
			break;
			case 3: system("cls");
			
				do{
				printf("Ingrese La Cedula: ");
				scanf("%s",&y);			
				}while((contadorp4(y)));
				if(buscarper2(p,q,y))
				pagoservicios(&(*p),&(*q),&(*b),y);
				else printf("\n ----No se encontro la Persona Registrada ----\n");	;
		
			break;

			case 4: system("cls");
			
				do{
				printf("Ingrese La Cedula: ");
				scanf("%s",&y);			
				}while((contadorp4(y)));
				if(buscarper2(p,q,y))
				pagoservi(&(*p),&(*q),&(*b),y);
				else printf("\n ----No se encontro la Persona Registrada ----\n");	;
		
			break;
		
		};
			
		printf("\n\n");
		system("pause");
		system("cls");
    };
}


