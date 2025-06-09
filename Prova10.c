#include <stdio.h>
#include <stdlib.h>

struct Produto{
    
    char nome[50], marca[12];
    int estoque;
    float preco;
    
};

int num=0;
struct Produto p;
void Cadastrar();
void Visualizar();
void Comprar();

int main(){
    
    int opcao;
    
    do{
    printf("\033[35m");
    printf("------ SuperMais ------\n");
     printf("\033[0m");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Visualizar informações do produto\n");
    printf("3 - Realizar compra\n");
    printf("0 - Sair\n");
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);
    getchar();
    system("clear");
    switch(opcao){
        case 1:
           Cadastrar();
           break;
        
        case 2:
           Visualizar();
           break;
           
        case 3:
           Comprar();
           break;
           
        case 0:
           printf("Volte sempre!!");
           break;
        
        default:
           printf("Opção invalida!!");
           break;
    }
    
    printf("\033[35m");
    printf("Clique enter para continuar...\n");
    printf("\033[0m");
    getchar();
    getchar();
    system("clear");
    
    }while(opcao!=0);
    
    return 0;
}

void Cadastrar(){
    
   printf("\033[35m");
    printf("------ Cadastro ------\n");
     printf("\033[0m");
    printf("Nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Marca: ");
    scanf(" %[^\n]", p.marca);
    printf("Preço: ");
    scanf("%f", &p.preco);
    printf("Quantidade em estoque: ");
    scanf("%d", &p.estoque);
    num++;
}

void Visualizar(){
    

    if(num==1){
    
     printf("\033[35m");
    printf("------ Visualizar ------\n");
     printf("\033[0m");
    printf("Nome: %s\n", p.nome);
    printf("Marca: %s\n", p.marca);
    printf("Preço: %.2f\n", p.preco);
    printf("Quantidade em estoque: %d\n", p.estoque);
    }
    else{
        printf("Nenhum produto cadastrado!!\n");
    }
}

void Comprar(){
    
    int quantidade, opcao;
    
    if(num==1){
    printf("\033[35m");
    printf("------ Compra ------\n");
    printf("\033[0m");
    printf("Produto: %s\n", p.nome);
    printf("Preço: %.2f\n", p.preco);
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidade);
    getchar();
    system ("clear");
    printf("Quantidade: %d\n", quantidade);
    printf("\033[32m");
    printf("Total: R$%.2f\n", quantidade*p.preco);
    printf("\033[0m");
    printf("\nDeseja confirmar a compra? (1 - Sim / 2 - Não\n");
    scanf("%d", &opcao);
    getchar();
    system ("clear");
    switch(opcao){
        case 1:
         printf("Compra confirmada!!\n");
         p.estoque = p.estoque - quantidade;
         break;
        
        case 2:
         printf("Compra cancelada!!\n");
         break;
         
        default:
         printf("Opção invalida!!\n");
    }
}

    else{
        printf("Nenhum produto cadastrado!!\n");
    }
}