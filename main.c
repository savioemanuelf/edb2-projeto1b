#include "headers/interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    Heap heap;
    initHeap(&heap);

    int opcao = 0;
    char arquivo[50];

    while (opcao != 6) {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do arquivo CSV: ");
                scanf(" %s", arquivo);

                if (strstr(arquivo, ".csv") == NULL) {
                    strcat(arquivo, ".csv");
                }
                carregarAeronaveCSV(arquivo, &heap);
                break;

            case 2:
                inserirAeronaveManual(&heap);
                break;

            case 3:
                printf("Aeronaves na heap (ordenadas pela prioridade):\n");
                mostrarHeap(&heap);
                break;

            case 4:
                removerAeronave(&heap);
                printf("Aeronave de maior prioridade removida.\n");
                break;

            case 5:
                consultarMaiorPrioridadeHeap(&heap);
                break;

            case 6:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    liberarHeap(&heap);
    return 0;
}