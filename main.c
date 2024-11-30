#include "cabecalho/interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    Heap heap;
    initHeap(&heap);

    int opcao = 0;
    char arquivo[50];

    while (opcao != 7) {
        printf("Pressione enter para limpar o terminal e ver o menu: \n");
        getchar();
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                opcaoSelecionada(1);
                printf("Digite o nome do arquivo CSV: ");
                scanf(" %s", arquivo);

                if (strstr(arquivo, ".csv") == NULL) {
                    strcat(arquivo, ".csv");
                }
                carregarAeronaveCSV(arquivo, &heap);
                getchar();
                break;

            case 2:
                inserirAeronaveManual(&heap);
                getchar();
                break;
            case 3:
                printf("Aeronaves na heap (ordenadas pela prioridade):\n");
                mostrarHeap(&heap);
                getchar();
                break;

            case 4:
                removerAeronave(&heap);
                printf("Aeronave de maior prioridade removida.\n");
                getchar();
                break;

            case 5:
                consultarMaiorPrioridadeHeap(&heap);
                getchar();
                break;
            case 6:
                listarCSV();
                getchar();
                break;
            case 7:
                printf("Saindo do programa...\n");
                sleep(1.5);
                limparTerminal();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                getchar();
        }
    }

    liberarHeap(&heap);
    return 0;
}