#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
#define TABULEIRO_TAMANHO 10
#define HABILIDADES_LINHA 3
#define HABILIDADES_COLUNA 5
// funcao para posicionar habilidades
// os parametros são para saber do tabuleiro(onde será posicionado), a habilidade, e duas variaveis para ajuda na localizacao do tabuleiro
void posicicaHabili(int tabu[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO], int habili[HABILIDADES_LINHA][HABILIDADES_COLUNA], int posicaoX,int posicaoY){
    // percorre o tamanho da habilidade(linha e coluna) para marcar sua posicao no tabuleiro
    for (int i = 0; i < HABILIDADES_LINHA; i++){
        for (int j = 0; j < HABILIDADES_COLUNA; j++){
            int x = posicaoX + i; // posicao em linha
            int y = posicaoY + j; //posicao em coluna
            // ver se os valores de x e y não são maiores que o tabuleiro, se está dentro dos limites
            if ( x < TABULEIRO_TAMANHO && y < TABULEIRO_TAMANHO){
                tabu[x][y] = habili[i][j];
            }
        }
        
    }
};

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // criando matriz para o tabuleiro
    int tabuleiro[TABULEIRO_TAMANHO][TABULEIRO_TAMANHO] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    // letras do cabeçalho
    char letras[10] = {'A','B','C','D','E','F','G', 'H','I','J'};
    // matrizes de habilidades
    int cone[HABILIDADES_LINHA][HABILIDADES_COLUNA] = {
        {0,0,5,0,0},
        {0,5,5,5,0},
        {5,5,5,5,5}
    };
    int cruz[HABILIDADES_LINHA][HABILIDADES_COLUNA] = {
        {0,0,6,0,0},
        {6,6,6,6,6},
        {0,0,6,0,0}
    };
    int octaedro[HABILIDADES_LINHA][HABILIDADES_COLUNA] = {
        {0,0,8,0,0},
        {0,8,8,8,0},
        {0,0,8,0,0}
    };

    // os valores possiveis são:
    /*
        [0][0]  [0][1]  [0][2]  [0][3]  [0][4]
        [1][0]  [1][1]  [1][2]  [1][3]  [1][4]
        [2][0]  [2][1]  [2][2]  [2][3]  [2][4]
        [3][0]  [3][1]  [3][2]  [3][3]  [3][4]
        [4][0]  [4][1]  [4][2]  [4][3]  [4][4]
        a parti daqui não são mais possiveis, pois ultrapassa:
        X[5][0] X[5][1] X[5][2] X[5][3] X[5][4] 
        X[6][0] X[6][1] X[6][2] X[6][3] X[6][4] 
    */
    posicicaHabili(tabuleiro,cruz,0,0);
    posicicaHabili(tabuleiro,octaedro,3,2);
    posicicaHabili(tabuleiro,cone,6,0);

    printf("Batalha Naval (nivel novato)\n");
    printf("=============================================\n\n");
    
    // mostrar letras
    printf("\t");
    for (int a = 0; a < 10; a++){
        printf("%c\t", letras[a]);
    }
    printf("\n\n");
    // mostrar tabuleiro com os numeros na lateral
    for (int i = 0; i < 10; i++){
        printf("%d\t", i + 1);
        for (int j = 0; j < 10; j++){
            printf("%d\t",tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
