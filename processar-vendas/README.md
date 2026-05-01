# Sistema de Processamento de Vendas e Descontos 🛒

Este projeto é um script Python desenvolvido para automatizar o fechamento de caixas e o cálculo de vendas, integrando validação de dados e uma política de descontos progressivos.

## 📋 Descrição do Projeto

O sistema atua como um PDV (Ponto de Venda) simplificado que permite registrar múltiplos produtos em uma única transação. Ele calcula o subtotal de cada item, valida se os valores inseridos são coerentes e aplica um desconto automático sobre o valor total da compra com base em faixas de preço.

## 🚀 Funcionalidades

O script gerencia o fluxo de venda através das seguintes etapas:
* **Entrada Dinâmica**: Solicita a quantidade total de produtos diferentes na compra para iniciar o ciclo de repetição.
* **Coleta e Validação**:
    * Registra nome, preço unitário e quantidade de cada item.
    * [cite_start]**Segurança de Dados**: Identifica se preços ou quantidades são iguais ou menores que zero, exibindo uma mensagem de erro para valores inválidos[cite: 1].
* [cite_start]**Acumulação de Totais**: Soma o valor de todos os produtos e contabiliza o volume total de itens comprados[cite: 1].
* **Política de Descontos Progressivos**:
    * [cite_start]**10% de desconto**: Para compras acima de **R$ 500,00**[cite: 1].
    * [cite_start]**5% de desconto**: Para compras acima de **R$ 200,00**[cite: 1].
* [cite_start]**Resumo Final**: Exibe a quantidade total de itens e o valor final da compra já com os descontos aplicados[cite: 1].

## 🛠️ Tecnologias Utilizadas

* **Python 3**: Linguagem base.
* [cite_start]**Estruturas de Repetição (`for`)**: Para processar múltiplos itens de uma única vez[cite: 1].
* [cite_start]**Lógica Condicional (`if/elif/else`)**: Para aplicação das regras de negócio e descontos[cite: 1].

## 💻 Exemplo de Execução

```text
Quantos produtos diferentes foram comprados ? 2
--------------------------------------------------------------------------------
Nome do produto: Monitor
Preço unitário: 600
Quantidade deste produto: 1
--------------------------------------------------------------------------------
Desconto aplicado de 10%! 
Resumo

1 itens

Total em R$: 540.0
```

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
