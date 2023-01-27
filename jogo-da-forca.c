#include <stdio.h>
#include <string.h>

#define 

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

int enforcou();

int main(){
    
    int acertou = 0;
    
    abertura();

    escolhepalavra();
        
    do {

        desenhaforca();

        chuta();

    } while (!acertou && !enforcou());
    
    printf("\n");
    printf("Voce erros mais de 5 vezes. Obrigado por jogar.");
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

    printf("Voce ja chutou %d vezes, sendo %d/ erradas.\n", tentativas);

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

//função que conta a quantidade de vezes que o jogador erro a letras da palavra secreta
int enforcou(){

    int erros = 0; //false

    //loop em todos os chutes dados
    for(int i = 0; i < tentativas; i++){
        
        int existe = 0; //false - palavra não encontrada

        //verifica se a letra chutada faz parte da palavra secreta
        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1; //true - a palavra foi encontrada
                break;
            }
        }

        //se a letra chutada não esta contido na palavra secreta, a variável erros é incrementada em 1
        if(!existe) erros++;

    }

    //retorna 1 se o limite de erros for maior do que 5. Se for menor, retorna 0
    return erros >= 5;
}