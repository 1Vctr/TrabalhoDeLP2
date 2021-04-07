#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    int soma = 0;
    printf("Digite um número inteiro positivo:\n");
    scanf("%d", &num);
    for (int i = 0; i <= num; i+=2)
    {
        soma += i;
    }
    printf("%d\n", soma);
    return 0;
}
