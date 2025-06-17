# Super Trunfo da Paraíba - Jogo Completo

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-green.svg)

Este projeto foi desenvolvido como parte dos requisitos para a disciplina de Jogos Digitais do curso da Estácio. Trata-se de uma implementação completa em linguagem C do jogo de cartas Super Trunfo, com o tema "Cidades da Paraíba".

O software apresenta um menu principal completo, permitindo ao jogador aprender as regras, estudar as cartas e, em seguida, participar de duelos estratégicos, consolidando conceitos de programação estruturada, manipulação de dados e interatividade com o usuário.

## 🚀 Funcionalidades Principais

- **Menu Principal Interativo:** Uma interface de usuário central para navegar entre as diferentes seções do jogo.
- **Manual de Instruções ('Como Jogar'):** Uma seção dedicada que explica as regras, os objetivos e os critérios de vitória do jogo.
- **Galeria de Cartas:** Um visualizador que permite ao jogador consultar a lista completa de cidades e ver os detalhes e atributos de cada carta individualmente, promovendo a análise estratégica antes dos duelos.
- **Sistema de Duelo Avançado:**
    - O jogador seleciona duas das 14 cidades para a batalha.
    - O jogador escolhe dois atributos distintos para a comparação.
    - O menu de seleção do segundo atributo é **dinâmico**, omitindo a primeira escolha.
    - A vitória é decidida por um **sistema de pontos**, onde cada atributo vencido concede 1 ponto à carta.
    - Implementa **regras especiais** onde o menor valor vence para "Ano de Fundação" e "Densidade Demográfica".

---

## ⚙️ Como Compilar e Executar

**Pré-requisitos:**
* É necessário ter um compilador C, como o **`gcc`**, instalado e configurado no `PATH` do sistema. O ambiente utilizado para o desenvolvimento foi o **MSYS2 com a toolchain UCRT64** no Windows.

**Passos:**

1.  Clone este repositório para a sua máquina local.
2.  Abra um terminal (como o MSYS2 UCRT64) na pasta raiz do projeto.
3.  Execute o seguinte comando para compilar o projeto:
    ```bash
    gcc main.c jogo.c -o super_trunfo
    ```
4.  Após a compilação bem-sucedida, execute o jogo com o comando:
    ```bash
    ./super_trunfo
    ```

---

## 🎮 Como Jogar

1.  Ao iniciar o programa, você verá o **Menu Principal**.
2.  Selecione a opção **"1. Como Jogar"** para entender as regras detalhadas do duelo.
3.  Selecione a opção **"2. Visualizar Cartas"** para navegar pela lista de cidades. Digite o número de uma cidade para ver seus atributos e planejar sua estratégia. Digite `0` para voltar ao menu principal.
4.  Quando estiver pronto, selecione **"3. Iniciar Duelo!"**. Siga as instruções na tela para escolher as duas cidades e os dois atributos da batalha. O resultado será exibido no final.
5.  O programa continuará no menu principal até que a opção **"0. Sair do Jogo"** seja escolhida.

---

## 📂 Estrutura de Arquivos

O projeto foi organizado de forma modular para facilitar a leitura e manutenção:
* `main.c`: Contém a função `main`, responsável pelo menu principal e pelo loop do jogo.
* `jogo.c`: Contém toda a implementação da lógica do jogo (instruções, galeria de cartas, duelo, comparações).
* `jogo.h`: O arquivo de cabeçalho que declara as funções presentes em `jogo.c`, funcionando como um "índice".
* `carta.h`: Contém apenas a definição da `struct Carta`, o molde para todas as cartas do jogo.
* `.gitignore`: Configurado para ignorar arquivos de compilação.

---