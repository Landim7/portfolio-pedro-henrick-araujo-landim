# Sistema de Otimização de Entregas 🚚

Este projeto consiste num algoritmo de gestão logística desenhado para processar listas de entregas, calcular tempos estimados, gerir prioridades e validar a viabilidade de janelas de tempo em tempo real.

## 📋 Descrição do Projeto

O sistema utiliza lógica de programação para organizar o fluxo de trabalho de um estafeta ou central de distribuição. Ele analisa variáveis como distância, condições de trânsito e prioridade do cliente para decidir a ordem das entregas e alertar sobre possíveis atrasos.

## 🚀 Estrutura do Algoritmo

O projeto está dividido em três componentes principais:

### 1. Fluxograma Operacional
[cite_start]Define o fluxo visual de decisões[cite: 1]:
* [cite_start]**Cálculo de Tempo**: Baseia-se na distância e no estado do trânsito[cite: 10, 16].
* [cite_start]**Validação de Janela**: Verifica se a entrega pode ser feita dentro do horário previsto[cite: 12].
* [cite_start]**Gestão de Prioridades**: Entregas prioritárias são movidas para o topo da lista[cite: 19].
* [cite_start]**Feedback**: Marcação automática de atrasos ou manutenção de rotas normais[cite: 14, 26].

### 2. Pseudocódigo (Lógica de Execução)
[cite_start]Implementa a lógica matemática do sistema[cite: 28, 30]:
* [cite_start]**Fórmula de Tempo**: $Tempo = Distância / Velocidade$ (com fator de ajuste de 1.5x para trânsito alto)[cite: 36, 37].
* [cite_start]**Tratamento de Erros**: Identificação de dados inválidos, como distâncias negativas[cite: 33].
* [cite_start]**Ordenação**: Sistema de pesos para organizar a próxima entrega na fila[cite: 41, 47, 49].

### 3. Cenários de Teste (QA)
[cite_start]Validação do sistema através de diferentes casos de uso[cite: 56]:
* [cite_start]**Cenário A (Ideal)**: Fluxo normal com alta prioridade[cite: 57].
* [cite_start]**Cenário B (Urgente)**: Entrega imediata[cite: 62].
* [cite_start]**Cenário C (Erro)**: Teste de robustez com entrada de distância negativa (-5km), resultando em remoção da entrega e log de erro[cite: 68, 72, 74].

## 🛠️ Sugestões de Melhoria

[cite_start]O projeto prevê evoluções para maior realismo[cite: 76]:
* [cite_start]**Complexidade de Variáveis**: Graduação do trânsito em múltiplos níveis em vez de apenas "Alto/Baixo"[cite: 77].
* [cite_start]**Validação de Tipos**: Bloqueio de entradas de texto em campos numéricos[cite: 82].
* [cite_start]**Critérios VIP**: Expansão dos fatores de prioridade (Clientes VIP, urgência médica, etc.)[cite: 78, 79].

## ✒️ Documentação Original
Os esquemas e lógicas foram extraídos dos seguintes documentos:
* **IMG_4992.pdf**: Lógica de fluxo e decisões.
* **IMG_4993.pdf**: Pseudocódigo técnico.
* **IMG_4994.pdf**: Tabela de cenários de teste.
* **IMG_4995.pdf**: Relatório de melhorias e análise crítica.

---
*Este repositório serve como documentação de um sistema lógico de automação para serviços de entrega.*

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
