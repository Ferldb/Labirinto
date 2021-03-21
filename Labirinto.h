#define livre 32;
#define rato 184;
#define parede 219;
#define visitada 46;
#define beco 176;

typedef struct elemento *Pilha;

Pilha *cria_pilha();
void libera_Pilha(Pilha *pi);
int consulta_topo_Pilha(Pilha *pi);
int insere_Pilha(Pilha *pi, int dado);
int remove_Pilha(Pilha *pi);
int tamanho_Pilha(Pilha *pi);
int Pilha_cheia(Pilha *pi);
int Pilha_vazia(Pilha *pi);
void imprime_Pilha(Pilha *pi);
int encontrar_rato(int labirinto[30][30]);