#include <stdio.h>
#include "Labirinto.c"
#include <stdlib.h>

void main()
{
    int labirinto[30][30];
    cria_labirinto(labirinto);
    printf("----- PROBLEMA DO LABIRINTO -----\n");
    printf("Labirinto gerado: \n");
    Pilha *pi = cria_pilha();
    imprime_lab(labirinto);
    printf("Iniciar busca pela saida: \n");
    system("pause");
    andar(labirinto, pi);
    system("pause");
}
