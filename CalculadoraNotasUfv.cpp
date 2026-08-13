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


    
        int notasLancadas = 0;
        int notasPendentes = 0;



    while (checagem) {

        char escolhaOpcao1 = true;
        char escolhaOpcao3 = true;

        auto agora = std::chrono::system_clock::now();
        std::time_t tempoAtual = std::chrono::system_clock::to_time_t(agora);
        std::tm* tempo_local = std::localtime(&tempoAtual);

        int dia = tempo_local->tm_mday;
        int mes = tempo_local->tm_mon + 1;
        int ano = tempo_local->tm_year + 1900;
        int hora = tempo_local->tm_hour;
        int minuto = tempo_local->tm_min;
        int segundo = tempo_local->tm_sec;

        int escolhaMenu;


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

            bool escolhaAcrescentarNovoAluno = true;
            bool checagemOpcao1 = true;

             while (checagemOpcao1) {

            for (int i = 0; i < 3; i++) {
                novoAluno.arrayNotas[i] = -1.0;
            }

            std::cout <<"Professor, digite as informacoes do seu aluno\n";
            std::cout << std::endl;
            std::cout << "Nome do aluno: ";
            std::getline(std::cin, novoAluno.nome);

            std::cout << "Matricula: ";
            std::cin >> novoAluno.matricula;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Numero de faltas: ";
            std::cin >> novoAluno.faltas;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            listaAlunos.push_back(novoAluno);
            //para funcoes de estruturas de dados, primeiro se coloca O NOME DO SEU VETOR, depois a FUNCAO DELE,
            //depois, O QUE VOCE QUER COLOCAR.

            while (escolhaAcrescentarNovoAluno) {

            std::cout << std::endl;
            std::cout << "Professor, voce gostaria de adicionar mais um aluno? S/N\n";
            std::cin >> escolhaOpcao1;
            std::cout << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if (escolhaOpcao1 != 'N' && escolhaOpcao1 != 'n' &&
            escolhaOpcao1 != 'S' && escolhaOpcao1 != 's') {
                continue;
            }

            if (escolhaOpcao1 == 'N' || escolhaOpcao1 == 'n') {
                escolhaAcrescentarNovoAluno = false;
                checagemOpcao1 = false;
                break;
            }    

            if(escolhaOpcao1 == 'S' || escolhaOpcao1 == 's') {
                break;
            }


        }

    }
}


        if (escolhaMenu == 2) {

            if(listaAlunos.size() == 0) {
                std::cout << "Nenhum aluno cadastrado ainda!\n";
                std::cout << std::endl;
                continue;
            }

            int matriculaDigitada;


            std::cout << std::endl;
            std::cout << "Professor, lance as notas das 3 provas que cada aluno realizou\n" << std::endl;
            std::cout << std::endl;
            std::cout << "Digite a matricula do aluno: \n";
            std::cin >> matriculaDigitada;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            bool encontrou = false;

            for (int i = 0; i < listaAlunos.size(); i++) {
            
                if (matriculaDigitada == listaAlunos[i].matricula) {
                    std::cout << "Matricula encontrada!\n";
                    std::cout << "Digite as notas das provas!\n";

                    std::cout << "P1: ";
                    std::cin >> listaAlunos[i].arrayNotas[0];
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::cout << "P2: ";
                    std::cin >> listaAlunos[i].arrayNotas[1];
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::cout << "P3: ";
                    std::cin >> listaAlunos[i].arrayNotas[2];
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    encontrou = true;
                    break;
                }
                

            }

            if(!encontrou) {
                std::cout << "Matricula nao cadastrada no sistema!\n";
            }

        }

        std::cout << std::endl;

        if (escolhaMenu == 3) {

            bool escolhaVerMais = true;
            bool checagemOpcao3 = true;


            while (checagemOpcao3) {

            int matriculaDigitada3;
            int variavelQueGuardaNumeroAluno;
            int escolhaVolta3;

            if(listaAlunos.size() == 0) {
                std::cout << "Nenhum aluno cadastrado ainda!\n";
                std::cout << std::endl;
                continue;
            }


            std::cout << "Digite a matricula do aluno para saber sua media e situacao atual\n";
            std::cin >> matriculaDigitada3;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            bool encontrou3 = false;

            for (int i = 0; i < listaAlunos.size(); i++) {
                if(matriculaDigitada3 == listaAlunos[i].matricula) {
                std::cout << "Matricula encontrada!\n";
                variavelQueGuardaNumeroAluno = i;
                encontrou3 = true;
                break;
                }

            }


            if (!encontrou3) {
                std::cout << "Matricula nao encontrada!\n";
                std::cout << std::endl;
                continue;
            }


            std::cout << std::endl;

            listaAlunos[variavelQueGuardaNumeroAluno].media = (listaAlunos[variavelQueGuardaNumeroAluno].arrayNotas[0] +
            listaAlunos[variavelQueGuardaNumeroAluno].arrayNotas[1] + listaAlunos[variavelQueGuardaNumeroAluno].arrayNotas[2]) / 3.0;

            
            if(listaAlunos[variavelQueGuardaNumeroAluno].faltas < 15 && 
                listaAlunos[variavelQueGuardaNumeroAluno].media >=60 ) {
                    listaAlunos[variavelQueGuardaNumeroAluno].StatusFinal = Aluno::Aprovado;
                }

            else if (listaAlunos[variavelQueGuardaNumeroAluno].faltas >= 15) { 
                listaAlunos[variavelQueGuardaNumeroAluno].StatusFinal = Aluno::ReprovadoFalta;
            }

            else {
                listaAlunos[variavelQueGuardaNumeroAluno].StatusFinal = Aluno::ReprovadoNota;
            }

            std::cout << "A media do aluno eh: ";
            std::cout << listaAlunos[variavelQueGuardaNumeroAluno].media;
            std::cout << std::endl;


            std::cout << "A situacao do aluno eh: ";
            switch (listaAlunos[variavelQueGuardaNumeroAluno].StatusFinal) {

                case Aluno::Aprovado: {
                    std::cout << "Aluno aprovado!" << std::endl;
                break;
                }

                case Aluno::ReprovadoNota: {
                    std::cout << "Aluno reprovado por nota!" << std::endl;
                break;

                }

                case Aluno::ReprovadoFalta: {
                    std::cout << "Aluno reprovado por falta!" << std::endl;
                break;

                }


            }


            std::cout << std::endl;

            std::cout << "Professor, gostaria de voltar para o menu?\n";
            std::cin >> escolhaOpcao3;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if (escolhaOpcao3 != 'N' && escolhaOpcao3 != 'n' &&
            escolhaOpcao3 != 'S' && escolhaOpcao3 != 's') {
                continue;
            }

            if (escolhaOpcao3 == 'N' || escolhaOpcao3 == 'n') {
                escolhaVerMais = false;
                checagemOpcao3 = false;
                break;
            }    

            if(escolhaOpcao3 == 'S' || escolhaOpcao3 == 's') {
                break;
            }

        }


        }

        if (escolhaMenu == 4) {

            if(listaAlunos.size() == 0) {
                std::cout << "Nenhum aluno cadastrado ainda!\n";
                std::cout << std::endl;
                continue;
            }

            for (int i = 0; i < listaAlunos.size(); i++) {
                if (listaAlunos[i].arrayNotas[0] == -1.0
                && listaAlunos[i].arrayNotas[1] == -1.0
            && listaAlunos[i].arrayNotas[2] == -1.0)
                std::cout << "As notas ainda nao foram cadastradas!\n";
                continue;
            }


            for (int i = 0; i < listaAlunos.size(); i++) {

                std::cout << std::endl;

                std::cout << "Aluno nº " << i << std::endl;
                std::cout << "Nome: " << listaAlunos[i].nome << std::endl;
                std::cout << "Matricula: " << listaAlunos[i].matricula << std::endl;
                std::cout << "Faltas: " << listaAlunos[i].faltas << std::endl;
                std::cout << "Notas das 3 provas, em ordem: " << listaAlunos[i].arrayNotas[0] << " " << listaAlunos[i].arrayNotas[1] << " " << listaAlunos[i].arrayNotas[2] << std::endl;
                std::cout << "Media: " << listaAlunos[i].media << std::endl;
                std::cout << "Situacao: " << listaAlunos[i].StatusFinal << std::endl;

                std::cout << std::endl;

            }



            
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








