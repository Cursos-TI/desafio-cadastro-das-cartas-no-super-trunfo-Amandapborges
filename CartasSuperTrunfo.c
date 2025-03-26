#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];            // Sigla do estado (ex: SP)
    char codigo[10];           // Código da carta
    char cidade[50];           // Nome da cidade
    int populacao;             // População em habitantes
    float area;                // Área em km²
    float pib;                 // PIB em milhões de R$
    int pontos_turisticos;     // Número de pontos turísticos
    float densidade;           // Densidade populacional (hab/km²)
    float pib_per_capita;      // PIB per capita (R$/hab)
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Cadastro da Carta:\n");
    
    printf("Estado (sigla): ");
    scanf("%2s", carta->estado);
    
    printf("Código da carta: ");
    scanf("%9s", carta->codigo);
    
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->cidade);  // Lê até encontrar uma quebra de linha
    
    printf("População (habitantes): ");
    scanf("%d", &carta->populacao);
    
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    
    printf("PIB (milhões de R$): ");
    scanf("%f", &carta->pib);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    
    // Calcula densidade populacional e PIB per capita
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000) / carta->populacao; // Convertendo PIB para R$
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("\nDados da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões de R$\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f R$\n", carta.pib_per_capita);
}

// Função para comparar duas cartas com base em um atributo escolhido
void compararCartas(Carta c1, Carta c2) {
    // Definindo o atributo para comparação (altere conforme necessário)
    // Opções: populacao, area, pib, densidade, pib_per_capita
    char atributo[] = "populacao";  // Atributo escolhido para comparação
    
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    
    // Exibe os valores do atributo para ambas as cartas
    if (strcmp(atributo, "populacao") == 0) {
        printf("Carta 1 - %s (%s): %d\n", c1.cidade, c1.estado, c1.populacao);
        printf("Carta 2 - %s (%s): %d\n", c2.cidade, c2.estado, c2.populacao);
    } else if (strcmp(atributo, "area") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, c1.area);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, c2.area);
    } else if (strcmp(atributo, "pib") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, c1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, c2.pib);
    } else if (strcmp(atributo, "densidade") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, c1.densidade);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, c2.densidade);
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, c1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, c2.pib_per_capita);
    }
    
    // Determina a carta vencedora
    int carta1_vence = 0;
    
    if (strcmp(atributo, "densidade") == 0) {
        // Para densidade, o menor valor vence
        if (c1.densidade < c2.densidade) {
            carta1_vence = 1;
        }
    } else {
        // Para outros atributos, o maior valor vence
        if (strcmp(atributo, "populacao") == 0 && c1.populacao > c2.populacao) {
            carta1_vence = 1;
        } else if (strcmp(atributo, "area") == 0 && c1.area > c2.area) {
            carta1_vence = 1;
        } else if (strcmp(atributo, "pib") == 0 && c1.pib > c2.pib) {
            carta1_vence = 1;
        } else if (strcmp(atributo, "pib_per_capita") == 0 && c1.pib_per_capita > c2.pib_per_capita) {
            carta1_vence = 1;
        }
    }
    
    // Exibe o resultado
    if (carta1_vence) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (strcmp(atributo, "densidade") == 0 && c1.densidade == c2.densidade) {
        printf("Resultado: Empate!\n");
    } else if (strcmp(atributo, "populacao") == 0 && c1.populacao == c2.populacao) {
        printf("Resultado: Empate!\n");
    } else if (strcmp(atributo, "area") == 0 && c1.area == c2.area) {
        printf("Resultado: Empate!\n");
    } else if (strcmp(atributo, "pib") == 0 && c1.pib == c2.pib) {
        printf("Resultado: Empate!\n");
    } else if (strcmp(atributo, "pib_per_capita") == 0 && c1.pib_per_capita == c2.pib_per_capita) {
        printf("Resultado: Empate!\n");
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
}

int main() {
    Carta carta1, carta2;
    
    printf("=== Cadastro da Carta 1 ===\n");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);
    
    printf("\n=== Cadastro da Carta 2 ===\n");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);
    
    // Compara as duas cartas
    compararCartas(carta1, carta2);
    
    return 0;
}
