#include <stdio.h>
#include <stdlib.h>

int main(){
    float temperatura;

    printf("Qual a temperatura na sua cidade hoje?: ");
    scanf("%f",&temperatura);
    if(temperatura < 22)
        printf("Eh melhor você se agasalhar!\n");
    if(temperatura == 24){
        printf("Eh a temperatura ambiente ideal!\n");
    }
    else if(temperatura >= 30)
        printf("Nao esqueca de se hidratar!");
    else
        printf("Dia agradável! :)");
    printf("\n\n");
    return 0;
}
