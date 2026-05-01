# Simulador de Poupança com Aportes Mensais 💰

Este projeto é um script Python desenvolvido para simular o crescimento de um investimento ao longo do tempo, considerando juros compostos e depósitos mensais variáveis.

## 📋 Descrição do Projeto

O simulador permite prever a evolução de um patrimônio financeiro mês a mês. O diferencial deste script é a interatividade: em cada mês da simulação, o usuário pode decidir se deseja realizar um novo aporte (depósito) ou não, permitindo uma visualização dinâmica dos juros incidindo sobre o saldo acumulado.

## 🚀 Funcionalidades

O script segue o seguinte fluxo de processamento:
* **Configuração Inicial**: Solicita o valor inicial do investimento, a taxa de juros mensal (%) e o tempo total da simulação em meses.
* **Ciclo de Investimento**: Para cada mês definido, o sistema solicita o valor do aporte mensal.
* **Cálculo de Juros Compostos**: O juro é calculado sobre o montante atualizado (saldo anterior + aporte do mês).
* **Monitoramento de Metas**: O sistema possui um gatilho de celebração caso o saldo ultrapasse a marca de **R$ 10.000,00**.
* **Relatório Contínuo**: Exibe o saldo atualizado detalhadamente após cada fechamento de mês.

## 🛠️ Tecnologias Utilizadas

* **Python 3**: Linguagem principal.
* **Estruturas de Repetição (`for`)**: Para gerenciar a evolução mensal do capital.
* **Lógica Matemática**: Aplicação de taxas percentuais e acumulação de valores.

## 💻 Exemplo de Uso

```text
Valor inicial do investimento: R$1000
Taxa de juros mensal: 1%
Número de meses da simulação: 3
-----------------------------------------------------------------
Quanto deseja depositar por mês? 1 (0 para nenhum): 200
Mês 1 :Saldo atualizado = R$ 1212.0
-----------------------------------------------------------------
```

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
