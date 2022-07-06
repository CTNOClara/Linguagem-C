//Aluno: Clarissa Thaís Nascimento de Oliveira
//Universidade Federal do Amazonas/Disciplina Algoritmo e Estrutura de Dados II

#include "stdio.h"
#include "stdlib.h"
//COMO CRIAR UMA ARVORE? - PASSO 1
//Estruturas de uma arvore, criando e definindo seus tipos
typedef struct NO{//estrutura tipo nó árvore 234
	int chave[4], tamanho;
	TipoNo *pai, *ponteiros[5];
}TipoNo;

typedef struct Arvore234{//estrutura tipo árvore 234 para raiz árvore
	TipoNo *raiz;
}TipoArvore234;
//COMO CRIAR UMA ARVORE? - PASSO 2
// a função para criar arvore precisa de outras função para criar "galho"
//oq seria essa criar galho? criação de um novo no e adiconar a raiz da arvore
//inicializa os elementos do no e as chaves
TipoNo *CriaNo(TipoNo *pai){ //o pai contém um ponteiro para algum elemento para a crição do no
	TipoNo *no = malloc(sizeof(TipoNo));
	int i;
	for(i=0;i<5;i++){
		no->ponteiros[i] = NULL; //todos os nós null, estão vazios, apenas foram inicializados
	}
	for(i=0;i<4;i++){
		no->chave[i] = 0; // cada chave recebe um valor começando em 0
	}
	no->tamanho = 0;
	no->pai = pai;
	return no;	
}
//COMO CRIAR UMA ARVORE? - PASSO 3
//agora vamos a criação da arvore em si, a função que irá inicializar a estrutura, a função
TipoArvore234 *CriaArvore(){
	TipoArvore234 *Arv234 = malloc(sizeof(TipoArvore234));
	Arv234->raiz = CriaNo(NULL);//o elemento raiz, recebeu a função criano, onde o no recebe como pai o valor Null, agora a arvore está inicializada e todos os elementos estão vazios
	return Arv234; 
}

//COMO INSERIR ELEMENTOS NA ARVORE? - PASSO 1
/*deve-se verificar quais as funções são necessárias  
funções: vazia(ok), criano(ok), ehfolha, inserir na folha, inserir na pilha, qualfilho
//deve-se criar um tipopilha para armazenar os pais
*/
int vaziaraiz(TipoNo **raiz){ //verifica se a raiz esta vazia 
	if((*raiz)->pai == NULL){
		return 1;
	}else{
		return 0;
	}
}
int raiz(TipoNo **raiz){//verifica no raiz com no pai (nulo)
    if((*raiz)->pai == NULL){ return 1; }
    else{ return 0; }
}

int folha(TipoNo **raiz){//verifica se no é folha (se o filho esq(pos 0) for nulo)
    if((*raiz)->ponteiros[0] == NULL){ return 1; }
    else{ return 0; }
}

