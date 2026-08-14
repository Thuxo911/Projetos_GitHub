#include <iostream>
#include <fstream>
#include <string>

int main () {


    //OFSTREAM


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
    //Cursor invisivel que indica onde a leitura/escrita vai acontecer
    //na escrita/leitura esse ponteiro se move para frente automaticamente


    //rdbuf()
    //retorna um ponteiro para o BUFFER INTERNO do arquivo
    //o BUFFER eh uma area de memoria temporaria que armazena dados antes de serem gravados no disco

    std::ofstream MeuarquivoRdbuf("arquivoRdbuf.txt");
    std::filebuf *buf = MeuarquivoRdbuf.rdbuf();

    MeuarquivoRdbuf << "Hello, World!\n";
    MeuarquivoRdbuf.close();

    //raramente usado





    //seekp()
    //seekp(position) move o ponteiro do arquivo para uma posicao especifica
    
    std::ofstream MeuarquivoSeekp("arquivoSeekp.txt");
    MeuArquivo.seekp(6);
    //sozinho, nao faz nada. Mais para frente, ha uma utilidade mt interessante

    MeuarquivoSeekp.close();





    std::ofstream MeuArquivoAlfabeto("arquivoAlfabeto.txt");

    MeuArquivoAlfabeto << "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

    MeuArquivoAlfabeto.seekp(3); //mover ponteiro para posicao 3 (comecando de 0)

    MeuArquivoAlfabeto << "X";

    MeuArquivoAlfabeto.seekp(10);

    MeuArquivoAlfabeto << "X";

    MeuArquivoAlfabeto.seekp(20);

    MeuArquivoAlfabeto << "X";

    //resultado
    //ABCXEFGHIJXLMNOPQRSTXVWXYZ
    //x substitui a terceira, a decima e a vigesima letras

    //seekp(position, origin)
    //seekp pode mover o ponteiro comecando de origens diferentes
    //std::ofstream::beg - inicio
    //std::ofstream::cur - posicao ATUAL
    //std::ofstream::end - fim

    MeuArquivoAlfabeto.close();


    std::cout << std::endl;

    std::ofstream MeuArquivoFrase("arquivoFrase.txt");

    MeuArquivoFrase << "Felizes sao os caes, que pelo faro descobrem os amigos\n";


    MeuArquivoFrase.seekp(4, std::ofstream::beg);
    MeuArquivoFrase << "j";

    std::cout << "Contagem comecando do meio\n";
    std::cout << "Palavra 'z' substituida por 'j. O ponteiro estava na posicao 0 e foi movido ate a 4.\n";
    std::cout << "Atualmente o ponteiro esta na posicao 4\n";

    MeuArquivoFrase.seekp(0, std::ofstream::beg);
    MeuArquivoFrase << "B";

    std::cout << "Contagem comecando do inicio\n";
    std::cout << "Palavra 'F' substituida por 'B'. O ponteiro estava na posicao 4 e foi movido ate a 0.\n";
    std::cout << "Atualmente o ponteiro esta na posicao 0\n";

    MeuArquivoFrase.seekp(-3, std::ofstream::end);
    MeuArquivoFrase << "a";

    std::cout << "Contagem comecando do fim\n";
    std::cout << "Palavra 's' substituida por 'a'. O ponteiro estava na posicao 56 e foi movido ate a 53.\n";
    std::cout << "Atualmente o ponteiro esta na posicao 53\n";

    MeuArquivoFrase.seekp(-13, std::ofstream::cur);
    MeuArquivoFrase << "i";

    std::cout << "Contagem comecando de onde o ponteiro estava pela ultima vez. Ou seja, 53\n";
    std::cout << "Palavra 'r' substituida por 'i'. O ponteiro estava na posicao 53 e foi movido ate a 40.\n";
    std::cout << "Atualmente o ponteiro esta na posicao 40\n";

    MeuArquivoFrase.close();

    //Belijes sao os caes, que pelo faro descobiem os amigoa

    std::cout << std::endl;


    //tellp
    //em que posicao esta o ponteiro

    std::ofstream MeuArquivoTell("arquivoTell.txt");
    
    std::cout << "Posicao inicial: " << MeuArquivoTell.tellp() << std::endl;  // 0
    
    MeuArquivoTell << "ABC";
    std::cout << "Depois de escrever ABC: " << MeuArquivoTell.tellp() << std::endl;  // 3
    
    MeuArquivoTell << "DEF";
    std::cout << "Depois de escrever DEF: " << MeuArquivoTell.tellp() << std::endl;  // 6

    MeuArquivoTell.seekp(1, std::ofstream::beg);

    MeuArquivoTell << "X";
    std::cout << "Depois de fazer a substitucao: " << MeuArquivoTell.tellp() << std::endl; //1

    //AXCDEF
    //o ponteiro substitui o 1, que eh B
    
    MeuArquivoTell.close();
    MeuArquivoLouco.close();



    //===============================================================================================
    //===============================================================================================
    //===============================================================================================
    //===============================================================================================
    //===============================================================================================
    //===============================================================================================
    //===============================================================================================
    //===============================================================================================
    //===============================================================================================



    //IFSTREAM  
    //LER AS LINHAS DE UM ARQUIVO
    //o ifstream NAO modifica nada, ele apenas LE
    //ele le o conteudo, traz para a memoria RAM e ai eu decido o que fazer com esses dados

    std::string textinho = "Oi! Tudo bem??\n";

    //criando e inserindo 
    std::ofstream ArquivoTextinho("arquivoTextinho.txt");
    ArquivoTextinho << textinho;
    ArquivoTextinho.close();

    //lendo - tem que usar OUTRO, nao pode usar ArquivoTextinho dnv
    std::ifstream ArquivoLeitura("arquivoTextinho.txt");

    std::cout << std::endl;

    while (std::getline (ArquivoLeitura, textinho)) { //LE TODAS AS LINHAS DO ARQUIVO
        std::cout << textinho << std::endl; //imprime no terminal
    }


    //le todos os caracteres ate a proxima quebra de linha e escreve-os em uma string
    std::string textoEx;
    std::getline(ArquivoLeitura, textoEx);
    std::cout << textoEx;

    
    ArquivoLeitura.close();

    std::cout << std::endl;


    //FUNCOES DE LEITURA
    //extraem caracteres de um arquivo e movem o ponteiro

    //get()
    //LE um UNICO caractere e retorna seu valor ASCII. Converta-o para char para ver qual eh o caractere
    //o ponteiro eh movido para o proximo caractere do arquivo

    std::ofstream ArquivoGet("arquivoGet.txt");
    ArquivoGet << "ABC";
    ArquivoGet.close();
    //PRECISA FECHAR O OFSTREAM PARA ABRIR O IFSTREAM!!!

    std::ifstream ArquivoGetLer("arquivoGet.txt");

    char myChar = ArquivoGetLer.get();
    std::cout << (int)myChar << std::endl; //ASCII (65)
    std::cout << myChar << std::endl;    //decimal (A)


    ArquivoGetLer.close();


    //get(destination, size, delimiter)
    //le uma sequencia de caracteres(string)
    //destination - array dos caracteres. ex: char v[100];
    //size - numero maximo de caracteres a ler (incluindo o \0) ex: 100
    //delimiter - caractere que faz a leitura parar 
    //nao precisa ter delimiter. o delimiter padrao eh '\n', mas se quiser colocar outro: 'a' '.' ' ', pode tambem


    std::ofstream ArquivoBom("arquivobom.txt");
    ArquivoBom << "Joao;25;8.5;Aprovado";
    ArquivoBom.close();

    std::ifstream ArquivoBomLer("arquivobom.txt");

    char nome[50];
    char idade[20];
    char nota[20];
    char status[10];

    ArquivoBomLer.get(nome, 50, ';');
    ArquivoBomLer.ignore(); //ignora o ;, ou seja, nao o imprime

     ArquivoBomLer.get(idade, 10, ';');
     ArquivoBomLer.ignore();
    
     ArquivoBomLer.get(nota, 10, ';');
     ArquivoBomLer.ignore();
    
     ArquivoBomLer.get(status, 20, '\n');

    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Idade: " << idade << std::endl;
    std::cout << "Nota: " << nota << std::endl;
    std::cout << "Status: " << status << std::endl;
    
    ArquivoBomLer.close();


    //getiline(destination, size, delimiter) eh quase igual ao get.
    //no getline, a quebra de linha/delimitador eh descartado e o ponteiro eh movido para o caractere seguinte
    //get remove do stream mas nao adiciona ao buffer
    //getline remove do stream e descarta













































    return 0;


}
