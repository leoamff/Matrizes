#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col);

int lerDentroIntervalo(int min, int max);
int contarImpares(int mat[][QTD_COLUNAS], int lin, int col);
void buscarElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento);
int calcularSomatorio(int mat[][QTD_COLUNAS], int lin, int col);
void calcularMediaPorLinha(int mat[][QTD_COLUNAS], int lin, int col);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    int somatorio, elemento;
    float media;

    // deve ser utilizado quando você quiser que a cada execução gere uma sequência diferente
    // de números aleatórios
    srand(time(0)); 

    printf("Digite a quantidade de linhas (1-%d): ", QTD_LINHAS);
    qtdLinhas = lerDentroIntervalo(1, QTD_LINHAS);
    printf("Digite a quantidade de colunas (1-%d): ", QTD_COLUNAS);
    qtdColunas = lerDentroIntervalo(1, QTD_COLUNAS);

    // lerMatriz(matriz, qtdLinhas, qtdColunas);
    preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
    printf("\n--------------------\n");
    imprimirMatriz(matriz, qtdLinhas, qtdColunas);

    // Contar e imprimir a quantidade de números ímpares
    int impares = contarImpares(matriz, qtdLinhas, qtdColunas);
    printf("Quantidade de números ímpares: %d\n", impares);

    // Buscar elemento digitado pelo usuário
    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elemento);
    buscarElemento(matriz, qtdLinhas, qtdColunas, elemento);

    // Calcular e imprimir o somatório dos elementos
    somatorio = calcularSomatorio(matriz, qtdLinhas, qtdColunas);
    printf("Somatório de todos os elementos: %d\n", somatorio);

    // Calcular e imprimir a média dos elementos
    media = (float)somatorio / (qtdLinhas * qtdColunas);
    printf("Média de todos os elementos: %.2f\n", media);

    // Imprimir a média de todos os elementos de cada linha
    calcularMediaPorLinha(matriz, qtdLinhas, qtdColunas);

    return 0;
}

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int lerDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor invalido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}

int contarImpares(int mat[][QTD_COLUNAS], int lin, int col) {
    int count = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] % 2 != 0) {
                count++;
            }
        }
    }
    return count;
}

void buscarElemento(int mat[][QTD_COLUNAS], int lin, int col, int elemento) {
    int encontrado = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == elemento) {
                printf("Elemento %d encontrado na posição [%d][%d]\n", elemento, i, j);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("Elemento %d não encontrado na matriz.\n", elemento);
    }
}

int calcularSomatorio(int mat[][QTD_COLUNAS], int lin, int col) {
    int soma = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
    }
    return soma;
}

void calcularMediaPorLinha(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        int somaLinha = 0;
        for (int j = 0; j < col; ++j) {
            somaLinha += mat[i][j];
        }
        float mediaLinha = (float)somaLinha / col;
        printf("Média dos elementos da linha %d: %.2f\n", i, mediaLinha);
    }
}
