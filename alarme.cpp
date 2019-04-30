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
	
	// ponteriso para controle do que ser� inserido na lista(d1),
	//controle do que ser� mostrado(d2),
	//apontar o local da primeira lista para n�o perder os dados.
	horas *despertar,*d1,*d2;
	
	//ponterio recebem o tamanho das structs.
	despertar = (horas*)malloc(sizeof(horas));
	d1 = despertar;
	d2= despertar;
	
	//char para mostrar encerramento do la�o.
	char sair[30];
	
	//la�o para inserir dados.
	while(strstr(sair,"0 0 0 0") == NULL)
	{
		system("cls");
		
		//ponteiro de inser�ao de dados aponta para endereco onde a hora atual sera alocada.
		printf("Hora que ir� dormir: ");
		scanf("%d",&d1->ha);
		
		//caso seja igual a 0(meia noite) digitado pelo usu�rio, troca o valor para 24 para facilitar calculos
		if(d1->ha == 0)
		d1->ha = 24;
		
		//depois ele testa se est� no formato de 24 horas.
		else
		if(d1->ha < 0 || d1->ha > 25)
		{
			printf("Formato de hora inv�lido...");
			break;
		}
		
		//ponteiro de inser�ao de dados aponta para endereco onde os minutos atuais serao alocada.
		printf("Minutos que ir� dormir: ");
		scanf("%d",&d1->ma);
		
		//testa se est� no formato de minutos.
		if(d1->ma > 59 || d1->ma < 0)
		{
			printf("Formato de minutos inv�lido...");
			break;
		}
		
		//ponteiro de inser�ao de dados aponta para endereco onde a hora de despertar sera alocada.
		printf("Hora que ir� acordar: ");
		scanf("%d",&d1->hd);
		if(d1->hd == 0)
		d1->hd = 24;
		else
		if(d1->hd <0 || d1->hd > 25)
		{
			printf("Formato de hora inv�lido...");
			break;
		}
		
		//ponteiro de inser�ao de dados aponta para endereco onde a minutos de despertar sera alocada.
		printf("Minutos que ir� acordar: ");
		scanf("%d",&d1->md);
		
		if(d1->md > 59 || d1->md < 0)
		{
			printf("Formato de minutos inv�lido...");
			break;
		}
		
		//Pode ser digitado ou n�o o comando para sair do la�o.
		printf("Caso n�o queira digitar mais horarios digite 0 0 0 0, caso contrario aperte enter: ");
		fflush(stdin);
		gets(sair);
		
		//caso sair seja diferente do comando pedido para sair,
		//d1 aponta para o ponterio prox q recebe o tamanho da variavel.
		if(strstr(sair,"0 0 0 0")==NULL)
		d1->prox = (horas*)malloc(sizeof(horas));
		
		//d1 recebe prox para fica amis simples o chamado das variaveis.
		d1=d1->prox;
	}
	
	//la�o de repeti��o para mostrar a resposta e fazer os calculos necess�rios,
	//como d1 quando chega aki ja est� apontando para o �ltimo endere�o que tem
	//usa-se d2 que est� apontado para o primeiro endere�o gravado,
	//por isso a necessidade de 3 ponteiros.
	
	//teste at� mostrar o -1 da hora atual significando que n�o foi colocado outro.
	
	while(d2->ha != -1)
	{
		//total de horas atuais em minutos
		int totalha = (d2->ha*60) + d2->ma;
		
		//total de horas para despertar em minutos.a
		int totalhd = (d2->hd *60) + d2->md;
		
		//se o total de horas atuais  for maior que o hora de despertar em minutos 
		//significa que � de um dia para o outro
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
		
		//devolver o 24 para 0 para melhor compreensao do usu�rio.
		if(d2->ha == 24)
		d2->ha = 0;
		
		
		if(d2->hd == 24)
		d2->hd = 0;
		
		printf("\nSe voc� dormir as %d:%d e acordar %d:%d ir� dormir %d minutos.",d2->ha,d2->ma,d2->hd,d2->md,total);
		
		//para apontar para o pr�ximo endereco que ir� ser calculado.
		d2 = d2->prox;
	}
	
}

