#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#define max 10

typedef struct VEICULO
{
	char marca[30];
	char modelo[30];
	int ano;
};

void incluir()
{
	VEICULO vei;
	
	FILE *automoveis;
	automoveis=fopen("automoveis.txt","a+");
	
	if(automoveis == NULL)
	{
		printf("Arquivo inexistente");
		exit(1);	
	}	
	int aux=0;
	while(aux<10)
	{
		fflush(stdin);
		printf("\nDigite uma marca: ");
		gets(vei.marca);
		if(strstr(vei.marca,"@fim")!=NULL)
		{
			printf("Laço encerrado...");
			getch();
			break;
		}
		fprintf(automoveis,"\nMarca: %s",vei.marca);
		
		printf("\nDigite um modelo: ");
		gets(vei.modelo);
		fprintf(automoveis,"\nModelo: %s",vei.modelo);
		
		printf("\nDigite o ano do carro: ");
		scanf("%d",&vei.ano);
		fprintf(automoveis,"\nAno: %d",vei.ano);
	}
	fclose(automoveis);
}

void iniciacao()
{
	VEICULO vei;
	
	char string[60];
	char verificar[30];
	char verificar2[30];
	int aux=0;
	FILE *automoveis;
	automoveis = fopen("automoveis.txt","r+");
	
	if(automoveis == NULL)
	{
		printf("Arquivo inexistente");
		exit(1);	
	}
	
	while(!feof)
	{
		fscanf(automoveis,"%s %s",string,vei.marca);
		fscanf(automoveis,"%s %s",string,vei.modelo);
		fscanf(automoveis,"%s %d",string,vei.modelo);
		
		fscanf(automoveis,"%s %s",string,verificar);
		if(!feof)
		if(strstr(vei.marca,verificar)==NULL)
		{
				FILE *automoveis;
				automoveis = fopen("automoveis[aux].txt","a+");
	
				if(automoveis == NULL)
				{
					printf("Arquivo inexistente");
					exit(1);	
				}
					fprintf(automoveis,"Marca: %s",vei.marca);
					fprintf(automoveis,"Modelo: %s",vei.modelo);
					fprintf(automoveis,"Ano: %d",vei.modelo);
					fclose(automoveis);
			
		}
		else
		{
			FILE *automoveis;
			automoveis = fopen("automoveis[aux].txt","a+");
	
			if(automoveis == NULL)
			{
				printf("Arquivo inexistente");
				exit(1);	
			}
			fprintf(automoveis,"Marca: %s",vei.marca);
			fprintf(automoveis,"Modelo: %s",vei.modelo);
			fprintf(automoveis,"Ano: %d",vei.modelo);
			fclose(automoveis);
		}
		strcpy(verificar2,vei.marca);
		aux++;
	}
	fclose(automoveis);
}


int main()
{
	setlocale(LC_ALL,"portuguese");
	incluir();
	iniciacao();
	
}
