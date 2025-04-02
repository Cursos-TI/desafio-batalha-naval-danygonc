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

    int horizontal[3] = {3, 3, 3};
    int vertical[3] = {3, 3, 3};

// navio horizontal
int linhaNH = 5;
int colunaNH = 2;
for (int i = 0; i < 3; i++){
tabuleiro [linhaNH][colunaNH + i] = horizontal [i];
}
//navio vertical

int linhaNV = 2;
int colunaNV = 5;
for (int i= 0; i < 3; i++){
tabuleiro [linhaNV + i][colunaNV] = vertical [i];
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