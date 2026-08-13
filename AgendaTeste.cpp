#include <iostream>
#include <fstream>
#include <string>

int main () {


    std::ofstream MeuArquivo("arquivo.txt");
    //cria o arquivo chamado "arquivo.txt" no disco, abrindo uma conexao entre esse arquivo e o programa

    MeuArquivo << "Oi! Estou escrevendo no meu arquivo usando ofstream!\n";
    //Pega o texto da RAM, e eh como se empurasse os dados para o arquivo.

    MeuArquivo.close();
    //finaliza a conexao, garante que tudo foi salvo no disco e libera o arquivo para outros programas usarem.

    //os arquivos (.txt, .jpg) sao armazenados no disco, e persistem mesmo depois do pc ser desligado
    //a memoria ram some ao desligar, sao dados temporarios

    //As variaveis (int, string, vector, etc.) ficam na RAM
    //Quando o programa termina, a RAM eh liberada e tudo some
    //Para salvar permanentemente, voce precisa gravar no disco


    //===============================================================================================
    //===============================================================================================
    //===============================================================================================

    int ano = 2026;

    //MeuArquivo << "ano\n";
    //MeuArquivo << "Esse eh o ano atual. Le-se DOIS MIL E VINTE E SEIS\n";

    //NAO PODE REUTILIZAR
    //Precisa CRIAR um novo objeto ofstream para o segundo arquivo.
    //PQ ele ja foi fechado. Mas daria para abrir outro...

    std::ofstream MeuArquivo2("arquivo2.txt");

    MeuArquivo2 << "ano\n";
    MeuArquivo2 << "Esse eh o ano atual. Le-se DOIS MIL E VINTE E SEIS\n";

    MeuArquivo2.close();

    //o \n ou std::endl pula uma linha. Agora vamos tentar reutilizar esse arquivo, reabrindo-o.

    MeuArquivo2.open("arquivo2reaberto.txt");
    //se eu colocar para abrir apenas, vai estar vazio. eh preciso colocar coisas nele

    MeuArquivo2 << "OIIIIIIIIIIIIIIIIIIIIII\n";

    MeuArquivo2.close();

    //===============================================================================================
    //===============================================================================================
    //===============================================================================================

    //MANIPULADORES
    //ALTERAM A FORMATACAO DOS DADOS    
    //fazendo o teste de varios...
    //os manipuladores tem std

    std::ofstream MeuArquivoLouco("arquivoLouco.txt");

    MeuArquivoLouco << std::boolalpha << true << std::endl;
    MeuArquivoLouco << std::boolalpha << false << std::endl;
    //escreve valores booleanos true/false ao inves de 0/1

    MeuArquivoLouco << std::endl;


    MeuArquivoLouco << std::dec << 12 << std::endl;
    MeuArquivoLouco << std::hex << 0 << std::endl;
    MeuArquivoLouco << std::oct << 100000 << std::endl;
    MeuArquivoLouco << std::hex << 5606 << std::endl;
    //representa numeros inteiros como decimais (todos os numeros acima ja sao decimais,
    //eh util para fazer conversao entre hexadecimal e octal, std::hex e std::oct)

    MeuArquivoLouco << std::endl;


    //std::endl escreve um caractere numa nova linha. tambem limpa o buffer de saida, o que o torna
    //menos eficiente do que imprimir \n. Uma coisa interessante a se notar, eh que
    //eh necessario escrever o std::endl JUNTO com o seu Arquivo, senao, nao vai funcionar ex: MeuArquivoLouco << std::endl;

    MeuArquivoLouco << std::endl;
    MeuArquivoLouco << std::endl;
    MeuArquivoLouco << std::endl;
    MeuArquivoLouco << std::endl;
    MeuArquivoLouco << std::endl;

    MeuArquivoLouco.close();

    //existem dezenas de manipuladores, mas por ora, nao sao relevantes

    //===============================================================================================
    //===============================================================================================
    //===============================================================================================

    //FUNCOES DE GRAVACAO DE ARQUIVOS
    //gravam dados em um arquivo e movem o ponteiro do arquivo para a primeira posicao apos o conteudo gravado.


    //write(str, n)
    //O metodo escreve n caracteres char do array str no arquivo

    std::ofstream MeuArquivoGravacao("arquivoGravacao.txt");

    char meuArray[] = "Hello World!\n";

    MeuArquivoGravacao.write(meuArray, 5);

    MeuArquivoGravacao << std::endl;


    //put(c)
    //coloca o caractere especificado 'c' no arquivo

    char letra = 'B';
    MeuArquivoLouco.put(letra);
    MeuArquivoGravacao.close();




    //===============================================================================================
    //===============================================================================================
    //===============================================================================================




    //FUNCOES DE MANIPULACAO DE ARQUIVOS
    //permitem abrir, fechar e navegar entre arquivos

    std::ofstream MeuArquivoManipulado("arquivoManipulado.txt");


    //quando voce escreve assim std::ofstream MeuArquivoManipulado("arquivoManipulado.txt");
    //voce CRIA o ofstream e JA ABRE ELE. Para nao abrir, eh so digital
    //std::ofstream MeuArquivoManipulado




    //o OPEN NAO ABRE uma janelinha visual como o bloco de notas.
    //ele NAO mostra nada na tela
    //o open CRIA uma conexao entre o disco e o arquivo, permitindo o programa ler ou escrever no arquivo
    //o open EH CRIADO AUTOMATICAMENTE. Ha arquivos acima que eu nao coloquei porque esqueci, mas sempre eh criado
    

    //is_open() eh o metodo que retorna true SE o arquivo estiver aberto e false caso contrario

    std::cout << MeuArquivoManipulado.is_open() << std::endl;
    MeuArquivoManipulado.open("arquivoManipulado.txt"); 
    std::cout << MeuArquivoManipulado.is_open() << std::endl;
    //aqui AMBOS DARAO 1(true), pq o arquivo foi aberto la em cima. Agora, criamos outro
    //nota: esses numeros sairao no terminal. Afinal, nao estamos MeuArquivo << e sim std::cout <<, 
    //que eh para sair no terminal

    std::cout << std::endl;

    std::ofstream MeuArquivoManipulado2;

    std::cout << MeuArquivoManipulado2.is_open() << std::endl; //0
    MeuArquivoManipulado2.open("arquivoManipulado.txt"); 
    std::cout << MeuArquivoManipulado2.is_open() << std::endl; //1

    std::cout << std::endl;

    //vai dar true pq esta aberto sim, daria o mesmo resultado se eu colocassse MeuArquivoManipulado2.is_open()
    //pois ambos foram abertos
    if (MeuArquivoManipulado.is_open()) { 
        std::cout << "Meu arquivo manipulado esta aberto!\n";
    }

    else {std::cout << "Meu arquivo manipulado NAO esta aberto!\n";}

    std::cout << std::endl;

    std::ofstream MeuArquivoFechado;
    //ele esta fechado. Entao na verificao vai dar falso

    if(MeuArquivoFechado.is_open()) {
        std::cout << "Meu arquivo  esta aberto!\n";
    }

    else {std::cout << "Meu arquivo NAO esta aberto!\n";}


    MeuArquivoManipulado.close();
    MeuArquivoManipulado2.close();
    MeuArquivoFechado.close();
    //fecha a conexao. eh recomendavel sempre fecha-los para liberar recursos
    //como podemos perceber, o proprio arquivoManipulado.txt ESTA VAZIO, pois
    //nada foi escrito nele, apenas no terminal




    //===============================================================================================
    //===============================================================================================
    //===============================================================================================



    //PONTEIROS
    //Cursor invisivel








    std::cout << std::endl;













    MeuArquivoLouco.close();







}
