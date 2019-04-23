#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	//variavel usada para gravar quantidades de n�meros que ser�o usados.
	int num;
	
	printf("Quantos n�meros voce quer digitar: ");
	scanf("%d",&num);
	
	//declara��o do ponteiro mais malloc reservando espa�o na mem�ria de acordo com
	//a quantidade exigida pelo �suario.
	int *p = (int*) malloc(num *sizeof(int));
	
	//grava os n�meros nos endere�os de memoria separados por malloc.
	for(int aux=0;aux<num;aux++)
	{
		printf("\nDigite um n�mero: ");
		scanf("%d",&p[aux]);
	}
	
	printf("/////////////////////////");
	printf("\nOs n�meros digitados foram: ");
	
	for(int aux=0;aux<num;aux++)
	{
		//mostra os n�meros gravados no endere�os de mem�ria separados por malloc.
		printf("\nO %d n�mero de %d � :%d ",aux+1,num,p[aux]);
	}
	//obs: malloc so separa o endere�o caso voc� n�o grave nada no endere�o tem uma chance muito alta
	//de ter sujeira nele, caso queira uma inici��o com zero � melhor usar calloc.
}
