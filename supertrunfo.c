#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para entrada de string
void inputString(char* prompt, char* buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove a quebra de linha
}

// Função para entrada de número inteiro
int inputInt( char* prompt) {
    char buffer[20];
    inputString(prompt, buffer, (buffer));
    atoi(buffer);
}

// Função para entrada de número float
float inputFloat( char* prompt) {
    char buffer[20];
    inputString(prompt, buffer, (buffer));
    atof(buffer);
}

int main() {
    // Variáveis para as cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2, pontos_turisticos1, pontos_turisticos2;
    float area1, area2, pib1, pib2;

    // Cabeçalho
    printf("=============================================\n");
    printf("    CADASTRO DE CARTAS - SUPER TRUNFO\n");
    printf("=============================================\n\n");

    // ========== CARTA 1 ==========
    printf(">>>>>>>>>> CARTA 1 <<<<<<<<<<\n");
    
    // Estado
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    limparBuffer();

    // Código
    inputString("Código da carta (ex: A01): ", codigo1, (codigo1));

    // Cidade
    inputString("Nome da cidade: ", cidade1, (cidade1));

    // População
    populacao1 = inputInt("População (ex: 1000000): ");

    // Área
    area1 = inputFloat("Área em km² (ex: 1521.11): ");

    // PIB
    pib1 = inputFloat("PIB em bilhões (ex: 699.28): ");

    // Pontos turísticos
    pontos_turisticos1 = inputInt("Número de pontos turísticos: ");

    // ========== CARTA 2 ==========
    printf("\n>>>>>>>>>> CARTA 2 <<<<<<<<<<\n");
    
    // Estado
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    limparBuffer();

    // Código
    inputString("Código da carta (ex: B01): ", codigo2, (codigo2));

    // Cidade
    inputString("Nome da cidade: ", cidade2, (cidade2));

    // População
    populacao2 = inputInt("População (ex: 800000): ");

    // Área
    area2 = inputFloat("Área em km² (ex: 1200.25): ");

    // PIB
    pib2 = inputFloat("PIB em bilhões (ex: 300.50): ");

    // Pontos turísticos
    pontos_turisticos2 = inputInt("Número de pontos turísticos: ");

    // ========== EXIBIÇÃO ==========
    printf("\n========== CARTAS CADASTRADAS ==========\n");

    // Carta 1
    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: R$ %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontos_turisticos1);

    // Carta 2
    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: R$ %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontos_turisticos2);

    printf("\nCadastro concluído com sucesso!\n");
    return 0;
}
