#ifndef AERONAVE_H
#define AERONAVE_H

struct Heap;  
typedef struct Heap Heap; 

typedef struct Aeronave {
    char id[10];
    int combustivel;
    int tempo;
    int tipo;
    int emergencia;
    int prioridade;
} Aeronave;

void calcularPrioridade(Aeronave *aeronave);
void carregarAeronaveCSV(const char *filename, Heap *heap);  

#endif // AERONAVE_H