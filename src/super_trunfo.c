/*
***************************************************************************************************
DECLARAÇÕES INICIAIS
***************************************************************************************************
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Carta {
    // Uma letra de 'A' a 'H' (representando um dos oito estados)
    char estado;

    // A letra do estado seguida de um número de 01 a 04 (ex: A01, B03),
    // o código terá 3 dígitos, a dimensão de 4 caracteres é necessária para 
    // acomodar o caractere \0 ao final, que determina o fim da string
    char codigo_carta[5];

    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;

    // Atributos dinâmicos, gerados na inicialização da carta (pib_per_capita, dens_pop, super_poder)
    float pib_per_capita;
    float dens_pop;
    float super_poder;
};

struct Carta *CARTAS[] = {NULL};

/*
***************************************************************************************************
PROTÓTIPOS DAS FUNÇÕES
***************************************************************************************************
*/

struct Carta criar_carta();
void coleta_dados_carta(struct Carta *c);
void exibe_dados_carta(struct Carta *c);
void init_carta(struct Carta *c);
void ler_dado_tela(char *prompt, void *target, char *scan_format, bool texto_com_espaco, int tamanho);
void imprimir_rotulo_alinhado(const char* rotulo);
void compara_cartas();
void limpa_buffer();

/*
***************************************************************************************************
CORPO DO PROGRAMA
***************************************************************************************************
*/

int main() {
    struct Carta c1, c2;

    printf("Bem-vindo ao Super Trunfo\n");
    printf("\nPara iniciar, crie a primeira carta\n\n");
    printf("--- PRIMEIRA CARTA ---\n");
    c1 = criar_carta();
    CARTAS[0] = &c1;
    exibe_dados_carta(&c1);
    
    printf("\nPressione ENTER para continuar...\n");
    getchar();

    printf("Agora, crie a segunda carta\n\n");
    printf("--- SEGUNDA CARTA ---\n");
    c2 = criar_carta();
    CARTAS[1] = &c2;
    exibe_dados_carta(&c2);
    
    printf("\nPressione ENTER para comparar as cartas e descobrir o vencedor...\n");
    getchar();
    
    compara_cartas();
    return 0;
}

struct Carta criar_carta() {
    struct Carta nova_carta;
    coleta_dados_carta(&nova_carta);
    init_carta(&nova_carta);
    return nova_carta;
}

void init_carta(struct Carta *c) {
    if (c->pib > 0 && c->populacao > 0 && c->area >0 && c->pontos_turisticos > 0) {
        c->pib_per_capita = c->pib / c->populacao;
        c->dens_pop = (c->populacao / c->area) * 1000;
        //"Super Poder" somando todos os atributos numéricos (população, área, PIB, número de pontos turísticos, 
        // PIB per capita e o inverso da densidade populacional – quanto menor a densidade, maior o "poder")
        c->super_poder = c->populacao + c->area + c->pib + c->pontos_turisticos + c->pib_per_capita + (100 - c->dens_pop);
    } else {
        printf("O preenchimento da carta esta incompleto\n");
    }
}

void coleta_dados_carta(struct Carta *c) {
    ler_estado:
    ler_dado_tela("Digite o estado (A-H): ", &c->estado, "%c", false, 0);
    if (c->estado < 'A' || c->estado > 'H') {
        printf("Estado invalido. Por favor, digite um estado de A a H.\n");
        goto ler_estado;
    }

    ler_codigo_carta:
    ler_dado_tela("Digite o codigo da carta (ex: A01): ", c->codigo_carta, "%3s", false, 0);
    if (CARTAS[0] != NULL && strcmp(CARTAS[0]->codigo_carta, c->codigo_carta) == 0) {
        printf("Codigo de carta ja existente. Por favor, digite um codigo diferente.\n");
        goto ler_codigo_carta;
    }

    ler_nome_cidade:
    ler_dado_tela("Digite o nome da cidade: ", c->nome_cidade, NULL, true, 50);
    if (CARTAS[0] != NULL && strcmp(CARTAS[0]->nome_cidade, c->nome_cidade) == 0) {
        printf("Nome da cidade ja existente. Por favor, digite um nome diferente.\n");
        goto ler_nome_cidade;
    }

    ler_dado_tela("Digite a populacao: ", &c->populacao, "%d", false, 0);
    ler_dado_tela("Digite a area: ", &c->area, "%f", false, 0);
    ler_dado_tela("Digite o PIB: ", &c->pib, "%f", false, 0);
    ler_dado_tela("Digite o numero de pontos turisticos: ", &c->pontos_turisticos, "%d", false, 0);

    printf("\nCarta %s criada com sucesso!\n", c->codigo_carta);
    printf("\nPressione ENTER para continuar...\n");
    getchar();
}

