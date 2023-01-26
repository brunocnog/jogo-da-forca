#include <stdio.h>
#include <string.h>

void abertura (){
    printf("************************\n");
    printf("*     Jogo da Forca    *\n");
    printf("************************\n\n");
}

void chuta(char chutes[], int* tentativas){    

    //imprimei o chute do jogador
    char chute;        
    printf("Digite uma letra: ");
    scanf(" %c", &chute);

    //array de char para armazenar os chutes do jogador
    chutes[*tentativas] = chute;
    (*tentativas)++;
}

int main(){

    char palavrasecreta[20];
    //tem a mesma função do printf, contudo ao invez de imprimir na tela, armazena os caracteres no buffer
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0, enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();
        
    do {
    
        printf("Voce ja deu %d chutes.\n", tentativas);
        //loop para imprimir a palavra secreta
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
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }                
        printf("\n\n");
            
        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
        
}