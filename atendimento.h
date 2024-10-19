#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
  int id_funcionario;
  char *nome;
  int data_nascimento[3];
  char *cpf;
  int senha;
  struct endereco local;
  struct funcionario *prox;
};

struct endereco {
  char *endereco;
  char *estado;
  char * cidade;
};

struct cliente {
  int id_cliente;
  char *nome;
  int data_nascimento[3];
  char *cpf;
  int senha;
  struct endereco;
  struct cliente *prox;
};

struct atendimento {
  int id_cliente;
  struct atendimento *prox;
};

typedef struct  atendimento Atendimento;
typedef struct  cliente Cliente;
typedef struct  funcionario Funcionario;
typedef struct  funcionario* Lista_Funcionario;
typedef struct  atendimento* Fila_Atendimento;
typedef struct  cliente* Lista_Cliente;

void cadastrar_funcionario(Lista_Funcionario*);
void excluir_funcionario(Lista_Funcionario*, int);
void cadastrar_cliente(Lista_Cliente*, Cliente novo);
void atender_cliente(Fila_Atendimento*);
void solicitar_atendimento(Fila_Atendimento*, int);
void excluir_cadastro(Lista_Cliente*, int);
int verificar_login(int, int, Lista_Cliente);