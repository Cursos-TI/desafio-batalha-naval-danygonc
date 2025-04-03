#include <stdio.h>

int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int tabuleiro [10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }    
    }

    int navio[3] = {3, 3, 3};

// navio horizontal
int linhaNH = 5;
int colunaNH = 2;
for (int i = 0; i < 3; i++){
tabuleiro [linhaNH][colunaNH + i] = navio [i];
}
//navio vertical

int linhaNV = 2;
int colunaNV = 5;
for (int i= 0; i < 3; i++){
tabuleiro [linhaNV + i][colunaNV] = navio [i];
}

//navio diagonal 1
int linhaND1 = 1;
int colunaND1 = 1;
for (int i= 0; i < 3; i++){
tabuleiro [linhaND1 + i][colunaND1] = navio [i];
}
//navio diagonal 2
int linhaND2 = 7;
int colunaND2 = 2;
for (int i= 0; i < 3; i++){
tabuleiro [linhaND2 - i][colunaND2 + i] = navio [i];
}

printf("  ");
for (int i= 0; i < 10; i++){
    printf("%c", linha[i]);
}
    printf ("\n");
    for (int i = 0; i < 10; i++){
        printf("%d", i);
        for (int j = 0; j < 10; j++)
    {
        printf("%d", tabuleiro[i][j]);
}
printf("\n");
}
return 0;
}
