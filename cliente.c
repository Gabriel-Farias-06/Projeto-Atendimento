#include "atendimento.h"

void solicitar_atendimento(Fila_Atendimento *fila, int id_cliente){
  Atendimento *novo = (Atendimento*) malloc(sizeof(Atendimento*));
  novo->id_cliente = id_cliente;
  novo->prox = NULL;
  if(*fila == NULL) *fila = novo;
  else{
    Atendimento *atual = *fila;
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
  }
}

void excluir_cadastro(Lista_Cliente *lista, int id){
  Cliente *ant, *atual = *lista;
  while(atual != NULL && atual->id_cliente != id)
  {
    ant = atual;
    atual = atual->prox;
  }

  char opcao;
  printf("Deseja realmente excluir o seu cadastro? (s/n): ");
  scanf(" %c", &opcao);

  if (opcao == 's' || opcao == 'S'){
    if (atual == *lista) *lista = atual->prox;
    else ant->prox = atual->prox;
    free (atual);
    printf("Cliente excluido com sucesso! \n");
  }
}
