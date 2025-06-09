#include <stdio.h>
#include <stdlib.h>

struct Aluno{
  char nome[50];
  int idade;
  float nota;
};

struct Aluno aluno[3];

void listarAlunos () {
    for(int i=0; i<3; i++){
        printf("Nome: %s\n", aluno[i].nome);
        printf("Idade: %d\n", aluno[i].idade);
        printf("Nota: %.2f\n", aluno[i].nota);
        printf("-------------------------\n");
    }
}

int main(){
    
    for(int i=0; i<3; i++){
        printf("Digite os dados do aluno:\n");
        printf("Nome: ");
        scanf("%s", aluno[i].nome);
        printf("Idade: ");
        scanf("%d", &aluno[i].idade);
        printf("Nota: ");
        scanf("%f", &aluno[i].nota);
        getchar();
        system("clear");
    }
    
    listarAlunos ();
    
    return 0;
}
