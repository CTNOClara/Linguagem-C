#include "stdio.h"
#include "stdlib.h"

typedef struct Medida TMedida;
struct Medida
{
	int long chave;

	int tempo;
	double temp;
	double lat, logt;
	double pressao;
	double densidade;

	TMedida *prox;
//	double lat, log;
};



TMedida *criarMedida(int chave, int tempo, double temp, double lat, double logt, double pressao, double densidade){
	TMedida *medida = malloc(sizeof(TMedida));

	medida->chave = chave;
	medida->tempo = tempo;
	medida->temp = temp;
	medida->lat = lat;
	medida->logt = logt;
	medida->pressao = pressao;
	medida->densidade = densidade;
	medida->prox = NULL;

	return medida;
}

typedef struct ele TELE;
struct ele{
	void *cargautil;
	TELE *prox;
};
TELE *criarELE(void *cargautil){
	TELE *e = malloc(sizeof(TELE));
	e->cargautil = cargautil;
	e->prox = NULL;

	return e;
}

typedef struct lista TLista;
struct lista{
	int qtde;
	TELE *inicio;
	TELE *fim;
};

TLista *criarLSE(){
	TLista *lse = malloc(sizeof(TLista));

	lse->inicio = NULL;
	lse->fim = NULL;
	lse->qtde = 0;

	return lse;
}

void inserirLSE(TLista *lse, void *novo){
	// lista vazia

	TELE *ele = criarELE(novo);
	if (lse->inicio == NULL){
		lse->inicio = ele;
		lse->fim = ele;
	}else{
		ele->prox = lse->inicio;
		lse->inicio = ele;
	}
	lse->qtde++;
}

