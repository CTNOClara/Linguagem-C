#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
typedef struct no TNO; //tipo nó
typedef struct no { 
    long int chave[4];
    TNO *filho[4]; 
};

typedef struct pilha TPilha;
typedef struct pilha{ // tipo pilha
    TNO *pai; 
    TPilha *prox; 
};

TNO *juntar(TPilha *pilha, int aux);
TNO *RotacaoDireita(TNO *pai, int aux);
TNO *RotacaoDireita(TNO *pai, int aux);
TNO *removerChaveNo(TNO *no, long int chave);
TNO *remover(TNO *no, long int chave, TPilha *pilhaPai);
TNO *criarno(long int chave);
TNO *inserirNo(TNO *pai, TNO *no, int indice);
TNO *inserirOrdenado(TNO *no, long int chave);

TNO *topoPilha(TPilha *pilha);
TNO *split(TNO *no, TPilha *pilha);
TNO *inserir(TNO *raiz, long int chave, TPilha *pilha);
TNO *inserirInterno (TNO *pai, TNO *no, TPilha *pilha);

TPilha *removerTopo(TPilha *pilha);
TPilha *inserirPilha(TPilha *pilha, TNO *no);

bool ehFolha(TNO *no);
bool pilhaVazia(TPilha *pilha);
bool existe(TNO *raiz, long int chave);
bool arvoreVazia(TNO *no, TPilha *pilha);

int temEspaco(TNO *raiz);
int pertence(TNO *no, long int chave);
int identificarFilho(TNO *no, long int chave);

#endif /* BIBLIOTECA_H */


