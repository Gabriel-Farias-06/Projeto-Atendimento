#include "atendimento.h"

int main(){
  Fila_Atendimento *fila_atendimento = NULL;
  Lista_Cliente *lista_cliente = NULL;
  Lista_Funcionario *lista_funcionario = NULL;
  int opcao = 0;
  do
  {
    printf("-------Bem-vindo a central de atendimento do XXXXXXXX-------\n\n\n\n1- Funcionario\n2- Cliente\n3- Sair \n\nDigite sua opcao: ");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      int id, senha;
      printf("-----Bem-vindo a central de atendimento-----\n\n\nDigite seu ID: ");
      scanf("%d", &id);
      printf("Digite sua senha: ");
      scanf("%d", &senha);
      if(verificar_login(id, senha, lista_cliente));
      
      break;
    
    case 2:
      
      break;

    default:
    printf("Opcao invalida! \n");
      break;
    }
  } while (opcao != 3);
  
}