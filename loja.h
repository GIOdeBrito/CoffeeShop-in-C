
#define G_VERSAO		1.0
#define SEGUNDOS(x)		(1000*x)
#define tem_char(x,y)	strchr(x,y) != 0
#define length(x)		sizeof(x)/sizeof(x[0])

typedef struct item {
	int id;
	char nome[128];
	char desc[256];
	double valor;
} item;

typedef struct {
	int quantity;
	int id;
} item_checkout;

typedef enum {false,true} bool;

void introducao();
void ler_cardapio(char*);
double str_para_double(char*);
int str_para_int(char*);
void realocar_objeto(void*,void*);
void* alterar_vetor(void*,int);
void listar_todos_itens(void);
char* ler_entrada(void);
void validar_escolha(char*);
bool e_numero(char*);
bool comparar_charv(char*,char*);
void mostrar_cardapio(void);
void imprimir_saudacao(void);
void esperar(double);
void listar_itens(int);
void init_cart(item_checkout*);
void list_cart(item_checkout[]);
void add_cart(item_checkout*,int);

extern item* itens;
extern int itens_q;
