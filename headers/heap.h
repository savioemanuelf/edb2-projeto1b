#ifndef HEAP_H
#define HEAP_H

#include "aeronave.h"  

#define MAX_HEAP_SIZE 100

typedef struct Heap {
    Aeronave *data;  
    int tamanho;
    int capacidade;
} Heap;

void initHeap(Heap *heap);
void inserirAeronave(Heap *heap, Aeronave aeronave);
Aeronave ordenarHeap(Heap *heap);
void removerAeronave(Heap *heap);
void mostrarHeap(Heap *heap);
void liberarHeap(Heap *heap);

#endif // HEAP_H
