#include <iostream>
#include <fstream>
#include <string>

int main () {


    std::ofstream MeuArquivo("arquivo.txt");

    MeuArquivo << "Oi! Estou escrevendo no meu arquivo usando ofstream!\n";

    MeuArquivo.close();



}
