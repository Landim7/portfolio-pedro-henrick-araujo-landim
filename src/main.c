/*
 * Projeto: Criptografia Matemática
 * Disciplina: Algoritmo e Pensamento Computacional
 *
 * Implementa duas camadas:
 * 1) Cifra de César com SHIFT fixo
 * 2) Deslocamento dinâmico baseado em PA, PG, Fibonacci ou números primos
 *
 * Observação: esta cifra é didática e NÃO deve ser usada para proteger dados reais.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_PALAVRA 16
#define TAM_LINHA 256
#define ARQUIVO_RESULTADO "resultado_criptografia.txt"
#define ARQUIVO_LOG "log_execucao.txt"

typedef enum {
    SEQ_PA = 1,
    SEQ_PG = 2,
    SEQ_FIBONACCI = 3,
    SEQ_PRIMOS = 4
} TipoSequencia;

typedef struct {
    char original[TAM_PALAVRA];
    char camada1[TAM_PALAVRA];
    char criptografada[TAM_PALAVRA];
    int shift;
    int tipoSequencia;
    int quantidadeLetras;
} RegistroCriptografia;

static void removerQuebraLinha(char *texto) {
    texto[strcspn(texto, "\r\n")] = '\0';
}

static int lerLinha(const char *mensagem, char *destino, size_t tamanho) {
    printf("%s", mensagem);
    if (fgets(destino, (int)tamanho, stdin) == NULL) {
        return 0;
    }

    if (strchr(destino, '\n') == NULL && !feof(stdin)) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            /* descarta caracteres que excederam o buffer */
        }
        destino[0] = '\0';
        return -1;
    }

    removerQuebraLinha(destino);
    return 1;
}

static int validarPalavra(const char *palavra) {
    size_t tamanho = strlen(palavra);

    if (tamanho < 1 || tamanho > 15) {
        return 0;
    }

    for (size_t i = 0; i < tamanho; i++) {
        if (!isalpha((unsigned char)palavra[i]) || (unsigned char)palavra[i] > 127) {
            return 0;
        }
    }
    return 1;
}

static void paraMaiusculas(char *texto) {
    for (size_t i = 0; texto[i] != '\0'; i++) {
        texto[i] = (char)toupper((unsigned char)texto[i]);
    }
}

static int lerInteiroIntervalo(const char *mensagem, int minimo, int maximo, int *valor) {
    char linha[TAM_LINHA];
    char extra;
    int numero;
    int status = lerLinha(mensagem, linha, sizeof(linha));

    if (status <= 0) {
        return 0;
    }

    if (sscanf(linha, "%d %c", &numero, &extra) != 1 || numero < minimo || numero > maximo) {
        printf("Entrada invalida. Digite um numero entre %d e %d.\n", minimo, maximo);
        return 0;
    }

    *valor = numero;
    return 1;
}

