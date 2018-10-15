#include <stdio.h>
#include <stdlib.h>

struct no{
  int val;
  struct no *esq;
  struct no *dir;
};typedef struct no no;

struct no* NovoNo(int val){

  struct no* no = (struct no*)malloc(sizeof(struct no));

  no->val = val;
  no->dir = NULL;
  no->esq = NULL;

  return(no);
};

struct no* MenorNo(struct no* ABB){
  struct no* atual = ABB; 
  while (atual->esq != NULL){
    atual = atual->esq;
  } 
    printf("%d",atual->val);
  
  return atual; 
}

struct no* RemoveNo(struct no* ABB, int valor) { 
    // base case 
    if (ABB == NULL) {
      return ABB; 
    }

    if (ABB->val > valor){
      ABB->esq = RemoveNo(ABB->esq, valor);
    }else if ( ABB->val < valor){
      ABB->dir = RemoveNo(ABB->dir, valor);
    } 
    else{  
        if (ABB->esq == NULL) { 
            struct no *temp = ABB->dir; 
            free(ABB); 
            return temp; 
        } else if (ABB->dir == NULL) { 
            struct no *temp = ABB->esq; 
            free(ABB); 
            return temp; 
        } 
        
        struct no* temp = MenorNo(ABB->dir); 
  

        ABB->val = temp->val; 
   
        ABB->dir = RemoveNo(ABB->dir, temp->val); 
    } 
    return ABB; 
} 

void pre_ordem(no *raiz);
void em_ordem(no *raiz);
void pos_ordem(no *raiz);
int busca_binaria(no *ABB, int valor);
void insere_ABB_recursivo(no *ABB, int valor);

void pre_ordem(no *raiz){
  if(raiz == NULL){
    return;
  }
  printf("%d -", raiz->val);
  pre_ordem(raiz->esq);
  pre_ordem(raiz->dir);
}


void em_ordem(no *raiz){
  if(raiz == NULL){
    return;
  }
  em_ordem(raiz->esq);
  printf("%d -", raiz->val);
  em_ordem(raiz->dir);
}


void pos_ordem(no *raiz){
  if(raiz == NULL){
    return;
  }
  pos_ordem(raiz->esq);
  pos_ordem(raiz->dir);
  printf("%d -", raiz->val);
  
}

int busca_binaria(no *ABB, int valor){


   if(ABB->val == valor){
    return 1;
  }else if(ABB->val > valor){
    if(ABB->esq !=NULL){
      busca_binaria(ABB->esq, valor);
    }else{
      return 0;
    }
  }else if(ABB->val < valor){
    if(ABB->dir != NULL){
      busca_binaria(ABB->dir, valor);
    }else{
      return 0;
    }
  }
}

void insere_ABB_recursivo(no *ABB, int valor){
  if(ABB->val > valor){
    if(ABB->esq !=NULL){
      insere_ABB_recursivo(ABB->esq, valor);
    }else{
      ABB->esq = NovoNo(valor);
    }
  }else{
    if(ABB->dir != NULL){
      insere_ABB_recursivo(ABB->dir, valor);
    }else{
      ABB->dir = NovoNo(valor);
    }
  }
}

int main(void) {
  
  struct no *ABB = NovoNo(5);
  int chaves_ABB[6] = {6,2,1,3,8,7};


  for(int i=0; i<=6 -1; i++){
    if(busca_binaria(ABB, chaves_ABB[i])){
    printf("\n Elemento ja existe");
    }else{
    insere_ABB_recursivo(ABB,chaves_ABB[i]);
    }
  }

  printf("\n");
  pre_ordem(ABB);
  ABB = RemoveNo(ABB,5);
  printf("\n");
  pre_ordem(ABB);
  printf("\n");
  ABB = RemoveNo(ABB,1);
  pre_ordem(ABB);

}
