#include <stdio.h>
#include <stdlib.h>

struct Relacao{
    float importacao;
    float exportacao;
    int anoInicio;
};

typedef struct Relacao Relacao;

//********************************************

void buildMatriz(int V, Relacao *G[V][V]){
    // inicializa as linhas e colunas da matriz
    for(int l=0;l<V;l++){
        for(int c=0;c<V;c++){
            G[l][c]=NULL;
        }
    }
}

//********************************************

int main(){

    // quantidade de vértices
    printf("Digite a quantidade de paises desejados: ");
    int V;
    scanf("%d",&V);
    // criação da matriz de adjacência
    Relacao *G[V][V];
    //buildMatriz(V,G); // inicialização da matriz de adjacência

    int opt=1;
    do{
        printf("Escolha uma das opções abaixo:\n");
        printf("1 - Sair\n");
        printf("2 - Verificar relação\n");
        printf("3 - Criar relação\n");
        scanf("%d",&opt);
        if(opt==2){
            verificarRelacao();
        }else if(opt==3){
            criarRelacao();
        }
    }while(opt!=1);
    
    return 0;
}

