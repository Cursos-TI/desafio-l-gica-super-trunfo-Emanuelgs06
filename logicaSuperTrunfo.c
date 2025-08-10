#include <stdio.h>
#include <string.h>  // fgets

int main() {

    // Variáveis da Carta 1
    char Estado1;
    char CodigoCarta1[4]; 
    char NomeCidade1[50];
    unsigned long int Populacao1;
    float Area1;
    float Pib1;
    int PontosTuristicos1;
    float DensidadePopulacional1;
    float Pibpercapita1;
    float Superpoder1;

    // Variáveis da Carta 2
    char Estado2;
    char CodigoCarta2[4];
    char NomeCidade2[50];
    unsigned long int Populacao2;
    float Area2;
    float Pib2;
    int PontosTuristicos2;
    float DensidadePopulacional2;
    float Pibpercapita2;
    float Superpoder2;

    // Entrada Carta 1
    printf("Digite os dados da Carta 1\n");
    printf("Estado (A-H): ");
    scanf(" %c", &Estado1);

    printf("Código (ex: A01): ");
    scanf("%3s", CodigoCarta1);

    printf("Nome da Cidade: ");
    getchar();
    fgets(NomeCidade1, sizeof(NomeCidade1), stdin);
    NomeCidade1[strcspn(NomeCidade1, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &Populacao1);

    printf("Área (km²): ");
    scanf("%f", &Area1);

    printf("PIB (bi R$): ");
    scanf("%f", &Pib1);

    printf("Pontos Turísticos: ");
    scanf("%d", &PontosTuristicos1);

    // Entrada Carta 2
    printf("\nDigite os dados da Carta 2\n");
    printf("Estado (A-H): ");
    scanf(" %c", &Estado2);

    printf("Código (ex: B02): ");
    scanf("%3s", CodigoCarta2);

    printf("Nome da Cidade: ");
    getchar();
    fgets(NomeCidade2, sizeof(NomeCidade2), stdin);
    NomeCidade2[strcspn(NomeCidade2, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &Populacao2);

    printf("Área (km²): ");
    scanf("%f", &Area2);

    printf("PIB (bi R$): ");
    scanf("%f", &Pib2);

    printf("Pontos Turísticos: ");
    scanf("%d", &PontosTuristicos2);

    // Cálculos importantes
    DensidadePopulacional1 = Populacao1 / Area1;
    DensidadePopulacional2 = Populacao2 / Area2;

    Pibpercapita1 = (Pib1 * 1000000000) / Populacao1;
    Pibpercapita2 = (Pib2 * 1000000000) / Populacao2;

    Superpoder1 = (float)Populacao1 + Area1 + Pib1 + (float)PontosTuristicos1 + Pibpercapita1 + (1 / DensidadePopulacional1);
    Superpoder2 = (float)Populacao2 + Area2 + Pib2 + (float)PontosTuristicos2 + Pibpercapita2 + (1 / DensidadePopulacional2);

    // Menus para escolha dos dois atributos

    int atributo1, atributo2;
    float valorC1A1, valorC2A1; // Valores do atributo 1 para carta 1 e 2
    float valorC1A2, valorC2A2; // Valores do atributo 2 para carta 1 e 2

    // Menu atributo 1
    printf("\n=== ESCOLHA O PRIMEIRO ATRIBUTO ===\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional (MENOR VENCE)\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("Digite o número do atributo 1: ");
    scanf("%d", &atributo1);

    // Menu atributo 2 (sem repetir atributo1)
    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO (diferente do primeiro) ===\n");
    if (atributo1 != 1) printf("1. População\n");
    if (atributo1 != 2) printf("2. Área\n");
    if (atributo1 != 3) printf("3. PIB\n");
    if (atributo1 != 4) printf("4. Pontos Turísticos\n");
    if (atributo1 != 5) printf("5. Densidade Populacional (MENOR VENCE)\n");
    if (atributo1 != 6) printf("6. PIB per Capita\n");
    if (atributo1 != 7) printf("7. Super Poder\n");
    printf("Digite o número do atributo 2: ");
    scanf("%d", &atributo2);

    // Função para pegar valores, feita só com ifs
    if (atributo1 == 1) { valorC1A1 = Populacao1; valorC2A1 = Populacao2; }
    else if (atributo1 == 2) { valorC1A1 = Area1; valorC2A1 = Area2; }
    else if (atributo1 == 3) { valorC1A1 = Pib1; valorC2A1 = Pib2; }
    else if (atributo1 == 4) { valorC1A1 = PontosTuristicos1; valorC2A1 = PontosTuristicos2; }
    else if (atributo1 == 5) { valorC1A1 = DensidadePopulacional1; valorC2A1 = DensidadePopulacional2; }
    else if (atributo1 == 6) { valorC1A1 = Pibpercapita1; valorC2A1 = Pibpercapita2; }
    else if (atributo1 == 7) { valorC1A1 = Superpoder1; valorC2A1 = Superpoder2; }
    else {
        printf("Atributo 1 inválido.\n");
        return 1;
    }

    if (atributo2 == 1) { valorC1A2 = Populacao1; valorC2A2 = Populacao2; }
    else if (atributo2 == 2) { valorC1A2 = Area1; valorC2A2 = Area2; }
    else if (atributo2 == 3) { valorC1A2 = Pib1; valorC2A2 = Pib2; }
    else if (atributo2 == 4) { valorC1A2 = PontosTuristicos1; valorC2A2 = PontosTuristicos2; }
    else if (atributo2 == 5) { valorC1A2 = DensidadePopulacional1; valorC2A2 = DensidadePopulacional2; }
    else if (atributo2 == 6) { valorC1A2 = Pibpercapita1; valorC2A2 = Pibpercapita2; }
    else if (atributo2 == 7) { valorC1A2 = Superpoder1; valorC2A2 = Superpoder2; }
    else {
        printf("Atributo 2 inválido.\n");
        return 1;
    }

    // Comparação do atributo 1
    printf("\n=== Comparação do primeiro atributo ===\n");
    printf("%s: %.2f\n", NomeCidade1, valorC1A1);
    printf("%s: %.2f\n", NomeCidade2, valorC2A1);

    if (atributo1 == 5) { // Densidade Populacional, menor vence
        if (valorC1A1 < valorC2A1) printf("Vencedor: %s\n", NomeCidade1);
        else if (valorC2A1 < valorC1A1) printf("Vencedor: %s\n", NomeCidade2);
        else printf("Empate!\n");
    } else { // maior vence
        if (valorC1A1 > valorC2A1) printf("Vencedor: %s\n", NomeCidade1);
        else if (valorC2A1 > valorC1A1) printf("Vencedor: %s\n", NomeCidade2);
        else printf("Empate!\n");
    }

    // Comparação do atributo 2
    printf("\n=== Comparação do segundo atributo ===\n");
    printf("%s: %.2f\n", NomeCidade1, valorC1A2);
    printf("%s: %.2f\n", NomeCidade2, valorC2A2);

    if (atributo2 == 5) { // Densidade Populacional, menor vence
        if (valorC1A2 < valorC2A2) printf("Vencedor: %s\n", NomeCidade1);
        else if (valorC2A2 < valorC1A2) printf("Vencedor: %s\n", NomeCidade2);
        else printf("Empate!\n");
    } else { // maior vence
        if (valorC1A2 > valorC2A2) printf("Vencedor: %s\n", NomeCidade1);
        else if (valorC2A2 > valorC1A2) printf("Vencedor: %s\n", NomeCidade2);
        else printf("Empate!\n");
    }

    // Soma dos atributos
    float somaC1 = valorC1A1 + valorC1A2;
    float somaC2 = valorC2A1 + valorC2A2;

    printf("\n=== Soma dos atributos ===\n");
    printf("%s: %.2f\n", NomeCidade1, somaC1);
    printf("%s: %.2f\n", NomeCidade2, somaC2);

    if (somaC1 > somaC2) printf("Vencedor final: %s\n", NomeCidade1);
    else if (somaC2 > somaC1) printf("Vencedor final: %s\n", NomeCidade2);
    else printf("Empate!\n");

    return 0;
}
