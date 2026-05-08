# 🏢 Auditoria de Orçamentos Corporativos (Python)
 
[![Python Version](https://img.shields.io/badge/python-3.x-blue.svg)](https://www.python.org/)
[![Status](https://img.shields.io/badge/status-concluído-brightgreen.svg)]()
 
## 📖 Sobre o Projeto
Este projeto foi desenvolvido como parte da disciplina de Programação de Computadores do curso de Engenharia de software. O objetivo do script é processar e calcular o orçamento de uma estrutura organizacional complexa (dicionários aninhados) de uma multinacional, aplicando regras de negócio dinâmicas e auditoria de execução.
 
A solução foi arquitetada utilizando conceitos avançados de Python para garantir flexibilidade, performance e rastreabilidade.
 
## 🚀 Funcionalidades
- **Cálculo Hierárquico:** Varredura completa da estrutura corporativa, independentemente do nível de profundidade.
- **Filtros Dinâmicos:** Capacidade de ignorar setores específicos e todos os seus subsetores na hora do cálculo financeiro.
- **Conversão de Câmbio:** Suporte a parâmetros opcionais para conversão de moedas em tempo de execução.
- **Sistema de Auditoria:** Monitoramento automatizado de tempo de execução e registro (logging) dos parâmetros utilizados na transação financeira.
 
## 🛠️ Tecnologias e Conceitos Aplicados
Este projeto foi construído utilizando Python puro (Standard Library), com foco nos seguintes paradigmas e recursos:
* **Funções Recursivas (Recursion):** Utilizadas para a navegação na árvore de dados (dicionários aninhados).
* **Decorators:** Implementação do `@auditor` para injetar comportamentos de log e cronometragem sem modificar a lógica de negócios.
* **Empacotamento de Argumentos (`*args` e `**kwargs`):** Utilizados tanto no decorator quanto na função principal para permitir a passagem dinâmica de departamentos a serem ignorados e taxas de câmbio.
 
## ⚙️ Como Executar
 
### Pré-requisitos
* Python 3.8 ou superior instalado.
 
### Passo a Passo
1. Clone este repositório:
   ```bash
   git clone https://github.com/Landim7/portfolio-pedro-henrick-araujo-landim/new/main/sistema-de-auditoria-de-Recursos-Corporativos
   ```
2. Acesse a pasta do projeto:
   ```bash
   cd seu-repositorio
   ```
3. Execute o script principal:
   ```bash
   python main.py
   ```
 
## 🧠 Lógica e Estrutura do Código
Breve explicação de como o código foi organizado:
* `A recursão foi construída para permitir que a função percorresse automaticamente todos os níveis da estrutura da empresa, sem precisar saber previamente quantos subdepartamentos existiam. A função verifica cada item do dicionário e, quando encontra outro dicionário, chama a si mesma novamente para continuar navegando na estrutura. Quando encontra um valor numérico, ele é somado ao total do orçamento. Dessa forma, o algoritmo consegue calcular os valores independentemente da profundidade da árvore de dados. O decorator `@auditor` foi acoplado ao projeto para adicionar uma camada de auditoria sem alterar a lógica principal da função de cálculo. Ele intercepta a execução da função `calcular_orcamento()`, registra os argumentos recebidos, inicia a contagem do tempo de execução utilizando a biblioteca `time` e, ao final do processamento, exibe o tempo total gasto pelo algoritmo. O uso de `*args` e `**kwargs` no decorator permitiu que ele funcionasse de maneira flexível com qualquer conjunto de parâmetros.`.
* **Dados:** Os dados simulados da empresa foram estruturados em... `A estrutura do dicionário foi organizada de forma hierárquica para simular a organização real de uma empresa multinacional. Os primeiros níveis representam unidades maiores, como a matriz e as filiais, enquanto os níveis internos representam departamentos e subdepartamentos, como TI, RH, Marketing e Financeiro. Cada setor pode conter outros dicionários, permitindo que a estrutura tenha profundidade variável.

Os nós finais da estrutura armazenam valores numéricos inteiros, representando o orçamento destinado a cada equipe ou setor específico. Esse modelo de dicionário aninhado foi escolhido porque facilita a navegação recursiva e permite expandir a empresa adicionando novos departamentos sem precisar modificar a lógica principal do algoritmo.`.
 
## 👤 Autor
 
* **Pedro Henrick Araujo Landim** * LinkedIn: (https://br.linkedin.com/in/pedro-landim-12a2a7361?trk=people-guest_people_search-card)
* E-mail: pedrolabdim1205@gmail.com
 
---
*Projeto acadêmico com foco na aplicação prática de conceitos avançados da linguagem Python.*

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
