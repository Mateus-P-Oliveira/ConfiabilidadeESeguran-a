#include <stdio.h>

// Função para calcular a comissão
float calcularComissao(float totalVendas) {
  float comissao = 0.0;

  if (totalVendas <= 1000) {
    comissao = totalVendas * 0.10;
  } else if (totalVendas <= 1800) {
    comissao = 1000 * 0.10 + (totalVendas - 1000) * 0.15;
  } else {
    comissao = 1000 * 0.10 + 800 * 0.15 + (totalVendas - 1800) * 0.20;
  }

  return comissao;
}

// Função para gerenciar as vendas
void gerenciarVendas() {
  int pasVendidas = 0, regadoresVendidos = 0, vasosVendidos = 0, temp;
  float totalVendas = 0.0;

  while (1) {
    int pas, regadores, vasos;
    printf("Digite o numero de pas, regadores e vasos vendidos (-1 para "
           "finalizar): ");
    scanf("%d %d %d", &pas, &regadores, &vasos);

    if (pas == -1) {
      break;
    }

    if (pasVendidas == 70 && regadoresVendidos == 80 && vasosVendidos == 90) {
      printf("Limite de vendas mensal atingido\n");
      break;
    }

    if (pas == 0 && regadores == 0 && vasos == 0) {
      printf("Nao houve vendas no mês\n");
    } else if (pasVendidas >= 71 || ((temp = pasVendidas + pas) >= 71)) {
      printf("Limite de Pas vendidas atingido\n");
      regadoresVendidos += regadores;
      vasosVendidos += vasos;
    } else if (regadoresVendidos >= 81 ||
               ((temp = regadoresVendidos + regadores) >= 81)) {
      printf("Limite de Regadores vendidas atingido\n");
      pasVendidas += pas;
      vasosVendidos += vasos;
    } else if (vasosVendidos >= 91 || ((temp = vasosVendidos + vasos) >= 91)) {
      printf("Limite de Vasos vendidas atingido\n");
      pasVendidas += pas;
      regadoresVendidos += regadores;
    } else {
      pasVendidas += pas;
      regadoresVendidos += regadores;
      vasosVendidos += vasos;
    }
    printf("Vendas Feitas: \nPas: %d \nRegadores: %d \nVasos: %d\n",
           pasVendidas, regadoresVendidos, vasosVendidos);
  }
  totalVendas =
      (pasVendidas * 45) + (regadoresVendidos * 30) + (vasosVendidos * 25);
  float comissao = calcularComissao(totalVendas);

  printf("Total de vendas: R$%.2f\n", totalVendas);
  printf("Comissao: R$%.2f\n", comissao);
}

int main() {
  gerenciarVendas();
  return 0;
}
