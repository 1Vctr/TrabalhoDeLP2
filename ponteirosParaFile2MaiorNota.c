/* Uso de:
     (i) fprintf, para colocar a  entrada do usu�rio em um arquivo
    (ii) fscanf, para ler o arquivo criado anteriormente
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
   FILE *arquivop;
   char nome[20];
   float nota1;
   float nota2;
   float nota3;
   float media;
   float maiorNota = -1;

   if ((arquivop = fopen("turma3notas.txt", "a+")) == NULL) {
      perror("");
      exit(2);
   }

   do {
      fprintf(stderr, "Nome do(a) aluno(a): ");
      fflush(stdin);

      if (fscanf(stdin, "%[^\n]", nome) != 1)
         break;
      fprintf(stderr, "Notas de 3 materias separadas por espa�o: ");
      fflush(stdin);
      fscanf(stdin, "%f%f%f", &nota1, &nota2, &nota3);
      maiorNota = nota1;
      if(nota2>maiorNota) maiorNota = nota2;
      if(nota3>maiorNota) maiorNota = nota3;
 
      media = (nota1 + nota2 + nota3)/3;

      fprintf(arquivop, "%s:%5.2f:%5.2f:%5.2f:%5.2f: A maior nota foi: %f\n", nome, nota1, nota2, nota3, media, maiorNota);
   } while (1);

   rewind(arquivop);

   while (fscanf(arquivop, "%[^:]:%f:%f:%f:%f a maior nota foi:%f", nome, &nota1, &nota2, &nota3, &media, &maiorNota) == 6)
      fprintf(stdout, "%-20s %6.2f %6.2f %6.2f %6.2f %6.2f", nome, nota1, nota2, nota3, media, maiorNota);

   return(0);
}
