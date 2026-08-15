#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>

//o modo 1 do jogo nao tem funcoes... eu fiz assim para ser didatico
//agora, para o resto do jogo, eh preciso fazer funcoes, senao o codigo fica gigante

    void inicializarTabuleiros(int matrizBack[][5], char matrizFront[][5], int numero) {

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matrizBack[i][j] = 0;
            }
        }

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                matrizFront[i][j] = '~';
            }
        }


    }

    void posicionarNaviosAleatoriamente(int matrizBack[][5], int numero) {



    }

    void imprimirTabuleiros() {



    }


    bool processarTiro() {



     }






int main () {

    srand(time(NULL));

    bool checagem = true;
    bool checagemModoJogo = true;
    bool checagemJogadorColocarNaviosManualOuRandom = true;

    int opcaoMenu;
    char opcaoComoJogar;
    int opcaoModoJogo;
    int escolhaJogadorColocarNaviosManualOuRandom;

    char teclaVoltarMenuVitoria;
    char teclaVoltarMenuDerrota;

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
                //aqui pode preencher tudo de uma vez pq eh int. Com char tem que ser manualmente ou com for

                char MatrizFront[5][5];

                for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            MatrizFront[i][j] = '~';
                        }
                    }
                    
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
            bool checagemJogadorColocouCoordenadaCerta = true;

            while (checagemJogadorColocouCoordenadaCerta) {

                std::string coordenadaDigitada;

                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Marinheiro(a)!Afunde todos os navios!!!\n";
                std::cout << "Digite as coordenadas para atirar com seu canhao!\n";
                std::cout << "Uma letra MAISCULA para o eixo X e uma letra para o eixo Y! Sem espaco\n";
                std::cout << "Numero de balas: " << numeroBalas << std::endl;
                std::cout << "Numero de navios restante: " << numeroNavios << std::endl;
                std::cout << std::endl;

                char caractere = 'A';
                int valorASCII = (int)caractere;
                //para representar o eixo X com letras provavelmente vou ter que usar ASCII, e ir somando para ir de A a E

                std::cout << "  ";
                for(int i = 0; i < 5; i ++) {
                    std::cout << i + 1 << " ";
                }

                std::cout << std::endl;

                for(int i = 0; i < 5; i++) {

                    std::cout << (char)valorASCII << " "; //linha

                    for (int j = 0; j < 5; j++) {
                    std::cout << MatrizFront[i][j] << " ";

                }

                    std::cout << std::endl;
                    valorASCII++;

                }   

                
                std::cout << std::endl;
                std::cout << "Posicao do tiro: ";
                std::getline(std::cin, coordenadaDigitada);

                char coordenadaLetra = coordenadaDigitada[0];
                //coordenada[0] ou coordenada.front()

                std::string coordenadaNum = coordenadaDigitada.substr(1);

                //para pegar a segunda parte usaremos substr e stoi
                //substr eh substring, ele pega so uma parte. No caso, ele pega a partir do caractere 1
                //stoi converte string para int

                int coordenadaNumero = std::stoi(coordenadaNum);

                //supondo que o jogador digitou B2
                //olhando para o meu caderno, B equivale a linha 1, e 2 equivale a coluna 1
                //ou seja, o numero que o jogador digita nao eh a coordenada exata
                //precisamos converter, talvez coordenadaReal = coordenadaDigitada - 1;
                //no caso de "B" converter para ASCII. B em ascii eh 66
                //entao coordenadaReal = ascii de B - 65
                //como ASCII esta em ordem crescente entao A B C D E = 65 66 67 68 69
 
                int coordenadaRealLetra = (char)coordenadaLetra - 65;
                int coordenadaRealNumero = coordenadaNumero - 1;

                std::cout << coordenadaRealLetra << std::endl;
                std::cout << coordenadaRealNumero << std::endl;
                //c6 acertou d1

                //4 porque 4 = 5-1 (limite - 1)
                //porque o eixo de cima eh 0 1 2 3 4, se for > 4 ja ta fora.
                if (coordenadaRealLetra > 4 || coordenadaRealLetra < 0
                    || coordenadaRealNumero > 4 || coordenadaRealNumero < 0) {

                        std::cout << std::endl;
                        std::cout << "Marinheiro(a)! Essa coordenada nao existe! Digite outra!\n";
                        continue;

                    }
                    

                    if(MatrizBack[coordenadaRealLetra][coordenadaRealNumero] == 2
                    || MatrizBack[coordenadaRealLetra][coordenadaRealNumero] == 3) {

                        std::cout << std::endl;
                        std::cout << "Marinheiro(a)! Voce ja atirou ai!\n";
                        continue;

                    }

                //B2 foi traduzido para coordenadaRealLetra = 1 e coordenadaRealNumero = 1! Agora verificaremos se la tem navio

                //colocaremos outros valores para a matriz que o jogador nao ve
                //2 para o navio acertado e 3 para o nao acertado
                //se o jogador tentar jogar de novo nesses lugares, ele sera impedido
                //a verificacao de se o lugar eh valido tem que ser colocada logo apos a verificacao de fronteiras. 
                //vamos colocar la em cima

                    if(MatrizBack[coordenadaRealLetra][coordenadaRealNumero] == 1) {
                        MatrizBack[coordenadaRealLetra][coordenadaRealNumero] = 2;
                        numeroNavios--;
                        numeroBalas--;
                        MatrizFront[coordenadaRealLetra][coordenadaRealNumero] = 'X';
                        
                        std::cout << std::endl;
                        std::cout << "Voce acertou o navio inimigo!\n";
                        std::cout << std::endl;
                        

                    }

                    else {


                        MatrizBack[coordenadaRealLetra][coordenadaRealNumero] = 3;
                        numeroBalas--;
                        MatrizFront[coordenadaRealLetra][coordenadaRealNumero] = '0';

                        std::cout << std::endl;
                        std::cout << "Voce errou! Nao ha navio ai!\n";

                    }

                    if(numeroNavios == 0) {

                        std::cout << std::endl;
                        std::cout << "Voce venceu! Parabens!!!!!\n";
                        std::cout << std::endl;

                        std::cout << "Aperte qualquer tecla para voltar para o menu: ";
                        std::cin >> teclaVoltarMenuVitoria;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        checagemJogadorColocouCoordenadaCerta = false;
                        checagemSeAQuantidadeNaviosEhSuficiente = false;
                        checagemModoJogo = false;

                    }

                    if(numeroBalas == 0) {


                        std::cout << std::endl;
                        std::cout << "Sua municao acabou! Game over!\n";
                        std::cout << "Localizacao dos navios restantes: \n";
                        std::cout << std::endl;

                char caractere = 'A';
                int valorASCII = (int)caractere;

                std::cout << "  ";
                for(int i = 0; i < 5; i ++) {
                    std::cout << i + 1 << " ";
                }

                std::cout << std::endl;

                for(int i = 0; i < 5; i++) {

                    std::cout << (char)valorASCII << " "; //linha

                    
                    for (int j = 0; j < 5; j++) {

                        if(MatrizBack[i][j] == 0 ||
                        MatrizBack[i][j] == 2 || MatrizBack[i][j] == 3) {
                            std::cout << MatrizFront[i][j] << " ";
                        }

                        else if (MatrizBack[i][j] == 1)  {
                            std::cout << "N ";
                        }
                }


                    std::cout << std::endl;
                    valorASCII++;

                }   
                    std::cout << std::endl;
                    std::cout << "Aperte qualquer tecla para voltar para o menu: ";
                        std::cin >> teclaVoltarMenuDerrota;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        checagemJogadorColocouCoordenadaCerta = false;
                        checagemSeAQuantidadeNaviosEhSuficiente = false;
                        checagemModoJogo = false;
                        
                    }
            }
            }

                if(opcaoModoJogo == 2) {
                    
                    int MatrizBackJogador[5][5];
                    char MatrizFrontJogador[5][5];

                    int MatrizBackPC[5][5];
                    char MatrizFrontPC[5][5];

                    inicializarTabuleiros(MatrizBackJogador, MatrizFrontJogador, 5);
                    inicializarTabuleiros(MatrizBackPC, MatrizFrontJogador, 5);

                    while (checagemJogadorColocarNaviosManualOuRandom) {

                    std::cout << std::endl;
                    std::cout << "Marinheiro(a), o seu inimigo mortal eh este computador!\n";
                    std::cout << "Voce gostaria de posicionar seus navios manualmente ou deixar que o destino decida?\n";
                    std::cout << "[1] Quero colocar meus navios\n";
                    std::cout << "[2] Deixar a escolha aleatoria\n";
                    std::cout << std::endl;
                    std::cout << "Digite: ";
                    std::cin >> escolhaJogadorColocarNaviosManualOuRandom;

                    //independente do que o jogador escolha, o computador sempre vai escolher os proprios navios aleatoriamente
                    
                    if(escolhaJogadorColocarNaviosManualOuRandom != 1 &&
                    escolhaJogadorColocarNaviosManualOuRandom != 2) {
                        std::cout << std::endl;
                        std::cout << "Opcao invalida\n";
                        std::cout << std::endl;
                        continue;
                    }


                    if(escolhaJogadorColocarNaviosManualOuRandom == 1) {



                    }



                    if(escolhaJogadorColocarNaviosManualOuRandom == 2) {

                        posicionarNaviosAleatoriamente(MatrizBackJogador, 5);
                        posicionarNaviosAleatoriamente(MatrizBackPC, 5);

                        
                    }







                }


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


