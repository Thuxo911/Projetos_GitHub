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

        auto agora = std::chrono::system_clock::now();
        std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
        std::tm* tempo_local = std::localtime(&tempoAtual);

        int dia = tempo_local->tm_mday;
        int mes = tempo_local->tm_mon + 1;
        int ano = tempo_local->tm_year + 1900;
        int hora = tempo_local->tm_hour;
        int minuto = tempo_local->tm_min;
        int segundo = tempo_local->tm_sec;



        int tempoMedio;
        int senhaAtual;
        int ultimaSenha;
        int proximaSenha;
        int opcaoMenu;

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
        std::cout << "Tempo media de espera da fila: " << tempoMedio << std::endl;
        std::cout << "Senha atual: " << senhaAtual << std::endl;
        std::cout << "Proxima senha: " << ultimaSenha << std::endl;
        std::cout << "Ultima senha: " << proximaSenha << std::endl;
        std::cout <<"============================================\n";
        std::cout << std::endl;


        std::cout << "Digite a sua opcao: " << opcaoMenu;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "[1] Cadastar aluno da fila\n";
        std::cout << "[2] Atender aluno da fila\n";
        std::cout << "[3] Ver quem eh o proximo da fila\n";
        std::cout << "[4] Tamanho total da fila\n";
        std::cout << "[5] Pausar fila\n";
        std::cout << "[6] Retomar fila\n";
        std::cout << "[7] Relatorio do dia\n";

        std::cout << "[8] Creditos\n";
        std::cout << "[9] Sair\n";
        

        if (opcaoMenu < 1 || opcaoMenu > 9) {
            std::cout << std::endl;
            std::cout << "Opcao errada! Tente novamente!";
            std::cout << std::endl;
        }

        if (opcaoMenu == 1) {




        }



        if (opcaoMenu == 8) {

            std::cout << std::endl;
            std::cout << "Feito por Marco Thullyo Sao Severino. Obrigado por logar <3 \n";
            std::cout << std::endl;

        }


        if (opcaoMenu == 9) {
            std::cout << std::endl;
            std::cout << "Adeus! Que bom servico voce nos prestou hoje!\n";
            return 0;
        }





    }







    return 0;


}












