# Sistema de Validação de Pagamento e Decomposição de Troco 💸

Este projeto apresenta uma solução lógica para automatizar o processo de finalização de vendas, focando na validação de valores recebidos e na otimização da entrega de troco através da decomposição em cédulas.

## 📋 Descrição do Projeto

O sistema simula a operação de um caixa de retalho. Ele recebe o valor total de uma compra e o valor entregue pelo cliente, decide se o pagamento é suficiente e, em caso positivo, calcula o troco exato, indicando a menor quantidade possível de notas (de 100 a 1) necessárias para compor o valor.

## 🚀 Estrutura Lógica

O projeto está documentado através de duas abordagens complementares:

### 1. Fluxograma Operacional
Representa o caminho de decisão do sistema:
* **Entrada**: Leitura do `valor_compra` e `valor_pago`.
* **Decisão Crítica**: Verificação se o pagamento é suficiente.
    * **Não**: Exibe a mensagem "Pagamento Insuficiente" e encerra.
    * **Sim**: Avança para o cálculo do troco e separação de notas.
* **Saída**: Exibição do resultado detalhado.

### 2. Pseudocódigo (Lógica Matemática)
Implementação técnica das funções de processamento:
* **`validar_pagamento`**: Retorna um valor booleano (Verdadeiro/Falso) comparando a compra com o pagamento.
* **`calcular_troco`**: Realiza a subtração simples para encontrar o montante a devolver.
* **`decompor_notas`**: Utiliza operações de divisão inteira (`DIV`) e resto (`MOD`) para calcular a distribuição das notas:
    * Notas processadas: **100, 50, 20, 10, 5, 2 e 1**.

## 🛠️ Tecnologias e Conceitos

* **Lógica de Programação**: Estruturas de decisão (`SE/SENÃO`) e funções modulares.
* **Aritmética Computacional**: Uso estratégico de operadores de divisão para manipulação de valores monetários.
* **Engenharia de Soluções**: Modelagem visual e estrutural para sistemas de PDV (Ponto de Venda).

## 💻 Exemplo de Saída do Sistema

Para uma compra de **R$ 137,00** paga com **R$ 200,00**:
* **Troco Total**: R$ 63,00
* **Decomposição**:
    * 0 nota(s) de 100
    * 1 nota(s) de 50
    * 0 nota(s) de 20
    * 1 nota(s) de 10
    * 0 nota(s) de 5
    * 1 nota(s) de 2
    * 1 nota(s) de 1

## ✒️ Documentação Consultada
* **Fluxograma do Sistema.pdf**: Mapeamento visual das decisões.
* **validar_pagamento.pdf**: Pseudocódigo detalhado com funções e lógica de decomposição.

---
*Este repositório faz parte de um estudo prático de Engenharia de Soluções Lógicas, focado na eficiência de algoritmos transacionais.*

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
