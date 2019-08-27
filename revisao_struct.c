#include<stdio.h>
#include<stdlib.h>
#define max 5
#include<locale.h>

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
	
	setlocale(LC_ALL,"portugues");
	
	pessoa p1[max];
	int aux;
	
	for(aux=0;aux<5;aux++)
	{
		system("cls");
		
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
			
		printf("\n-----------------------------------------");
		getch();
	}
	
	pessoa aux2;
	int i,j,min;
		
	//Uso do método de seleção de selection sort.
	//Menos caro em processamento do que o bolha.
	
	//Usando índice.
	for (i=0; i<max-1; i++){
	        min = i;
	        
	    for (j=i+1; j<max; j++){
	    	
	       	 if (p1[j].idade < p1[min].idade)
	        	min = j;
	         
	    }
	    
		aux2 = p1[min];
	    p1[min] = p1[i];
		p1[i] = aux2;
		
	}
	
	//Usando uma variável da struct direto
	
/*	int pmenor;
	
	for (i=0; i<max-1; i++){
		
	        aux2 = p1[i];
	        
	    for (j=i+1; j<max; j++){
	    	
	       	 if (p1[j].idade < aux2.idade)
	        	aux2 = p1[j];
	        	pmenor=j;
	    }
	    
		p1[pmenor]=p1[i];
		p1[i] = menor;
		
	}*/
	
	
        for ( i=0; i<max; i++){
            printf("\n%s",p1[i].nome);
        }
    
}
