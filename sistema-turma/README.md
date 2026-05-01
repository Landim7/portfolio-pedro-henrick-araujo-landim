# Sistema de Avaliação de Turma 🎓

Este projeto é um script Python desenvolvido para automatizar o cálculo de médias escolares e a classificação de desempenho de alunos em uma turma.

## 📋 Descrição do Projeto

O script permite que um professor ou administrador escolar insira o número total de alunos de uma turma e, para cada aluno, registre o nome e duas notas. O sistema calcula automaticamente a média e define o status acadêmico do aluno com base em regras de aprovação pré-definidas.

## 🚀 Funcionalidades

O sistema opera através de um fluxo interativo:
* **Entrada de Quantidade**: Define quantos alunos serão processados no ciclo atual.
* **Processamento Individual**:
    * Coleta o **Nome** do aluno.
    * Coleta duas notas (**Nota 1** e **Nota 2**).
    * Calcula a média aritmética simples.
* **Classificação de Status**:
    * **Aprovado**: Média maior ou igual a **7.0**.
    * **Recuperação**: Média entre **5.0** e **6.9**.
    * **Reprovado**: Média abaixo de **5.0**.

## 🛠️ Tecnologias Utilizadas

* **Python 3**: Linguagem base para a lógica do sistema.
* **Estruturas de Repetição (`for`)**: Para iterar sobre o número total de alunos da turma.
* **Lógica Condicional (`if/elif/else`)**: Para determinar o resultado acadêmico.

## 💻 Exemplo de Uso

```text
Quantos alunos existem na turma ? 2
Um total de: 2 alunos
Nome no aluno: João
Nota 1 do aluno: 8
Nota 2 do aluno: 7
-----------------------------------------------------------------
João :Aprovado com média 7.5
Nome no aluno: Maria
Nota 1 do aluno: 5
Nota 2 do aluno: 6
-----------------------------------------------------------------
Maria :Recuperação, Média: 5.5
```

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
