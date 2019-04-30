#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

//struct para salva as variaveis de maior importancia para uso da lista encadenada.
typedef struct horas
{
	//variaveis para guarda hora e minutos atuais, hora iniciada com -1 para controle de quantas listas foram salvas.
	int ha=-1;
	int ma;
	
	//variaveis para guarda hora e minutos que pretende despertar.
	int hd;
	int md;
	
	//ponteiro indicado o local da proxima lista encadenada.
	horas *prox;
	
}horas;//nome da struct hora.

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	// ponteriso para controle do que será inserido na lista(d1),
	//controle do que será mostrado(d2),
	//apontar o local da primeira lista para não perder os dados.
	horas *despertar,*d1,*d2;
	
	//ponterio recebem o tamanho das structs.
	despertar = (horas*)malloc(sizeof(horas));
	d1 = despertar;
	d2= despertar;
	
	//char para mostrar encerramento do laço.
	char sair[30];
	
	//laço para inserir dados.
	while(strstr(sair,"0 0 0 0") == NULL)
	{
		system("cls");
		
		//ponteiro de inserçao de dados aponta para endereco onde a hora atual sera alocada.
		printf("Hora que irá dormir: ");
		scanf("%d",&d1->ha);
		
		//caso seja igual a 0(meia noite) digitado pelo usuário, troca o valor para 24 para facilitar calculos
		if(d1->ha == 0)
		d1->ha = 24;
		
		//depois ele testa se está no formato de 24 horas.
		else
		if(d1->ha < 0 || d1->ha > 25)
		{
			printf("Formato de hora inválido...");
			break;
		}
		
		//ponteiro de inserçao de dados aponta para endereco onde os minutos atuais serao alocada.
		printf("Minutos que irá dormir: ");
		scanf("%d",&d1->ma);
		
		//testa se está no formato de minutos.
		if(d1->ma > 59 || d1->ma < 0)
		{
			printf("Formato de minutos inválido...");
			break;
		}
		
		//ponteiro de inserçao de dados aponta para endereco onde a hora de despertar sera alocada.
		printf("Hora que irá acordar: ");
		scanf("%d",&d1->hd);
		if(d1->hd == 0)
		d1->hd = 24;
		else
		if(d1->hd <0 || d1->hd > 25)
		{
			printf("Formato de hora inválido...");
			break;
		}
		
		//ponteiro de inserçao de dados aponta para endereco onde a minutos de despertar sera alocada.
		printf("Minutos que irá acordar: ");
		scanf("%d",&d1->md);
		
		if(d1->md > 59 || d1->md < 0)
		{
			printf("Formato de minutos inválido...");
			break;
		}
		
		//Pode ser digitado ou não o comando para sair do laço.
		printf("Caso não queira digitar mais horarios digite 0 0 0 0, caso contrario aperte enter: ");
		fflush(stdin);
		gets(sair);
		
		//caso sair seja diferente do comando pedido para sair,
		//d1 aponta para o ponterio prox q recebe o tamanho da variavel.
		if(strstr(sair,"0 0 0 0")==NULL)
		d1->prox = (horas*)malloc(sizeof(horas));
		
		//d1 recebe prox para fica amis simples o chamado das variaveis.
		d1=d1->prox;
	}
	
	//laço de repetição para mostrar a resposta e fazer os calculos necessários,
	//como d1 quando chega aki ja está apontando para o último endereço que tem
	//usa-se d2 que está apontado para o primeiro endereço gravado,
	//por isso a necessidade de 3 ponteiros.
	
	//teste até mostrar o -1 da hora atual significando que não foi colocado outro.
	
	while(d2->ha != -1)
	{
		//total de horas atuais em minutos
		int totalha = (d2->ha*60) + d2->ma;
		
		//total de horas para despertar em minutos.a
		int totalhd = (d2->hd *60) + d2->md;
		
		//se o total de horas atuais  for maior que o hora de despertar em minutos 
		//significa que é de um dia para o outro
		//por isso soma 1440 que seria o total de minutos que tem em 24 horas.
		
		if(totalhd<totalha)
		{
			totalhd += 1440;
		}
		
		//Calcula os minutos faltantes para acordar.
		int total = totalha - totalhd;
		
		//if para evitar  que mostre minutos negativos.
		if(total<0)
		total *= -1;
		
		//devolver o 24 para 0 para melhor compreensao do usuário.
		if(d2->ha == 24)
		d2->ha = 0;
		
		
		if(d2->hd == 24)
		d2->hd = 0;
		
		printf("\nSe você dormir as %d:%d e acordar %d:%d irá dormir %d minutos.",d2->ha,d2->ma,d2->hd,d2->md,total);
		
		//para apontar para o próximo endereco que irá ser calculado.
		d2 = d2->prox;
	}
	
}

