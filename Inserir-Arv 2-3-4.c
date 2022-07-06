/*
04/2022 (PT-BR) - Manaus/AM

Universidade Federal do Amazonas - UFAM
Algoritmo e Estrutura de Dados 2 - AED2

Trabalho Prático 02 - Marcação de Consulta em Clínica Veterinária (Árvore 2-3-4)
Autora: Clarissa Thaís Nascimento de Oliveira 
*/

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "inserir.h"

TNO *criarNo(long int chave) { //cria/inicializa novo nó
    TNO *novoNo;
    
    novoNo = criarArvore();
    novoNo -> chave[0] = 1;
    novoNo -> chave[1] = chave;

    return novoNo;
}

TNO *inserirNo(TNO *pai, TNO *no, int indice) {
    pai -> filho[indice] = no;

    return pai;
}

TNO *inserirOrdenado(TNO *no, long int chave) {
    long int aux = 0;
    long int meio = (no -> chave[0] / 2) + 1; 

    if(chave < no->chave[meio]) {
        if(chave < no->chave[meio - 1] && (meio-1) != 0) {
            aux = no -> chave[meio];
            no -> chave[meio+1] = aux;
            aux = no -> chave[meio-1];
            no -> chave[meio-1] = chave; 
            no -> chave[meio] = aux;
            no -> chave[0]++;
        } else {
            aux = no -> chave[meio];
            no -> chave[meio] = chave; 
            no -> chave[meio+1] = aux;
            no -> chave[0]++;
        }
    } else {
        no -> chave[meio+1] = chave;
        no -> chave[0]++;
        
    }
    return no;
}

bool ehFolha(TNO *no) { 
    if(no->filho[0] == NULL && no->filho[1] == NULL && no->filho[2] == NULL && no->filho[3] == NULL) {                     
        return true; // eh folha
    } else {
        return false; // nao eh folha
    }
}

bool existe(TNO *no, long int chave) { 
    int aux = pertence(no, chave);
    
    if(aux == 0){ // não existe
        return  0;
    } else if(aux > 0 && aux < 5){ // existe
        return 1;
    } else {
       return existe(no->filho[aux-5], chave);
    }
}

bool pilhaVazia(TPilha *pilha) { 
    if(pilha->pai == NULL) {
        return true;
    }
    
    return false;
}

bool arvoreVazia(TNO *no, TPilha *pilha) { 
    if(pilhaVazia(pilha) && no->chave[0] == 0) {
        return true;
    }
    
    return false;
}

int temEspaco(TNO *no) { 
    if(no->chave[0] == 3) { // não tem espaco
        return 0;
    } else { // tem espaco
        return 1;
    }
}

int pertence(TNO *no, long int chave) {
    int filho = 5;
    int indice = 1;
    
    while(indice <= no->chave[0]) {
        if(chave == no->chave[indice]) {
            return indice;
        }

        if(chave < no->chave[indice] && no->filho[0] != NULL) { 
            return filho;
        }

        if(chave > no->chave[indice] && no->filho[0] != NULL && indice == no->chave[0]) { 
            return filho + 1;
        }

        filho++;
        indice++;
    }

    return 0;
}

int identificarFilho(TNO *no, long int chave) {
    int aux = pertence(no, chave);
    
    if(aux != 0) { aux -= 5; }

    return aux;
}

TNO *topoPilha(TPilha *pilha) {
    return (pilha -> pai);
}

TNO *split(TNO *no, TPilha *pilha) { 
   int pos;
   TNO *pai, *irmao;

    // insere a chave[2](central) no pai
    if(pilhaVazia(Pilha)){ // quebra a raiz
        pai = criarNo(no->chave[2]);
        pai -> filho[0] = no;
    } else { 
        pai = topoPilha(pilha);
        pilha  = removerTopo(pilha);
        pai = inserirInterno(pai, no, pilha);
    }

    // cria irmão e coloca seus filhos 
    irmao = criarNo(no->chave[3]);
    irmao -> filho[0] = no -> filho[2]; 
    irmao -> filho[1] = no -> filho[3];

    // organiza filhos (removendo os filhos 2 e 3)
    no -> filho[2] = NULL;
    no -> filho[3] = NULL;
    no -> chave[0] = 1;

    // usa pertence para dizer onde inserir o filho
    pos = pertence(pai, irmao->chave[1]); 
    pai = inserirNo(pai, irmao, (pos-5));

    //insere o pai modificado na pilha
    pilha = inserirPilha(pilha, pai); 

    return pai;
}

TNO *inserir(TNO *raiz, long int chave, TPilha *pilha) {
    if(arvoreVazia(raiz, pilha)) {
        raiz = criarNo(chave);

        return raiz;
    }
    
    if(!existe(raiz, chave)) { // se não existe
        if(ehFolha(raiz) == 1){ // se é folha
            if(temEspaco(raiz) == 1){ // se tem espaço 
                raiz = inserirOrdenado(raiz, chave); 

                return raiz;
            } else { // não tem espaço 
                raiz = split(raiz, pilha); 
                raiz = inserir(raiz, chave, pilha); 

                return raiz;
            }
        } else { // se não é folha
            pilha = inserirPilha(pilha, raiz); 
            
            TNO *filho = criarArvore();
            int idFilho = identificarFilho(raiz, chave); // descobre o filho que deve ser inserido
            
            filho = raiz -> filho[idFilho]; 
            filho = inserir(filho, chave, pilha); // insere no filho 

            return raiz;
        }
    } else { // existe
        return raiz;
    }
}

TNO *inserirInterno(TNO *pai, TNO *no, TPilha *pilha) {
    if(temEspaco(pai)) {
        pai = inserirOrdenado(pai, no->chave[2]);
    } else {
        pai = split(pai, pilha);
    }
    return pai;
}

TPilha *inserirPilha(TPilha *topo, TNO *no) { 
    TPilha *aux = criarPilha();

    aux -> pai = no;
    aux -> prox = topo;

    return aux;
}

TPilha *removerTopo(TPilha *topo) { 
    TPilha *novoTopo;
    novoTopo = topo -> prox;
    free(topo);

    return novoTopo;
}








