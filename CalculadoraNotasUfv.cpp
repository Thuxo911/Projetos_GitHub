#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>



struct Aluno { 

    std::string nome;
    int matricula;
    int faltas;
    float arrayNotas[3];
    double media;
    enum Situacao {Aprovado, ReprovadoNota, ReprovadoFalta};
    Situacao StatusFinal;

};


int main () {

    bool checagem = true;
    std::vector<Aluno> listaAlunos{};

    //dentro do <> esta o TIPO DE DADO que eu quero guardar dentro do vector
    // se fosse um vector de notas, seria std::vector<int>


    
        int notasLancadas;
        int notasPendentes;
        int escolhaMenu;



    while (checagem) {

        auto agora = std::chrono::system_clock::now();
        std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
        std::tm* tempo_local = std::localtime(&tempoAtual);

        int dia = tempo_local->tm_mday;
        int mes = tempo_local->tm_mon + 1;
        int ano = tempo_local->tm_year + 1900;
        int hora = tempo_local->tm_hour;
        int minuto = tempo_local->tm_min;
        int segundo = tempo_local->tm_sec;



        std::cout << "============================================\n";
        std::cout << "     SISTEMA DE CALCULO DE NOTAS - UFV     \n";
        std::cout << "============================================\n";
        std::cout << std::endl;

        std::cout << "Acesso em: " << dia << "/" << mes << "/" << ano << std::endl;
        std::cout << "Hora: " << hora << ":" << minuto << ":" << segundo << std::endl;
        std::cout << std::endl;

        std::cout << "Alunos matriculados: " << listaAlunos.size() << std::endl;
        std::cout << "Notas lancadas: " << notasLancadas << std::endl;
        std::cout << "Notas pendentes: " << notasPendentes << std::endl;
        std::cout << std::endl;

        std::cout << "[1] Adicionar aluno\n";
        std::cout << "[2] Inserir notas de um aluno\n";
        std::cout << "[3] Calcular media e situacao\n";
        std::cout << "[4] Relatorio geral\n";
        std::cout << "[5] Creditos\n";
        std::cout << "[6] Sair\n";
        std::cout << std::endl;
        std::cout << "Digite a opcao desejada: ";
        std::cin >> escolhaMenu;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (escolhaMenu > 6 || escolhaMenu < 1) {
            std::cout << std::endl;
            std::cout << "Escolha errada! Insira um numero valido\n";
            std::cout << std:: endl;
            continue;
        }


        if (escolhaMenu == 1) {

            Aluno novoAluno;

            std::cout <<"Professor, digite as informacoes do seu aluno\n";
            



        }








        if (escolhaMenu == 5) {
            std::cout << std::endl; 
            std::cout << "Desenvolvido por Marco Thullyo Sao Severino. Obrigado por logar! <3\n";
            std::cout << std::endl;

        }

        if (escolhaMenu == 6) {
            std::cout << std::endl; 
            std::cout << "Adeus, professor!\n";
            std::cout << std::endl;
            return 0;
        }



    }






    return 0;
}








