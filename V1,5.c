#include <stdio.h>
#include <stdlib.h>

typedef struct Livro{
    char autor[50];
    char nome[50];
} Livro;

Livro Obra;

void menu(){
    
    printf("___||______________________||___\n \n");
    printf("___|| ＢＩＢＬＩＯＴＥＣＡ ||___ \n \n");
    
    printf("=-=-=-=-=-= Ｍｅｎｕ =-=-=-=-=-= \n \n"
           "[ 1 ] - Cadastrar \n"
           "[ 2 ] - Listar \n"
           "[ 3 ] - Consultar por titulo \n"
           "[ 4 ] - Consultar por autor \n"
           "[ 0 ] - Sair \n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
    
}

void clear(){
    for (int i = 0; i < 10; i++){
        printf("\n \n \n \n \n \n \n \n \n \n");
    }
}

void cadastro(){
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
    printf(" Nome do autor: ");
    fgets(Obra.autor, 50, stdin);
    printf(" Título da obra: ");
    fgets(Obra.nome, 50, stdin);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n \n");
}

void listar(){
    printf("\nObra: %d ",Obra.nome);
    printf("\nAutor(a): %s ",Obra.autor);
    printf("\n \n");
}

int main (){
    
    int opcao, opcao2; 
    
    do{
        menu();
        
        printf("Por favor, escolha uma opção:");
        scanf  ("%d", &opcao);
        printf("\n");
        
        switch (opcao) {
            case 1 :
                clear();
                cadastro();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                printf ("           CADASTROU\n");
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
    
                case 2 :
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
                listar();
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
    
                case 3 :
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
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
    
                case 4 :
                clear();
                printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
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
    
                case 0 :
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
        
    }while (opcao != 0);
    
    return 0;
}

