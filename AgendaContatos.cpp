#include <iostream>
#include <fstream>
#include <string>
#include <limits>


struct Contato {

    std::string nome;
    std::string telefone;
    std::string email;
    std::string cidade;
    int id;
    bool favorito;


};


int main () {

    bool checagem = true;
    int opcaoMenu;



    while (checagem) {

        std::cout << "============================================\n";
        std::cout << "         AGENDA DE CONTATOS - MENU         \n";
        std::cout << "============================================\n";
        std::cout << "\n";
        std::cout << "  [1] - Adicionar novo contato\n";
        std::cout << "  [2] - Listar todos os contatos\n";
        std::cout << "  [3] - Buscar contato por nome\n";
        std::cout << "  [4] - Buscar contato por telefone\n";
        std::cout << "  [5] - Editar um contato\n";
        std::cout << "  [6] - Remover um contato\n";
        std::cout << "  [7] - Salvar contatos em arquivo\n";
        std::cout << "  [8] - Carregar contatos do arquivo\n";
        std::cout << "  [9] - Ordenar contatos\n";
        std::cout << " [10] - Mostrar total de contatos\n";
        std::cout << " [11] - Limpar toda a agenda\n";
        std::cout << " [12] - Marcar/desmarcar favoritos\n";
        std::cout << " [13] - Mostrar contatos favoritos\n";
        std::cout << "\n";
        std::cout << "  [11] - Creditos\n";
        std::cout << "  [12] - Sair da agenda\n";
        std::cout << "\n";
        std::cout << "============================================\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcaoMenu;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (opcaoMenu < 1 || opcaoMenu > 12) {
            std::cout << std::endl;
            std::cout << "Opcao errada. Por favor, escolha um numero entre 1 e 12\n";
            std::cout << std::endl;
            continue;
        }



        if (opcaoMenu) {

        }
    








    }







}

 














