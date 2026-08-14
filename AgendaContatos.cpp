#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>


struct Contato {

    std::string nome;
    std::string telefone;
    std::string email;
    std::string cidade;
    int id;
    bool favorito;


};


int main () {



    //OFSTREAM - SALVAR DADOS PARA NAO PERDER MAIS
    //IFSTREAM - CARREGAR/RECUPERAR/LER DADOS JA SALVOS
    //logo, usamos ofstream na saida e ifstream na entrada

    bool checagem = true;
    bool checagem1 = true;
    bool checagem2 = true;
    int opcaoMenu;
    char escolha1;
    char escolha2;
    std::string nomeProcurado;
    int idProcurado;

    std::string aSerEditado;

    
    std::vector<Contato> listaContatos{};

    /*

    std::ifstream ArquivoContatoLeitura("contatos.txt");

    if (ArquivoContatoLeitura.is_open()) {

            

        for(int i = 0; i < listaContatos.size(); i++) {
            listaContatos[i].push_back(contatoTemp);
        }
    }

    ArquivoContatoLeitura.close();
    //sEMPRE FECHA O ARQUIVO DE LEITURA ANTES DE ABRIR O DE ESCRITA!! E TEM QUE TER NOMES DIFERENTES

     ArquivoContato << "Contato numero: " << listaContatos.size() << std::endl;
            ArquivoContato << novoContato.nome;
            ArquivoContato << std::endl;
            ArquivoContato << novoContato.telefone;
            ArquivoContato << std::endl;
            ArquivoContato << novoContato.email;
            ArquivoContato << std::endl;
            ArquivoContato << novoContato.cidade;
            ArquivoContato << std::endl;
            ArquivoContato << novoContato.id;
            ArquivoContato << std::endl;

            ArquivoContato.close();


    std::ofstream ArquivoContato("contatos.txt");

    */


    while (checagem) {



        //DETALHE SUPER IMPORTANTE QUE EU DESCOBRI
        //DURANTE TODO O MOMENTO EM QUE O USUARIO ESTIVER NO MENU, DIGITANDO, FAZENDO ACOES,
        //NAO MEXEMOS NO IFSTREAM OU OFSTREAM
        //OFSTREAM E IFSTREAM SAO USADOS APENAS QUANDO O PROGRAMA EH ABERTO E FECHADO
        //POR ISSO, TODOS OS CONTATOS SAO SALVOS APENAS NO VECTOR, OU SEJA, APENAS NA MEMORIA RAM
        //NA HORA DE SAIR/ENTRAR QUE TEMOS QUE SALVA-LO OU RECUPERA-LO DO DISCO 
        //isso eh feito tambem pela facilidade, imagine que voce queira apagar o contato 5, por exemplo,
        //o problema eh que apagar algo num arquivo de texto usando ofstream/ifstream da uma dor de cabeca gigantesca
        //eh muito mais facil resolver isso na memoria ram

        std::cout << "============================================\n";
        std::cout << "         AGENDA DE CONTATOS - MENU         \n";
        std::cout << "============================================\n";
        std::cout << "\n";
        std::cout << "  [1] - Adicionar novo contato\n";
        std::cout << "  [2] - Listar todos os contatos\n";
        std::cout << "  [3] - Buscar contato por nome\n";
        std::cout << "  [4] - Buscar contato por id\n";
        std::cout << "  [5] - Editar um contato\n";
        std::cout << "  [6] - Remover um contato\n";
        std::cout << "  [7] - Ordenar contatos\n";
        std::cout << " [8] - Mostrar total de contatos\n";
        std::cout << " [9] - Limpar toda a agenda\n";
        std::cout << " [10] - Marcar/desmarcar favoritos\n";
        std::cout << " [11] - Mostrar contatos favoritos\n";
        std::cout << "\n";
        std::cout << "  [12] - Creditos\n";
        std::cout << "  [13] - Sair da agenda\n";
        std::cout << "\n";
        std::cout << "============================================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoMenu;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (opcaoMenu < 1 || opcaoMenu > 13) {
            std::cout << std::endl;
            std::cout << "Opcao errada. Por favor, escolha um numero entre 1 e 12\n";
            std::cout << std::endl;
            continue;
        }

        if (opcaoMenu == 1) {

            while (checagem1) {

            Contato novoContato;
            
            std::cout << std::endl;
            std::cout << "Por favor, insira os dados dos seu contato\n";
            std::cout << "Nome: ";
            std::cin >> novoContato.nome;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            std::cout << "Telefone: ";
            std::cin >> novoContato.telefone;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            std::cout << "E-mail: ";
            std::cin >> novoContato.email;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            std::cout << "Cidade: ";
            std::cin >> novoContato.cidade;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            std::cout << "ID: ";
            std::cin >> novoContato.id;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            novoContato.favorito = false;
            listaContatos.push_back(novoContato);


            std::cout << std::endl;
            std::cout << "Deseja adicionar mais contatos? Y/N\n";
            std::cin >> escolha1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (escolha1 == 'Y' || escolha1 == 'y') {
                continue;
            }

            else break;

            }



        }

        if (opcaoMenu == 2) {

            while(checagem2) {

            std::cout << std::endl;

            for (int i = 0; i < listaContatos.size(); i++) {

                std::cout << "Contato " << i+1 << std::endl;
                std::cout << "Nome: " << listaContatos[i].nome << std::endl;
                std::cout << "Telefone: " << listaContatos[i].telefone << std::endl;
                std::cout << "Email: " << listaContatos[i].email << std::endl;
                std::cout << "Cidade: " << listaContatos[i].cidade << std::endl;
                std::cout << "ID: " << listaContatos[i].id << std::endl;
                std::cout << std::endl;

            }

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Digite M para voltar ao menu\n";
            std::cin >> escolha2;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (escolha1 == 'M' || escolha1 == 'm') {
                break;
            }

            else continue;

            }

        }


        

        if (opcaoMenu == 3) {


            std::cout << std::endl;
            std::cout << "Digite o nome do contato: \n";
            std::cin >> nomeProcurado;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            bool achou = false;
            //essa flag eh super importante e aparece em varios trabalhos meus
            //explicacao: fazemos um for para procurar a pessoa. depois que procuramos, damos um break
            //para sair desse for, pois nao eh mais necessario procurar
            //mas e se nao achou?? entao DEPOIS do for, precisaria ter uma mensagem alertando que nao achou
            //o problema eh que o break sai do for e a mensagem de que nao foi achado seria impressa sempre
            //com essa flag, garantimos que a mensagem sera impressa apenas se ela continuar false, ou seja, se nao achar

            for(int i = 0; i < listaContatos.size(); i++) {
                if (nomeProcurado == listaContatos[i].nome) {

                    std::cout << "Achamos o seu contato! Seu perfil completo esta exibido abaixo:\n";
                    std::cout << std::endl;
                    std::cout << "Contato " << i+1 << std::endl;
                    std::cout << "Nome: " << listaContatos[i].nome << std::endl;
                    std::cout << "Telefone: " << listaContatos[i].telefone << std::endl;
                    std::cout << "Email: " << listaContatos[i].email << std::endl;
                    std::cout << "Cidade: " << listaContatos[i].cidade << std::endl;
                    std::cout << "ID: " << listaContatos[i].id << std::endl;
                    achou = true;
                    break;
                }
            }

                if(!achou) {
                    std::cout << std::endl;
                    std::cout << "Infelizmente, seu contato nao foi encontrado\n";
                    std::cout << std::endl;
                    continue;
                }
        }

        if (opcaoMenu == 4) {


            std::cout << std::endl;
            std::cout << "Digite o ID do contato: \n";
            std::cin >> idProcurado;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            bool achou = false;
            //essa flag eh super importante e aparece em varios trabalhos meus
            //explicacao: fazemos um for para procurar a pessoa. depois que procuramos, damos um break
            //para sair desse for, pois nao eh mais necessario procurar
            //mas e se nao achou?? entao DEPOIS do for, precisaria ter uma mensagem alertando que nao achou
            //o problema eh que o break sai do for e a mensagem de que nao foi achado seria impressa sempre
            //com essa flag, garantimos que a mensagem sera impressa apenas se ela continuar false, ou seja, se nao achar

            for(int i = 0; i < listaContatos.size(); i++) {
                if (idProcurado == listaContatos[i].id) {

                    std::cout << "Achamos o seu ID! Seu perfil completo esta exibido abaixo:\n";
                    std::cout << std::endl;
                    std::cout << "Contato " << i+1 << std::endl;
                    std::cout << "Nome: " << listaContatos[i].nome << std::endl;
                    std::cout << "Telefone: " << listaContatos[i].telefone << std::endl;
                    std::cout << "Email: " << listaContatos[i].email << std::endl;
                    std::cout << "Cidade: " << listaContatos[i].cidade << std::endl;
                    std::cout << "ID: " << listaContatos[i].id << std::endl;
                    achou = true;
                    break;
                }
            }

                if(!achou) {
                    std::cout << std::endl;
                    std::cout << "Infelizmente, seu ID nao foi encontrado\n";
                    std::cout << std::endl;
                    continue;
                }


            
        }

        if (opcaoMenu == 5) { //editar contato


            std::cout << std::endl;
            std::cout << "Informe qual contato voce quer editar digitando o nome OU id\n";
            std::cin >> aSerEditado;

            for(int i = 0; i < listaContatos.size(); i++) {
                
                //std::to_string CONVERTE O INT EM STRING. MAS APENAS TEMPORARIAMENTE
                //se o usuario digitou INT, ele tem que converter em ID EM STRING PARA COMPARAR COM A RESPOSTA DO USUARIO.
                //"Converter" entre aspas, pois nao precisamos reconverter - aqui esta sendo usado para comparacao
                //e portanto eh so uma copia

                if(aSerEditado == listaContatos[i].nome || aSerEditado == std::to_string(listaContatos[i].id)) {
                    
                    std::cout << std::endl;
                    std::cout << "Por favor, insira os dados dos seu contato\n";
                    std::cout << std::endl;
                    std::cout << "Contato: " << i + 1 << std::endl;
                    std::cout << "Nome: ";
                    std::cin >> listaContatos[i].nome;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                    std::cout << "Telefone: ";
                    std::cin >> listaContatos[i].telefone;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                    std::cout << "E-mail: ";
                    std::cin >> listaContatos[i].email;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                    std::cout << "Cidade: ";
                    std::cin >> listaContatos[i].cidade;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


                    std::cout << "ID: ";
                    std::cin >> listaContatos[i].id;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    std::cout << std::endl;
                    std::cout << "Contato " << i + 1 << " editado com sucesso!!!\n";
                    std::cout << std::endl;
    

                }


            }
            
        }

        if (opcaoMenu == 6) {

            





            
        }

        if (opcaoMenu == 7) {
            
        }

        if (opcaoMenu == 8) {
            
        }

        if (opcaoMenu == 9) {
            
        }

        if (opcaoMenu == 10) {
            
        }

        if (opcaoMenu == 11) {
            
        }


        if (opcaoMenu == 12) {

            std::cout << std::endl;
            std::cout << "Feito por Marco Thullyo Sao Severino!! Obrigado por logar <3\n";
            std::cout << std::endl;

        }


        if (opcaoMenu == 13) {

            std::cout << std::endl;
            std::cout << "Adeus!\n";
            std::cout << std::endl;
            return 0;

        }
    








    }



    return 0;



}

 














