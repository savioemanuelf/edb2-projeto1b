#include "headers/heap.h"
#include <stdio.h>
#include <string.h>

int main() {
    char arquivo[50];
    Heap heap;
    initHeap(&heap);

    printf("Nome do arquivo CSV: ");
    scanf(" %s", arquivo);
    
    if(strstr(arquivo, ".csv") == NULL) {
        strcat(arquivo, ".csv");
        carregarAeronaveCSV(arquivo, &heap);
    } else {
        carregarAeronaveCSV("teste.csv", &heap);
    }

    printf("Aeronaves na heap (ordenadas pela prioridade):\n");
    mostrarHeap(&heap);

    Aeronave top = ordenarHeap(&heap);
    printf("Aeronave com maior prioridade: %s\n", top.id);

    removerAeronave(&heap);
    printf("\nAeronaves apos remover a de maior prioridade:\n");
    mostrarHeap(&heap);

    liberarHeap(&heap);

    return 0;
}
