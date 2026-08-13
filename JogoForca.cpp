#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

    static std::string palavras4[391] = {
            "amor", "casa", "vida", "flor", "gato", "vaca", "pato", "lobo", "urso", "alho",
            "muro", "teto", "mesa", "lata", "fita", "nave", "pote", "faca", "cama", "selo",
            "sopa", "doce", "bolo", "fogo", "neve", "frio", "hora", "jogo", "bola", "time",
            "tatu", "onda", "pipa", "nuca", "mico", "hino", "gelo", "feno", "dedo",
            "iodo", "cubo", "bico", "zelo", "vaso", "tapa", "sino", "rede", "piso", "moda",
            "lado", "pino", "fato", "mito", "caos", "sapo", "puma", "rubi", "neto", "toco", "siri", "urro", "mate",
            "jacu", "gomo", "lula", "luau", "faro", "juba", "paca", "urna", "fofo", "pano", "duna",
            "lima", "cana", "nove", "sebo", "maio", "unha", "kiwi", "mola", "favo", "reta", "rolo", 
            "bota", "gole", "ruga", "caco", "bule", "ralo", "furo", "sova", "isca", "duro", "guru", "menu",
            "fumo", "gala", "lava", "tira", "foca", "luva", "saco", "muco", "saci", "anta", "vala", "peru",
            "moto", "poro", "mofo", "bote", "siso", "fole", "loja", "cuia", "gajo", "fino", "galo", "czar", 
            "fada", "zero", "seis", "ator", "feto", "erva", "arma", "cera", "arco", "oito", "tufo", "mina", "lago",
            "gene", "mato", "mata", "veia", "fulo", "ocre", "naco", "bala", "cria", "sete", "roxo", "xixi",
            "tara", "papo", "gaze", "beco", "doze", "toga", "agro", "bula", "cruz", "seda", "teia", "musa",
            "colo", "luar", "oral", "veto", "data", "coxa", "caju", "vivo", "pomo", "diva", "urbe", "luso",
            "mago", "mapa", "vago", "raio", "proa", "osso", "mana", "roca", "rosa", "acre", "rasa", "anjo",
            "copa", "cura", "ceia", "novo", "ogro", "cima", "dono", "nora", "sono", "ouro", "seta", "cujo",
            "cabo", "bofe", "cego", "cepo", "luxo", "dose", "meia", "tupi", "meio", "gafe", "gado", "ateu", "olho",
            "vaga", "limo", "odor", "anel", "ramo", "tomo", "falo", "topo", "eixo", "peso", "coro", "sebe", 
            "joio", "nego", "pneu", "cara", "asno", "cena", "sexy", "raro", "cume", "ledo", "aval", "trem", "taxa",
            "grau", "rola", "puro", "leal", "mero", "nato", "real", "alfa", "dolo", "beta", "dote", "tipo", "luta", "hera",
            "nome", "pena", "azul", "nexo", "orla", "nada", "tese", "pose", "face", "alvo", "foco", "cela", "rima", "cedo",
            "arte", "ente", "alma", "deus", "cota", "apto", "mote", "auge", "sina", "brio", 
            "alto", "atum", "azar", "azia", "base", "bela", "belo", "bile", "boca", "boda",
            "bode", "boia", "boto", "breu", "cala", "capa", "coco", "copo", "dado", "dama",
            "dano", "dias", "dica", "dito", "dona", "ecos", "elmo", "elos", "erro", "fala",
            "fava", "feio", "figa", "figo", "fila", "fome", "gago", "gata", "gema", "gira",
            "giro", "gola", "goma", "gota", "gozo", "guia", "gula", "iate", "ilha", "ioga",
            "item", "jaca", "jato", "jeca", "jipe", "joia", "jota", "juiz", "jura", "juta",
            "laje", "lama", "leoa", "leva", "leve", "lixo", "loba", "lona", "lota", "luto",
            "mala", "medo", "mula", "nabo", "nado", "neta", "nojo", "nota", "nova", "nulo",
            "obra", "pele", "pelo", "pera", "polo", "povo", "quiz", "rata", "rato", "reis",
            "remo", "reza", "riso", "roda", "rodo", "rude", "sala", "sapa", "sede", "sela",
            "soja", "sola", "solo", "soma", "tela", "toca", "tubo", "uivo", "unto", "vale",
            "vaza", "veio", "vela", "viga", "vila", "voto", "xale", "xepa", "zaga", "zebu",
            "zika", "zona" 
        };

        static std::string palavras5[395] = {
            "abade", "abono", "abuso", "aceso", "acido", "acaso", "adaga", "adubo", "afago", "afixo",
            "agito", "aguia", "ajuda", "alibi", "altar", "aluno", "amado", "amago", "amido", "amigo",
            "amplo", "anexo", "ansia", "antro", "anzol", "apelo", "apito", "apoio", "apuro", "arame",
            "arara", "ardor", "areia", "aroma", "arpao", "asilo", "astro", "ativo", "atlas", "audaz",
            "aviao", "aviso", "bacia", "bagre", "baiao", "balde", "balsa", "bambu", "banco", "bando",
            "barao", "barco", "bardo", "barra", "barro", "bazar", "beato", "bento", "berco", "besta",
            "bicho", "bispo", "blusa", "boato", "bocal", "boina", "bolha", "bolso", "bomba", "bonde",
            "borda", "botao", "braco", "brado", "brasa", "bravo", "brejo", "briga", "brita", "bruxa",
            "bucha", "bujao", "bulbo", "burgo", "burro", "busto", "cacau", "cacho", "cacto", "caixa",
            "calca", "caldo", "calvo", "campo", "canal", "canoa", "canto", "capim", "capuz", "carga",
            "cargo", "carma", "carne", "carpa", "carta", "casco", "casta", "caule", "celta", "censo",
            "cerco", "cesto", "chapa", "chato", "chave", "chefe", "choro", "chuva", "ciclo", "cifra",
            "cinza", "circo", "cismo", "cisne", "ciume", "claro", "clero", "clima", "clipe", "clone",
            "clube", "cobre", "cofre", "coisa", "coito", "cervo", "combo", "conde", "conta", "conto",
            "copao", "corda", "coroa", "corpo", "corte", "corvo", "couro", "cravo", "credo", "creme",
            "crime", "crina", "crise", "cromo", "culpa", "culto", "cupim", "curvo", "cuspe", "custo",
            "cutis", "danca", "dardo", "dedao", "denso", "dente", "deusa", "diabo", "dieta", "digno",
            "disco", "docil", "dogma", "doido", "dorso", "douto", "drama", "dreno", "droga", "duelo",
            "dupla", "ebano", "edito", "elite", "enjoo", "epico", "epoca", "ereto", "esqui", "estio",
            "etano", "etica", "etnia", "exato", "exame", "exito", "exodo", "extra", "facho", "faial",
            "faina", "faixa", "falso", "fardo", "farol", "farpa", "farsa", "farto", "favor", "feixe",
            "feliz", "fenda", "feria", "ferro", "festa", "fetal", "feudo", "fibra", "ficha", "filme",
            "final", "finta", "firma", "fisco", "flora", "fluxo", "fobia", "foice", "folha", "folia",
            "fonte", "forca", "forma", "forno", "forte", "fossa", "fosso", "fraco", "frade", "freio",
            "fresa", "frota", "fruto", "fuzil", "gaita", "galao", "galho", "ganso", "garfo", "garra",
            "gasto", "gatao", "gemeo", "genio", "gesso", "giria", "globo", "glote", "gnomo", "golpe",
            "gordo", "gorro", "gosma", "graca", "grade", "grama", "grato", "grave", "grego", "grife",
            "grilo", "gripe", "grupo", "gruta", "gueto", "harpa", "haste", "heroi", "hiato", "hiena",
            "hifen", "himen", "hotel", "hulha", "humor", "humus", "ibope", "idolo", "idoso", "igapo",
            "ileso", "imago", "impar", "impio", "imune", "indio", "ingua", "irmao", "janta", "japao",
            "jarra", "jaula", "jejum", "jeito", "jongo", "jorro", "jovem", "juizo", "junco", "juiza",
            "justa", "labia", "labor", "lacio", "lagoa", "laico", "lanca", "lapis", "largo", "larva",
            "lasca", "latao", "latex", "lazer", "lebre", "legal", "legua", "leito", "lenco", "lenda",
            "lenha", "lento", "leque", "lerdo", "leste", "letra", "libio", "licao", "lider", "lilas",
            "limao", "lince", "linda", "linha", "lirio", "litro", "livro", "lombo", "louco", "louro",
            "lousa", "lugar", "lustro", "macio", "madre", "mafia", "magro", "maior", "malha", "mamae",
            "mamao", "mambo", "manha", "mania", "manta", "manto", "magia", "marca", "marco", "massa",
            "matiz", "meada", "mecha", "meigo", "melao", "menor", "menta", "mesao", "metal", "metro",
            "mielo", "milho", "mimo", "miolo", "missa", "misto", "miudo", "moeda", "moela", "moita",
            "molde", "molho", "monge", "monte", "moral" };

        static std::string palavras6[395] = {
            "abelha", "abraco", "acacia", "acordo", "acucar", "adendo", "adepto", "adulto", "afavel", "agonia",
            "agravo", "agulha", "aldeia", "alface", "alfaia", "alinea", "alpaca", "animal", "anseio", "apogeu",
            "aposta", "apreco", "aranha", "arauto", "argila", "astuto", "ataque", "atalho", "atraso", "avanco",
            "avidez", "babaca", "bacana", "bacilo", "bagaca", "bainha", "baiano", "bairro", "balada", "balaio",
            "balcao", "baleia", "baliza", "banana", "barril", "batata", "batina", "beleza", "bebida", "bronca",
            "bexiga", "bigode", "bilhao", "boleto", "boneco", "bonito", "bosque", "boteco", "bovino", "branco",
            "brasao", "brinde", "bronze", "buraco", "buzina", "cabana", "cabeca", "cabelo", "cabide", "cadeia",
            "cajado", "calado", "calhau", "califa", "camelo", "camisa", "canudo", "capela", "capote", "careca",
            "carona", "cartao", "casaca", "casaco", "cavalo", "cavaco", "cebola", "cedula", "celula", "centro",
            "cereal", "cereja", "chapeu", "charco", "cheiro", "choque", "chique", "chumbo", "cigano", "cinema",
            "cinico", "cidade", "classe", "cliche", "coacao", "coelho", "colega", "colete", "colono", "coluna",
            "cometa", "comida", "comite", "condor", "confim", "coruja", "cranio", "cracha", "crente", "crosta",
            "culote", "cupido", "curral", "dadiva", "decada", "debito", "decano", "defesa", "degrau", "delito",
            "desejo", "desuso", "devoto", "diacho", "diario", "ditado", "ditame", "divino", "dizimo", "doenca",
            "doente", "domino", "dragao", "duende", "dureza", "duvida", "efeito", "efusao", "elenco", "elixir",
            "embalo", "embate", "empate", "enigma", "ensaio", "ensino", "enxada", "enxame", "equino", "equipe",
            "engano", "errado", "escada", "escala", "escama", "escopo", "escuro", "esfera", "esmola", "espaco",
            "espada", "espiga", "esposa", "estado", "estojo", "estopa", "estufa", "evento", "exilio", "extase",
            "fabula", "facada", "faisca", "falcao", "farofa", "fofura", "folego", "frango", "frasco", "fraude",
            "freira", "fresta", "frieza", "fronha", "frouxo", "fumaca", "farelo", "fatura", "favela", "fedido",
            "felino", "ferida", "fivela", "flanco", "flecha", "flerte", "fluido", "fofoca", "fralda", "franco",
            "franja", "fresco", "gaiato", "gaiola", "galego", "galera", "galeto", "gaveta", "geleia", "gemido",
            "genero", "genese", "girafa", "gloria", "gorila", "garoto", "granja", "grampo", "grosso", "guarda",
            "habito", "halito", "herege", "helice", "hexano", "hipico", "hostil", "idiota", "igreja", "imagem",
            "imenso", "imovel", "impeto", "impuro", "inepto", "infame", "ingles", "iniquo", "intimo", "inveja",
            "isopor", "idioma", "iguana", "ilusao", "imerso", "imundo", "jacare", "janela", "jardim", "jargao",
            "javali", "joelho", "jogada", "jornal", "jubilo", "jumento", "jurema", "jovial", "jazigo", "labuta",
            "lacuna", "lastro", "latido", "lavabo", "leitao", "leitor", "letivo", "libido", "limite", "lingua",
            "lirico", "lisura", "luneta", "lustro", "legiao", "legume", "levada", "macaco", "maduro", "magico",
            "malote", "maluco", "mamilo", "manada", "mancha", "manejo", "mangue", "maroto", "marfim", "margem",
            "marujo", "mastro", "matriz", "maxixe", "maximo", "menino", "mestre", "metade", "milhao", "minuto",
            "modelo", "modulo", "moinho", "morada", "moreno", "mucama", "mudeza", "mulher", "musica", "namoro",
            "narina", "nativo", "nectar", "negrito", "neutro", "nevada", "niquel", "nitido", "novela", "novato",
            "nucleo", "numero", "objeto", "oceano", "ofensa", "oitavo", "olimpo", "oposto", "optico", "oracao",
            "orador", "orbita", "orelha", "origem", "outono", "ovelha", "pacato", "pacote", "padrao", "paixao",
            "palito", "panela", "panico", "papaia", "papiro", "pardal", "parede", "parque", "pastel", "pateta",
            "patina", "pecado", "pedaco", "pedida", "pegada", "pelado", "peleja", "penedo", "pepino", "perigo",
            "perito", "peruca", "petala", "pijama", "piloto", "pincel", "pipoca", "pirata", "planta", "poeira",
            "poesia", "polida", "pomada", "portao", "pranto", "predio", "pregao", "premio", "pressa", "pureza",
            "quadra", "quadro", "quarto", "queijo", "queixa"
        };

        static std::string palavras7[395] = {
            "abacate", "abacaxi", "absurdo", "acamado", "acougue", "adesivo", "advento", "alecrim", "alergia", "alicate", "aluguel", "amarelo", "amianto", "amizade", "amuleto", "andador", "ansioso", "aplauso", "aquario", "armario", "arquivo", "armazem", "asfalto", "aspecto", "assador", "assunto", "augusto",
            "babador", "batedor", "babuino", "bagagem", "balanco", "bandido", "baralho", "barraca", "barraco", "barriga", "beldade", "bermuda", "besouro", "bizarro", "bilhete", "biquini", "bobagem", "boicote", "bolacha", "boliche",
            "cabrito", "cacador", "cacique", "cadeado", "cadeira", "caderno", "calcado", "calculo", "caloria", "camafeu", "caminho", "camurca", "canario", "canhoto", "cantina", "capital", "capitao", "capsula", "caracol", "carisma", "carpete", "carroca", "cascata", "casinha", "castelo", "catarro", "caverna", "caxumba", "celeiro", "cenario", "censura", "centeio", "certeza", "cerveja", "charuto",
            "deboche", "decibel", "defeito", "deitado", "deidade", "delgado", "delicia", "delirio", "dentuco", "deserto", "destino", "detalhe", "devasso", "diabete", "diadema", "dialogo", "difunto", "diploma", "direito", "divinal",
            "egoismo", "eleitor", "embuste", "empatia", "empadao", "encanto", "encosto", "endosso", "energia", "enfermo", "engasgo", "engenho", "enxofre", "epilogo", "eremita", "errante", "ervilha", "esbelto", "escalao", "escambo", "escasso", "escravo", "esmalte", "espanto", "espelho", "espesso", "espinho",
            "fachada", "fadinha", "fadista", "falacia", "faminto", "farmaco", "farrapo", "fazenda", "feriado", "ferrete", "fervura", "fidalgo", "fileira", "filhote", "firmeza", "fixador", "flagelo", "flanela", "floreio", "florido", "focinho", "folgado", "folheto",
            "galante", "galaxia", "galeria", "galinha", "garagem", "garrafa", "general", "gengiva", "gigante", "ginasta", "glacial", "glicose", "gordura", "gorjeta", "gostoso",
            "habitat", "haltere", "heranca", "heroina", "higiene", "hipnose", "honesto", "hortela", "hospede", "humilde",
            "ignobil", "ilustre", "imbecil", "imersao", "imortal", "impacto", "imperio", "imposto", "impulso", "incenso", "inedito", "infante", "inferno", "infeliz", "inimigo", "injusto", "insigne", "insonia", "intacto", "integro",
            "jaqueta", "jesuita", "jogador", "jornada", "jubileu", "jumento", "justica", "jurista",
            "lagarta", "lagrima", "lamento", "lampada", "lampejo", "laranja", "lasanha", "latrina", "lavador", "legenda", "leitura", "leviano", "limpeza", "liquido", "litoral", "lixeira", "locutor", "losango", "loteria", "loucura",
            "macabro", "macacao", "madeira", "maestro", "magreza", "maldade", "maldoso", "malhado", "malvado", "maminha", "mandato", "maneira", "maniaco", "matador", "mateiro", "materia", "matinal", "maxilar", "medalha", "medicao", "melodia", "mercado", "mesario", "metrica", "milagre", "miseria", "mistura",
            "nanismo", "narciso", "natural", "navalha", "negocio", "nervoso", "nevoada", "ninfeta", "nobreza", "notavel",
            "obliquo", "obscuro", "oficial", "oficina", "omissao", "opiniao", "oraculo", "ordeiro", "oregano", "orgulho", "oriente", "orvalho", "ousadia", "outeiro", "oxidado",
            "padaria", "pagador", "palavra", "palhaco", "palheta", "palmito", "pantano", "papelao", "paraiso", "parente", "partida", "passado", "passeio", "passaro", "passivo", "pastoso", "patente", "patinho", "patrono", "pecador", "pedagio", "pedante", "pedinte", "pelucia", "pequeno", "perdido", "perfume", "periodo", "pessimo", "picador", "piedade", "pintura",
            "quartel", "querido", "quimica", "quinino", "quantia",
            "rabento", "rabisco", "racismo", "raquete", "realeza", "rebanho", "rebelde", "receita", "recesso", "recheio", "recluso", "recurso", "redondo", "reflexo", "refugio", "regalia", "remedio", "remorso", "repente", "resgate", "residuo", "retalho",
            "sagrado", "salario", "salgado", "samurai", "sanfona", "sangria", "saudade", "secador", "sedento", "segredo", "semente", "senador", "sentido", "seringa", "silvado", "simples", "sincero", "sistema", "sobrado", "socorro", "sofrido", "sozinho",
            "tamanho", "tapioca", "teclado", "teimoso", "telhado", "tenista", "terapia", "termico", "tesoura", "timidez", "titular", "torcida", "torneio", "tortura", "traicao", "traidor", "tumulto",
            "umidade", "unidade", "urgente", "usuario", "vaidade", "valente", "vanilha", "vasilha", "vegetal", "veiculo", "verdade", "vertice", "vestido", "vigario", "vinagre", "violeta", "virtude", "viscoso", "vitoria", "vizinho"
        };

        static std::string palavras8[395] = {
            "abertura", "aboboral", "absoluto", "abstrato", "academia", "acampado", "acidente", "acordado",
            "acuidade", "adesista", "adjetivo", "advogado", "afogador", "africano", "agressao", "agressor",
            "agronomo", "ajuntado", "alargado", "alascano", "albatroz", "albergue", "alcatrao", "alfaiate",
            "alienado", "almiscar", "almofada", "alquimia", "alvejado", "amargura", "amazonia", "ambiente",
            "amendoim", "amigavel", "amnesico", "anarquia", "anatomia", "ancestro", "angelico", "anomalia",
            "anorexia", "antidoto", "antilope", "aparelho", "apendice", "apostolo", "aprendiz", "aquatico",
            "aquarela", "araucano", "armadura", "arqueiro", "artesano", "arvoredo", "aspirina", "atentado",
            "atestado", "atletico", "ausencia", "autonomo", "avestruz", "azimutal", "bacalhau", "bacteria",
            "baixinho", "balancao", "balancim", "baluarte", "bandeira", "banquete", "barbarie", "barbeiro",
            "baronesa", "barranco", "basilica", "basquete", "batalhao", "baunilha", "beijinho", "belicoso",
            "benefico", "berimbau", "bimestre", "biologia", "biscoito", "bissexto", "botanico", "botequim",
            "bramante", "brandura", "brasilia", "brochura", "cabeludo", "caboclao", "cacarola", "cachorro",
            "caixeiro", "calmaria", "camarada", "camarote", "caminhao", "campanha", "canastra", "cantante",
            "caramelo", "caravana", "cardapio", "carnaval", "carapuca", "carrasco", "carreira", "carrinho",
            "cascavel", "castanha", "catadura", "catarata", "catedral", "catolico", "centauro", "ceramica",
            "chancela", "chaveiro", "chuveiro", "cicatriz", "cilindro", "cineasta", "ciumento", "cobertor",
            "cochilha", "colegial", "colorido", "comissao", "comitiva", "comercio", "compasso", "complexo",
            "conceito", "concorde", "concurso", "condessa", "condutor", "confesso", "conforto", "conjunto",
            "conselho", "contagio", "contente", "contorno", "contrato", "convento", "conversa", "corcunda",
            "cordeiro", "corredor", "correcto", "corrente", "costelao", "creatina", "criatura", "criminal",
            "cruzeiro", "cultural", "decisivo", "defensor", "delegado", "delicado", "demencia", "demonico",
            "dentista", "desafino", "desanimo", "desastre", "descanso", "desculpa", "desertor", "desgaste",
            "desgosto", "despacho", "desprezo", "destaque", "diapasao", "diagonal", "diamante", "diarreia",
            "didatico", "dinamica", "dinamite", "dinheiro", "diretora", "discreto", "discurso", "distante",
            "distinto", "distrito", "diversao", "divorcio", "doutrina", "duvidoso", "ecologia", "economia",
            "educacao", "educador", "elefante", "elegante", "eletrico", "embarque", "emissora", "empanada",
            "endereco", "energico", "entidade", "entranha", "epidemia", "episodio", "escarceu", "escassez",
            "escocesa", "escombro", "escritor", "escultor", "esferico", "espacoso", "espanhol", "especial",
            "essencia", "estadual", "estatico", "estatuto", "estimulo", "estomago", "estranho", "estreito",
            "excursao", "exemplar", "exercito", "expresso", "fantasia", "fantasma", "farmacia", "fascismo",
            "feminino", "ferragem", "ferreiro", "festival", "filosofo", "flamengo", "floresta", "fogueira",
            "fonetico", "formacao", "fracasso", "francesa", "fraqueza", "fundacao", "gabinete", "garanhao",
            "gasolina", "genetico", "geografo", "goleador", "golfinho", "gorjeado", "grandeza", "guardiao",
            "guitarra", "harmonia", "herdeiro", "heroismo", "historia", "homicida", "horrivel", "hospital",
            "ilusorio", "imitacao", "imperial", "impostor", "imprensa", "impresso", "incendio", "indicado",
            "indigena", "indireto", "infancia", "infeccao", "inferior", "infinito", "ingresso", "inocente",
            "instinto", "interior", "intrusao", "invernal", "javanesa", "jogadora", "judicial", "justinho",
            "lacracao", "ladrilho", "lanterna", "lealdade", "legitimo", "lenhador", "leopardo", "limonada",
            "linguica", "locadora", "louvavel", "lugarejo", "macacada", "macarrao", "malefico", "malhador",
            "mamifero", "mancebia", "mandarim", "manequim", "maratona", "marcador", "marquesa", "massacre",
            "material", "machismo", "mecanico", "medalhao", "medicina", "medieval", "melancia", "membrana",
            "mensagem", "mercador", "metalico", "microbio", "minerado", "ministro", "mocidade", "misterio",
            "molecula", "mongolia", "montanha", "moradora", "mosquito", "mostarda", "multidao", "nacional",
            "namorado", "narrador", "natureza", "naufrago", "negativo", "nocturno", "nogueira", "nonagono",
            "nordeste", "normando", "novidade", "numerico", "nutricao", "objetivo", "obrigado", "ocidente",
            "ofensivo", "olimpico", "operacao", "operario", "oposicao", "orfanato", "organico", "oriental",
            "original", "orquidea", "otimismo", "paciente", "padrasto", "paladino", "palanque", "palmeira",
            "pandemia", "papagaio", "paraense", "parafuso", "paralelo", "parasita", "parceiro", "passagem",
            "pastilha", "patricio", "pavilhao", "pedestal", "pedestre", "pedreiro", "pelicano", "pioneiro",
            "penhasco", "perdicao", "perfeito"
        };

                static std::string palavras9[395] = {
            "abdicacao", "aberracao", "abobadado", "abominoso", "abordagem", "abortista", "abracador", "abstracao", "abundante", "academico",
            "acampante", "acendedor", "acessivel", "acessorio", "acrobacia", "adaptacao", "adequacao", "adestrado", "adjetival", "admiracao",
            "admiravel", "adocicado", "adoradora", "advocacia", "aeroporto", "afinidade", "afirmacao", "agilidade", "agradavel", "agregacao",
            "agronomia", "alabastro", "albergado", "alcaloide", "alcoolico", "alegorico", "alfandega", "algarismo", "alienacao", "alienante",
            "almirante", "alteracao", "altimetro", "alvarenga", "ambicioso", "ambiental", "amendoado", "americano", "amiguinho", "ampliacao",
            "ampulheta", "analgesia", "analogico", "anatomico", "andorinha", "anedotico", "anestesia", "animadora", "anonimato", "ansiedade",
            "antebraco", "antepasto", "anticorpo", "apanhador", "aparencia", "aperitivo", "apetitoso", "aplicacao", "apontador", "aprovacao",
            "aquisicao", "aracnideo", "arcabouco", "areamento", "argamassa", "argentino", "argumento", "armadilha", "armamento", "arquiteto",
            "arrastado", "arrogante", "artificio", "aspiracao", "aspirador", "assassino", "astrologo", "astronomo", "atencioso", "atendente",
            "atenuacao", "aterragem", "atletismo", "atmosfera", "audacioso", "audiencia", "auricular", "autentico", "automovel", "avalanche",
            "avaliacao", "avicultor", "bagageiro", "balaustre", "balizador", "bananeira", "banimento", "banqueiro", "barateiro", "batedeira",
            "batimento", "bebedeira", "bebedouro", "belvedere", "benfeitor", "berinjela", "beterraba", "biografia", "biologico", "boiadeiro",
            "borboleta", "brinquedo", "britanico", "bronquite", "cabeleira", "cacambada", "cachalote", "cachoeira", "cachorrao", "cafeteira",
            "calcanhar", "caldeirao", "calibrado", "calunioso", "caminhada", "campainha", "camponesa", "camuflado", "canalhada", "candidato",
            "carbonato", "carinhoso", "carnivoro", "carregado", "carrossel", "cartolada", "cartolina", "carvalhal", "casamento", "cascadura",
            "castidade", "categoria", "cauteloso", "cavalaria", "cavaleiro", "cavalgada", "cavernoso", "celestial", "cemiterio", "centopeia",
            "cerimonia", "champanhe", "charlatao", "chimarrao", "chinchila", "chocolate", "cimentado", "cirurgiao", "claridade", "cobertura",
            "colegiado", "coletanea", "colocacao", "colunista", "comercial", "comovente", "companhia", "comprador", "conclusao", "concubina",
            "confianca", "confiante", "confronto", "congelado", "congresso", "conhecido", "conjugado", "conquista", "consorcio", "consulado",
            "consultor", "contadora", "contraste", "copilador", "corcovado", "corretivo", "corrupcao", "cortinado", "cosmetico", "cotidiano",
            "criminoso", "crueldade", "crustaceo", "dancarino", "decadente", "dedicacao", "defasagem", "defensiva", "delegacao", "delineado",
            "demagogia", "democrata", "densidade", "deposicao", "depressao", "derivacao", "derrocada", "desacordo", "desajuste", "desespero",
            "desilusao", "desolacao", "despedida", "diabolico", "diferenca", "dignidade", "dilatacao", "diluviano", "dinamismo", "diplomata",
            "diretoria", "dirigente", "discordia", "discussao", "distancia", "divinacao", "documento", "domestico", "dominacao", "donatario",
            "dualidade", "duplicata", "ebuliente", "economico", "editorial", "educativo", "eficiente", "embaixada", "emboscada", "emergente",
            "emigrante", "emocional", "empolgado", "empregado", "enamorado", "encantado", "encarnado", "encenacao", "endorfina", "engasgado",
            "enrolacao", "entediado", "epilepsia", "esclerose", "escorpiao", "escotilha", "esculpido", "escuridao", "esmeralda", "espaguete",
            "esperanca", "espinhaco", "esplanada", "estalagem", "estrelado", "estudante", "estudioso", "eucalipto", "exaltacao", "excavacao",
            "excelente", "exclusivo", "executivo", "expedicao", "explosivo", "exposicao", "expositor", "expressao", "extorsivo", "faculdade",
            "faiscante", "falsidade", "fanatismo", "federacao", "feminismo", "feminista", "ferradura", "festejado", "figurante", "filmadora",
            "filosofia", "filtracao", "flutuante", "fortaleza", "framboesa", "frequente", "fronteira", "fuzileiro", "gafanhoto", "garantido",
            "gazeteiro", "geladeira", "geminiano", "gengivite", "geometria", "geriatria", "gentileza", "ginastico", "giratorio", "gladiador",
            "glicerina", "goiabeira", "gramatica", "grandioso", "gravidade", "grelhador", "guarnicao", "guindaste", "habitacao", "habitante",
            "harmonico", "herbivoro", "hermetico", "hesitacao", "hispanico", "histerico", "historico", "holograma", "humanismo", "humanista",
            "humorista", "idealista", "ideologia", "ignorante", "igualdade", "ilustrado", "imaculado", "imigracao", "imigrante", "imperador",
            "imponente", "imposicao", "impressao", "impressor", "incognito", "incubacao", "indagacao", "indicacao", "individuo", "industria",
            "iniciacao", "inimizade", "inquerito", "inquilino", "instancia", "instituto", "instrucao", "instrutor", "intelecto", "interacao",
            "interface", "internato", "intimacao", "intrepido", "inundacao", "inventivo", "invernada", "invocacao", "irrigacao", "islamismo",
            "jacaranda", "juramento", "juventude", "labirinto", "lagartixa", "lambuzado", "lamparina", "lapideira", "legalismo", "lembranca",
            "letargico", "liberdade", "lideranca", "ligamento", "limitacao"
        };


    static std::string palavras10[400] = {
    "abominavel", "acelerador", "acentuacao", "acidentado", "acomodacao", "acrobatico", "acucararia", "acumulacao", "adaptativo", "adocicante",
    "adulterado", "adversario", "afortunado", "agricultor", "aguardente", "alfabetico", "alojamento", "alucinante", "amadorismo", "ambulancia",
    "amendoeira", "amostragem", "analfabeto", "anarquismo", "anarquista", "anfiteatro", "anglicismo", "angustiado", "animalismo", "antiquario",
    "apologista", "apreciacao", "arrogancia", "articulado", "artilharia", "assembleia", "assinatura", "assistente", "associacao", "astrologia",
    "astronomia", "atualidade", "atualizado", "autoridade", "autorizado", "azulejista", "amostrador", "arquivista", "bacteriano", "balconista",
    "bandoleiro", "barbarismo", "batalhador", "biblioteca", "bilionario", "biografico", "bloqueador", "bombardeio", "borrachudo", "brasileiro",
    "brincalhao", "bronzeador", "burocracia", "beneficial", "bocejadora", "broqueador", "cacofonico", "calendario", "caligrafia", "camuflagem",
    "candelabro", "cangaceiro", "capacidade", "caprichoso", "carburador", "carcereiro", "caricatura", "carnivoria", "carroceiro", "cascavilho",
    "cataclismo", "celebracao", "cenografia", "centenario", "centigrado", "cerimonial", "charlatano", "ciclotrono", "coagulacao", "cobrimento",
    "comediante", "comentario", "comodidade", "competente", "competicao", "composicao", "comprimido", "computacao", "comunidade", "condenacao",
    "consciente", "consumidor", "continente", "cordelista", "corpulento", "corrimento", "cozinheiro", "credencial", "cronometro", "crucifixao",
    "cruzamento", "civilidade", "corneteiro", "daltonismo", "declaracao", "defeituoso", "demarcacao", "democracia", "dependente", "deportacao",
    "desastrado", "descoberta", "deseducado", "desemprego", "desenhista", "desgracado", "desiludido", "desordeiro", "desportivo", "desventura",
    "dicionario", "diligencia", "disciplina", "documental", "dramaturgo", "duplicacao", "decomposto", "disposicao", "desfalcado", "docilidade",
    "eclesiaste", "ecologista", "economista", "edificacao", "elaboracao", "eleitorado", "eliminacao", "embaixador", "empacotado", "empregador",
    "empresario", "encantador", "enfermeiro", "engenharia", "engenheiro", "engraxador", "entusiasmo", "entusiasta", "esburacado", "escaladora",
    "escritorio", "escultural", "espadachim", "espantalho", "especifico", "espectador", "espetaculo", "espontaneo", "estagiario", "estrategia",
    "estrutural", "etimologia", "eucaristia", "exageracao", "excelencia", "exportador", "expressivo", "extradicao", "extremista", "explorador",
    "exportacao", "evaporacao", "fabricacao", "facilitado", "fantastico", "fascinacao", "federativo", "felicidade", "figurativo", "filantropo",
    "folclorico", "formidavel", "fotografia", "franqueado", "fatalidade", "fidelidade", "finalidade", "facilidade", "futilidade", "fornecedor",
    "fundamento", "fechamento", "garimpeiro", "gastronomo", "gelatinoso", "gemelidade", "genealogia", "geriatrico", "governador", "governante",
    "gramatical", "guilhotina", "gladiadora", "gravitacao", "galhofeiro", "habilidade", "hemisferio", "herborista", "hidraulico", "hidrofobia",
    "hipertenso", "hipopotamo", "homeopatia", "hospedeiro", "hospitalar", "hidratacao", "hipocrisia", "hemorragia", "hegemonico", "iconografo",
    "idealizado", "identidade", "idiomatico", "ignorancia", "iluminacao", "ilustracao", "imperativo", "imperatriz", "implicacao", "importador",
    "importante", "impossivel", "imprudente", "inalterado", "inclinacao", "indefinido", "indeferido", "indignacao", "inesperado", "infantaria",
    "infeccioso", "infinitude", "inflamacao", "informacao", "inglesinha", "inspiracao", "instalacao", "integracao", "intendente", "introducao",
    "inventario", "importacao", "imaginacao", "inoculacao", "jardineiro", "jornalista", "jornaleiro", "justiceiro", "julgamento", "justamente",
    "lancamento", "latifundio", "legislacao", "letramento", "licenciado", "liquidacao", "literatura", "locomotiva", "lanchonete", "lavanderia",
    "legalidade", "maquinaria", "macrobiota", "madrugador", "magistrado", "magnetismo", "mandatario", "mandibular", "manutencao", "maquinista",
    "marceneiro", "marinheiro", "marmoraria", "matematica", "mecanizado", "melancolia", "mencionado", "mensageiro", "mercadoria", "mercenario",
    "mesquinhez", "metalurgia", "microfilme", "milionario", "ministerio", "mobiliario", "mulherengo", "moralidade", "mobilidade", "narcisismo",
    "narcisista", "nascimento", "necessario", "negociacao", "neurologia", "noticiario", "natalidade", "obediencia", "obliterado", "observacao",
    "observador", "obstinacao", "oligarquia", "orientacao", "ornamental", "ortodontia", "ostentacao", "otimizacao", "orcamental", "onisciente",
    "palavreado", "pandemonio", "parachoque", "paralisado", "partidario", "passageiro", "passarinho", "patriarcal", "pecaminoso", "pedagogico",
    "penalidade", "penetracao", "penhorador", "pensamento", "pentagrama", "perceptivo", "perfumaria", "periodista", "persecutor", "personagem",
    "pessimismo", "pessimista", "pistoleiro", "pitagorico", "pluralismo", "politizado", "predatorio", "privilegio", "procurador", "professora",
    "proletario", "psicologia", "psiquiatra", "publicacao", "preparacao", "perfuracao", "parlamento", "perfurador", "quadratura", "quantidade",
    "quarentena", "queimadura", "quilometro", "quiroptero", "radioativo", "reclamacao", "recompensa", "referencia", "regimental", "rendimento",
    "reparticao", "reproducao", "residencia", "resolutivo", "respectivo", "respiracao", "retratista", "reumatismo", "reveladora", "rodoviario",
    "romancista", "rivalidade", "retardacao", "recordacao", "sacerdotal", "sacrificio", "saneamento", "secretaria", "segregacao", "semelhanca"
};



