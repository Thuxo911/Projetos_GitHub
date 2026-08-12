#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

    static std::string palavras4[391] = {
            "amor", "casa", "vida", "flor", "gato", "vaca", "pato", "lobo", "urso", "alho",
            "muro", "teto", "mesa", "lata", "fita", "nave", "pote", "faca", "cama", "selo",
            "sopa", "doce", "bolo", "fogo", "neve", "frio", "hora", "jogo", "bola", "time",
            "tatu", "onda", "pipa", "nuca", "mico", "hino", "gelo", "feno", "dedo",
            "iodo", "cubo", "bico", "zelo", "vaso", "tapa", "sino", "rede", "piso", "moda",
            "lado", "pino", "fato", "mito", "caos", "sapo", "puma", "rubi", "neto", "toco", "siri", "urro", "mate",
            "jacu", "gomo", "lula", "luau", "faro", "juba", "paca", "urna", "fofo", "pano", "duna",
            "lima", "cana", "nove", "sebo", "maio", "unha", "kiwi", "mola", "favo", "reta", "rolo", 
            "bota", "gole", "ruga", "caco", "bule", "ralo", "furo", "sova", "isca", "duro", "guru", "menu",
            "fumo", "gala", "lava", "tira", "foca", "luva", "saco", "muco", "saci", "anta", "vala", "peru",
            "moto", "poro", "mofo", "bote", "siso", "fole", "loja", "cuia", "gajo", "fino", "galo", "czar", 
            "fada", "zero", "seis", "ator", "feto", "erva", "arma", "cera", "arco", "oito", "tufo", "mina", "lago",
            "gene", "mato", "mata", "veia", "fulo", "ocre", "naco", "bala", "cria", "sete", "roxo", "xixi",
            "tara", "papo", "gaze", "beco", "doze", "toga", "agro", "bula", "cruz", "seda", "teia", "musa",
            "colo", "luar", "oral", "veto", "data", "coxa", "caju", "vivo", "pomo", "diva", "urbe", "luso",
            "mago", "mapa", "vago", "raio", "proa", "osso", "mana", "roca", "rosa", "acre", "rasa", "anjo",
            "copa", "cura", "ceia", "novo", "ogro", "cima", "dono", "nora", "sono", "ouro", "seta", "cujo",
            "cabo", "bofe", "cego", "cepo", "luxo", "dose", "meia", "tupi", "meio", "gafe", "gado", "ateu", "olho",
            "vaga", "limo", "odor", "anel", "ramo", "tomo", "falo", "topo", "eixo", "peso", "coro", "sebe", 
            "joio", "nego", "pneu", "cara", "asno", "cena", "sexy", "raro", "cume", "ledo", "aval", "trem", "taxa",
            "grau", "rola", "puro", "leal", "mero", "nato", "real", "alfa", "dolo", "beta", "dote", "tipo", "luta", "hera",
            "nome", "pena", "azul", "nexo", "orla", "nada", "tese", "pose", "face", "alvo", "foco", "cela", "rima", "cedo",
            "arte", "ente", "alma", "deus", "cota", "apto", "mote", "auge", "sina", "brio", 
            "alto", "atum", "azar", "azia", "base", "bela", "belo", "bile", "boca", "boda",
            "bode", "boia", "boto", "breu", "cala", "capa", "coco", "copo", "dado", "dama",
            "dano", "dias", "dica", "dito", "dona", "ecos", "elmo", "elos", "erro", "fala",
            "fava", "feio", "figa", "figo", "fila", "fome", "gago", "gata", "gema", "gira",
            "giro", "gola", "goma", "gota", "gozo", "guia", "gula", "iate", "ilha", "ioga",
            "item", "jaca", "jato", "jeca", "jipe", "joia", "jota", "juiz", "jura", "juta",
            "laje", "lama", "leoa", "leva", "leve", "lixo", "loba", "lona", "lota", "luto",
            "mala", "medo", "mula", "nabo", "nado", "neta", "nojo", "nota", "nova", "nulo",
            "obra", "pele", "pelo", "pera", "polo", "povo", "quiz", "rata", "rato", "reis",
            "remo", "reza", "riso", "roda", "rodo", "rude", "sala", "sapa", "sede", "sela",
            "soja", "sola", "solo", "soma", "tela", "toca", "tubo", "uivo", "unto", "vale",
            "vaza", "veio", "vela", "viga", "vila", "voto", "xale", "xepa", "zaga", "zebu",
            "zika", "zona" 
        };

    static std::string palavras5[] = {

    };

    static std::string palavras6[] = {

    };

    static std::string palavras7[] = {

    };

    static std::string palavras8[] = {

    };

    static std::string palavras9[] = {

    };

    static std::string palavras10[] = {

    };


std::string sortear(int x) {


    switch(x) {
        case 4: {
        return palavras4[rand() % 391]; 
        //rand()% N = numero aleatorio entre 0 e N-1
    }

        case 5: {

        }

        case 6: {

        }

        case 7: {

        }
        
        case 8: {

        }

        case 9: {

        }

        case 10: {


        }


    }



}






int main() {

    srand(time(0)); //para a escolha de uma palavra aleatoria nas listas 
    int vidas;
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

            int escolhaTamanho;
            std::string palavraSorteada;

            std::cout << "Qual o tamanho da palavra? Min: 4, Max: 10\n."; 
            std::cout << "Apenas substantivos e adjetivos sem acentos\n";
            std::cout << "Regra: digite as letras em letra MINUSCULA\n";
            std::cin >> escolhaTamanho;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        

            switch (escolhaTamanho) {
                case 4: {

                    palavraSorteada = sortear(4);

                    vidas = 7;

                break;
                }

                case 5: {

                    palavraSorteada = sortear(5);

                    vidas = 7;


                break;
                }

                case 6: {

                    palavraSorteada = sortear(6);

                    vidas = 6;

                break;
                }

                case 7: {

                    palavraSorteada = sortear(7);

                    vidas = 6;

                break;
                }

                case 8: {

                    palavraSorteada = sortear(8);

                    vidas = 6;

                break;
                }

                case 9: {

                    palavraSorteada = sortear(9);
                    vidas = 5;

                break;
                }

                case 10: {

                    palavraSorteada = sortear(10);

                    vidas = 5;

                break;
                }

                default: { //numero maior que 10 e menor que 4

                std::cout << std::endl;
                std::cout << "Tamanho errado! O numero pode ir de 4 A 10!\n";
                std::cout << std::endl;
                continue; // pula para o proximo iterador de while(checagem)

                }
            
            }       










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












