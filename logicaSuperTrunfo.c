#include <stdio.h>
#include <string.h>  // Adiciona no topo por conta do fgets
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


    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1\n");

    printf("Estado (letra de 'A' a 'H'):\n");
    scanf(" %c", &Estado1);      // espaço para limpar buffer

    printf("Código da Carta (ex: A01):\n");
    scanf("%3s", CodigoCarta1);

    printf("Nome da Cidade:\n");
    getchar(); // limpa o '\n' do buffer deixado pelo scanf anterior
    fgets(NomeCidade1, sizeof(NomeCidade1), stdin);
    NomeCidade1[strcspn(NomeCidade1, "\n")] = '\0';
   
    printf("População:\n");
    scanf("%lu", &Populacao1);

    printf("Área (em km²):\n");
    scanf("%f", &Area1);

    printf("PIB (em bilhões de reais):\n");
    scanf("%f", &Pib1);

    printf("Número de Pontos Turísticos:\n");
    scanf("%d", &PontosTuristicos1);

       
    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2\n");

    printf("Estado (letra de 'A' a 'H'):\n");
    scanf(" %c", &Estado2);      // espaço para limpar buffer

    printf("Código da Carta (ex: B02):\n");
    scanf("%3s", CodigoCarta2);

    printf("Nome da Cidade:\n"); // imprime a mensagem e pula uma linha
    getchar(); // limpa o '\n' do buffer deixado pelo scanf anterior
    fgets(NomeCidade2, sizeof(NomeCidade2), stdin); // lê a linha inteira com espaços
    NomeCidade2[strcspn(NomeCidade2, "\n")] = '\0'; // ele apaga o \n e evita o erro de acontecer denovo
   
    printf("População:\n");
    scanf("%lu", &Populacao2);

    printf("Área (em km²):\n");
    scanf("%f", &Area2);

    printf("PIB (em bilhões de reais):\n");
    scanf("%f", &Pib2);

    printf("Número de Pontos Turísticos:\n");
    scanf("%d", &PontosTuristicos2);

    
    // Cálculo da Densidade Populacional
    DensidadePopulacional1 = Populacao1 / Area1;  //Carta 1
    DensidadePopulacional2 = Populacao2 / Area2; //Carta 2

    // Cálculo do PIB per Capita
    Pibpercapita1 = (Pib1 * 1000000000) / Populacao1;  //Carta 1
    Pibpercapita2 = (Pib2 * 1000000000) / Populacao2; //Carta 2

    // Cálculo do Super Poder  = (população, área, PIB, número de pontos turísticos,PIB per capita e o inverso da densidade populacional)
    Superpoder1 = (float)Populacao1 + Area1 + Pib1 + (float)PontosTuristicos1 + Pibpercapita1 + ( 1 / DensidadePopulacional1 );
    Superpoder2 = (float)Populacao2 + Area2 + Pib2 + (float)PontosTuristicos2 + Pibpercapita2 + ( 1 / DensidadePopulacional2 );
    
    // Menu interativo
    int escolha;
    
    printf("\n=== MENU DE COMPARAÇÃO ===\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional (MENOR VENCE)\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("Escolha um atributo para comparar (1 a 7): ");
    scanf("%d", &escolha);

    printf("\nComparando %s vs %s:\n", NomeCidade1, NomeCidade2);
    
    // Comparação das Cartas
    switch (escolha)
    {
    case 1:                 // População
        printf("População - %lu x %lu\n", Populacao1, Populacao2);

    // Primeiro if: compara qual cidade tem maior população
    if (Populacao1 > Populacao2) {
        // Segundo if (aninhado): verifica se a população da cidade 1 é maior que 1 milhão
        if (Populacao1 > 1000000) {
            // Se sim, mostra mensagem personalizada
            printf("Resultado: %s venceu com mais de 1 milhão de habitantes!\n", NomeCidade1);
        } else {
            // Se não, mostra mensagem simples de vitória
            printf("Resultado: %s venceu!\n", NomeCidade1);
        }
    }
    // Agora verifica se a cidade 2 tem maior população
    else if (Populacao2 > Populacao1) {
        // If aninhado para verificar se também passa de 1 milhão
        if (Populacao2 > 1000000) {
            printf("Resultado: %s venceu com mais de 1 milhão de habitantes!\n", NomeCidade2);
        } else {
            printf("Resultado: %s venceu!\n", NomeCidade2);
        }
    }
    // Se não for maior nem menor são iguais
    else {
        printf("Resultado: Empate!\n");
    }
    break;

    case 2:                 // Área
       printf("Área - %.2f x %.2f\n", Area1, Area2);
        if (Area1 > Area2) {
            printf("Resultado: %.2f venceu!\n", Area1);
        }
        else if (Area2 > Area1){
            printf("Resultado: %.2f venceu!\n", Area2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
        break;

    case 3:                 // PIB
       printf("PIB - %.2f x %.2f\n", Pib1, Pib2);
        if (Pib1 > Pib2) {
            printf("Resultado: %.2f venceu!\n", Pib1);
        }
        else if (Pib2 > Pib1){
            printf("Resultado: %.2f venceu!\n",Pib2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
        break;

    case 4:                 // Pontos Turísticos
        printf("Pontos Turisticos - %d x %d\n", PontosTuristicos1, PontosTuristicos2);
        if (PontosTuristicos1 > PontosTuristicos2) {
            printf("Resultado: %d venceu!\n", PontosTuristicos1);
        }
        else if (PontosTuristicos2 > PontosTuristicos1){
            printf("Resultado: %d venceu!\n",PontosTuristicos2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
        break;

    case 5:                 // Densidade Populacional = Menor Vence
    printf("Densidade Populacional - %.2f x %.2f\n", DensidadePopulacional1, DensidadePopulacional2);
        if (DensidadePopulacional1 < DensidadePopulacional2) {
            printf("Resultado: %.2f venceu!\n", DensidadePopulacional1);
        }
        else if (DensidadePopulacional2 < DensidadePopulacional1) {
            printf("Resultado: %.2f venceu!\n",DensidadePopulacional2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
        break;

    case 6:                 // PIB per Capita
    printf("PIB per Capita - %.2f x %.2f\n", Pibpercapita1, Pibpercapita2);
        if (Pibpercapita1 > Pibpercapita2) {
            printf("Resultado: %.2f venceu!\n", Pibpercapita1);
        }
        else if (Pibpercapita2 > Pibpercapita1) {
            printf("Resultado: %.2f venceu!\n", Pibpercapita2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
        break;

    case 7:                 // Super Poder
      printf("Super Poder - %.2f x %.2f\n", Superpoder1, Superpoder2);
        if (Superpoder1 > Superpoder2) {
            printf("Resultado: %.2f venceu!\n", Superpoder1);
        }
        else if (Superpoder2 > Superpoder1){
            printf("Resultado: %.2f venceu!\n",Superpoder2);
        }
        else {
            printf("Resultado: Empate!\n");
        }
        break;
    
    default:
    printf("Erro: Opção Invalida");
        break;
    }


    // Mostrar dados completos das cartas (opcional)
    char verCartas;
    printf("\nDeseja ver todos os dados das cartas? (S/N): ");
    scanf(" %c", &verCartas);

    if (verCartas == 'N' || verCartas == 'n') {
        printf("Encerrando...\n");
        return 0;
    } 

    // Exibição dos dados da Carta 1
    printf("***RESULTADO***\n");
    
    printf("\nCarta 1:\n");

    printf("Estado: %c\n", Estado1);
    printf("Código: %s\n", CodigoCarta1);
    printf("Nome da Cidade: %s\n", NomeCidade1);
    printf("População: %lu\n", Populacao1);
    printf("Área: %.2f km²\n", Area1);
    printf("PIB: %.2f bilhões de reais\n", Pib1);
    printf("Número de Pontos Turísticos: %d\n", PontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km² \n", DensidadePopulacional1);
    printf("PIB per capita: %.2f Reais\n", Pibpercapita1);
    printf("Super Poder: %.2f \n", Superpoder1);

    // Exibição dos dados da Carta 2
    printf("\nCarta 2:\n");
   
    printf("Estado: %c\n", Estado2);
    printf("Código: %s\n", CodigoCarta2);
    printf("Nome da Cidade: %s\n", NomeCidade2);
    printf("População: %lu\n", Populacao2);
    printf("Área: %.2f km²\n", Area2);
    printf("PIB: %.2f bilhões de reais\n", Pib2);
    printf("Número de Pontos Turísticos: %d\n", PontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km² \n", DensidadePopulacional2);
    printf("PIB per capita: %.2f Reais\n", Pibpercapita2);
    printf("Super Poder: %.2f \n",Superpoder2);
   
        return 0;
    }
    
