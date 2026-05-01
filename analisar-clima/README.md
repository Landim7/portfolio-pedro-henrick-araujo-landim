# Analisador de Clima Semanal 🌡️

Este projeto consiste em um script Python desenvolvido para monitorar e analisar variações de temperatura ao longo de uma semana (7 dias), identificando condições climáticas críticas e calculando médias operacionais.

## 🚀 Funcionalidades

O script automatiza a análise de dados meteorológicos simples através das seguintes etapas:
* **Entrada de Dados**: Solicita ao usuário a temperatura para cada um dos 7 dias da semana.
* **Cálculo de Média**: Calcula a média aritmética das temperaturas registradas no período.
* **Monitoramento de Calor**: Contabiliza quantos dias registraram temperaturas superiores a **35.0°C**.
* **Alerta de Condições Extremas**: 
    * O sistema dispara um aviso de "Condições climáticas perigosas" caso detecte temperaturas extremas (atualmente configurado para valores acima de 45°C ou variações específicas).
* **Relatório Final**: Exibe um resumo formatado com a média, contagem de dias quentes e o status de segurança climática.

## 🛠️ Tecnologias Utilizadas

* **Python 3**: Linguagem principal utilizada.
* **Estruturas de Repetição (`for`)**: Para coleta eficiente de dados semanais.
* **Lógica Condicional (`if/else`)**: Para classificação de riscos e alertas.

## 📋 Exemplo de Execução

```text
Digite a temperatura do dia 1: 30
Digite a temperatura do dia 2: 36
...
Média semanal:  32.5
-----------------------------------------------------------------
Dias acima de 35ºC:  1
-----------------------------------------------------------------
Cuidado: Condições climáticas perigosas detectadas!
```

[Voltar ao início](https://github.com/Landim7/portifolio-pedro-landim)
