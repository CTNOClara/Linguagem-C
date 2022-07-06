#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "remover.h"

int buscar(TNO *no) {
    int aux = no -> chave[0];

    if (ehFolha(no)) { // é folha
        return no -> chave[aux];
    } else { // não é folha
        return buscar(no->filho[aux]);
    }
}

TNO *juntar(TPilha *pilha, int aux) {
    pilha -> pai = inserirOrdenado(pilha->pai, pilha->pai->filho[aux]->chave[1]);
    pilha -> pai -> filho[0] = NULL;
    pilha -> pai -> filho[1] = NULL;

    return pilha;
}

//ROTAÇÕES
TNO *RotacaoDireita(TNO *pai, int aux) { 

}

TNO *RotacaoEsquerda(TNO *pai, int aux) {
    int indice = pai -> filho[aux] -> chave[0];
    
    pai -> chave[1] = pai -> chave[1];
    pai -> chave[1] = pai -> filho[aux] -> chave[indice];
    pai -> filho[aux] -> chave[0] = removerChaveNo(pai->filho[aux], pai->filho[aux]->chave[indice]);
    
    return pai;
}

TNO *removerChaveNo(no, chave) {

}

TNO *remover(TNO *no, int chave, TPilha *pilhaPai) {
    int aux;
    TNO *filho, *noMDM;

    if(arvoreVazia(no, pilhaPai)) {
        return no;
    }

    aux = pertence(no, chave);

    if(aux > 0) { // se a chave está no nó
        if(ehFolha(no, pilhaPai) && no->chave[0] == 1){ // só tem uma folha em um único nó
            no = removerChaveNo(no, chave);

            return no;
        }

        if(!ehFolha(no, pilha)){ // nó intermediario
            filho = identificarFilho(no, aux);
            pilhaPai = inserirPilha(pilhaPai, no);
            noMDM = buscar(filho);

            int indice = noMDM->chave[0];
            no -> chave[aux] = noMDM -> chave[indice];
            noMDM = remover(noMDM, noMDM->chave[indice], pilhaPai);
        }

        if(ehFolha(no)) {
            int temp = pertence(no, chave);
            int aux = temp +1; // irmão 

            if(pilhaPai->pai->chave[0] == 1) { // 2 filhos
                if(no->chave[0] == 1 && pilha->pai->filho[aux]->chave[0] == 1) {
                    pilhaPai -> pai = juntar(pilhaPai->pai, aux);
                }
            }
        } else { // não tem 1 filho, tem 2
            if(aux == 0) {
                pilhaPai -> pai = RotacaoEsquerda(pilhaPai->pai, aux);
            } else {
                pilhaPai -> pai = RotacaoDireita(pilhaPai->pai, aux);
            }
        }
    }
    return no;
}




