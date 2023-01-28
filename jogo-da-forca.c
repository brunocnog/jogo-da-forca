#include <stdio.h>
#include <string.h>
#include <stdlib.h> //adicionado por conta da função exit()
#include <time.h> //adicionado para escolher a palavra secreta de forma randomica
#include "jogo-da-forca.h"


//declarando variável globais
char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

//função principal
int main(){    
      
    abertura();
    escolhepalavra();
        
    do {

        desenhaforca();
        chuta();

    } while (!ganhou() && !enforcou());    

    adicionaPalavra();
}

/* FUNÇÕES */

void abertura (){
    printf("************************\n");
    printf("*     Jogo da Forca    *\n");
    printf("************************\n\n");
}
//função para imprimir e armazenar o chute do jogador, incrementando a variável chutesDados ao final
void chuta(){    

    char chute;        
    printf("Digite uma letra: ");
    scanf(" %c", &chute);

    chutes[chutesDados] = chute;
    chutesDados++;
}

//verifica se o jogador já chutou determinada letra
int jachutou(char letra){

    int achou = 0; //false

    for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou; //retornar 0 ou 1
}

void desenhaforca(){

    printf("Voce ja chutou %d vezes.\n", chutesDados);

     //loop para imprimir a palavra secreta
        for(int i = 0; i <strlen(palavraSecreta); i++){

           if(jachutou(palavraSecreta[i])){
                printf("%c ", palavraSecreta[i]);
           }else {
                printf("_ ");
            }
        }                
        printf("\n\n");
}

void escolhepalavra(){

    //tem a mesma função do printf, contudo ao invez de imprimir na tela, armazena os caracteres no buffer
    //sprintf(palavraSecreta, "MELANCIA");

    FILE *f;

    //abre o arquivo
    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Banco de dados de palavras nao disponivel\n\n");
        exit(1);
    }

    int qtdPalavras;
    fscanf(f, "%d", &qtdPalavras);

    srand(time(0));
    int randomico = rand() % qtdPalavras;

    for (int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

//função que conta a quantidade de vezes que o jogador erro a letras da palavra secreta
int enforcou(){

    int erros = 0; //false

    //loop em todos os chutes dados
    for(int i = 0; i < chutesDados; i++){
        
        int existe = 0; //false - palavra não encontrada

        //verifica se a letra chutada faz parte da palavra secreta
        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){
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

//verifica se o jogador acertou todos os chutes
int ganhou(){

    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jachutou(palavraSecreta[i])){
            return 0;
        }
    }
    printf("\n");
    printf("Parabens, voce ganhou!!\n\n");
    return 1;
}

//solicita ao jogado, no final do jogo, se ele quer adicionar uma nova palavra no jogo
void adicionaPalavra() {
    char quer;

    printf("Adicionar uma nova palavra ao jogo (S/N): ");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novaPalavra[20];

        printf("Digite a nova palavra, em letras maiusculas: ");
        scanf("%s", novaPalavra);

        FILE *f;

        //abre o arquivo
        f = fopen("palavras.txt", "r+");
        if(f == 0){
            printf("Banco de dados de palavras não disponivel\n\n");
            exit(1);
        }

        //lê o número que está no começo do arquivo e incrementa
        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        //sobreescreve a primeira linha com o novo número
        fseek(f, 0, SEEK_SET); //parâmetros (o arquiv, quanto bytes andar (esq/dir), e de onde ele deve começar a andar)
        fprintf(f, "%d", qtd);
        /*  SEEK_SET - informa ao ponteiro para ficar na posição corrent. 
            SEEK_CUR - informa ao ponteiro para andar a partir do ponto atual.
            SEEK_END - informa ao ponteiro para andar a partir do fim do arquivo. */

        //adiciona a nova palavra ao final do arquivo
        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novaPalavra); //o /n é para quebrar uma linha no final da última palavra

        //fecha o arquivo
        fclose(f);
    }

} 