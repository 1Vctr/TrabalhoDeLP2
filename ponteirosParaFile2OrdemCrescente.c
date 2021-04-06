/* Uso de:
     (i) fprintf, para colocar a  entrada do usu�rio em um arquivo
    (ii) fscanf, para ler o arquivo criado anteriormente
*/

#include <stdio.h>

void ordenar(float *menorp, float *maiorp); /*Declarando a função para poder ser utilizada na main*/

int main(void){
   FILE *arquivop;
   char nome[20];
   float nota1;
   float nota2;
   float nota3;
   float media;

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

      ordenar(&nota1, &nota2); /*Ordena as notas em ordem crescente*/
      ordenar(&nota1, &nota3);
      ordenar(&nota2, &nota3);



      media = (nota1 + nota2 + nota3)/3;

      fprintf(arquivop, "%s:%5.2f:%5.2f:%5.2f:%5.2f\n", nome, nota1, nota2, nota3, media);
   } while (1);

   rewind(arquivop);

   while (fscanf(arquivop, "%[^:]:%f:%f:%f:%f", nome, &nota1, &nota2, &nota3, &media) == 5)
      fprintf(stdout, "%-20s %6.2f %6.2f %6.2f %6.2f", nome, nota1, nota2, nota3, media);

   return(0);
}

void ordenar(float *menorp, float *maiorp)
{
        float temp; 
         if ( *menorp > *maiorp) {
                 temp = *menorp;
              *menorp = *maiorp;
              *maiorp = temp;
        }
}
