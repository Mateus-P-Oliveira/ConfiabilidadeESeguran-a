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
  int pasVendidas = 0, regadoresVendidos = 0, vasosVendidos = 0;
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
    } else if (pasVendidas > 70) {
      printf("Limite de Pas vendidas atingido\n");
      regadoresVendidos += regadores;
      vasosVendidos += vasos;
    } else if (regadoresVendidos > 80) {
      printf("Limite de Regadores vendidas atingido\n");
      pasVendidas += pas;
      vasosVendidos += vasos;
    } else if (vasosVendidos > 90) {
      printf("Limite de Vasos vendidas atingido\n");
      pasVendidas += pas;
      regadoresVendidos += regadores;
    } else {
      pasVendidas += pas;
      regadoresVendidos += regadores;
      vasosVendidos += vasos;
    }

    totalVendas += pas * 45 + regadores * 30 + vasos * 25;
  }

  float comissao = calcularComissao(totalVendas);

  printf("Total de vendas: R$%.2f\n", totalVendas);
  printf("Comissao: R$%.2f\n", comissao);
}

int main() {
  gerenciarVendas();
  return 0;
}
