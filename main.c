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

void verificarRelacao(int V, Relacao *G[V][V]){
    printf("Digite o índice da linha (pais): ");
    int l = scanf("%d",&l);
    printf("Digite o índice da coluna (pais relacionado): ");
    int c = scanf("%d",&c);
    
    if(G[l][c] == NULL){
        printf("Não existe relacao entre os paises digitados!\n");
    }else{
        printf("A relacao existe:\n");
        printf("1-Valor Importacao = %f.\n",G[l][c]->importacao);
        printf("2-Valor Exportacao = %f.\n",G[l][c]->exportacao);
        printf("3-Inicio relacao ano = %d.\n",G[l][c]->anoInicio);
    }
};

void criarRelacao(int V, Relacao *G[V][V]){
    printf("Digite o índice da linha (pais): ");
    int l = scanf("%d",&l);
    printf("Digite o índice da coluna (pais relacionado): ");
    int c = scanf("%d",&c);
    G[l][c] = malloc(sizeof(Relacao));
    printf("\nDigite os dados da relacao:");
    printf("\nImportacoes = ");
    scanf("%f",&G[l][c]->importacao);
    printf("Exportacoes = ");
    scanf("%f",&G[l][c]->exportacao);
    printf("Ano inicio relacao = ");
    scanf("%d",&G[l][c]->anoInicio);
}

void removerRelacao(int V, Relacao *G[V][V]){
    printf("Digite o índice da linha (pais): ");
    int l = scanf("%d",&l);
    printf("Digite o índice da coluna (pais relacionado): ");
    int c = scanf("%d",&c);
    free(G[l][c]);
}

//********************************************

int main(){
    // quantidade de vértices
    printf("Digite a quantidade de paises desejados: ");
    int V;
    scanf("%d",&V);
    // criação da matriz de adjacência
    Relacao *G[V][V];
    buildMatriz(V,G); // inicialização da matriz de adjacência

    int opt=1;
    do{
        printf("Escolha uma das opções abaixo:\n");
        printf("1 - Sair\n");
        printf("2 - Verificar relação\n");
        printf("3 - Criar relação\n");
        printf("4 - Remover relação\n");
        scanf("%d",&opt);
        if(opt==2){
            verificarRelacao(V,G);
        }else if(opt==3){
            criarRelacao(V,G);
        }else if(opt==4){
            removerRelacao(V,G);
        }
    }while(opt!=1);
    
    return 0;
}

