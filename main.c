#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    // Declara e inicializa as variáveis
    int chute;
    int acertou;
    int nivel;
    int totaldetentativas;
    int inicio;
    int fim;
    int jogarnovamente = 1;

    // definindo a quantidade de pontos iniciais
    double pontos = 1000;

    
    // É necessário para gerar um número secreto randomico
    srand(time(0));

    while (jogarnovamente){
        // imprime cabecalho do nosso jogo
        printf("\n\n");
        printf("            P /_\\ P                                \n");
        printf("            /_\\_|_|_/_\\                           \n");
        printf("        n_n | ||. .|| | n_n Bem-vindo ao            \n");
        printf("        |_|_|nnnn nnnn|_|_| Jogo de Adivinhação!    \n");
        printf("        |" " | |_| |" " |                           \n");
        printf("        |_____| ' _ ' |_____|                       \n");
        printf("        \\__|_|__/                                  \n");
        printf("\n\n");
        
        // Menu
        printf("Qual o nível de dificuldade? \n");
        printf("(1) Fácil, (2) Médio, (3) Difícil\n\n");
        printf("Escolha: ");
        scanf("%d", &nivel);
        printf("Escolha o valor de início e fim do intervalo ex.:<0 200>: ");
        scanf("%d %d", &inicio, &fim);

        int numerosecreto = rand() % (fim - inicio + 1) + inicio;

        
        switch (nivel)
        {
        case 1:
            totaldetentativas = 20;
            break;
        case 2:
            totaldetentativas = 15;
            break;
        default:
            totaldetentativas = 6;
            break;
        }
        
        // loop principal do jogo
        for (int i = 1; i <= totaldetentativas; i++) {
            printf("Tentativa %d de %d\n", i, totaldetentativas);
            printf("Chute um número: ");
            scanf("%d", &chute);

            // trata o chute de um número negativo
            if(chute < 0) {
                printf("Você não pode chutar números negativos!\n");
                i--;
                continue;
            }
    
            // verifica se acertou, se foi maior ou menor
            acertou = (chute == numerosecreto);
    
            if(acertou) {
                break;
            } else if(chute > numerosecreto) {
                printf("Seu chute foi MAIOR que o número secreto\n");
            } else {
                printf("Seu chute foi MENOR que o número secreto\n");
            }
    
            // calcula a quantidade de pontos
            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos = pontos - pontosperdidos;
        }
        
        if(acertou) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("\nParabéns! Você acertou!\n");
            printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
        } else {
            printf("       \\|/ ____ \\|/    \n");   
            printf("        @~/ ,. \\~@      \n");   
            printf("       /_( \\__/ )_\\    \n");   
            printf("          \\__U_/        \n");
    
            printf("\nVocê perdeu! Tente novamente!\n\n");
        }
        printf("Deseja jogar novamente?  <1 - Sim, 0 - Não>: ");
        scanf("%d", &jogarnovamente);
    }
}