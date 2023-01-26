#include <stdio.h>
#include <string.h>

int main()
{
    char palavrasecreta[20];
    //tem a mesma função do printf, contudo ao invez de imprimir na tela, armazena os caracteres no buffer
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0, enforcou = 0, tentativas=0;
    char chutes[26];
    
    do {

    for(int i = 0; i <strlen(palavrasecreta); i++){

        //teste booleano para o if abaixo   
        int achou = 0; //false

        //armazena a palavra secreta dentro do array de char chutes
        for(int j = 0; j < tentativas; j++){
            if(chutes[j] == palavrasecreta[i]){
                achou = 1; //true
                break;
            }
        }
        if(achou){
            printf("%c", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
            
        }
        printf("\n\n");
        
        char chute;

        printf("Digite uma letra: ");
        scanf(" %c", &chute);

        //array de char para armazenar os chutes do jogador
        chutes[tentativas] = chute;
        tentativas++;        

        for(int i = 0; i < strlen(palavrasecreta); i++){
            if(palavrasecreta[i] == chute){
            printf("A posicao %d tem esse letra.\n\n", i+1);            
            }        
        }
    } while (!acertou && !enforcou);
    
}