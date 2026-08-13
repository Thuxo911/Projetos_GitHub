#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <chrono>
#include <vector>


    struct Aluno {

        std::string nome;
        int senha;
        int numeroPedidos;
        double saldo;
        bool pcd;

    };


int main () {

    bool checagem = true;
    bool filaPausada = false;

        auto agora = std::chrono::system_clock::now();
        std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
        std::tm* tempo_local = std::localtime(&tempoAtual);

        int dia = tempo_local->tm_mday;
        int mes = tempo_local->tm_mon + 1;
        int ano = tempo_local->tm_year + 1900;
        int hora = tempo_local->tm_hour;
        int minuto = tempo_local->tm_min;
        int segundo = tempo_local->tm_sec;



        int tempoMedio = 0;
        int senhaAtual = 0;
        int ultimaSenha = 0;
        int proximaSenha = 0;
        int opcaoMenu = 0;
        

        char respostaPCD;

        std::vector<Aluno> filaRU{};


    while (checagem) {

        std::cout << "===========================================\n";
        std::cout << "SISTEMA DE FILA - RESTAURANTE UNIVERSITARIO\n";
        std::cout <<      "Universidade Federal de Vicosa\n";
        std::cout <<"============================================\n";

        std::cout << std::endl;
        std::cout << "Bem-vindo, atendente! Chegou a hora do almoco, e bem... os alunos estao com fome!\n";
        std::cout << "Cadastre os estudantes, atenda-os e gerencia a fila! Boa sorte\n";
        std::cout << "Hora: " << hora << ":" << minuto << ":" << segundo << std::endl;
        std::cout << std::endl;

        std::cout <<"============================================\n";
        std::cout << "Tempo medio de espera da fila: " << tempoMedio << std::endl;
        std::cout << "Senha atual: " << senhaAtual << std::endl;
        std::cout << "Proxima senha: " << ultimaSenha << std::endl;
        std::cout << "Ultima senha: " << proximaSenha << std::endl;
        std::cout <<"============================================\n";
        std::cout << std::endl;


        std::cout << "[1] Chegar aluno na fila\n";
        std::cout << "[2] Atender aluno da fila\n";
        std::cout << "[3] Ver quem eh o proximo da fila\n";
        std::cout << "[4] Tamanho total da fila\n";
        std::cout << "[5] Pausar fila\n";
        std::cout << "[6] Retomar fila\n";
        std::cout << "[7] Relatorio do dia\n";
        std::cout << "[8] Mandar toda fila embora\n";
        std::cout << "[9] Expulsar um aluno especifico\n";

        std::cout << "[10] Creditos\n";
        std::cout << "[11] Sair\n";
        std::cout << std::endl;

        std::cout << "Digite a sua opcao: ";
        std::cin >> opcaoMenu;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        

        if (opcaoMenu < 1 || opcaoMenu > 11) {
            std::cout << std::endl;
            std::cout << "Opcao errada! Tente novamente!";
            std::cout << std::endl;
        }

        if (opcaoMenu == 1) {

            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }



            Aluno novoAluno;

            std::cout << std::endl;
            std::cout << "Um aluno chegou! Hora de cadastrá-lo!\n";

            std::cout << "Nome do aluno: ";
            std::cin >> novoAluno.nome;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Senha do aluno: ";
            std::cin >> novoAluno.senha;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Numero de pedidos: ";
            std::cin >> novoAluno.numeroPedidos;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (novoAluno.numeroPedidos <= 0) {
                std::cout << std::endl;
                std::cout << "Um aluno nao pode entrar no RU sem ter pedidos! Voce disse isso e ele foi embora.\n";
                std::cout << std::endl;
                continue;
            }


            std::cout << "Saldo: ";
            std::cin >> novoAluno.saldo;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            if (novoAluno.saldo <= 0) {
                std::cout << std::endl;
                std::cout << "Um aluno nao pode entrar no RU sem ter saldo! Voce disse isso e ele foi embora.\n";
                std::cout << std::endl;
                continue;
            }


            bool checagemVoltarRespostaPCD = true;

            while (checagemVoltarRespostaPCD) {

            std::cout << "O aluno eh PCD? (S ou N): ";
            std::cin >> respostaPCD;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (respostaPCD != 'n' && respostaPCD != 'N' && respostaPCD != 'S' && respostaPCD != 's') {
                std::cout << "Voce digitou errado! Tente novamente.\n";
                continue;
            }
            
            else if (respostaPCD == 'N' || respostaPCD == 'n') {
                novoAluno.pcd = false;
                checagemVoltarRespostaPCD = false;
            }

            else { 
                novoAluno.pcd = true;
                checagemVoltarRespostaPCD = false;
            }

        }


        //o pcd tem prioridade. no entanto, um pcd que chega primeiro tem prioridade
        //ex: uma fila (as letras p sao alunos pcd)
        //a b c p1 e p3 f p2. entao vai
        //p1 a b c e p3 f p2
        //p1 p3 a b c e f p2 //entao tem que procurar O PRIMEIRO ALUNO QUE NAO SEJA PCD PARA COLOCAR O PCD DPS DELE
        //p1 p3 p2 a b c e f



        if(novoAluno.pcd) {
            
        bool inserido = false;

        std::cout << std::endl;
        std::cout << "Ops! Parece que encontramos aluno(s) PCD pela fila. Movendo eles para frente...\n";
        std::cout << std::endl;

          for (int i = 0; i < filaRU.size(); i++) {
                if(filaRU[i].pcd == false) {
                    filaRU.insert(filaRU.begin() + i, novoAluno);
                    inserido = true;
                    break;
                }

            }


            if (!inserido) {
                filaRU.push_back(novoAluno);

            }

        }


            else filaRU.push_back(novoAluno);



        }
    

        if (opcaoMenu == 2) {

            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }

            int contagem = filaRU.size();


            if (filaRU.size() == 0) {

                std::cout << std::endl;
                std::cout << "A fila esta vazia! Nao ha ninguem para atender!\n";
                std::cout << std::endl;
                continue;

            }
            
    
            std::cout << "Voce esta atendendo o primeiro aluno da fila!\n";
            std::cout << "Bem-vindo(a), " << filaRU[0].nome << " e tenha um bom almoco!" << std::endl;

            std::cout << filaRU[0].nome << " entra restaurante adentro.";


            filaRU.erase(filaRU.begin());  
            contagem--;

            if (contagem == 0) {
                std::cout << std::endl;
                std::cout << "A fila ficou vazia!\n";
                std::cout << std::endl;
                break;

        }

        std::cout << "Ainda ha mais pessoas para atender!\n";



        }

        

        if (opcaoMenu == 3) {

            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }


            if(filaRU.size() == 0) {
                std::cout << std::endl;
                std::cout << "A fila esta vazia! Nao ha ninguem para atender!\n";
                std::cout << std::endl;
                continue;
            }

            std::cout << std::endl;
            std::cout << "Dados do proximo da fila\n";
            std::cout << "Nome: " << filaRU[0].nome << std::endl;
            std::cout << "Senha: " << filaRU[0].senha << std::endl;
            std::cout << "Numero de pedidos: " << filaRU[0].numeroPedidos << std::endl;
            std::cout << "Saldo: " << filaRU[0].saldo << std::endl;
            std::cout << "PCD?: ";

            if (filaRU[0].pcd) {
                std::cout << "Sim\n";
            }
            else std::cout << "Nao\n";

        }


        if (opcaoMenu == 4) {

            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }

            std::cout << std::endl;
            std::cout << "Atualmente, a fila tem " << filaRU.size() << " alunos.\n";
            std::cout << std::endl;

        }


        if (opcaoMenu == 5) {

            filaPausada = true;

            std::cout << std::endl;
            std::cout << "Voce decide fazer uma pausa do seu servico. A fila esta pausada. Para retomar seu trabalho, selecione a opcao 6.\n";
            std::cout << std::endl;

        }

        if (opcaoMenu == 6) {

            filaPausada = false;

            std::cout << std::endl;
            std::cout << "O descanso acabou. A fila esta pronta para funcionar normalmente.\n";
            std::cout << std::endl;

        }

        if (opcaoMenu == 7) {

            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }

        std::cout << "=======================\n";
        std::cout << "RELATORIO DE TRABALHO\n";
        std::cout << "Universidade Federal de Vicosa\n";
        std::cout <<"========================\n";
        std::cout << std::endl;

        std::cout << 







        }

        if (opcaoMenu == 8) {


            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }


        }

        if (opcaoMenu == 9) {


            if(filaPausada) {
                std::cout << std::endl;
                std::cout << "Voce esta descansando. Nao pode trabalhar.";
                std::cout << std::endl;
            }

            

            
        }



        if (opcaoMenu == 10) {

            std::cout << std::endl;
            std::cout << "Feito por Marco Thullyo Sao Severino. Obrigado por logar <3 \n";
            std::cout << std::endl;

        }


        if (opcaoMenu == 11) {
            std::cout << std::endl;
            std::cout << "Adeus! Que bom servico voce nos prestou hoje!\n";
            return 0;
        }





    }







    return 0;


}










