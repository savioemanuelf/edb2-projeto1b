#ifndef INTERFACE_H
#define INTERFACE_H

#include "heap.h"

void exibirMenu();
void inserirAeronaveManual(Heap *heap); // Insere uma aeronave a dedo
void consultarMaiorPrioridadeHeap(Heap *heap); // Consulta a aeronave de maior prioridade

#endif // INTERFACE_H