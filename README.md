# pequena revisão
full
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ponteiros
int *ponteiro_inteiro;

// passagem por valor (copia do conteudo da variavel)
int funcao(int a, int b) {
   int c  = a + b; // a = 20, b = 10
   a = 30; 
   return c;
}

// passagem por referencia (copia do endereco da variavel)
int outra(int *a, int *b) {
   int c = *a + *b;
   *a = 30;
   return c;
}

void conversor_horas(int seg, int *hh, int *mm, int ss) {
    
}

int funcao_recursiva(int a) {
    if (a == 0) return 1;
    funcao_recursiva(a-1);
}

int main() {
    int i = 10; // variavel comum
    int j = 10;
    ponteiro_inteiro = &i; // quando nao inicializa é NULL (*void) 000000
    *ponteiro_inteiro = 20; // i = 20;

    funcao(i, j); // nao altera o conteudo da variavel

    outra(i, j); // altera o conteudo da variavel

    ponteiro_inteiro = (int*)malloc(5 * sizeof(int)); // alocando 4bytes
    memset(ponteiro_inteiro, 0, sizeof(int)); // preenche o espaço da variavel com 0
    ponteiro_inteiro = (int*)calloc(5, sizeof(int)); // alocando 5 * 4 bytes = 20 bytes
    ponteiro_inteiro = (int*)realloc(ponteiro_inteiro, sizeof(int)); //realocando 4bytes;
    free(ponteiro_inteiro); // libera memoria
    ponteiro_inteiro = NULL;

    //ponteiro e array
    char *p; // malloc(20*sizeof(char))
    char str[100];
    p = str;
    scanf("%d", &i);
    scanf("%s", str);

    return 0;
}

/// criacao TAD tipos abstrados de dados. 

// modulo.h
typedef struct { 
    int matricula;
    char nome[60];
    char email[60];
} aluno;

aluno* criar(int matricula, char* nome, char *email);
void destruir(aluno *a);
void imprimir(aluno *a);

// modulo.c
aluno* criar(int matricula, char* nome, char *email) {
    aluno* novo = (aluno*)malloc(sizeof(aluno));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    strcpy(novo->email, email);
    return novo;
}

void destruir(aluno *a) {
    free(a);
    a = NULL;
}

void imprimir(aluno *a) {
    printf("%d %s %s", a->matricula, a->nome, a->email);
}

// arquivos

FILE *fp; // um ponteiro arquivo

void arquivos() {
    fp = fopen("c:\\dados.txt", "w+"); // t - textos; b - binarios; r - ler, w - gravar, a - adicionar
    fseek(fp, 0, SEEK_SET); //inicio do arquivo
    fseek(fp, 10, SEEK_CUR); // anda 10 posicoes no arquivo
    //leitura de dados
    char ch = fgetc(fp); //ler um caracter
    char linha[128];
    fgets(linha, sizeof(linha), fp); // ler uma linha
    int matricula; char nome[60]; int data;
    fscanf(fp, "%d %s %d", &matricula, nome, &data); // ler uma linha formatada
    fread(linha, sizeof(linha), 10, fp); // ler uma bloco de linhas
    // escrita de dados
    fputc(fp, ch); // esrever um caracter
    fputs(linha, fp); // escrever uma linha
    fprintf(fp, "%d %s %d", matricula, nome, data); // escrever uma linha formatada
    fwrite(linha, sizoef(linha), 10, fp); //escrever blocos de linhas (ex. 10 linhas)
    // verificar fim do arquivo
    feof(fp) == EOF;
    // fechar arquivo
    fclose(fp);
}

// tipos de organizaçao
// arquivos seriais - grava no final sempre. Arquivo de log.
// arquivo sequencial - grava em ordem de uma chave.
// arquivo indexado - indice, principal, extensão.
// arquivo direto - funçao hash 
// arquivo invertido - lista de valores para um conjunto de chaves. nome 

// compressão de dados
// Algoritmo  Run-lenght: frequencia dos simbolos: troca a sequencia de simbolos por qtde e o simbolo.
// Algoritmo Huffman: frequencia de simbolos; codifica com menos bits com mais frequencia e mais bits para menos frequencia.
// Algoritmo LZW: não trabalha com frequencia de simbolo, gera codigo com a descorberta de simbolos, gera um dicionario de codigo que é salvo.

// ordenação de arquivos
// algortimos classicos de ordenacao de dados: bubblesort, insertsort, heapsort, quicksort, mergesort.
// ordear arquivo grandes, o mergesort. divide o arquivo em partes menores que sao ordenados e depois intercaldos.
// 
//
void mergesort(int inicio, int fim) {
    int meio = inicio+fim/2;
    mergesort(inicio, meio);
    mergesort(meio+1,fim);
    intercala(inicio, fim);
}
