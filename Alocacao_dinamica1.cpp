#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	//variavel usada para gravar quantidades de números que serão usados.
	int num;
	
	printf("Quantos números voce quer digitar: ");
	scanf("%d",&num);
	
	//declaração do ponteiro mais malloc reservando espaço na memória de acordo com
	//a quantidade exigida pelo úsuario.
	int *p = (int*) malloc(num *sizeof(int));
	
	//grava os números nos endereços de memoria separados por malloc.
	for(int aux=0;aux<num;aux++)
	{
		printf("\nDigite um número: ");
		scanf("%d",&p[aux]);
	}
	
	printf("/////////////////////////");
	printf("\nOs números digitados foram: ");
	
	for(int aux=0;aux<num;aux++)
	{
		//mostra os números gravados no endereços de memória separados por malloc.
		printf("\nO %d número de %d é :%d ",aux+1,num,p[aux]);
	}
	//obs: malloc so separa o endereço caso você não grave nada no endereço tem uma chance muito alta
	//de ter sujeira nele, caso queira uma inicição com zero é melhor usar calloc.
}
