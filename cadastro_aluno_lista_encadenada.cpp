#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

//struct usadas para  informa��es do curso
typedef struct curso
{
	char nome[40];
	char sigla[10];
	int periodos;
};

//struct usada para informa��es do aluno
typedef struct aluno
{
	char nome[40];
	int ativo=0;
	
	//liga struct do curso e aluno, deixando aluno como principal.
	curso curso;
	
	//ponteiro que aponta a proxima lista
	aluno* prox;
};

//fun��o para mostrar o menu do sistema.
int menu(int opc)
{
	fflush(stdin);
	system("cls");
	printf("1-Incluir Aluno ");
	printf("\n2-Pesquisar Aluno");
	printf("\n3-Sair");
	printf("\nDigite a opcao pretendida: ");
	scanf("%d",&opc);
	//retorna a op��o escolhida.
	return opc;
}

//fun��o utilizada para prencher os dados do aluno cadastrado,
//recebe como parametro um endere�o de um ponteiro.
void prencher(aluno *inserir2)
{
	system("cls");
	fflush(stdin);
	
	printf("\nDigite o nome do aluno: ");
	gets(inserir2 -> nome);
	
	inserir2 -> ativo = 1;//variavel utilizada para verificar se o aluno existe.
		
	printf("\nDigite o nome do curso do aluno: ");
	gets(inserir2 -> curso.nome);
		
	printf("\nDigite a sigla do curso do aluno: ");
	gets(inserir2 -> curso.sigla);
		
	printf("\nDigite o periodo do aluno: ");
	scanf("%d",&inserir2 ->curso.periodos);
	
}

//Grava os daados pegos na lista encardenada fazendo uso,
//da fun��o strcpy para copiar as palavras.
//A fun��o recebe como parametro o endere�o da struct e o ponteiro inserir.

void inserir_dados(aluno *inserir2,aluno *inserir1)
{
	
	strcpy(inserir1->nome,inserir2->nome);
	
	inserir1 -> ativo = inserir2->ativo;
		
	strcpy(inserir1->curso.nome,inserir2->curso.nome);
		
	strcpy(inserir1->curso.sigla,inserir2->curso.sigla);
		
	inserir1->curso.periodos = inserir2->curso.periodos;
	
}

//Fun��o para inserir o nome que vai ser pesquisado, 
//recebe ele em um endere�o da struct que foi passado como par�metro.
void inserir_pesquisa(aluno*pesq2)
{
	fflush(stdin);
	system("cls");
	
	printf("Digite o aluno que deseja pesquisar: ");
	gets(pesq2->nome);
}

//Fun��o para mostrar o resultado da pesquisa,
//a fun��o recebe como par�metro um endere�o de mem�ria,
// e um ponteiro que mostra o inicio da lista. 
void pesquisar(aluno*pesq2,aluno*pesq)
{
	//verifica se acho o nome
	int verifica=0;	
	
	//roda ate o final da lista.			
	while(pesq->prox != NULL)
	{
		//se for igual os nomes mostra na tela
		if(strstr(pesq2->nome,pesq->nome) != NULL)
		{
			printf("\nO nome do aluno: %s",pesq->nome);
			printf("\nCurso: %s",pesq->curso.nome);
			printf("\nSigla do curso: %s",pesq->curso.sigla);
			printf("\nPeriodo: %d",pesq->curso.periodos);
			printf("\n------------------------------------");
			getch();
			//acha o nome verifica recebe 1
			verifica=1;
		}
		
		//pesq recebe a proxima lista.
		pesq = pesq->prox;
	}
	
	//se o verifca continua com zero nome n�o foi encontrado.
	if(verifica==0)
	{
		printf("\nAluno nao encontrado...");
		getch();
	}	
	
}

//Fun��o para demonstrar a saida do sistema.
void sair()
{
	system("cls");
	printf("\nSaindo do sistema...");
	
}

int main()
{
	//declacracoes de variaveis.
	
	//usada para mostrar o endere�o de mem�ria que ser� usada nas fun��es.
	aluno 	Aluno;
	
	//ponteiro que aponta para o inicio da lista recebendo o tamanho da lista 
	aluno	*ini=(aluno*)malloc(sizeof(aluno));
	
	//ponteiro que prenche a lista recebe o tamanho da lista e o endere�o que ela come�a
	aluno	*inserir1  = ini;
	aluno 	*pesq;
	//variavel que controla  a op��o escolhida no menu.
	int opc=0;
	
	
	for(;opc!=3;)
	{
		opc = menu(opc);
		
		if(opc==1)
		{
			//Fun��o utilizada para preencher as informa��es,
			//recebe como par�metro endere�o da fun��o.
			prencher(&Aluno);
			
			//Fun��o utilizada para inserir os dados na lista, 
			//os par�metros um para o endere�o da fun��o usada para preencher e
			//um ponteiro que insere os dados na lista 
			inserir_dados(&Aluno,inserir1);
			
			//ponteiro recebe o tamanho do proximo caso queiram realizar mais cadastros.
			inserir1 -> prox = (aluno*) malloc(sizeof(aluno));
			inserir1 = inserir1 -> prox;
		}
		
		if(opc==2)
		{
			pesq = ini;
			//Fun��o para pega o nome pesquisa em um endere�o de fun��o
			inserir_pesquisa(&Aluno);
			
			//Recebe o que vai ser pesquisado pelo endere�o da fun��o,
			//e envia o ponteiro ini como comeco da lista, porem dentro
			//da funcao � trocado para que nn seja alterdo.
			pesquisar(&Aluno,ini);
		}
		
		if(opc==3)
		{
			//demonstra a saida do sistema.
			sair();
			free(pesq);
			free(inserir1);
			free(ini);
		}
			
	}
		
}
	

	

