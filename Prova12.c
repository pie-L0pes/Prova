#include <stdio.h>
#include <stdlib.h>

struct Pizza{
    char nome[50], descricao[300];
    float preco;
    int id;
};

struct Clientes{
    char nome[50], cpf[10], telefone [11]; 
    int id;
};

int numc=0;
int num=0;
struct Pizza p[100];
struct Clientes c[100];
void Cadastrarp();
void Cadastrarc();
void Listarp();
void Listarc();
void Vender();

int main(){
    
    int opcao;
    
    do{
    printf("\033[35m");
    printf("------ Nostra Pizza ------\n");
    printf("\033[0m");
    printf("1 - Cadastrar Pizza\n");
    printf("2 - Cadastrar Clientes\n");
    printf("3 - Listar Pizzas\n");
    printf("4 - Listar Clientes\n");
    printf("5 - Vender\n");
    printf("0 - Sair\n");
    printf("Selecione uma opção: ");
    scanf("%d", &opcao);
    getchar();
    system("clear");
    switch(opcao){
        case 1:
           Cadastrarp();
           break;
        
        case 2:
           Cadastrarc();
           break;
           
        case 3:
           Listarp();
           break;
           
        case 4:
           Listarc();
           break;
           
        case 5:
           Vender();
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

void Cadastrarp(){
    
    printf("\033[35m");
    printf("------ Cadastro de Pizza ------\n");
    printf("\033[0m");
    printf("Nome: ");
    scanf(" %[^\n]", p[num].nome);
    printf("Descição: ");
    scanf(" %[^\n]", p[num].descricao);
    printf("Preço: ");
    scanf("%f", &p[num].preco);
    p[num].id= num;
    printf("\033[31m");
    printf("ID: %d\n", p[num].id);
    printf("\033[0m");
    num++;
}

void Cadastrarc(){
    
    printf("\033[35m");
    printf("------ Cadastro de Clientes ------\n");
    printf("\033[0m");
    printf("Nome: ");
    scanf(" %[^\n]", c[numc].nome);
    printf("CPF: ");
    scanf(" %[^\n]", c[numc].cpf);
    printf("Telefone: ");
    scanf(" %[^\n]", c[numc].telefone);
    c[numc].id= numc;
    printf("\033[31m");
    printf("ID: %d\n", c[numc].id);
    printf("\033[0m");
    numc++;
}

void Listarp(){
    printf("\033[35m");
    printf("------- Pizzas -------\n");
    printf("\033[0m");
    for(int i=0;i<num;i++){
        printf("%s\n", p[i].nome);
        printf("%s\n", p[i].descricao);
        printf("ID: %d\n", p[i].id);
        printf("Preço: R$%.2f\n", p[i].preco);
        printf("\033[35m");
        printf("---------------------------\n");
        printf("\033[0m");
    }
}

void Listarc(){
    printf("\033[35m");
    printf("------- Clientes -------\n");
    printf("\033[0m");
    for(int i=0;i<num;i++){
        printf("Nome: %s\n", c[i].nome);
        printf("CPF: %s\n", c[i].cpf);
        printf("Telefone: %s\n", c[i].telefone);
        printf("ID: %d\n", c[i].id);
        printf("\033[35m");
        printf("---------------------------\n");
        printf("\033[0m");
    }
}

void Vender(){
    int idp, idc, encontrado=0, correto, quant, encontrado1=1;
    printf("\033[35m");
    printf("------- Venda -------\n");
    printf("\033[0m");
    printf("ID da pizza: ");
    scanf("%d", &idp);
    for(int i=0; i<num; i++){
        if(idp==p[i].id){
            printf("ID do cliente: ");
            scanf("%d", &idc);
            encontrado=1;
            for(int i=0;i<numc;i++){
                if(idc==c[i].id){
                    encontrado1=0;
                    getchar();
                    system("clear");
                    printf("Nome do usuário: %s\n", c[idc].nome);
                    printf("Pizza: %s\n", p[idp].nome);
                    printf("Correto? (1 - Sim/ 2 - Não): ");
                    scanf("%d", &correto);
                    getchar();
                    system ("clear");
                    switch(correto){
                        case 1:
                          printf("Quantidade de pizzas: ");
                          scanf("%d", &quant);
                          getchar();
                          system ("clear");
                          printf("Total: %.2f\n", quant*p[idp].preco);
                          printf("Deseja confirmar? (1 - Sim/ 2 - Não)\n");
                          scanf("%d", &correto);
                          switch(correto){
                              case 1:
                                printf("Venda confirmada!!\n");
                                break;
                              
                              case 2:
                                printf("Venda encerrada!!\n");
                                break;
                              
                              default:
                                printf("Opção invalida!!\n");
                                break;
                          }
                          break;
                          
                        case 2:
                            printf("Venda encerrada!\n");
                            break;
                        
                        default:
                          printf("Opção invalida!!\n");
                          break;
                    }
                    
                }
                else if(encontrado1==1){
                    printf("ID de usuário não encontrado!!\n");
                }
            }
        }
        else if(encontrado==0){
            printf("ID de pizza não encontrado!!\n");
        }
    }
    
    
    
}