#include <stdio.h>

int fatorial(int n) {
    int r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}

int arranjo(int n, int p) {
    int r = 1;
    for (int i = 0; i < p; i++) r *= (n - i);
    return r;
}

int combinacao(int n, int p) {
    if (p > n - p) p = n - p;
    int r = 1;
    for (int i = 1; i <= p; i++) {
        r = r * (n - p + i) / i;
    }
    return r;
}

void trianguloPascal(int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int s = 0; s < linhas - i - 1; s++) printf("  ");
        for (int j = 0; j <= i; j++) {
            printf("%4d", combinacao(i, j));
        }
        printf("\n");
    }
}

int main() {
    int opcao, n, p;

    do {
        printf("\n   MENU   \n");
        printf("1 - Triangulo de Pascal\n");
        printf("2 - Arranjo\n");
        printf("3 - Permutacao Simples\n");
        printf("4 - Combinacao\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantas linhas? ");
                scanf("%d", &n);
                if (n < 1) { printf("Valor invalido.\n"); break; }
                trianguloPascal(n);
                break;

            case 2:
                printf("Digite n e p (A(n,p)): ");
                scanf("%d %d", &n, &p);
                if (n < 0 || p < 0 || p > n) { printf("Valores invalidos (precisa p <= n).\n"); break; }
                printf("A(%d,%d) = %d\n", n, p, arranjo(n, p));
                break;

            case 3:
                printf("Digite n (P(n) = n!): ");
                scanf("%d", &n);
                if (n < 0 || n > 12) { printf("Valor invalido (use 0 a 12).\n"); break; }
                printf("P(%d) = %d\n", n, fatorial(n));
                break;

            case 4:
                printf("Digite n e p (C(n,p)): ");
                scanf("%d %d", &n, &p);
                if (n < 0 || p < 0 || p > n) { printf("Valores invalidos (precisa p <= n).\n"); break; }
                printf("C(%d,%d) = %d\n", n, p, combinacao(n, p));
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
