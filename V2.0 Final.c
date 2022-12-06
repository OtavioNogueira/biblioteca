#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 225

typedef struct livro {
    char titulo[MAX];
    char autor[MAX];
} Livro;   //objeto livro

typedef struct no {
    Livro *livro;       //criar o objeto do tipo livro
    struct no *proximo;
} No;

typedef struct lista {
    int tamanho; //tamanho a ser definido
    No *primeiro;
} Lista;   //objeto lista para ter controle de livros criados

char *getString(char *mensagem) {
    char *string = (char *) malloc(MAX * sizeof(char)); //aloca memória para armazenar o valor de 'MAX' strings

    printf("%s", mensagem);
    fgets(string, MAX, stdin);  //Lê a mensagem inserida
    string[strcspn(string, "\n")] = '\0';   //a função strcspn() vai percorrer a string procurando o "\n, quando ele encontrar essa posição ela será o tamanho da string, pois terá chegado no final, assim atribuindo '\0', conhecido como fim de uma string

    return string;
}   //Lê qual string foi inserida para a consulta específica de autor ou título

void imprimirLivro(Livro *livro) {
    if (livro == NULL) {
        return;
    }               //se a função estiver recebendo o livro com NULL já vindo de outra função(listar e consultar por título ou autor), realize os printfs

    printf("Titulo: %s \n", livro->titulo);
    printf("Autor: %s \n", livro->autor);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");

} //imprimir determinado livro quando chamada

void menu(){

    printf("___||______________________||___\n \n");
    printf("    ___|| BIBLIOTECA ||___ \n \n");

    printf("=-=-=-=-=-= Menu =-=-=-=-=-=-=-=- \n \n"
           "[ 1 ] - Cadastrar \n"
           "[ 2 ] - Listar \n"
           "[ 3 ] - Consultar por titulo \n"
           "[ 4 ] - Consultar por autor \n"
           "[ 0 ] - Sair \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");

}    //exibir o menu

void clear(){
    for (int i = 0; i < 10; i++){
        printf("\n \n \n \n \n \n \n \n \n \n");    //um 'for' para pular várias linhas e 'limpar' a tela das informações anteriores, pois a função system() é propensa a erros
    }
}   // "limpar" a tela com uma sequência de linhas

void listar(Lista *lista) {
    if (lista == NULL || lista->tamanho == 0) {
        return;
    }               //se a lista estiver recebendo NULL de outra função ou seu tamanho ser 0, retorne o processo

    No *no = lista->primeiro;

    while (no != NULL) {            //enquanto NULL não for recebido, continue chamando a função para imprimir os livros já inseridos
        imprimirLivro(no->livro);
        no = no->proximo;
    }
}     //opção listar os livros já inseridos

Livro *cadastrar(){
    Livro *livro = (Livro *) malloc(sizeof(Livro));
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
    strcpy(livro->titulo, getString("Digite o titulo: "));  //a função strcpy() copia o conteúdo de uma string para outra, ou seja, ela vai literalmente copiar o que vier na getString() e atribuir ao título ou autor
    strcpy(livro->autor, getString("Digite o autor: "));
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");

    return livro; //retorna um livro, pois foi criado e adicionado
}     //inserção de novo livro

Lista *criarLista() {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    lista->tamanho = 0;         //inicializa
    lista->primeiro = NULL;     //atribui que não há valor inserido ainda, logo, primeiro

    return lista;
}   //cria uma nova lista ao ser chamada

Livro *consultarPorAutor(Lista *lista, char *autor) {
    if (lista == NULL || autor == NULL || lista->tamanho == 0) {
        return NULL;           //se a lista estiver recebendo NULL de outra função ou autor estiver recebendo nulo ou seu tamanho ser 0, retorne nulo
    }

    No *no = lista->primeiro;

    while (no != NULL) {
        if (strcasecmp(no->livro->autor, autor) == 0) {
            return no->livro;
        }
                                //Compara a charactere da variável autor enquanto for diferente, quando for igual retorna o livro cadastrado
        no = no->proximo;
    }

    return NULL;
}   //realiza a consulta por autores já inseridos

Livro *consultarPorTitulo(Lista *lista, char *titulo) {
    if (lista == NULL || titulo == NULL || lista->tamanho == 0) {
        return NULL;                //se a lista estiver recebendo NULL de outra função ou o titulo estiver recebendo nulo ou seu tamanho ser 0, retorne nulo
    }

    No *no = lista->primeiro;

    while (no != NULL) {
        if (strcasecmp(no->livro->titulo, titulo) == 0) {   //função strcasecmp() comparando duas strings idependente de sua formatação
            return no->livro;
        }
                                    //Compara a charactere da variável titulo enquanto for diferente, quando for igual retorna o livro cadastrado
        no = no->proximo;
    }

    return NULL;
} //realiza a consulta por títulos já inseridos

