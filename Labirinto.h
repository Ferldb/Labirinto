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
void cria_labirinto(int *labirinto[30][30]);
void andar(int *labirinto[30][30], Pilha *pi);
void imprime_lab(int labirinto[30][30]);
int encontrar_rato(int labirinto[30][30]);
int encontrar_saida(int labirinto[30][30]);
