#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[30];
    char codigo[5];
    char cidade[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para calcular densidade populacional
float densidade(struct Carta c) {
    return (float)c.populacao / c.area;
}

// Função para exibir carta
void exibirCarta(struct Carta c) {
    printf("\n--- Carta %s ---\n", c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.cidade);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade(c));
}

// Função para comparar duas cartas baseado na escolha
void comparar(struct Carta c1, struct Carta c2, int opcao) {
    printf("\nComparando as cartas %s (Cidade: %s) e %s (Cidade: %s)\n",
           c1.codigo, c1.cidade, c2.codigo, c2.cidade);

    switch (opcao) {
        case 1: // População
            if (c1.populacao > c2.populacao)
                printf("Vencedora: %s (%d habitantes)\n", c1.cidade, c1.populacao);
            else if (c2.populacao > c1.populacao)
                printf("Vencedora: %s (%d habitantes)\n", c2.cidade, c2.populacao);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            if (c1.area > c2.area)
                printf("Vencedora: %s (%.2f km²)\n", c1.cidade, c1.area);
            else if (c2.area > c1.area)
                printf("Vencedora: %s (%.2f km²)\n", c2.cidade, c2.area);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            if (c1.pib > c2.pib)
                printf("Vencedora: %s (%.2f bilhões)\n", c1.cidade, c1.pib);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s (%.2f bilhões)\n", c2.cidade, c2.pib);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedora: %s (%d pontos turísticos)\n", c1.cidade, c1.pontosTuristicos);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedora: %s (%d pontos turísticos)\n", c2.cidade, c2.pontosTuristicos);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade populacional (menor vence)
            if (densidade(c1) < densidade(c2))
                printf("Vencedora: %s (%.2f hab/km²)\n", c1.cidade, densidade(c1));
            else if (densidade(c2) < densidade(c1))
                printf("Vencedora: %s (%.2f hab/km²)\n", c2.cidade, densidade(c2));
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    struct Carta c1, c2;
    int opcao;

    printf("Cadastro da Carta 1\n");
    printf("Estado: "); fgets(c1.estado, 30, stdin); strtok(c1.estado, "\n");
    printf("Código da Carta: "); fgets(c1.codigo, 5, stdin); strtok(c1.codigo, "\n");
    printf("Cidade: "); fgets(c1.cidade, 30, stdin); strtok(c1.cidade, "\n");
    printf("População: "); scanf("%d", &c1.populacao);
    printf("Área (km²): "); scanf("%f", &c1.area);
    printf("PIB (em bilhões): "); scanf("%f", &c1.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &c1.pontosTuristicos);

    getchar(); // limpar buffer do teclado

    printf("\nCadastro da Carta 2\n");
    printf("Estado: "); fgets(c2.estado, 30, stdin); strtok(c2.estado, "\n");
    printf("Código da Carta: "); fgets(c2.codigo, 5, stdin); strtok(c2.codigo, "\n");
    printf("Cidade: "); fgets(c2.cidade, 30, stdin); strtok(c2.cidade, "\n");
    printf("População: "); scanf("%d", &c2.populacao);
    printf("Área (km²): "); scanf("%f", &c2.area);
    printf("PIB (em bilhões): "); scanf("%f", &c2.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &c2.pontosTuristicos);

    // Exibir cartas cadastradas
    exibirCarta(c1);
    exibirCarta(c2);

    // Menu de comparação
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Comparação
    comparar(c1, c2, opcao);

    return 0;
}