void exibe_dados_carta(struct Carta *c) {
    imprimir_rotulo_alinhado("Estado");
    printf("%c\n", c->estado);

    imprimir_rotulo_alinhado("Codigo da carta");
    printf("%s\n", c->codigo_carta);

    imprimir_rotulo_alinhado("Nome da cidade");
    printf("%s\n", c->nome_cidade);

    imprimir_rotulo_alinhado("Populacao");
    printf("%d\n", c->populacao);

    imprimir_rotulo_alinhado("Area");
    printf("%.2f km2\n", c->area);

    imprimir_rotulo_alinhado("PIB");
    printf("R$ %.2f\n", c->pib);

    imprimir_rotulo_alinhado("Pontos turisticos");
    printf("%d\n", c->pontos_turisticos);

    imprimir_rotulo_alinhado("PIB per capita");
    printf("R$ %.2f\n", c->pib_per_capita);

    imprimir_rotulo_alinhado("Densidade populacional");
    printf("%.2f hab/km2\n", c->dens_pop);

    imprimir_rotulo_alinhado("Super Poder");
    printf("%.2f\n", c->super_poder);
}

void compara_cartas() {
    struct Carta *c1 = CARTAS[0];
    struct Carta *c2 = CARTAS[1];
    char *ven_pop, *ven_area, *ven_pib, *ven_ptur, *ven_pip_pc, *ven_dens_pop, *ven_spoder;

    // Compara cada atributo e aponta para o código da carta vencedora.
    ven_pop = (c1->populacao > c2->populacao) ? c1->codigo_carta : c2->codigo_carta;
    ven_area = (c1->area > c2->area) ? c1->codigo_carta : c2->codigo_carta;
    ven_pib = (c1->pib > c2->pib) ? c1->codigo_carta : c2->codigo_carta;
    ven_ptur = (c1->pontos_turisticos > c2->pontos_turisticos) ? c1->codigo_carta : c2->codigo_carta;
    ven_pip_pc = (c1->pib_per_capita > c2->pib_per_capita) ? c1->codigo_carta : c2->codigo_carta;
    ven_dens_pop = (c1->dens_pop > c2->dens_pop) ? c1->codigo_carta : c2->codigo_carta;
    ven_spoder = (c1->super_poder > c2->super_poder) ? c1->codigo_carta : c2->codigo_carta;

    char *arrayAtributos[] = {ven_pop, ven_area, ven_pib, ven_ptur, ven_pip_pc, ven_dens_pop, ven_spoder};

    // Identifica vencedor geral do comparativo
    int contador_c1 = 0, contador_c2 = 0;
    for (int i = 0; i < 7; i++) {
        if (arrayAtributos[i] == c1->codigo_carta) {
            contador_c1++;
        } else {
            contador_c2++;
        }
    }

    char vencedor[4];
    if (contador_c1 > contador_c2) {
        strcpy(vencedor, c1->codigo_carta);
    } else {
        strcpy(vencedor, c2->codigo_carta);
    }

    // Exibe vencedor e resultado do comparativo
    printf("\n--- RESULTADO ---\n");
    imprimir_rotulo_alinhado("Vencedor");
    printf("%s\n\n", vencedor);

    printf("COMPARATIVO:\n");

    imprimir_rotulo_alinhado("Populacao");
    printf("%s\n", ven_pop);

    imprimir_rotulo_alinhado("Area");
    printf("%s\n", ven_area);

    imprimir_rotulo_alinhado("PIB");
    printf("%s\n", ven_pib);

    imprimir_rotulo_alinhado("Pontos turisticos");
    printf("%s\n", ven_ptur);

    imprimir_rotulo_alinhado("PIB per capita");
    printf("%s\n", ven_pip_pc);

    imprimir_rotulo_alinhado("Densidade populacional");
    printf("%s\n", ven_dens_pop);

    imprimir_rotulo_alinhado("Super Poder");
    printf("%s\n", ven_spoder);
}

/*
***************************************************************************************************
FUNÇÕES COMPLEMENTARES
***************************************************************************************************
*/

void ler_dado_tela(char *prompt, void *target, char *scan_format, bool texto_com_espaco, int tamanho) {
    printf("%s", prompt);
    if (texto_com_espaco) {
        fgets(target, tamanho, stdin);
        ((char*)target)[strcspn(target, "\n")] = 0;
    } else {
        scanf(scan_format, target);
        limpa_buffer();
    }
}

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimir_rotulo_alinhado(const char* rotulo) {
    // Largura definida arbitrariamente (apenas para os fins deste projeto)
    const int LARGURA_TOTAL = 28; 

    printf("%s", rotulo);

    // Calcula quantos pontos faltam para atingir a largura total
    int pontos_necessarios = LARGURA_TOTAL - strlen(rotulo);

    // Para evitar número negativo de pontos a serem impressos
    if (pontos_necessarios < 0) {
        pontos_necessarios = 0;
    }

    for (int i = 0; i < pontos_necessarios; i++) {
        printf(".");
    }

    // Imprime os dois pontos e o espaço no final
    printf(": ");
}