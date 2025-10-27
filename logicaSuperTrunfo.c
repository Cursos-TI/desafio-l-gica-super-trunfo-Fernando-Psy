#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[20];
    char nome[100];
    long populacao;
    double area;
    double pib; // em milhões (ou unidade que preferir)
} Cidade;

static void remove_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
}

static void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void lerCidade(Cidade *c) {
    printf("Digite o código da cidade: ");
    if (scanf("%19s", c->codigo) != 1) { c->codigo[0] = '\0'; }
    limpar_buffer();

    printf("Digite o nome da cidade: ");
    if (fgets(c->nome, sizeof(c->nome), stdin) == NULL) c->nome[0] = '\0';
    remove_newline(c->nome);

    printf("Digite a população (inteiro): ");
    while (scanf("%ld", &c->populacao) != 1) {
        printf("Entrada inválida. Digite a população (inteiro): ");
        limpar_buffer();
    }
    limpar_buffer();

    printf("Digite a área (km^2, decimal permitido): ");
    while (scanf("%lf", &c->area) != 1) {
        printf("Entrada inválida. Digite a área (decimal): ");
        limpar_buffer();
    }
    limpar_buffer();

    printf("Digite o PIB (milhões, decimal permitido): ");
    while (scanf("%lf", &c->pib) != 1) {
        printf("Entrada inválida. Digite o PIB (decimal): ");
        limpar_buffer();
    }
    limpar_buffer();
}

int main(void) {
    Cidade a, b;
    int pontosA = 0, pontosB = 0;

    printf("Cadastro da Carta 1:\n");
    lerCidade(&a);
    printf("\nCadastro da Carta 2:\n");
    lerCidade(&b);
    printf("\n--- Comparações ---\n");

    // População
    printf("População: %s = %ld  |  %s = %ld\n", a.nome, a.populacao, b.nome, b.populacao);
    if (a.populacao > b.populacao) {
        printf("Vencedor (população): %s\n", a.nome);
        pontosA++;
    } else if (a.populacao < b.populacao) {
        printf("Vencedor (população): %s\n", b.nome);
        pontosB++;
    } else {
        printf("Empate na população.\n");
    }

    // Área
    printf("\nÁrea: %s = %.2f km^2  |  %s = %.2f km^2\n", a.nome, a.area, b.nome, b.area);
    if (a.area > b.area) {
        printf("Vencedor (área): %s\n", a.nome);
        pontosA++;
    } else if (a.area < b.area) {
        printf("Vencedor (área): %s\n", b.nome);
        pontosB++;
    } else {
        printf("Empate na área.\n");
    }

    // PIB
    printf("\nPIB: %s = %.2f  |  %s = %.2f\n", a.nome, a.pib, b.nome, b.pib);
    if (a.pib > b.pib) {
        printf("Vencedor (PIB): %s\n", a.nome);
        pontosA++;
    } else if (a.pib < b.pib) {
        printf("Vencedor (PIB): %s\n", b.nome);
        pontosB++;
    } else {
        printf("Empate no PIB.\n");
    }

    // Resultado final
    printf("\n--- Resultado Final ---\n");
    printf("%s: %d pontos\n", a.nome, pontosA);
    printf("%s: %d pontos\n", b.nome, pontosB);

    if (pontosA > pontosB) {
        printf("A cidade vencedora é: %s\n", a.nome);
    } else if (pontosA < pontosB) {
        printf("A cidade vencedora é: %s\n", b.nome);
    } else {
        // Desempate simples: comparar população, depois PIB, depois área
        if (a.populacao != b.populacao) {
            printf("Empate nos pontos. Desempate por população: %s\n", (a.populacao > b.populacao) ? a.nome : b.nome);
        } else if (a.pib != b.pib) {
            printf("Empate nos pontos. Desempate por PIB: %s\n", (a.pib > b.pib) ? a.nome : b.nome);
        } else if (a.area != b.area) {
            printf("Empate nos pontos. Desempate por área: %s\n", (a.area > b.area) ? a.nome : b.nome);
        } else {
            printf("Empate total entre as cartas.\n");
        }
    }

    return 0;
}
