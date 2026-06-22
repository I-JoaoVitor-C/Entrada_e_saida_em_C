#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void exemplo_printf() {
    printf("\n———PARTE1: ENTRADA E SAÍDA———");
    printf("Olá mundo \n");
    printf("Um número: %d\n", 42);

    printf("Um número real: %2f\n", 3.14159);
    printf("Uma frase: %s\n", "Bem vindo ao C");
}

void exemplo_scanf() {
    int idade;
    float altura;
    char nome[50];

    printf("\n———Digite seus dados———");
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    printf("\ndados lidos:\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);
}

int somar(int a, int b) {
    int resultado = a + b;
    return resultado;
}

int eh_par(int numero) {
    if(numero% 2 == 0) {
        return 1; // verdadeiro
    }
    return 0; // falso
}

void mostrar_menu() {
    printf("\nPARTE2: FUNÇÕES E MODULARIZAÇÃO———\n");
    printf("1. Somar dois números\n");
    printf("2. Verificar se um número é par\n");
    printf("3. Próxima parte\n");

    printf("Escolha: ");
}

int fatorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial(n-1);
}

void demonstrar_funcoes() {
    int num1, num2;

    printf("———TESTANDO FUNÇÕES———");
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    int soma = somar(num1, num2);

    if (eh_par(num1)) {
        printf("%d é par\n", num1);
    }   else {
        printf("%d é impar\n", num1);
    }
    int fat = fatorial(5);
    printf("5! (fatorial de 5) = %d\n", fat);
}

void gerencia_string() {
    printf("\n———PARTE3: GERENCIAMENTO DE MEMÓRIA———\n");
    char nome_fixo[50] = "João Silva";
    printf("nome (estático): %s\n", nome_fixo);
    int tamanho = strlen(nome_fixo);
    printf("Tamanho do  nome: %d caracteres\n", tamanho);
}

void exemplo_malloc() {
    printf("\n———Alocação dinâmica———\n");
    char *nome = (char *) malloc(100 * sizeof(char));
    if (nome = NULL) {
        printf("Erro não consegui alocar memória!\n");
        return;
    }
    printf("Digite um nome: ");
    scanf("%s", nome);
    char * nome_copia = (char *) malloc(100 * sizeof(char));
    strcpy(nome_copia, nome);
    printf("Nome original: %s\n", nome);
    printf("Nome copiado: %s\n", nome_copia);
    free(nome);
    free(nome_copia);
    printf("Memória liberada com sucesso!\n");
}

void gerenciar_lista_nomes() {
    printf("\n———Lista de nomes———\n");
    int quantidade;
    printf("Quantos nomes você quer digitar? ");
    scanf("%d",&quantidade);
    char **nomes = (char **) malloc(quantidade * sizeof(char *));
    for (int i = 0; i < quantidade; i++) {
        nomes[i] = (char *) malloc(50 * sizeof(char));
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", nomes[i]);
    }

    printf("\n———Nomes digitados———\n");
    for(int i = 0; i < quantidade; i++) {
        printf("%d. %s (tem %lu caracteres)\n",
        i + 1, nomes[i], strlen(nomes[i]));
}
    for (int i = 0; i < quantidade; i++) {
        free(nomes[i]);
    }
    free(nomes);
    printf("Todos os nomes foram liberados da memória!\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;
    printf("Aula E/S, Funções e Memória em C\n");

    while(opcao != 4) {
        printf("\n———Menu Principal———\n");
        printf("1. Demonstração de Entrada e Saída\n");
        printf("2. Demonstração de Funções\n");
        printf("3. Demonstração de Memória e Strings\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

    switch(opcao) {
        case 1:
        exemplo_printf();
        exemplo_scanf();
        break;
        case 2: 
        mostrar_menu();
        demonstrar_funcoes();
        break;
        case 3:
        gerencia_string();
        exemplo_malloc();
        gerenciar_lista_nomes();
        break;
        case 4:
        printf("\nAté a próxima aula! Bom estudo!\n");
        break;
        default:
        printf("Opção inválida. Tente novamente.\n");
    }

    }
}
