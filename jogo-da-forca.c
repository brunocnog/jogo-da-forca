#include <stdio.h>
#include <string.h>

//declarando variável globais
char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

//protótipo das funções
void abertura ();

void escolhepalavra();

void chuta();

int jachutou(char letra);

void desenhaforca();

int main(){
    
    int acertou = 0, enforcou = 0;
    
    abertura();

    escolhepalavra();
        
    do {

        desenhaforca();

        chuta();

    } while (!acertou && !enforcou);
        
}

/* FUNÇÕES */

void abertura (){
    printf("************************\n");
    printf("*     Jogo da Forca    *\n");
    printf("************************\n\n");
}

void chuta(){    

    //imprimei o chute do jogador
    char chute;        
    printf("Digite uma letra: ");
    scanf(" %c", &chute);

    //array de char para armazenar os chutes do jogador
    chutes[tentativas] = chute;
    tentativas++;
}

//verifica se o jogador já chutou determinada letra
int jachutou(char letra){

    int achou = 0;

    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca(){

    printf("Voce ja deu %d chutes\n", tentativas);

     //loop para imprimir a palavra secreta
        for(int i = 0; i <strlen(palavrasecreta); i++){

           if(jachutou(palavrasecreta[i])){
                printf("%c ", palavrasecreta[i]);
           }else {
                printf("_ ");
            }
        }                
        printf("\n\n");
}

void escolhepalavra(){

    //tem a mesma função do printf, contudo ao invez de imprimir na tela, armazena os caracteres no buffer
    sprintf(palavrasecreta, "MELANCIA");

}