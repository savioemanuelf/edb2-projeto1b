# Ativdade de EDB2
## Controle de Tráfego Aéreo

**Este projeto tem como objetivo desenvolver um sistema de controle de tráfego
aéreo utilizando uma lista de prioridades implementada como um heap
máximo. A estrutura heap será utilizada para gerenciar as prioridades das
aeronaves de acordo com critérios específicos, permitindo a rápida identificação e remoção da aeronave de maior prioridade. Além disso, o sistema
permitirá a atualização das prioridades das aeronaves, possibilitando ajustes
dinâmicos conforme novas informações sejam inseridas.**

## Obejtivos
**O sistema:**
- Carrega informações das aeronaves a partir de um arquivo .csv.
- Permite a inserção manual de novas aeronaves pelo usuário.
- Calcula a prioridade de cada aeronave com base em critérios definidos.
- Gerencia as aeronaves em uma lista de prioridades, garantindo que a aeronave com maior prioridade esteja sempre acessível e ordenada.
- Implementa as operações básicas de um heap: inserção, remoção, visualização e atualização de prioridade.

## Configuração e execução

**Baixe todos os arquivos**:

**Instale as ferramentas essenciais para gcc**:

- Dica: Atualize os repositórios de pacotes caso esteja no Linux:
```bash
  sudo apt update
```
**Instale o compilador C**
```bash
  sudo apt install gcc
```
**Certifique-se de que o comando make está disponível**
```bash
  make --version
  sudo apt install make (Caso não esteja instalado)
```
**Compilar o programa:**
```bash
  Abra o terminal na pasta raíz
```
**Seguintes Comandos:**
```bash
  make
```
```bash
  make run
```
```bash
  make clean (Caso deseje apagar os arquivos temporários)
```