std::string sortear(int x) {


    switch(x) {
        case 4: {
        return palavras4[rand() % 391]; 
        //rand()% N = numero aleatorio entre 0 e N-1
    }

        case 5: {
        return palavras5[rand() % 395]; 
        }

        case 6: {
            return palavras6[rand() % 395]; 
        }

        case 7: {
            return palavras7[rand() % 395]; 
        }
        
        case 8: {
            return palavras8[rand() % 395]; 
        }

        case 9: {
            return palavras9[rand() % 395]; 
        }

        case 10: {
            return palavras10[rand() % 400]; 
        }


    }

    return 0;

}






int main() {

    srand(time(0)); //para a escolha de uma palavra aleatoria nas listas 
    int vidas;
    bool checagem1 = true;
    bool checagem2 = true;


        while (checagem1) {

        int escolha;


        std::cout << "==========BEM-VINDO(A)==========\n";
        std::cout << "=========JOGO DA FORCA=========\n";
        std::cout << std::endl;

        std::cout << "Vamos jogar forca? Forca eh um jogo muito divertido que se baseia em um principio simplerrimo:\n";
        std::cout << "Raciocinio logico combinado com conhecimento sobre palavras\n";
        std::cout << "Vamos nessa?\n";
        std::cout << std::endl;

        std::cout << "Digite uma das opcoes no seu teclado\n";
        std::cout << std::endl;

        std::cout <<" 1 - Comecar a jogar\n";
        std::cout <<" 2 - Creditos\n";
        std::cout <<" 3 - Sair\n";
        
        std::cout << std::endl;
        std::cout << "Minha escolha eh:\n";
        std::cin >> escolha;    

        //ao digitar 42, por exemplo, no buffer fica 42\n
        //entao, ao passar pelo loop, ele entra na primeira opcao (if escolha != 1 && escolha != 2...)
        //mas quando volta aqui, o \n esta sozinho. Entao o compilador passa direto pelo cin, achando que ja tem outra resposta


        std::cin.clear();   //limpa flags de erro. ex: digitou string ao inves de int

        //std::cin.ignore(100000, '\n'); ignore caracteres ate atingir o limite OU ate encontrar o delimitador
        //ex: supondo que o parametro é (100, \n)
        //usuario digita um numero de 50 caracteres. Ele ignora os 50 caracteres e encontra o \n. Funciona
        //usuario digita um numero de 150 caracteres. Ele ignora os 100 primeiros e PARA mesmo sem ter encontrado o \n
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //nesse contexto, ignorar significa que ele vai percorrer o numero de elementos que se encontra no primeiro parametro
        //ate chegar no segundo parametro. Entao em (100, \n) ele percorreria os 100 elementos, mas se encontrasse o  \n antes, pararia
        //(Aqui, o sentido de ignorar os 100 primeiros elementos eh que ele esta na busca pelo \n)
        //(agora, quando ele encontra o \n, ai ele ignora o \n. Se ele passa de 100 caracteres, da problema, porque o \n esta fora desse alcance de 100 caracteres)
   
        //O PULO DO GATO
        //O ignore NAO DESCARTA O 42, por exemplo. O numero que voce digitou ja foi consumido e esta na variavel "escolha"
        //O ignore SO VE O QUE SOBROU NO BUFFER

        std::cout << std::endl; 

        if (escolha != 1 && escolha != 2 && escolha != 3) {
                std::cout << "Escolha errada! Mais atencao na proxima vez!\n";
                std::cout << std::endl;
        }

        if (escolha == 1) {

            checagem2 = true;

            int escolhaTamanho;
            std::string palavraSorteada;
            char palavraOculta[10];

            std::cout << "Qual o tamanho da palavra? Min: 4, Max: 10\n."; 
            std::cout << "Apenas substantivos e adjetivos. A maioria das palavras nao tem acento\n";
            std::cout << "Regra: digite as letras em letra MINUSCULA\n";
            std::cout << std::endl;
            std::cin >> escolhaTamanho;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        

            switch (escolhaTamanho) {
                case 4: {

                    palavraSorteada = sortear(4);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 7;

                break;
                }

                case 5: {

                    palavraSorteada = sortear(5);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 8;


                break;
                }

                case 6: {

                    palavraSorteada = sortear(6);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 8;

                break;
                }

                case 7: {

                    palavraSorteada = sortear(7);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 9;

                break;
                }

                case 8: {

                    palavraSorteada = sortear(8);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 10;

                break;
                }

                case 9: {

                    palavraSorteada = sortear(9);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 19;

                break;
                }

                case 10: {

                    palavraSorteada = sortear(10);

                    for (int i = 0; i < escolhaTamanho; i++)
                    palavraOculta[i] = '_';

                    vidas = 100;

                break;
                }

                default: { //numero maior que 10 e menor que 4

                std::cout << std::endl;
                std::cout << "Tamanho errado! O numero pode ir de 4 A 10!\n";
                std::cout << std::endl;
                continue; // pula para o proximo iterador de while(checagem)

                }
            
            }
        

        std::cout << std::endl;




            int numeroTentativas = 0;
            char letraJogador;
            char letrasUsadas[26];
            char ultimaLetra = '-';

        while (checagem2) {

            

            for (int i = 0; i < escolhaTamanho; i++) {
            std::cout << palavraOculta[i] << " ";
            }

            std::cout << std::endl;

            std::cout << "Vidas: " << vidas << std::endl;

            std::cout << "Letras usadas: ";
            for (int i = 0; i < numeroTentativas; i++) {
            std::cout << letrasUsadas[i] << " ";
            }

            std::cout << std::endl;


            std::cout << "Ultima letra digitada: " << ultimaLetra << std::endl;
            
            std::cout << std::endl;

            std::cout << "Digite a letra!\n";
            std::cin >> letraJogador;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        



            bool letraRepetida = false;

            for (int i = 0; i < numeroTentativas; i++) {
                if (letraJogador == letrasUsadas[i])
                letraRepetida = true;
                break;
            }

            if(letraRepetida) {
            std::cout << "\nOpa! Voce ja tentou a letra '" << letraJogador << "'. Escolha outra!\n\n";                
            std::cout << std::endl;
                continue;
            }





            ultimaLetra = letraJogador;

            letrasUsadas[numeroTentativas] = letraJogador;

            bool acertou = false;

            numeroTentativas++;

        for (int i = 0; i < escolhaTamanho; i++)
            if (letraJogador == palavraSorteada[i]) {
                palavraOculta[i] = letraJogador;
                acertou = true;
            }

            if (!acertou) vidas--;

            if (vidas <= 0) {
                std::cout << std::endl;
                std::cout << "Puxa! Infelizmente, voce perdeu! Tente novamente\n";
                std::cout << "A palavra sorteada era: " << palavraSorteada << std::endl;
                std::cout << std::endl;
                checagem2 = false;
                continue;
            }

        


            int numeroLetrasQueCombinam = 0;
            
            for (int i = 0; i < escolhaTamanho; i++) {

                if (palavraSorteada[i] == palavraOculta[i])
                numeroLetrasQueCombinam++;

                if(numeroLetrasQueCombinam == escolhaTamanho) {
                checagem2 = false;
                break;
                }

        }


        }






        for (int i = 0; i < escolhaTamanho; i++) {
            std::cout << palavraOculta[i] << " ";
            }

            if (vidas > 0) {
 
            std::cout << std::endl;
            std::cout << "Meus parabens! Voce acertou!\n";
            std::cout << "A palavra era: " << palavraSorteada << std::endl;
            std::cout << std::endl;

            }

    
        }

        if (escolha == 2) {
            std::cout << "Desenvolvido por Marco Thullyo Sao Severino. Obrigado por jogar! <3\n";
            std::cout << std::endl;
        }

        if (escolha == 3) {
            std::cout << "Tchauzinho!\n";
            return 0;
        }







        }







    return 0;

}









