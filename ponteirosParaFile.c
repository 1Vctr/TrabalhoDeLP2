/* ponteirosParaFile.c
 * Programa que usa ponteiros para FILE
 * Pega todos os n�meros de um arquivo de entrada e
 * escreve eles arredondados para duas casas decimais, em outro arquivo, de sa�da.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
      FILE *entrada_p;      // ponteiro para o arquivo de entrada
      FILE *saida_p;        // ponteiro para o arquivo de sa�da

      double item;
      int estado_da_entrada;  // valor do status retornado pela fun��o fscanf
      int contador = 0;

      // Prepara��o para os arquivos de entrada e sa�da
      entrada_p = fopen("entrada.txt", "r");
      saida_p   = fopen("saida.txt", "w");

      // Recebe cada �tem, o formata, e o escreve ao arquivo de sa�da
      estado_da_entrada = fscanf(entrada_p, "%lf", &item);
      while (estado_da_entrada == 1) {
          contador++;
          printf("Salvando no arquivo de saida o item arredondado... \n número de itens considerados: %d \n", contador);
          fprintf(saida_p, "%.2f\n", item);
          estado_da_entrada = fscanf(entrada_p, "%lf", &item);
      }
      fprintf(saida_p, "O número total de itens é: %d\n", contador);
      printf("Fechando os arquivos...\n\n");
      // Fecha os arquivos
      fclose(entrada_p);
      fclose(saida_p);

      return (0);
}

