#include "atendimento.h"

void cadastrar_funcionario(Lista_Funcionario *lista){
  
  Funcionario *novo = (Funcionario*) malloc(sizeof(malloc));

  printf("Digite o ID do novo funcionario: ");
  scanf("%d", &novo->id_funcionario);

  Funcionario *atual = *lista;
  while (atual != NULL){
    if (atual->id_funcionario == novo->id_funcionario){
      free (novo);
      printf("ID de funcionario ja existente!\n");
      break;
    }
    atual = atual->prox;
  }

  printf("Digite o nome do novo funcionario: ");

  fflush(stdin);
  gets(novo->nome);

  printf("Digite a data de nascimento do novo funcionario (dd/mm/aa): ");
  scanf("%d/%d/%d", &novo->data_nascimento[0], &novo->data_nascimento[1], &novo->data_nascimento[2]);

  printf("Digite o cpf do novo funcionario (000.000.000-00): ");
  gets(novo->cpf);
  if (novo->cpf[3] != '.' || novo->cpf[7] != '.' || novo->cpf[10] != '-') {
    printf("Digite no formato especificado!");
    free(novo);
    return;
  }

  atual = *lista;
  while (atual != NULL){
    if (strcmp(atual->cpf, novo->cpf) == 0){
      free (novo);
      printf("CPF de funcionario ja existente!\n");
      break;
    }
    atual = atual->prox;
  }

  printf("Digite a senha do novo funcionario: ");
  scanf("%d", &novo->senha);

  printf("Digite o estado do novo funcionario: ");
  
  fflush(stdin);
  gets(novo->local.estado);

  printf("Digite a cidade do novo funcionario: ");
  
  fflush(stdin);
  gets(novo->local.cidade);

  printf("Digite o endereco do novo funcionario: ");

  fflush(stdin);
  gets(novo->local.endereco);

  novo->prox = NULL;
  if(*lista == NULL) *lista = novo;

  while (atual->prox != NULL) atual = atual->prox;
  atual->prox = novo;

}

void excluir_funcionario(Lista_Funcionario *lista, int id){
  Funcionario *ant, *atual = *lista;
  while(atual != NULL && atual->id_funcionario != id)
  {
    ant = atual;
    atual = atual->prox;
  } 

  if(atual == NULL) printf("Funcionario nao encontrado! \n");
  else {
    char opcao;
    printf("Funcionario encontrado, deseja realmente excluir o funcionario %s ? (s/n): ", atual->nome);
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S'){
      if (atual == *lista) *lista = atual->prox;
      else ant->prox = atual->prox;
      free (atual);
      printf("Funcionario excluido com sucesso! \n");
    }
  }
  
}

void cadastrar_cliente(Lista_Cliente *lista, Cliente dados){
  Cliente *atual = *lista;
  while(atual != NULL){
    if (atual->id_cliente == dados.id_cliente || strcmp(dados.cpf, atual->cpf) == 0)
    {
      printf("CPF ou ID iguais aos de clientes ja cadastrados! \n");
      return;
    }
    atual = atual->prox;
  }

  
  Cliente *novo = (Cliente *) malloc(sizeof(Cliente));

  if(*lista == NULL) *lista = novo;
  atual = *lista;

  while(atual->prox != NULL) atual = atual->prox;
  atual->prox = novo;
}

void atender_cliente(Fila_Atendimento *fila){
  Atendimento *primeiro = *fila;
  char opcao;
  printf("Digite S concluido quando terminar o atendimento do cliente %d: ", primeiro->id_cliente);
  scanf(" %c", &opcao);
  if (opcao == 'S' || opcao == 's'){
    *fila = primeiro->prox;
    free(primeiro);
  }
}

int verificar_login(int id, int senha, Lista_Cliente *lista_cliente){
  Cliente *atual = *lista_cliente;
  while(atual != NULL){
    if(atual->id_cliente == id && atual->senha == senha) return 1;
    atual = atual->prox;
  }
  return 0;
}