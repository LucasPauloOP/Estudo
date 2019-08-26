#include<stdio.h>
#include<stdlib.h>
#define max 5

/* Fazer um programa para armazenar os dados de 5 pessoas (nome e idade)
em um vetor de registros, colocar os elementos do veotor em ordem crescente 
de idade, e depois
imprimir o vetor ordenado */
//#include<string.h>

typedef struct{
	
	char rua[30];
	char bairro[30];
	char estado[30];
	char cidade[30];
	int num;
	
}endereco;

typedef struct{
	char nome[30];
	endereco end;
	int idade;
	float peso;
}pessoa;

int main(){
	pessoa p1[max];
	int aux;
	
	for(aux=0;aux<5;aux++)
	{
		printf("\nDigite o nome da pessoa: ");
		fflush(stdin);
		gets(p1[aux].nome);
		
		printf("\nDigite a idade da pessoa: ");
		scanf("%d",&p1[aux].idade);
		
		printf("\nDigite o peso da pessoa: ");
		scanf("%2.f",&p1[aux].peso);
		
		fflush(stdin);
		printf("\n----------Endereco-------------");
		
		printf("\nDigite o seu estado: ");
		gets(p1[aux].end.estado);
		
		printf("\nDigite o sua cidade: ");
		gets(p1[aux].end.cidade);
		
		printf("\nDigite o seu bairro: ");
		gets(p1[aux].end.bairro);
		
		printf("\nDigite o seu rua: ");
		gets(p1[aux].end.rua);
		
		printf("\nDigite o número de sua casa: ");
		scanf("%d",&p1[aux].end.num);
	}
	
	pessoa aux2;
	int i,j;
	for ( j=max-1; j>0; j--){
        for ( i=0; i<j; i++){
            if (p1[i].idade > p1[i+1].idade){                            
                aux2 = p1[i];
               	p1[i] = p1[j];
                p1[j] = aux2;          
            }
        }
    }
	

	
}
