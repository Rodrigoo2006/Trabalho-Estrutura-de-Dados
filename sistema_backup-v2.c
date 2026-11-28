#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da Pilha (LIFO) - Historico de versoes de backup
typedef struct NoBackup {
    int idBackup;
    char descricao[200];
    struct NoBackup* proximo;
} NoBackup;

// Estrutura da Lista Encadeada - Catalogo de arquivos
typedef struct NoArquivo {
    char nome[50];
    char ultimaAlteracao[100];
    int revisoes;
    struct NoArquivo* proximo;
} NoArquivo;

// Estrutura da Fila (FIFO) - Backups aguardando processamento
typedef struct NoFila {
    char descricao[200];
    struct NoFila* proximo;
} NoFila;

NoBackup* topo = NULL;
NoArquivo* listaArquivos = NULL;
NoFila* inicioFila = NULL;
NoFila* fimFila = NULL;
int contadorBackups = 0;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- OPERACOES DA PILHA (LIFO) ---

void criarBackup(char desc[]) {
    NoBackup* novo = (NoBackup*) malloc(sizeof(NoBackup));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    contadorBackups++;
    novo->idBackup = contadorBackups;
    strcpy(novo->descricao, desc);
    novo->proximo = topo;
    topo = novo;

    printf("[SUCESSO] Backup #%d criado com sucesso!\n", contadorBackups);
}

void restaurarBackup() {
    if (topo == NULL) {
        printf("[AVISO] Nenhum backup disponivel.\n");
        return;
    }

    NoBackup* temp = topo;
    printf("[RESTAURACAO] Backup ID %d: %s\n", temp->idBackup, temp->descricao);
    topo = topo->proximo;
    free(temp);
    printf("[SUCESSO] Sistema revertido.\n");
}

void consultarHistorico() {
    if (topo == NULL) {
        printf("[AVISO] Historico vazio.\n");
        return;
    }

    NoBackup* atual = topo;
    printf("\n===== HISTORICO DE VERSOES (PILHA LIFO) =====\n");
    while (atual != NULL) {
        printf("-> Backup ID: %d | Descricao: %s\n", atual->idBackup, atual->descricao);
        atual = atual->proximo;
    }
    printf("=============================================\n");
}

// --- OPERACOES DA FILA (FIFO) ---

void enfileirarBackup(char desc[]) {
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    strcpy(novo->descricao, desc);
    novo->proximo = NULL;

    if (fimFila == NULL) {
        inicioFila = novo;
        fimFila = novo;
    } else {
        fimFila->proximo = novo;
        fimFila = novo;
    }
}

void processarFila() {
    if (inicioFila == NULL) {
        printf("[AVISO] Nenhum backup pendente na fila.\n");
        return;
    }

    printf("\n===== PROCESSANDO FILA DE BACKUPS (FIFO) =====\n");
    while (inicioFila != NULL) {
        NoFila* temp = inicioFila;
        criarBackup(temp->descricao);
        inicioFila = temp->proximo;
        free(temp);
    }
    fimFila = NULL;
    printf("==============================================\n");
}

// --- OPERACOES DA LISTA ENCADEADA ---

void cadastrarArquivo() {
    char nome[50];
    char alteracao[100];
    char descFila[200];

    printf("Digite o nome do arquivo (ex: main.c): ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    if (strlen(nome) == 0) {
        printf("[AVISO] Nome invalido.\n");
        return;
    }

    printf("Digite a descricao da alteracao: ");
    fgets(alteracao, sizeof(alteracao), stdin);
    alteracao[strcspn(alteracao, "\n")] = '\0';

    // Verifica se o arquivo ja existe na lista
    NoArquivo* atual = listaArquivos;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            strcpy(atual->ultimaAlteracao, alteracao);
            atual->revisoes++;

            sprintf(descFila, "%s (rev.%d) - %s", atual->nome, atual->revisoes, alteracao);
            enfileirarBackup(descFila);

            printf("[SUCESSO] Arquivo '%s' atualizado e enviado para a fila!\n", nome);
            return;
        }
        atual = atual->proximo;
    }

    // Se nao existir, insere novo no no inicio da lista
    NoArquivo* novo = (NoArquivo*) malloc(sizeof(NoArquivo));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->ultimaAlteracao, alteracao);
    novo->revisoes = 1;
    novo->proximo = listaArquivos;
    listaArquivos = novo;

    sprintf(descFila, "%s (rev.1) - %s", nome, alteracao);
    enfileirarBackup(descFila);

    printf("[SUCESSO] Arquivo '%s' cadastrado e enviado para a fila!\n", nome);
}

void listarArquivos() {
    if (listaArquivos == NULL) {
        printf("[AVISO] Nenhum arquivo cadastrado.\n");
        return;
    }

    NoArquivo* atual = listaArquivos;
    printf("\n===== CATALOGO DE ARQUIVOS (LISTA ENCADEADA) =====\n");
    while (atual != NULL) {
        printf("- %s | Revisoes: %d | Ultima alteracao: %s\n",
               atual->nome, atual->revisoes, atual->ultimaAlteracao);
        atual = atual->proximo;
    }
    printf("==================================================\n");
}

int main() {
    int opcao = -1;
    char descricao[200];

    do {
        printf("\n===== SISTEMA DE BACKUP DE ARQUIVOS =====\n");
        printf("1 - Cadastrar / Modificar Arquivo\n");
        printf("2 - Criar Versao de Backup (Push)\n");
        printf("3 - Consultar Historico de Backups\n");
        printf("4 - Restaurar Ultimo Backup (Pop)\n");
        printf("5 - Listar Arquivos Cadastrados\n");
        printf("6 - Processar Fila de Backups (FIFO)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                cadastrarArquivo();
                break;
            case 2:
                printf("Digite a descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0';
                if (strlen(descricao) > 0) {
                    criarBackup(descricao);
                } else {
                    printf("[AVISO] Descricao vazia.\n");
                }
                break;
            case 3:
                consultarHistorico();
                break;
            case 4:
                restaurarBackup();
                break;
            case 5:
                listarArquivos();
                break;
            case 6:
                processarFila();
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("[AVISO] Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
