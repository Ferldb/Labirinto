#include <stdio.h>
#include "Labirinto.h"
#include <time.h>
#include <Windows.h>

struct elemento
{
    int posicao;
    struct elemento *prox;
};

typedef struct elemento Elem;

Pilha *cria_pilha()
{
    Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
    if (pi != NULL)
    {
        *pi = NULL;
    }
    return pi;
}

void libera_Pilha(Pilha *pi)
{
    if (pi != NULL)
    {
        Elem *no;
        while ((*pi) != NULL)
        {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha *pi)
{
    if (pi == NULL)
        return 0;
    if ((*pi) == NULL)
        return 0;
    int dado = (*pi)->posicao;
    return dado;
}

int insere_Pilha(Pilha *pi, int dado)
{
    if (pi == NULL)
        return 0;
    Elem *no;
    no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->posicao = dado;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha *pi)
{
    if (pi == NULL)
        return 0;
    if ((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

void cria_labirinto(int *labirinto[30][30])
{
    time_t t;
    int num, num2;

    srand(time(NULL));
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            int num = (rand() % 3);

            if (num == 1)
            {
                labirinto[i][j] = parede;
            }
            else
            {
                labirinto[i][j] = livre;
            }
        }
    }

    for (int i = 0; i < 30; i++)
    {
        labirinto[0][i] = parede;
        labirinto[i][0] = parede;
        labirinto[29][i] = parede;
        labirinto[i][29] = parede;
    }

    do
    {
        num = (rand() % (28 - 1 + 1)) + 0;
        num2 = (rand() % (28 - 1 + 1)) + 0;
    } while (labirinto[num][1] == 219 || labirinto[num2][28] == 219);

    labirinto[num][1] = rato;
    labirinto[num2][29] = livre;
}

void andar(int *labirinto[30][30], Pilha *pi)
{

    int saida = encontrar_saida(labirinto);
    int atual = encontrar_rato(labirinto);
    insere_Pilha(pi, atual);
    do
    {
        atual = consulta_topo_Pilha(pi);
        int i = atual / 100;
        int j = atual % 100;
        if (labirinto[i][j + 1] == 32)
        {
            labirinto[i][j] = visitada;
            j++;
            insere_Pilha(pi, i * 100 + j);
            labirinto[i][j] = rato;
        }
        else if (labirinto[i + 1][j] == 32)
        {
            labirinto[i][j] = visitada;
            i++;
            insere_Pilha(pi, i * 100 + j);
            labirinto[i][j] = rato;
        }
        else if (labirinto[i - 1][j] == 32)
        {
            labirinto[i][j] = visitada;
            i--;
            insere_Pilha(pi, i * 100 + j);
            labirinto[i][j] = rato;
        }
        else if (labirinto[i][j - 1] == 32)
        {
            labirinto[i][j] = visitada;
            j--;
            insere_Pilha(pi, i * 100 + j);
            labirinto[i][j] = rato;
        }
        else
        {
            if (atual == saida)
            {
                break;
            }
            else
            {
                remove_Pilha(pi);
                labirinto[i][j] = beco;
                atual = consulta_topo_Pilha(pi);
                int i = atual / 100;
                int j = atual % 100;
                if (i == 0 && j == 0)
                {
                    printf("Labirinto sem solucao\n");
                    return;
                }
                labirinto[i][j] = rato;
            }
        }
        Sleep(150);
        system("cls");
        imprime_lab(labirinto);
    } while (atual != saida);
    if (atual == saida)
        printf("Labirinto concluido com sucesso!\n");
    libera_Pilha(pi);
}

void imprime_lab(int labirinto[30][30])
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            printf("%c", labirinto[i][j]);
        }
        printf("\n");
    }
}

int encontrar_rato(int labirinto[30][30])
{
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (labirinto[i][j] == 184)
            {
                return i * 100 + j;
            }
        }
    }
}

int encontrar_saida(int labirinto[30][30])
{

    for (int j = 0; j < 30; j++)
    {
        if (labirinto[j][29] == 32)
        {
            return (j * 100 + 29);
        }
    }
}
