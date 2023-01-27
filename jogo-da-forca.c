#include <stdio.h>
#include <string.h>

//protótipo das funções
void abertura ();

void chuta(char chutes[], int* tentativas);

int jachutou(char letra, char *chutes, int tentativas);

 void desenhaforca(char *palavrasecreta, char *chutes, int tentativas);

int main(){

    char palavrasecreta[20];
    //tem a mesma função do printf, contudo ao invez de imprimir na tela, armazena os caracteres no buffer
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0, enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();
        
    do {

        desenhaforca(palavrasecreta, chutes, tentativas);

        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);
        
}

/* FUNÇÕES */

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

//verifica se o jogador já chutou determinada letra
int jachutou(char letra, char *chutes, int tentativas){

    int achou = 0;

    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca(char *palavrasecreta, char *chutes, int tentativas){

    printf("Voce ja deu %d chutes\n", tentativas);

     //loop para imprimir a palavra secreta
        for(int i = 0; i <strlen(palavrasecreta); i++){

           if(jachutou(palavrasecreta[i], chutes, tentativas)){
                printf("%c ", palavrasecreta[i]);
           }else {
                printf("_ ");
            }
        }                
        printf("\n\n");
}