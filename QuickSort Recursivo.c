#include <stdio.h>
#include <stdlib.h>

void QuickSort(int vetor[], int esquerda, int direita)
{
  int i, j, aux;
  i = esquerda;
  j = direita;
  aux = vetor[i];

  if( esquerda < direita){
    while(i < j){
      while(vetor[j] <= aux && i < j){
        j--;
      }
      vetor[i] = vetor[j];
      while(vetor[i] >= aux && i < j){
        i++;
      }
      vetor[j] = vetor[i];
    }
    vetor[i] = aux;

    QuickSort(vetor, esquerda, i - 1);
    QuickSort(vetor, j + 1, direita);
  }
}

