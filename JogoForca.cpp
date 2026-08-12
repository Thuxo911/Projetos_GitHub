#include <iostream>
#include <string>



int main() {


    bool checagem = true;


        while (checagem) {

        int escolha;


        std::cout << "==========BEM-VINDO(A)==========\n";
        std::cout << "=========JOGO DA FORCA=========\n";
        std::cout << std::endl;

        std::cout << "Vamos jogar forca? Forca eh um jogo muito divertido que se baseia em um principio simplerrimo:\n";
        std::cout << "Raciocinio logico combinado com conhecimento sobre palavras\n";
        std::cout << "Vamos nessa?\n";
        std::cout << std::endl;

        std::cout << "Digite uma das opcoes no seu teclado\n";
        std::cout << std::endl;

        std::cout <<" 1 - Comecar a jogar\n";
        std::cout <<" 2 - Creditos\n";
        std::cout <<" 3 - Sair\n";

        if (escolha != 1 && escolha != 2 && escolha != 3) {
                std::cout << "Escolha errada! Mais atencao na proxima vez!\n";
                std::cout << std::endl;
        }

        if (escolha == 1)

        if (escolha == 2) {
            std::cout << "Desenvolvido por Marco Thullyo Sao Severino. Obrigado por jogar! <3\n";
        }

        if (escolha == 3) {
            return 0;
        }







        }







    return 0;

}












