#ifndef INTERFACE_H
#define INTERFACE_H

#include "heap.h"

void exibirMenu();
void inserirAeronaveManual(Heap *heap); // Insere uma aeronave a dedo
void consultarMaiorPrioridadeHeap(Heap *heap); // Consulta a aeronave de maior prioridade
void limparTerminal(); // Limpa terminal com base no sistema operacional
void opcaoSelecionada(int opcao); // Exibe a opcao selecionada após limpar o terminal
void listarCSV(); // Listar arquivos CSV no diretório da aplicação
#endif // INTERFACE_H