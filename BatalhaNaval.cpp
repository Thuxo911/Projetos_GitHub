#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>

int main () {

    bool checagem = true;
    bool checagemModoJogo = true;

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

            while(checagemModoJogo) {
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

            if (opcaoModoJogo < 1 || opcaoModoJogo > 3) {
                std::cout << std::endl;
                std::cout << "Opcao errada! Tente novamente\n";
                std::cout << std::endl;
                continue;
        
            }

            if (opcaoModoJogo == 1) {


                int MatrizBack[5][5] = {0};
                //matriz que a maquina ve

                char MatrizFront[5][5] = {'~'};
                //matriz que o jogador ve

                int numeroNavios = 0;

                bool checagemSeAQuantidadeNaviosEhSuficiente = true;
       
        //comecamos com apenas 10 navios      
      while(checagemSeAQuantidadeNaviosEhSuficiente)   {        
               for(int i = 0; i < 5; i++)  {
                    for (int j = 0; j < 5; j++) {

                        //0,1,2 (1/3 chance)
                        if(rand()% 3 == 0) {
                            MatrizBack[i][j] = {1};
                            numeroNavios++;
                        }

                        if(numeroNavios == 10) {
                            checagemSeAQuantidadeNaviosEhSuficiente = false;
                            break;
                        }


                    }
                }
                
            }

            int numeroBalas = 16;
            std::string coordenada;

                std::cout << std::endl;

                std::cout << std::endl;
                std::cout << "Marinheiro(a)!Afunde todos os navios!!!\n";
                std::cout << "Digite as coordenadas para atirar com seu canhao!\n";
                std::cout << "Uma letra MAISCULA para o eixo X e uma letra para o eixo Y! Sem espaco\n";
                std::cout << std::endl;

                char caractere = 'A';
                int valorASCII = (int)caractere;
                //para representar o eixo X com letras provavelmente vou ter que usar ASCII, e ir somando para ir de A a E


                for(int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                    std::cout << (char)valorASCII << " " << MatrizFront[i][j] << " ";
                    valorASCII++;

                }

                        std::cout << std::endl;
                }   


                 std::cout << "Posicao do tiro: ";
                std::cin >> coordenada;
                std::getline(std::cin, coordenada);

                char coordenadaLetra = coordenada[0];
                //coordenada[0] ou coordenada.front()

                std::string coordenadaNum = coordenada.substr(1);

                //para pegar a segunda parte usaremos substr e stoi
                //substr eh substring, ele pega so uma parte. No caso, ele pega a partir do caractere 1
                //stoi converte string para int

                int coordenadaNumero = std::stoi(coordenadaNum);





            /*
            for(int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    std::cout << MatrizBack[i][j] << " ";

                }

                std::cout << std::endl;
            }

            */





            }



        
            }


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