static int ehPrimo(int numero) {
    if (numero < 2) {
        return 0;
    }
    for (int divisor = 2; divisor <= numero / divisor; divisor++) {
        if (numero % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

/*
 * Retorna o termo da sequência na posição i (começando em zero).
 * PA: a1=1, razão=2 -> 1, 3, 5, 7, ...
 * PG: a1=1, razão=2 -> 1, 2, 4, 8, ...
 * Fibonacci: 1, 1, 2, 3, 5, 8, ...
 * Primos: 2, 3, 5, 7, 11, 13, ...
 *
 * O módulo 26 mantém o deslocamento dentro do alfabeto circular A-Z.
 */
static int termoSequencia(TipoSequencia tipo, int indice) {
    switch (tipo) {
        case SEQ_PA:
            return (1 + 2 * indice) % 26;

        case SEQ_PG: {
            int termo = 1;
            for (int i = 0; i < indice; i++) {
                termo = (termo * 2) % 26;
            }
            return termo;
        }

        case SEQ_FIBONACCI: {
            int anterior = 1, atual = 1;
            if (indice == 0 || indice == 1) {
                return 1;
            }
            for (int i = 2; i <= indice; i++) {
                int proximo = (anterior + atual) % 26;
                anterior = atual;
                atual = proximo;
            }
            return atual;
        }

        case SEQ_PRIMOS: {
            int encontrados = 0;
            int candidato = 2;
            while (1) {
                if (ehPrimo(candidato)) {
                    if (encontrados == indice) {
                        return candidato % 26;
                    }
                    encontrados++;
                }
                candidato++;
            }
        }

        default:
            return 0;
    }
}

static const char *nomeSequencia(TipoSequencia tipo) {
    switch (tipo) {
        case SEQ_PA: return "PA";
        case SEQ_PG: return "PG";
        case SEQ_FIBONACCI: return "Fibonacci";
        case SEQ_PRIMOS: return "Primos";
        default: return "Desconhecida";
    }
}

static void aplicarCifraCesar(const char *entrada, char *saida, int shift) {
    int deslocamento = ((shift % 26) + 26) % 26;

    for (size_t i = 0; entrada[i] != '\0'; i++) {
        saida[i] = (char)('A' + (entrada[i] - 'A' + deslocamento) % 26);
    }
    saida[strlen(entrada)] = '\0';
}

static void aplicarSequencia(const char *entrada, char *saida, int shift, TipoSequencia tipo) {
    for (size_t i = 0; entrada[i] != '\0'; i++) {
        int dinamico = termoSequencia(tipo, (int)i);
        int deslocamentoTotal = (shift + dinamico) % 26;
        saida[i] = (char)('A' + (entrada[i] - 'A' + deslocamentoTotal) % 26);
    }
    saida[strlen(entrada)] = '\0';
}

static void mostrarSequencia(TipoSequencia tipo, int quantidade) {
    printf("Sequencia %s: ", nomeSequencia(tipo));
    for (int i = 0; i < quantidade; i++) {
        printf("%d", termoSequencia(tipo, i));
        if (i < quantidade - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

static int salvarRegistro(const RegistroCriptografia *registro) {
    FILE *arquivo = fopen(ARQUIVO_RESULTADO, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo de resultado");
        return 0;
    }

    fprintf(arquivo,
            "Original: %s | Camada 1: %s | Palavra codificada: %s | SHIFT: %d | Tipo: %d (%s) | Letras: %d\n",
            registro->original,
            registro->camada1,
            registro->criptografada,
            registro->shift,
            registro->tipoSequencia,
            nomeSequencia((TipoSequencia)registro->tipoSequencia),
            registro->quantidadeLetras);
    fclose(arquivo);

    arquivo = fopen(ARQUIVO_LOG, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo de log");
        return 0;
    }

    fprintf(arquivo,
            "Operacao=CRIPTOGRAFIA; original=%s; shift=%d; sequencia=%s; letras=%d; camada1=%s; resultado=%s\n",
            registro->original,
            registro->shift,
            nomeSequencia((TipoSequencia)registro->tipoSequencia),
            registro->quantidadeLetras,
            registro->camada1,
            registro->criptografada);
    fclose(arquivo);

    return 1;
}

static void criptografar(void) {
    RegistroCriptografia registro = {0};
    char entrada[TAM_LINHA];
    int status;

    status = lerLinha("Digite uma palavra (1 a 15 letras, sem acentos ou espacos): ",
                      entrada, sizeof(entrada));
    if (status <= 0) {
        printf("Nao foi possivel ler a palavra.\n");
        return;
    }

    if (!validarPalavra(entrada)) {
        printf("Palavra invalida. Use somente letras A-Z, sem acentos, espacos ou simbolos, com ate 15 letras.\n");
        return;
    }

    paraMaiusculas(entrada);
    strcpy(registro.original, entrada);
    registro.quantidadeLetras = (int)strlen(entrada);

    if (!lerInteiroIntervalo("Digite o SHIFT (0 a 25): ", 0, 25, &registro.shift)) {
        return;
    }

    printf("\nEscolha a sequencia:\n");
    printf("1 - Progressao Aritmetica (PA: 1, 3, 5, 7...)\n");
    printf("2 - Progressao Geometrica (PG: 1, 2, 4, 8...)\n");
    printf("3 - Fibonacci (1, 1, 2, 3, 5...)\n");
    printf("4 - Numeros primos (2, 3, 5, 7, 11...)\n");

    if (!lerInteiroIntervalo("Opcao: ", 1, 4, &registro.tipoSequencia)) {
        return;
    }

    aplicarCifraCesar(registro.original, registro.camada1, registro.shift);
    aplicarSequencia(registro.original, registro.criptografada, registro.shift,
                     (TipoSequencia)registro.tipoSequencia);

    mostrarSequencia((TipoSequencia)registro.tipoSequencia, registro.quantidadeLetras);

    printf("\nPalavra original: %s\n", registro.original);
    printf("Apos camada 1 (Cesar): %s\n", registro.camada1);
    printf("Palavra criptografada (duas camadas): %s\n", registro.criptografada);

    if (salvarRegistro(&registro)) {
        printf("Resultado salvo em '%s' e log registrado em '%s'.\n",
               ARQUIVO_RESULTADO, ARQUIVO_LOG);
    }
}

/* Exibe o conteúdo de um arquivo de texto, se ele existir. */
static void consultarArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    char linha[TAM_LINHA];

    if (arquivo == NULL) {
        printf("Ainda nao existe o arquivo '%s'. Criptografe uma palavra primeiro.\n", nomeArquivo);
        return;
    }

    printf("\n--- %s ---\n", nomeArquivo);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    printf("--- fim ---\n");
    fclose(arquivo);
}

static void exibirMenu(void) {
    printf("\n====================================\n");
    printf("     CRIPTOGRAFIA MATEMATICA\n");
    printf("====================================\n");
    printf("1 - Criptografar palavra\n");
    printf("2 - Consultar resultados salvos\n");
    printf("3 - Consultar log de execucao\n");
    printf("0 - Sair\n");
}

int main(void) {
    int opcao = -1;

    do {
        exibirMenu();
        if (!lerInteiroIntervalo("Escolha uma opcao: ", 0, 3, &opcao)) {
            continue;
        }

        switch (opcao) {
            case 1:
                criptografar();
                break;
            case 2:
                consultarArquivo(ARQUIVO_RESULTADO);
                break;
            case 3:
                consultarArquivo(ARQUIVO_LOG);
                break;
            case 0:
                printf("Programa encerrado. Ate mais!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
