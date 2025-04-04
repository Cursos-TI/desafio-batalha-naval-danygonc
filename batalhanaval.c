#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabuleiro[10][10];

    // Inicializar o tabuleiro com água (0)
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            tabuleiro[i][j] = 0;

    int navio[3] = {3, 3, 3};

    // Navio horizontal
    for (int i = 0; i < 3; i++)
        tabuleiro[5][2 + i] = navio[i];

    // Navio vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[2 + i][5] = navio[i];

    // Navio diagonal 1
    for (int i = 0; i < 3; i++)
        tabuleiro[1 + i][1] = navio[i];

    // Navio diagonal 2
    for (int i = 0; i < 3; i++)
        tabuleiro[7 - i][2 + i] = navio[i];

    // habilidade - cone
    int habilidadeCone[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidadeCone[i][j] = (i >= j && i + j <= 4) ? 1 : 0;

    // habilidade - cruz
    int habilidadeCruz[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidadeCruz[i][j] = (i == 2 || j == 2) ? 1 : 0;

    // habilidade - octaedro
    int habilidadeOctaedro[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            habilidadeOctaedro[i][j] = ((i - 2)*(i - 2) + (j - 2)*(j - 2) <= 4) ? 1 : 0;

    // Ponto central para aplicar habilidades
    int linhaHabilidade = 5;
    int colunaHabilidade = 5;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int li = linhaHabilidade - 2 + i;
            int co = colunaHabilidade - 2 + j;

            if (li >= 0 && li < 10 && co >= 0 && co < 10) {
                if (habilidadeCone[i][j] == 1 && tabuleiro[li][co] == 0)
                    tabuleiro[li][co] = 5;
                if (habilidadeCruz[i][j] == 1 && tabuleiro[li][co] == 0)
                    tabuleiro[li][co] = 5;
                if (habilidadeOctaedro[i][j] == 1 && tabuleiro[li][co] == 0)
                    tabuleiro[li][co] = 5;
            }
        }
    }

    // Impressão do tabuleiro
    printf("  ");
    for (int i = 0; i < 10; i++) {
        printf("%c", linha[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d", i);
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~"); // água
            else if (tabuleiro[i][j] == 3)
                printf("#"); // navio
            else if (tabuleiro[i][j] == 5)
                printf("*"); // habilidade
            else
                printf("?"); // erro
        }
        printf("\n");
    }

    return 0;
}
