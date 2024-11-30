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
                printf("O arquivo %s foi carregado com sucesso\n", arquivo);
                getchar();
                break;

            case 2:
                inserirAeronaveManual(&heap);
                sleep(3);
                break;
            case 3:
                printf("Aeronaves na heap (ordenadas pela prioridade):\n");
                mostrarHeap(&heap);
                sleep(3);
                break;

            case 4:
                removerAeronave(&heap);
                printf("Aeronave de maior prioridade removida.\n");
                sleep(3);
                break;

            case 5:
                consultarMaiorPrioridadeHeap(&heap);
                sleep(3);
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                sleep(3);
        }
    }

    liberarHeap(&heap);
    return 0;
}