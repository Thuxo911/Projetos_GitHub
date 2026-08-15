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

//eu posso dar esse nome generico "lista" se eu tivesse varias listas
//ex: EstaVazio(listaContatos) e EstaVazio(listaBackup)
//ai nos parametros da funcao eu chamaria apenas de lista e funcionaria sempre para qualquer lista que eu colocasse
//aqui eu so tenho uma lista mas coloquei isso apenas para testar

//o & usa DIRETAMENTE o vetor original listaContatos

bool EstaVazio(const std::vector<Contato>& lista) {
    
    if(lista.size() == 0) {
        std::cout << std::endl;
        std::cout << "A lista de contatos esta vazia!\n";
        std::cout << std::endl;
        return true;
    } 

    else return false;


}


int main () {



    //OFSTREAM - SALVAR DADOS PARA NAO PERDER MAIS
    //IFSTREAM - CARREGAR/RECUPERAR/LER DADOS JA SALVOS
    //logo, usamos ofstream na saida e ifstream na entrada

    bool checagem = true;
    bool checagem1 = true;
    bool checagem2 = true;
    bool checagem7 = true;
    bool checagem9 = true;
    bool checagemFavorita = true;
    bool checagemDesfavorita = true;
    int opcaoMenu;
    char escolha1;
    char escolha2;
    char escolha9;
    std::string nomeProcurado;
    int idProcurado;
    int resposta10;
    char respostaFavorito;
    char respostaDesfavorito;

    std::string aSerEditado;
    std::string aSerApagado;
    std::string respostaQualOrdenar;
    std::string aSerFavoritado;
    std::string aSerDesfavoritado;

    
    std::vector<Contato> listaContatos{};

    std::ifstream ArquivoContatoLeitura("contatos.txt");

    if (ArquivoContatoLeitura.is_open()) {

         Contato contatoTemp;
         //criamos esse porque novoContato ainda nem existe... e melhor; usamos o contatoTemp
         //apenas para desempacotar as coisa do .txt para coloca-las no vetor

         //o arquivo tenta ler o nome. se falhar, quer dizer que o nome acabou, e consequentemente, nao ha mais nada a ler
        while(std::getline(ArquivoContatoLeitura, contatoTemp.nome, ';')) {

            //getline tem 3 parametros: o arquivo a ser lido, os dados, e o ponto de parada
        
        std::getline(ArquivoContatoLeitura, contatoTemp.telefone, ';');

        std::getline(ArquivoContatoLeitura, contatoTemp.email, ';');

        std::getline(ArquivoContatoLeitura, contatoTemp.cidade, ';');

        //getline so ta lendo string, mas ID e favorito estao em int e bool respectivamente. vamos converter
        //converter string para int e string para bool

        std::string stringTempId;
        std::getline(ArquivoContatoLeitura, stringTempId, ';');
        contatoTemp.id = std::stoi(stringTempId);


        std::string stringTempFavorito;
        std::getline(ArquivoContatoLeitura, stringTempFavorito);
        //essa eh a ultima informacao da linha, onde nao ha mais ';', entao ele deve procurar apenas pelo fim da linha

         if (stringTempFavorito == "1" || stringTempFavorito == "true") {
            contatoTemp.favorito = true;
        }

        else contatoTemp.favorito = false;

        listaContatos.push_back(contatoTemp);

    }

        
    
    }

    ArquivoContatoLeitura.close();


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
        std::cout << "  [8] - Numero total de contatos\n";
        std::cout << "  [9] - Limpar toda a agenda\n";
        std::cout << "  [10] - Marcar/desmarcar favoritos\n";
        std::cout << "  [11] - Mostrar contatos favoritos\n";
        std::cout << "\n";
        std::cout << "  [12] - Creditos\n";
        std::cout << "  [13] - Salvar e sair da agenda\n";
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
            std::getline(std::cin >> std::ws, novoContato.nome);
            //o cin normal para de capturar no primeiro espaco em branco. Ao inves de capturar Marco Thullyo, ele so captura marco
            //o getline captura tudo
            //std::ws limpa a sujeira do enter, porque toda vez que digitamos o enter eh como se ele ficasse "grudado" ali
            //ai nao precisa mais de clear ou ignore
   
            std::cout << "Telefone: ";
            std::getline(std::cin >> std::ws, novoContato.telefone);

            std::cout << "E-mail: ";
            std::getline(std::cin >> std::ws, novoContato.email);

            std::cout << "Cidade: ";
            std::getline(std::cin >> std::ws, novoContato.cidade);

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

            if(EstaVazio(listaContatos)) continue;
            
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

            if (escolha2 == 'M' || escolha2 == 'm') {
                break;
            }

            else continue;

            }

        }

        if (opcaoMenu == 3) {

            if(EstaVazio(listaContatos)) continue;


            std::cout << std::endl;
            std::cout << "Digite o nome do contato: \n";
            std::getline(std::cin >> std::ws, nomeProcurado);
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

            if(EstaVazio(listaContatos)) continue;


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

            if(EstaVazio(listaContatos)) continue;

            std::cout << std::endl;
            std::cout << "Informe qual contato voce quer editar digitando o nome OU id\n";
            std::getline(std::cin >> std::ws, aSerEditado);

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
                    std::getline(std::cin >> std::ws, listaContatos[i].nome);
    
                    std::cout << "Telefone: ";
                    std::getline(std::cin >> std::ws, listaContatos[i].telefone);

                    std::cout << "E-mail: ";
                    std::getline(std::cin >> std::ws, listaContatos[i].email);

                    std::cout << "Cidade: ";
                    std::getline(std::cin >> std::ws, listaContatos[i].cidade);

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

            if(EstaVazio(listaContatos)) continue;
            
            std::cout << std::endl;
            std::cout << "Qual contato voce gostaria de apagar? Digite o nome ou o ID\n";
            std::getline(std::cin >> std::ws, aSerApagado);
            std::cout << std::endl;

            bool apagado = false;

            for (int i = 0; i < listaContatos.size(); i++) {

                if(aSerApagado == listaContatos[i].nome || aSerApagado == std::to_string(listaContatos[i].id)) {
                    listaContatos.erase(listaContatos.begin() + i);
                    std::cout << "O contato " << i + 1 << " foi apagado\n";
                    std::cout << std::endl;
                    apagado = true;
                    break;

                }


            }

            if(!apagado) {
                std::cout << std::endl;
                std::cout << "O contato nao existe. Provavelmente voce digitou errado ou ele ja foi apagado.\n";
                std::cout << std::endl;
                continue;
            }



            
        }

        if (opcaoMenu == 7) {

            if(EstaVazio(listaContatos)) continue;

            while (checagem7) {

            std::cout << std::endl;
            std::cout << "Voce gostaria de ordenar os contatos seguindo qual criterio? Nome ou id?\n";
            std::cout << "Resposta: ";
            std::getline(std::cin >> std::ws, respostaQualOrdenar);

            if (respostaQualOrdenar == "nome" || respostaQualOrdenar == "Nome"
            || respostaQualOrdenar == "Nomes" || respostaQualOrdenar == "nomes") {


                //o for vai ate listaContatos.size() - 1 SEMPRE PARA NAO TER RISCO DE CRASHAR
                //pq se a lista tiver so um contato ela ja esta ordenada
                //se tem dois contatos ela so ordena uma vez e para ou nem ordena  

                //detalhe: nao pode ser apenas um for pq se nao ele so vai dar uma passada. faremos dois for
               for (int i = 0; i < listaContatos.size() - 1; i++) {
                    for(int j = 0; j < listaContatos.size() - i - 1; j++) {

                if(listaContatos[j].nome > listaContatos[j+1].nome) {

                    Contato contatotemp;
                    
                    //contatotemp eh um STRUCT
                    //listaContatos eh um VETOR
                    //listaContatos[i] eh um STRUCT
                    //podemos apenas igualar dois tipos de dados iguais
                    //aqui estamos igualando dois structs
                    contatotemp = listaContatos[j];
                    listaContatos[j] = listaContatos[j+1];
                    listaContatos[j+1] = contatotemp;

                }


               }
            }

            break;
            }


            else if (respostaQualOrdenar == "id" || respostaQualOrdenar == "ID" || 
            respostaQualOrdenar == "Id" || respostaQualOrdenar == "iD") {


                for (int i = 0; i < listaContatos.size() - 1; i++) {
                    for(int j = 0; j < listaContatos.size() - i - 1; j++) {
                        if(listaContatos[j].id > listaContatos[j+1].id) {
                        
                        Contato contato2temp;

                        contato2temp = listaContatos[j];
                        listaContatos[j] = listaContatos[j+1];
                        listaContatos[j+1] = contato2temp;

                        }


                    }

                }

                break;
            }


            else {

                std::cout << std::endl;
                std::cout << "Parece que voce digitou errado. Tente novamente\n";
                std::cout << std::endl;
                continue;

            }

        }

            
        }

        if (opcaoMenu == 8) {

            std::cout << std::endl;
            std::cout << "Ha um total de " << listaContatos.size() << " contatos na sua lista.\n";
            std::cout << std::endl;
            
        }

        if (opcaoMenu == 9) {

            if(EstaVazio(listaContatos)) continue;

            while (checagem9) {

            std::cout << "Essa decisao nao pode ser revertida. Voce tem certeza que quer fazer isso?\n";
            std::cout << "Digite Y ou N: \n";
            std::cin >> escolha9;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (escolha9 == 'Y' || escolha9 == 'y') {

                listaContatos.clear();

                std::cout << std::endl;
                std::cout << "A lista foi toda apagada!\n";
                std::cout << std::endl;
                break;
            }

            else break;

        }

            
        }

        if (opcaoMenu == 10) {

            if(EstaVazio(listaContatos)) continue;


            std::cout << std::endl;
            std::cout << "Voce gostaria de marcar ou desmarcar favoritos?\n";
            std::cout << "[1] Marcar\n";
            std::cout << "[2] Desmarcar\n";
            std::cin >> resposta10;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;

            if(resposta10 != 1 && resposta10 != 2) {
                std::cout << std::endl;
                std::cout << "Opcao errada\n";
                std::cout << std::endl;
                continue;
            }

            else if(resposta10 == 1) {

                while(checagemFavorita) {

                    int numeroFavoritos = 0;

                for(int i = 0; i < listaContatos.size(); i++) {

                    if(listaContatos[i].favorito) {
                        numeroFavoritos++;
                    }  

                }


                 if(numeroFavoritos == listaContatos.size()) {
                        std::cout <<std::endl;
                        std::cout << "Todos os contatos ja estao favoritados\n";
                        std::cout << std::endl;
                        break;
                    }

                        std::cout <<std::endl;
                        std::cout << "Qual contato voce gostaria de favoritar? Escolha pelo nome ou id: \n";
                        std::getline(std::cin >> std::ws, aSerFavoritado);
                        std::cout << std::endl;

                        bool achouFavorito = false;

                        for(int i = 0; i < listaContatos.size(); i++) {

                            if(aSerFavoritado == listaContatos[i].nome ||
                            aSerFavoritado == std::to_string(listaContatos[i].id)) {
                                listaContatos[i].favorito = true;
                                achouFavorito = true;
                            }
                        }

                        if (!achouFavorito) {

                            std::cout << std::endl;
                            std::cout << "Nao encontramos o seu contato...\n";
                            std::cout << std::endl;
                            continue;
                
                        }


                        std::cout << std::endl;
                        std::cout << "Gostaria de favoritar mais contatos?? Y/N: \n";
                        std::cin >> respostaFavorito;

                        if (respostaFavorito == 'Y' || respostaFavorito == 'y') {
                            continue;
                        }


                        else break;

                    }
            }
            

            else if(resposta10 == 2) {


                   while(checagemDesfavorita) {

                    int numeroFavoritos = 0;

                     for(int i = 0; i < listaContatos.size(); i++) {

                        if(listaContatos[i].favorito) {
                            numeroFavoritos++;
                                 }  

                            }


                 if(numeroFavoritos == 0) {
                        std::cout <<std::endl;
                        std::cout << "Nao ha nenhum contato favorito a ser desmarcado\n";
                        std::cout << std::endl;
                        break;
                    }

                        std::cout <<std::endl;
                        std::cout << "Qual contato voce gostaria de desmarcar? Escolha pelo nome ou id: \n";
                        std::getline(std::cin >> std::ws, aSerDesfavoritado);
                        std::cout << std::endl;


                         bool achouDesfavorito = false;

                        for(int i = 0; i < listaContatos.size(); i++) {

                            if(aSerDesfavoritado == listaContatos[i].nome ||
                            aSerDesfavoritado == std::to_string(listaContatos[i].id))  {
                                listaContatos[i].favorito = false;
                                achouDesfavorito = true;

                            }   
                        }

                        if (!achouDesfavorito) {

                            std::cout << std::endl;
                            std::cout << "Nao encontramos o seu contato...\n";
                            std::cout << std::endl;
                            continue;
                
                        }

                        std::cout << std::endl;
                        std::cout << "Gostaria de desfavoritar mais contatos?? Y/N: \n";
                        std::cin >> respostaDesfavorito;

                        if (respostaDesfavorito == 'Y' || respostaDesfavorito == 'y') {
                            continue;
                        }

                        else break;

                    }

                
            }




            
        }

        if (opcaoMenu == 11) {

            if(EstaVazio(listaContatos)) continue;

            int numeroFavoritos = 0;

            for(int i = 0; i < listaContatos.size(); i++) {
                if(listaContatos[i].favorito) {
                    numeroFavoritos++;
                }  
            }

            if(numeroFavoritos == 0) {
                        std::cout <<std::endl;
                        std::cout << "Nao ha nenhum contato favorito a ser mostrado\n";
                        std::cout << std::endl;
                        continue;
                    }

                std::cout << std::endl;
                std::cout << "Mostrando todos os contatos favoritos...\n";
                std::cout << std::endl;

                for(int i = 0; i < listaContatos.size(); i++) {

                    if(listaContatos[i].favorito) {

                        std::cout << "Contato " << i+1 << std::endl;
                        std::cout << "Nome: " << listaContatos[i].nome << std::endl;
                        std::cout << "Telefone: " << listaContatos[i].telefone << std::endl;
                        std::cout << "Email: " << listaContatos[i].email << std::endl;
                        std::cout << "Cidade: " << listaContatos[i].cidade << std::endl;
                        std::cout << "ID: " << listaContatos[i].id << std::endl;
                        std::cout << std::endl;

                    }

                }

                std::cout << std::endl;

            
        }


        if (opcaoMenu == 12) {

            std::cout << std::endl;
            std::cout << "Feito por Marco Thullyo Sao Severino!! Obrigado por logar <3\n";
            std::cout << std::endl;

        }

        //logica de EMPACOTAR E DESEMPACOTAR
        //Voce salva o seu vetor, que esta repleto de Contatos, antes de sair
        //voce "empacota" tudo em linhas, tipo nome;telefone;email;cidade;id;favorito
        //ai ele salva assim. na hora de desempacotar, ele vai retirando os pontos e virgulas e colocando
        //cada dado em sua linha
        //nome
        //telefone
        //...

        //na hora de desempacotar, ele nao desempacota para escrever NO .txt, mas sim PARA SEPARAR CERTINHO
        //para que os dados sejam colocados no vector novamente...

        /*
        Enquanto o programa esta rodando, todos os contatos vivem na memoria RAM (dentro do std::vector). 
        Mas quando fecha a tela preta do terminal, a RAM eh limpa e tudo desaparece. 

        O ofstream (empacotar na saida) pega todos os dados do vector antes do programa fechar
        e os escreve na "pedra" (no disco rigido, dentro de um .txt)

        O ifstream (desempacotar na entrada) eh a primeira coisa que acontece quando o programa eh aberto
        Ele vai no arquivo .txt, le os dados separados por ponto e virgula e reconstroi o vector inteirinho na RAM
        antes mesmo do menu ser exibido 



        
        */

        if (opcaoMenu == 13) {


            std::ofstream ArquivoContatos("contatos.txt");

            for(int i = 0; i < listaContatos.size(); i++) {
            ArquivoContatos << listaContatos[i].nome << ";" <<
            listaContatos[i].telefone << ";" << listaContatos[i].email <<
            ";" << listaContatos[i].cidade << ";" << listaContatos[i].id << ";" 
            << listaContatos[i].favorito << std::endl;

            }

            //booleano salva como 0 ou 1
            //o ofstream NAO SABE O QUE EH INT OU BOOL. Para ele, tudo eh string


            ArquivoContatos.close();

            std::cout << std::endl;
            std::cout << "Adeus! Sua lista foi salva como 'contatos.txt'!\n";
            std::cout << std::endl;
            return 0;

        }
    }
    return 0;

}




