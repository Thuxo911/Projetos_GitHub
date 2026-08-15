#include <iostream>
#include <limits>
#include <string>





int main () {

    bool checagem;

    int opcaoMenu;
    char opcaoComoJogar;
    int opcaoModoJogo;

    while (checagem) {
        
        

        std::cout << "=======================================================\n";
        std::cout << "                                                     \n";
        std::cout << "         ~~~  BATALHA NAVAL  ~~~                         \n";
        std::cout << "    ~~~  Jogo de Estrategia no Mar  ~~~             \n";
        std::cout << "                                                     \n";
        std::cout << "=======================================================\n";
        std::cout << "   ___     __   ___    __   ___   __   ___  \n";
        std::cout << "  |___|   |__| |___|  |__| |___  |__| |___| \n";
        std::cout << "  | N |   | A || V |  |I | | O | | S  | \n";
        std::cout << "  |___|   |__| |___|  |__| |___| |__| |___| \n";
        std::cout << "                                                     \n";
        std::cout << "=======================================================\n";
        std::cout << "                 MENU PRINCIPAL                      \n";
        std::cout << "=======================================================\n";
        std::cout << "                                                     \n";
        std::cout << "  [1] Jogar                   \n";
        std::cout << "  [2] Como jogar                \n";
        std::cout << "  [3] Creditos                                  \n";
        std::cout << "                                                     \n";
        std::cout << "  [0]  Sair                                         \n";
        std::cout << "                                                     \n";
        std::cout << "=======================================================\n";
        std::cout << "  Digite a opcao desejada, marinheiro(a): ";
        std::cin >> opcaoMenu;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcaoMenu > 3 || (opcaoMenu < 1 && opcaoMenu !=0)) {
            std::cout << std::endl;
            std::cout <<"Opcao errada! Tente novamente.\n";
            std::cout << std::endl;
            continue;

        }

        if (opcaoMenu == 1) {

            std::cout << std::endl;
            std::cout << "============================================\n";
            std::cout << "              MODOS DE JOGO         \n";
            std::cout << "============================================\n";
            std::cout << "[1] Jogar Sozinho                \n";
            std::cout << "1 tabuleiro. O computador sorteia um mapa com varios navios e voce ataca. Voce pode perder se seus tiros se esgotarem.\n";
            std::cout << std::endl;
            std::cout << "[2] Jogador Vs Computador                \n";
            std::cout << "2 tabuleiros. O jogador coloca navios no seu proprio mapa e o computador coloca os dele no mapa dele.\n"; 
            std::cout << "Voce pode perder se seus tiros se esgotarem ou se o computador destruir todos os seus navios.\n";
            std::cout << std::endl;
            std::cout << "[3] Jogador Vs Jogador                                \n";
            std::cout << "2 tabuleiros. Um jogador coloca navios no seu proprio mapa, enquanto o outro nao pode ver. Depois, o outro faz o mesmo.\n";
            std::cout << "Voce pode perder se seus tiros se esgotarem ou se o outro jogador destruir todos os seus navios.\n";
            std::cout << std::endl;
            std::cout << "Digite aqui sua opcao: ";
            std::cin >> opcaoModoJogo;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            



        }


        
        if (opcaoMenu == 2) {

            std::cout << std::endl;
            std::cout << "============================================\n";
            std::cout << "         COMO JOGAR BATALHA NAVAL          \n";
            std::cout << "============================================\n";
            std::cout << "\n";
            std::cout << "  Voce tem um tabuleiro secreto com navios.\n";
            std::cout << "  O objetivo e afundar os navios inimigos.\n";
            std::cout << "\n";
            std::cout << "  - O tabuleiro eh uma matriz de linhas e colunas.\n";
            std::cout << "  - Para atirar, digite uma coordenada.\n";
            std::cout << "  - Se acertar, o navio foi atingido!\n";
            std::cout << "  - Se errar, caiu na agua.\n";
            std::cout << "\n";
            std::cout << "  Simbolos:\n";
            std::cout << "    ~ = agua vazia\n";
            std::cout << "    X = acertou (tiro no navio inimigo)\n";
            std::cout << "    0 = errou (tiro na agua)\n";
            std::cout << "\n";
            std::cout << "  Vence quem afundar todos os navios primeiro!\n";
            std::cout << "\n";
            std::cout << "============================================\n";
            std::cout << std::endl;
            std::cout << "Digite qualquer tecla para voltar: ";
            std::cin >> opcaoComoJogar;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
            
        }

        
        if (opcaoMenu == 3) {

            std::cout << std::endl;
            std::cout <<"Feito por Marco Thullyo! Obrigado por jogar <<33\n";
            std::cout << std::endl;
            continue;

        }

        if(opcaoMenu == 0) {

            std::cout << std::endl;
            std::cout <<"Adeus, marinheiro(a)!\n";
            std::cout << std::endl;
            return 0;

        }


    }








    return 0;
}


