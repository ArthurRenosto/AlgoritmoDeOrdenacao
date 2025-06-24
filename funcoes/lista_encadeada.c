#include "lista_encadeada.h"

// Função que insere um novo nó no início da lista encadeada
// Retorna o novo início da lista
Node* inserir_inicio(Node* head, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        while (head) {
            Node* temp = head;
            head = head->prox;
            free(temp);
        }
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = head;
    return novo;
}

// Função que insere um novo nó no final da lista encadeada
// Retorna o início da lista
Node* inserir_fim(Node* head, int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (!novo) {
        fprintf(stderr, "Erro de alocação de memória!\n");
        liberar_lista(head);
        exit(EXIT_FAILURE);
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (head == NULL) return novo;
    Node* temp = head;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = novo;
    return head;
}

// Função que converte um vetor em lista encadeada
// Se fim=1, insere no final (mantém ordem); se fim=0, insere no início (inverte ordem)
Node* vetor_para_lista(int vetor[], int tamanho, int fim) {
    Node* head = NULL;
    if (fim) {
        for (int i = 0; i < tamanho; i++) {
            head = inserir_fim(head, vetor[i]);
        }
    } else {
        for (int i = tamanho - 1; i >= 0; i--) {
            head = inserir_inicio(head, vetor[i]);
        }
    }
    return head;
}

// Função que converte uma lista encadeada em vetor
// Copia os valores dos nós para o vetor
void lista_para_vetor(Node* head, int vetor[], int tamanho) {
    Node* atual = head;
    int i = 0;
    while (atual != NULL && i < tamanho) {
        vetor[i++] = atual->valor;
        atual = atual->prox;
    }
}

// Função que libera a memória ocupada por uma lista encadeada
void liberar_lista(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
