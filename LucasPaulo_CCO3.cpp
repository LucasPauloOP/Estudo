#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

//variavel para guarda opcoes do menu.
int opc;

//struct para endereco da pessoa cadastrada.
typedef struct endereco
{
	char rua[30];
	char bairro[30];
	char cidade[30];
	char estado[30];
	int num;
};

//struct para nome e telefone da pessoa cadastrada.
typedef struct cadastro
{
	char nome[30];
	int telefone;
	endereco end;
};


void menu()
{
	system("cls");
	printf("#########################");
	printf("\n#\t1-Incluir\t#");
	printf("\n#\t2-Pesquisar\t#");
	printf("\n#\t3-Sair\t\t#");
	printf("\n#########################");
	printf("\nDigite a opção de sua escolha: ");
	scanf("%d",&opc);
}

void incluir()
{
	//funcao para incluir uma informação no arquivo.
	fflush(stdin);
	system("cls");
	cadastro cad;
	
	//abertura do arquivo
	FILE *agenda;
	agenda = fopen("agenda.txt","a+");
	
	//controle de erro do arquivo.
	if(agenda == NULL)
	{
		printf("Arquivo inexistente...");
		exit(1);
	}
	
	//caso contrário segue o cadastro normalmente
	else
	{
		//Usando o gets grava a informação e usando o fprintf escreve a infromação no arquivo.
		
		printf("\nDigite o nome: ");
		gets(cad.nome);
		fprintf(agenda,"Nome: %s",cad.nome);
		
		printf("\nDigite o telefone: ");
		scanf("%d",&cad.telefone);
		fprintf(agenda,"\nTelefone: %d",cad.telefone);
		
		printf("\n-------Digite seu endereço------\n");
		fflush(stdin);
		
		printf("\nDigite sua cidade: ");
		gets(cad.end.cidade);
		fprintf(agenda,"\nCidade: %s",cad.end.cidade);
		
		printf("\nDigite seu bairro: ");
		gets(cad.end.bairro);
		fprintf(agenda,"\tBairro: %s",cad.end.bairro);
		
		printf("\nDigite sua rua: ");
		gets(cad.end.rua);
		fprintf(agenda,"\tRua: %s",cad.end.rua);
		
		printf("\nDigite o número da casa: ");
		scanf("%d",&cad.end.num);
		fprintf(agenda,"\tNúmero: %d",cad.end.num);
		fflush(stdin);
		fprintf(agenda,"\n\n");
		
		//fecha o arquivo
		fclose(agenda);
	}
	
	
}

void pesquisar()
{
	//funcao usada para pesquisar uma informação no arquivo
	//OBS: quando fecha o arquivo o curso fica no final da informação por isso optei por reabrir o arquivo no pesquisar
	//para automaticamente o curso fica no começo do arquivo facilitando a leitura.
	
	fflush(stdin);
	system("cls");
	char nome_pesq[60];
	cadastro cad;
	char string[60];
	FILE *agenda;
	agenda = fopen("agenda.txt","r");
	
	//variavel usada para contabilizar se achou ou nao um nome.
	int contador = 0;

	if(agenda == NULL)
	{
		printf("Arquivo inexistente...");
		exit(1);
	}
	else
	{
		
		printf("Digite o nome a ser pesquisado: ");
		gets(nome_pesq);
		while(!feof(agenda))
		{
			//le o arquivo.
			//string le informacoes despreziveis, como a palavra nome ou telefone.
			//strings uteis sao salvas em variaveis diferentes para serem usadas na comparação.
			
				fscanf(agenda,"%s %s",string,cad.nome);
				fscanf(agenda,"%s %d",string,&cad.telefone);
				fscanf(agenda,"%s %s",string,cad.end.cidade);
				fscanf(agenda,"%s %s",string,cad.end.bairro);
				fscanf(agenda,"%s %s",string,cad.end.rua);
				fscanf(agenda,"%s %d",string,&cad.end.num);
				
			//impede do programa mostrar as informações ja salvas uma 
			//segunda vez mais quando atinge o final do arquivo.
			if(!feof(agenda))
			
			//compara as strings se for igual retorna valor diferente de NULL.
			if(strstr(nome_pesq,cad.nome) != NULL )
			{
				//contador muda para 1 conabilizando que a pessoa em questão foi encontrada.
				contador = 1;
				//mostra as informações do cadastrado na tela.
				printf("\nTelefone: %d",cad.telefone);
				printf("\nCidade: %s",cad.end.cidade);
				printf("\nBairro: %s",cad.end.bairro);
				printf("\nRua: %s",cad.end.rua);
				printf("\nNumero da casa: %d",cad.end.num);
				printf("\n");
				getch();
			}
		}
		//caso o contador nao mude para  1  a pessoa nao existe no cadastro
		if(contador == 0 )
			{
				printf("\n#################################");
				printf("\n#\tPessoa não cadastrada\t#");
				printf("\n#################################");
				getch();
			}
			//fechar o  arquivo.
		fclose(agenda);
	}
}

int main()
{
	setlocale(LC_ALL,"portuguese");
	do
	{
		menu();
		if(opc==1)
		{
			incluir();
		}
		
		if(opc==2)
		{
			pesquisar();
		}
		
		if(opc==3)
		{
			printf("Programa sendo fechado...");
		}
	}
	while(opc!=3);
	
}
