#include "../cabecalho/aeronave.h"
#include "../cabecalho/heap.h"
#include "../cabecalho/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcularPrioridade(Aeronave *aeronave)
{
    aeronave->prioridade = (1000 - aeronave->combustivel) +
                           (1440 - aeronave->tempo) +
                           500 * aeronave->tipo +
                           5000 * aeronave->emergencia;
}

// CARREGAR AERONAVE
void carregarAeronaveCSV(const char *filename, Heap *heap)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        listarCSV();
        return;
    } else {
        printf("O arquivo %s foi carregado com sucesso\n", filename);
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        Aeronave aeronave;

        int n = sscanf(line, "%9[^,], %d, %d, %d, %d",
                       aeronave.id,
                       &aeronave.combustivel,
                       &aeronave.tempo,
                       &aeronave.tipo,
                       &aeronave.emergencia);
        if (n == 5)
        {
            calcularPrioridade(&aeronave);
            inserirAeronave(heap, aeronave);
        }
    }

    fclose(file);
}