#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct informacoes
{
	char Nome[30];
	int Idade;
};

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	int quantidade;
	struct informacoes *p;
	
	printf("Quantas pessoas você irá cadastrar: ");
	scanf("%d",&quantidade);
	informacoes info;
	p = (struct informacoes*) malloc(quantidade *sizeof(info));
	
	fflush(stdin);
	for(int aux=0;aux<quantidade;aux++)
	{
		fflush(stdin);
		printf("\nDigite o nome da pessoa: ");
		gets(p[aux].Nome);
	
		printf("\nDigite a idade da pessoa: ");
		scanf("%d",&p[aux].Idade);
	}
	
	printf("/////////////////////////////////");
	printf("\nAs informações colocadas foram: ");
	
	for(int aux=0;aux<quantidade;aux++)
	{
		printf("\nO nome da pessoa: %s ",p[aux].Nome);
		
		printf("\nA idade da pessoa: %d ",p[aux].Idade);
	}
	
}
