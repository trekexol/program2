struct tran {
	char codigo[5];
	char code[5];
	char dia[5];
	char mes[5];
	char ano[5];
	char hora[5];
	char min[5];
	char seg[5];
	char tope[20];
	char ncuenta[50];
	char ncuenta2[50];
	char cedula [50];
	char nombre [50];
	int monto;
	
	tran *sig;
	
};


struct perso{
	
	char code[5];
	char tcuenta[5];
	char ncuenta[50];
	char cedula [50];
	int saldo;
	perso *prox;
	tran *lado;
}est;

struct bancos{
	char name[100];
	char code[30];
	char dire[100];
	bancos *prox;
	perso *aba;
};

