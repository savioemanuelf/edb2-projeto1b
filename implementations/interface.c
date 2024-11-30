#include "../headers/interface.h"
#include <stdio.h>
#include <string.h>

void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Carregar aeronaves de um arquivo CSV\n");
    printf("2. Inserir aeronave manualmente\n");
    printf("3. Mostrar aeronaves na heap\n");
    printf("4. Remover aeronave com maior prioridade\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

void inserirAeronaveManual(Heap *heap) {
    Aeronave novaAeronave;

    printf("Digite o ID da aeronave: ");
    scanf(" %9s", novaAeronave.id);

    printf("Digite o nivel de combustivel (0-1000): ");
    scanf("%d", &novaAeronave.combustivel);

    printf("Digite o tempo de voo em minutos: ");
    scanf("%d", &novaAeronave.tempo);

    printf("Digite o tipo (0 para pouso, 1 para decolagem): ");
    scanf("%d", &novaAeronave.tipo);

    printf("Digite o status de emergencia (0 para nao, 1 para sim): ");
    scanf("%d", &novaAeronave.emergencia);

    calcularPrioridade(&novaAeronave);
    inserirAeronave(heap, novaAeronave);

    printf("Aeronave inserida com sucesso!\n");
}

void consultarMaiorPrioridadeHeap(Heap *heap) {
    Aeronave top = ordenarHeap(heap);
    if (strcmp(top.id, "EMPTY") == 0) {
        printf("Heap vazia.\n");
    } else {
        printf("Aeronave de maior prioridade:\n");
        printf("ID: %s, Combustivel: %d, Tempo: %d, Tipo: %d, Emergencia: %d, Prioridade: %d\n", 
               top.id, top.combustivel, top.tempo, top.tipo, top.emergencia, top.prioridade);
    }
}