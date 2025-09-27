# Super Trunfo em C

Este é um projeto simples desenvolvido em linguagem C para a disciplina de "Introdução à Programação de Computadores". O programa simula uma partida do jogo Super Trunfo, onde o usuário cadastra duas cartas com atributos de cidades e o sistema as compara para determinar a vencedora com base no maior número de atributos superiores.

## Funcionalidades

- **Cadastro de Cartas**: Permite ao usuário inserir dados para duas cartas, incluindo nome da cidade, população, área, PIB, etc.
- **Validação de Dados**: O sistema verifica se o código ou nome da cidade já foi utilizado na primeira carta para evitar duplicatas.
- **Cálculo de Atributos**: Atributos como "PIB per capita", "Densidade populacional" e "Super Poder" são calculados dinamicamente com base nos dados inseridos.
- **Comparação Detalhada**: Após o cadastro, o programa compara cada um dos atributos das duas cartas.
- **Exibição Formatada**: Todos os dados e resultados são exibidos de forma organizada e alinhada no console, com suporte a caracteres especiais (acentos, ç) graças ao tratamento de codificação UTF-8.

## Como Compilar e Executar

Este projeto foi desenvolvido em C puro e pode ser compilado com qualquer compilador C padrão, como o GCC.

**1. Pré-requisitos:**
   - Ter um compilador C (como o GCC) instalado.

**2. Compilação:**
   Abra o terminal na pasta do projeto e execute o seguinte comando para compilar o programa. Substitua `seu_arquivo.c` pelo nome do seu arquivo de código-fonte.

   ```bash
   gcc -o super_trunfo seu_arquivo.c -W -Wall
   ```
   - `-o super_trunfo`: Define o nome do arquivo executável de saída.
   - `-W -Wall`: Flags recomendadas que ativam avisos do compilador para ajudar a identificar possíveis problemas no código.

**3. Execução:**
   Após a compilação bem-sucedida, execute o programa com o comando:

   ```bash
   ./super_trunfo
   ```

## Exemplo de Uso

Abaixo está um exemplo completo de uma execução do programa, desde a criação das cartas até a exibição do resultado final.

```text
Bem-vindo ao Super Trunfo

Para iniciar, crie a primeira carta

--- PRIMEIRA CARTA ---
Digite o estado (A-H): A
Digite o código da carta (ex: A01): A01
Digite o nome da cidade: URUGUAIANA
Digite a população: 117210
Digite a área: 5702098
Digite o PIB: 3436885536.6
Digite o número de pontos turísticos: 8

Carta A01 criada com sucesso!

Pressione ENTER para continuar...

Estado......................: A
Código da carta.............: A01
Nome da cidade..............: URUGUAIANA
População...................: 117210
Área........................: 5702098.00 km²
PIB.........................: R$ 3436885504.00
Pontos turísticos...........: 8
PIB per capita..............: R$ 29322.46
Densidade populacional......: 20.56 hab/km²
Super Poder.................: 3442734336.00

Pressione ENTER para continuar...

Agora, crie a segunda carta

--- SEGUNDA CARTA ---
Digite o estado (A-H): A
Digite o código da carta (ex: A01): A02
Digite o nome da cidade: TAQUARA
Digite a população: 54353
Digite a área: 450195
Digite o PIB: 1476842212.43
Digite o número de pontos turísticos: 9

Carta A02 criada com sucesso!

Pressione ENTER para continuar...

Estado......................: A
Código da carta.............: A02
Nome da cidade..............: TAQUARA
População...................: 54353
Área........................: 450195.00 km²
PIB.........................: R$ 1476842240.00
Pontos turísticos...........: 9
PIB per capita..............: R$ 27171.31
Densidade populacional......: 120.73 hab/km²
Super Poder.................: 1477373952.00

Pressione ENTER para comparar as cartas e descobrir o vencedor...

--- RESULTADO ---
Vencedor....................: A01

COMPARATIVO:
População...................: A01
Área........................: A01
PIB.........................: A01
Pontos turísticos...........: A02
PIB per capita..............: A01
Densidade populacional......: A02
Super Poder.................: A01
```

## Tecnologias Utilizadas

- Linguagem C (Padrão C99+)
- Biblioteca Padrão do C (`stdio.h`, `string.h`, `stdbool.h`)