void ordenar(int vetor[], int tam){//insertion sort
	for(int i=0; i<tam; i++){
		int aux = vetor[i];
		int j = i - 1;
		while(j >= 0 && vetor[j] > aux){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
}

void auxInserir(TipoNo **raiz, int valor, TipoAvrore234 *amw){//função auxiliar p inserção ordenada
	int tam = (*raiz) -> tamanho;
  	(*raiz) -> dado[tam] = valor;//insere elemento na raiz
  	(*raiz) -> tamanho++;//tamanho aumenta em 1
  	ordenar((*raiz)->dado, (*raiz)->tamanho);//ordenação de elementos inseridos
  	if((*raiz)->tamanho == 4){ dividir(raiz, amw); }//se nó filho está cheio (4 elementos), é dividido 
}

void inserir(TipoArvore234 *amw, int valor){//função inserção de valores
  TNO *ant, *pres = amw -> root; //ant - anterior, pres - presente, amw - árvore multiway, root - raiz
  do{//não folha
    ant = pres; //nó anterior igual nó presente
    pres = buscarFilho(&ant, valor);
  }while(pres);
  auxInserir(&ant, valor, amw);//é folha
}
int main(){
	printf("Chegou ate aqui");
}
/*
void inserir (TipoArvore234 *no, int *chave, TipoPilha *pai)
    if vazia(no) && vazia(pai)    
        // primeira chave
        no = cria_no(chave)
        retorne(no)
    se folha(no)
        no = inserir_folha (no, chave, pai)
        retorne (no)
    senão
        filho = qual_filho(no,chave)
        pai = inserir_pilha(pai, no)
        filho = inserir(filho, chave, pai)
        retorne (no)
    fim-se
fim

//funções 
TNO *criarNO(TNO *pai);
T234 *criar234();
int raiz(TNO**);
int folha(TNO**);
void auxInserir(TNO**, int, T234*);
void inserir(T234*, int);
TNO* buscarFilho(TNO**, int);
void buscarValor(T234*, int);
void dividir(TNO**, T234*);
void auxImprimir(TNO*, int);
void imprimir(T234*);

TNO *criarNO(TNO *pai){//cria/inicializa nó
	TNO *no = malloc(sizeof(TNO));
	for(int i=0; i<5; i++){ no -> ponteiros[i] = NULL; }//nós filhos recebem null
  for(int i=0; i<4; i++){ no -> dado[i] = 0; }
	no -> tamanho = 0;
	no -> pai = pai;
  return no;
}

T234 *criar234(){//cria árvore
  T234 *arv = malloc(sizeof(T234));
  arv -> root = criarNO(NULL);//cria no raiz árvore
  return arv;
}
	
int raiz(TNO **raiz){//verifica no raiz com no pai (nulo)
    if((*raiz)->pai == NULL){ return 1; }
    else{ return 0; }
}

int folha(TNO **raiz){//verifica se no é folha (se o filho esq(pos 0) for nulo)
    if((*raiz)->ponteiros[0] == NULL){ return 1; }
    else{ return 0; }
}

void ordenar(int vetor[], int tam){//insertion sort
	for(int i=0; i<tam; i++){
		int aux = vetor[i];
		int j = i - 1;
		while(j >= 0 && vetor[j] > aux){
			vetor[j+1] = vetor[j];
			j--;
		}
		vetor[j+1] = aux;
	}
}

void auxInserir(TNO **raiz, int valor, T234 *amw){//função auxiliar p inserção ordenada
	int tam = (*raiz) -> tamanho;
  	(*raiz) -> dado[tam] = valor;//insere elemento na raiz
  	(*raiz) -> tamanho++;//tamanho aumenta em 1
  	ordenar((*raiz)->dado, (*raiz)->tamanho);//ordenação de elementos inseridos
  	if((*raiz)->tamanho == 4){ dividir(raiz, amw); }//se nó filho está cheio (4 elementos), é dividido 
}

void inserir(T234 *amw, int valor){//função inserção de valores
  TNO *ant, *pres = amw -> root; //ant - anterior, pres - presente, amw - árvore multiway, root - raiz
  do{//não folha
    ant = pres; //nó anterior igual nó presente
    pres = buscarFilho(&ant, valor);
  }while(pres);
  auxInserir(&ant, valor, amw);//é folha
}

TNO *buscarFilho(TNO **raiz, int valor){//procura em qual filho do no está (possivelmente) o valor buscado
    int tam = (*raiz) -> tamanho;
    if(folha(raiz)){ return 0; } //se for folha não há filhos possíveis, retorna nulo
    else{ //buscar pos do possível filho
        int i=0;
        while(i<tam && valor > (*raiz)->dado[i]){ i++; }
        return (*raiz) -> ponteiros[i]; //caso valor buscado seja > que todos os elementos, retorna o último filho
    }
}

void auxBuscar(TNO *root, int valor, int nivel){//função auxiliar de busca
  int i; int tam = root -> tamanho;
  for(i=0; i<tam; i++){
    if(valor < root->dado[i]){ break; }
    else{
      if(valor == root->dado[i]){//elemento encontrado
        printf("o dado %d estava no nivel %d da arvore e na posicao %d do no\n", valor, nivel, i);
        return;
      }
    }
  }
  if(!root->ponteiros[0]){ printf("o valor %d nao encontra-se na arvore.\n", valor); }
  else{
    if(i == tam){ i--; }
    auxBuscar(root->ponteiros[i], valor, nivel+1);
  }
}

void buscarValor(T234 *a234, int valor){//função de busca de elemento na árvore
  auxBuscar(a234->root, valor, 0);
}

void trocarFilho(TNO *pai, TNO *filho){//função trocar filhos
  int i=0, j;
  while(pai -> ponteiros[i]){ i++; }
  TNO *aux;
  int tam = i+1;
  pai -> ponteiros[i] = filho;
  for(i=0; i<tam-1; i++){
    int auxi = pai -> ponteiros[i] -> tamanho-1;
    for(j=i+1; j<tam; j++){
      int auxj = pai -> ponteiros[j] -> tamanho-1;
      if(pai->ponteiros[j]->dado[auxj] < pai->ponteiros[i]->dado[auxi]){//ordenação e troca de nós filhos
        aux = pai -> ponteiros[j];
        pai -> ponteiros[j] = pai -> ponteiros[i];
        pai -> ponteiros[i] = aux;
      }
    }
  }
}

void dividir(TNO **fesq, T234 *amw){//divisão de nó filho
  TNO *aux, *pai, *fdir;//fdir - filho direito, fesq - filho esquerdo
  int i, dir, esq;
  int meio = (*fesq) -> dado[1];
  (*fesq) -> tamanho = 1; (*fesq) -> dado[1] = 0;
  if(!(*fesq)->pai){//se não for raiz
    pai = criarNO((*fesq)->pai);//cria novo nó (raiz)
    amw -> root = pai;//raiz árvore recebe nó pai
    pai -> ponteiros[0] = *fesq;//filho esquerdo recebe nó pai em filho (pos 0)  
  }else{ pai = (*fesq) -> pai; }//se for raiz
  (*fesq) -> pai = pai;
  fdir = criarNO(pai);//cria no irmão a direita de nó atual
  auxInserir(&fdir, (*fesq)->dado[2], amw);
  auxInserir(&fdir, (*fesq)->dado[3], amw);
  (*fesq) -> dado[2] = 0; 
  (*fesq) -> dado[3] = 0;
  trocarFilho(pai, fdir);
  auxInserir(&pai, meio, amw);
  i=0; esq=0; dir=0;
  aux = (*fesq) -> ponteiros[i];
  while(i<5 && aux){
  	(*fesq) -> ponteiros[i] = NULL;
    if(aux->dado[(aux->tamanho)-1] > meio){
    	fdir -> ponteiros[dir] = aux;
      	dir++;
    }else{
    	(*fesq)->ponteiros[esq] = aux;
        esq++;
    }
    i++;
    aux = (*fesq) -> ponteiros[i];
  }
}

void auxImprimir(TNO *raiz, int nivel){//função auxiliar de impressão
    int i, tam = raiz->tamanho;
    for(i=0; i<tam; i++){
      printf("    %d      %d      %d\n", nivel, i, raiz->dado[i]);
    }
    i=0;
    while(i < 4 && raiz->ponteiros[i]){
      auxImprimir(raiz->ponteiros[i], nivel+1);
      i++;
    }
}

void imprimir(T234 *a234){//imprime árvore 
  auxImprimir(a234->root, 0);
}
