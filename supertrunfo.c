#include <stdio.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    // Variáveis para as cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2, pontos_turisticos1, pontos_turisticos2;
    float area1, area2, pib1, pib2;

    // Cabeçalho do programa
    printf("=============================================\n");
    printf("    CADASTRO DE CARTAS - SUPER TRUNFO\n");
    printf("=============================================\n\n");
    
    // Instruções iniciais
    printf("Vamos cadastrar 2 cartas. Para cada carta, informe:\n");
    printf("- Estado (A a H)\n");
    printf("- Codigo (ex: A01)\n");
    printf("- Nome da cidade\n");
    printf("- Populacao, area, PIB e pontos turisticos\n\n");

    // ========== CARTA 1 ==========
    printf(">>>>>>>>>> DADOS DA CARTA 1 <<<<<<<<<<\n");

    // Estado
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);
    limparBuffer();

    // Código
    printf("Digite o codigo da carta (%c01-%c04): ", estado1, estado1);
    scanf("%3s", codigo1);
    limparBuffer();

    // Cidade
    printf("Digite o nome da cidade: ");
    scanf("%49[^\n]", cidade1);
    limparBuffer();

    // Dados numéricos
    printf("Digite a populacao (ex: 1000000): ");
    scanf("%d", &populacao1);

    printf("Digite a area em km² (ex: 1521.11): ");
    scanf("%f", &area1);

    printf("Digite o PIB em bilhoes (ex: 699.28): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos1);
    limparBuffer();

    // ========== CARTA 2 ==========
    printf("\n>>>>>>>>>> DADOS DA CARTA 2 <<<<<<<<<<\n");

    // Estado
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    limparBuffer();

    // Código
    printf("Digite o codigo da carta (%c01-%c04): ", estado2, estado2);
    scanf("%3s", codigo2);
    limparBuffer();

    // Cidade
    printf("Digite o nome da cidade: ");
    scanf("%49[^\n]", cidade2);
    limparBuffer();

    // Dados numéricos
    printf("Digite a populacao (ex: 800000): ");
    scanf("%d", &populacao2);

    printf("Digite a area em km² (ex: 1200.25): ");
    scanf("%f", &area2);

    printf("Digite o PIB em bilhoes (ex: 300.50): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos2);

    // ========== EXIBIÇÃO ==========
    printf("\n\n========== RESULTADO DO CADASTRO ==========\n");

    // Carta 1
    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("Populacao: %d habitantes\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: R$ %.2f bilhoes\n", pib1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos1);

    // Carta 2
    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("Populacao: %d habitantes\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: R$ %.2f bilhoes\n", pib2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos2);

    printf("\nCartas cadastradas com sucesso!\n");
    return 0;
}
