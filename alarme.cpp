#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

typedef struct horas
{
	int ha=-1;
	int ma;
	int hd;
	int md;
	horas *prox;
	
}horas;

int main()
{
	setlocale(LC_ALL,"portuguese");
	horas *despertar,*d1,*d2;
	despertar = (horas*)malloc(sizeof(horas));
	d1 = despertar;
	d2= despertar;
	
	char sair[30];
	
	while(strstr(sair,"0 0 0 0") == NULL)
	{
		system("cls");
		printf("Hora que irá dormir: ");
		scanf("%d",&d1->ha);
		if(d1->ha == 0)
		d1->ha = 24;
		else
		if(d1->ha < 0 || d1->ha > 25)
		{
			printf("Formato de hora inválido...");
			break;
		}
		
		
		printf("Minutos que irá dormir: ");
		scanf("%d",&d1->ma);
		
		if(d1->ma > 59 || d1->ma < 0)
		{
			printf("Formato de minutos inválido...");
			break;
		}
		
		
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
		
		printf("Minutos que irá acordar: ");
		scanf("%d",&d1->md);
		
		if(d1->md > 59 || d1->md < 0)
		{
			printf("Formato de minutos inválido...");
			break;
		}
		
		
		printf("Caso não queira digitar mais horarios digite 0 0 0 0, caso contrario aperte enter: ");
		fflush(stdin);
		gets(sair);
		if(strstr(sair,"0 0 0 0")==NULL)
		d1->prox = (horas*)malloc(sizeof(horas));
		d1=d1->prox;
	}
	while(d2->ha != -1)
	{
		int totalha = (d2->ha*60) + d2->ma;
		int totalhd = (d2->hd *60) + d2->md;
		if(totalhd<totalha)
		{
			totalhd += 1440;
		}
		int total = totalha - totalhd;
		if(total<0)
		total *= -1;
		
		
		if(d2->ha == 24)
		d2->ha = 0;
		
		
		if(d2->hd == 24)
		d2->hd = 0;
		
		printf("\nSe você dormir as %d:%d e acordar %d:%d irá dormir %d minutos.",d2->ha,d2->ma,d2->hd,d2->md,total);
		
		d2 = d2->prox;
	}
	
}

