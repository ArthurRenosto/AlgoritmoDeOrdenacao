#include "lista_encadeada.h"

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

void lista_para_vetor(Node* head, int vetor[], int tamanho) {
    Node* atual = head;
    int i = 0;
    while (atual != NULL && i < tamanho) {
        vetor[i++] = atual->valor;
        atual = atual->prox;
    }
}

void liberar_lista(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