int adicionar(Lista *lista, Livro *livro) {
    if (lista == NULL || livro == NULL) {
        return -1;
    }               //se lista e livro vierem com NULL de cadastrar, realize o processo e adicione na lista

    No *novo = (No *) malloc(sizeof(No)); //aloca memória para novo 
    novo->livro = livro;    //novo livro
    novo->proximo = NULL;   

    if (lista->tamanho == 0) {
        lista->primeiro = novo; //se o tamanho da lista for zero, primeiro valor recebe um novo dado
    } else {
        No *no = lista->primeiro;   //caso contrário, apenas adicione um novo

        while (no->proximo != NULL) {
            no = no->proximo;           //enquanto um dado novo estiver sendo eviado, entre na "lista de inserção"
        }

        no->proximo = novo;     // proximo receberá a adição de um novo valor
    }

    lista->tamanho += 1; // adicione 1 valor ao tamanho da lista
    return lista->tamanho;
}     // adiciona um novo livro na lista

int main (){
    
    setlocale(LC_ALL, "Portuguese");

    Lista *lista = criarLista();        //criando uma nova lista e chamando a função para isso
    Livro *livro = NULL;                // o NULL indica que o ponteiro não aponta para nenhum valor na memória ainda

    int opcao, opcao2;              //'opcao' para o switch case do menu; 'opcao2' para o switch case do menu de retorno
    char *entrada = (char *) malloc(225 * sizeof(char));            //variável para receber o texto nas opções que exigem inserção de texto

    do{
        menu();      //chamando a função menu

        livro = NULL;
        strcpy(entrada, "");        //essa função copia o segundo elemento no primeiro, nesse caso 'entrada' receberá um valor vazio

        printf("Por favor, escolha uma opção: ");
        scanf  ("%d", &opcao);      //lê o valor para definir o que fazer no switch case
        getchar();                  //limpa o buffer do teclado para não dar problema no case 1
        printf("\n");

        switch (opcao) {
            case 1 :        //cadastrar
                clear();    //chama função para 'limpar a tela'
                livro = cadastrar();        //livro recebendo a função que realiza o cadastro
                adicionar(lista, livro);    //livro novo adicionado
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                printf ("           CADASTROU\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");

                printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-\n"
                       "[ 1 ] - Menu \n"
                       "[ 0 ] - Sair \n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
                scanf  ("%d", &opcao2);     //lendo opção para o menu de retorno

                switch (opcao2){
                    case 1:
                    clear();
                    break;

                    case 0:
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                    printf ("            SAIU\n");
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");
                    opcao = 0;
                    break;
                }
                break;

                case 2 :    //listar
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                listar(lista);      //chamando a função para listar o livros já inseridos
                printf("\n \n \n");

                printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-\n"
                       "[ 1 ] - Menu \n"
                       "[ 0 ] - Sair \n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
                scanf  ("%d", &opcao2);

                switch (opcao2){
                    case 1:
                    clear();
                    break;

                    case 0:
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                    printf ("            SAIU\n");
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");
                    opcao = 0;
                    break;
                }
                break;

                case 3 :    //consultar por titulo
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                entrada = getString("Digite o titulo: ");
                livro = consultarPorTitulo(lista, entrada);
                imprimirLivro(livro);
                printf("\n");
                printf ("       CONSULTOU TÍTULO\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");

                printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-\n"
                       "[ 1 ] - Menu \n"
                       "[ 0 ] - Sair \n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
                scanf  ("%d", &opcao2);

                switch (opcao2){
                    case 1:
                    clear();
                    break;

                    case 0:
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                    printf ("            SAIU\n");
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");
                    opcao = 0;
                    break;
                }
                break;

                case 4 :    //consultar por autor
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                entrada = getString("Digite o autor: ");
                livro = consultarPorAutor(lista, entrada);
                imprimirLivro(livro);
                printf("\n");
                printf ("       CONSULTOU AUTOR\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");

                printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-\n"
                       "[ 1 ] - Menu \n"
                       "[ 0 ] - Sair \n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
                scanf  ("%d", &opcao2);

                switch (opcao2){
                    case 1:
                    clear();
                    break;

                    case 0:
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                    printf ("            SAIU\n");
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");
                    opcao = 0;
                    break;
                }
                break;

                case 0 :    //sair
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                printf ("            SAIU\n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");
                break;

                default :
                printf ("Valor inválido\n");

                printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-\n"
                       "[ 1 ] - Menu \n"
                       "[ 0 ] - Sair \n");
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
                scanf  ("%d", &opcao2);

                switch (opcao2){
                    case 1:
                    clear();
                    break;

                    case 0:
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                    printf ("            SAIU\n");
                    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n \n");
                    opcao = 0;
                    break;
                }


        }

    }while (opcao != 0);    //em qualquer momento que 0 for pressionado no menu, o código sem encerra


    return 0;
}