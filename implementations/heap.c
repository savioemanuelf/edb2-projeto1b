#include "../headers/heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializar o heap
void initHeap(Heap *heap) {
    heap->tamanho = 0;
    heap->capacidade = 10; 
    heap->data = (Aeronave *)malloc(heap->capacidade * sizeof(Aeronave));
    if (heap->data == NULL) {
        perror("Erro ao alocar memória para o heap");
        exit(EXIT_FAILURE);
    }
}

// PRIORIDADE DA HEAP NA INSERÇÃO
void heapifyUp(Heap *heap) {
    int index = heap->tamanho - 1;
    while (index > 0) {
        int pai = (index - 1) / 2;
        if (heap->data[pai].prioridade >= heap->data[index].prioridade)
            break;
        Aeronave temp = heap->data[pai];
        heap->data[pai] = heap->data[index];
        heap->data[index] = temp;
        index = pai;
    }
}

void heapifyDown(Heap *heap, int index) {
    int maior = index;
    int filhoEsquerdo = 2 * index + 1;
    int filhoDireito = 2 * index + 2;

    if (filhoEsquerdo < heap->tamanho && heap->data[filhoEsquerdo].prioridade > heap->data[maior].prioridade) {
        maior = filhoEsquerdo;
    }

    if (filhoDireito < heap->tamanho && heap->data[filhoDireito].prioridade > heap->data[maior].prioridade) {
        maior = filhoDireito;
    }

    if (maior != index) {
        Aeronave temp = heap->data[index];
        heap->data[index] = heap->data[maior];
        heap->data[maior] = temp;
        heapifyDown(heap, maior);
    }
}

// EXPANSÃO DA HEAP
void expandHeap(Heap *heap) {
    heap->capacidade *= 2;
    heap->data = (Aeronave *)realloc(heap->data, heap->capacidade * sizeof(Aeronave));
    if (heap->data == NULL) {
        perror("Erro ao realocar memória para o heap");
        exit(EXIT_FAILURE);
    }
}


// Inserir aeronave na heap (estatico)
// void inserirAeronave(Heap *heap, Aeronave aeronave) {
//     if (heap->tamanho >= MAX_HEAP_SIZE) {
//         printf("Heap cheia, nao sera possível inserir mais aeronaves.\n");
//         return;
//     }
    
//     // Inserindo a aeronave no final da heap
//     heap->data[heap->tamanho] = aeronave;
//     heap->tamanho++;

//     // Subir a aeronave na heap
//     int i = heap->tamanho - 1;
//     while (i > 0 && heap->data[i].prioridade > heap->data[(i - 1) / 2].prioridade) {
//         // Trocar a aeronave com pai
//         Aeronave temp = heap->data[i];
//         heap->data[i] = heap->data[(i - 1) / 2];
//         heap->data[(i - 1) / 2] = temp;
//         i = (i - 1) / 2; // Mover para o pai
//     }
// }

// Inserir aeronave na heap (dinamico)
void inserirAeronave(Heap *heap, Aeronave aeronave) {
    if (heap->tamanho >= heap->capacidade) {
        expandHeap(heap);
    }

    // Inserindo aeronave no fim
    heap->data[heap->tamanho] = aeronave;
    heap->tamanho++;

    // Subindo aeronave na heap
    heapifyUp(heap);
}


// Exibir o conteúdo do heap
void mostrarHeap(Heap *heap) {
    if (heap->tamanho == 0) {
        printf("Heap vazia.\n");
        return;
    }

    for (int i = 0; i < heap->tamanho; i++) {
        Aeronave a = heap->data[i];
        printf("ID: %s, Combustivel: %d, Tempo: %d, Tipo: %d, Emergencia: %d, Prioridade: %d\n", 
               a.id, a.combustivel, a.tempo, a.tipo, a.emergencia, a.prioridade);
    }
}


// Consultar a aeronave com maior prioridade
Aeronave ordenarHeap(Heap *heap) {
    if (heap->tamanho > 0) {
        return heap->data[0];
    }
    Aeronave emptyAeronave = {"EMPTY", 0, 0, 0, 0, 0};
    return emptyAeronave;
}


void removerAeronave(Heap *heap) {
    if (heap->tamanho == 0) {
        printf("Heap vazia, nao ha nada para remover.\n");
        return;
    }
    heap->data[0] = heap->data[heap->tamanho - 1];
    heap->tamanho--;
    heapifyDown(heap, 0);
}

void liberarHeap(Heap *heap) {
    free(heap->data);
    heap->data = NULL; 
    heap->tamanho = 0;
    heap->capacidade = 0;
}
