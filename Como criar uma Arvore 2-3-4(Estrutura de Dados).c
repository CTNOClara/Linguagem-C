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
TipoPilha 

//COMO INSERIR ELEMENTOS NA ARVORE? - PASSO 1
/*deve-se verificar quais as funções são necessárias  
funções: vazia(ok), criano(ok), ehfolha, inserir na folha, inserir na pilha, qualfilho
//deve-se criar um tipopilha para armazenar os pais
*/

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




