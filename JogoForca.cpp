#include <iostream>
#include <string>
#include <limits>



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
        
        std::cout << std::endl;
        std::cout << "Minha escolha eh:\n";
        std::cin >> escolha;    

        //ao digitar 42, por exemplo, no buffer fica 42\n
        //entao, ao passar pelo loop, ele entra na primeira opcao (if escolha != 1 && escolha != 2...)
        //mas quando volta aqui, o \n esta sozinho. Entao o compilador passa direto pelo cin, achando que ja tem outra resposta


        std::cin.clear();   //limpa flags de erro. ex: digitou string ao inves de int

        //std::cin.ignore(100000, '\n'); ignore caracteres ate atingir o limite OU ate encontrar o delimitador
        //ex: supondo que o parametro é (100, \n)
        //usuario digita um numero de 50 caracteres. Ele ignora os 50 caracteres e encontra o \n. Funciona
        //usuario digita um numero de 150 caracteres. Ele ignora os 100 primeiros e PARA mesmo sem ter encontrado o \n
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //nesse contexto, ignorar significa que ele vai percorrer o numero de elementos que se encontra no primeiro parametro
        //ate chegar no segundo parametro. Entao em (100, \n) ele percorreria os 100 elementos, mas se encontrasse o  \n antes, pararia
        //(Aqui, o sentido de ignorar os 100 primeiros elementos eh que ele esta na busca pelo \n)
        //(agora, quando ele encontra o \n, ai ele ignora o \n. Se ele passa de 100 caracteres, da problema, porque o \n esta fora desse alcance de 100 caracteres)
   
        //O PULO DO GATO
        //O ignore NAO DESCARTA O 42, por exemplo. O numero que voce digitou ja foi consumido e esta na variavel "escolha"
        //O ignore SO VE O QUE SOBROU NO BUFFER

        std::cout << std::endl; 

        if (escolha != 1 && escolha != 2 && escolha != 3) {
                std::cout << "Escolha errada! Mais atencao na proxima vez!\n";
                std::cout << std::endl;
        }

        if (escolha == 1) {

        }

        if (escolha == 2) {
            std::cout << "Desenvolvido por Marco Thullyo Sao Severino. Obrigado por jogar! <3\n";
            std::cout << std::endl;
        }

        if (escolha == 3) {
            std::cout << "Tchauzinho!\n";
            return 0;
        }







        }







    return 0;

}












