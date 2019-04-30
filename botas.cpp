
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>

int main ()
{
	setlocale(LC_ALL,"portuguese");
	
	int pares;//variavel para guardar o número de botas encontrados

	printf("Digite a quantidade de pares: ");
	scanf("%d",&pares);
	
	int tamanho;//variavel para guarda o tamanho da bota
	
	int tamanhod[61],tamanhoe[61];
	//vetor de cada lado da bota para gravar se existe a bota ou não;
	
	char l;//char para guarda ao qual pé pertence a bota.
	
	int aux=0;//variavel auxiliar para rodar o laço.
	
	//laço para zerar os vetores.
	while(aux<61)
	{
		tamanhod[aux]=0;
		tamanhoe[aux]=0;
		aux++;
	}
	
	//teste para verificar se o número de botas encontrado é par.
	if(pares % 2 != 0)
	{
		printf("\nA quantidade de pares precisa ser um número par...");
		exit(1);
	}
	
	//variavel para demonstrar o numero de  pares de botas foi encontrado.
	int par=0;
	
	aux = 0;
	
	//laço para inserir o dados e testa-los.
	while(aux<pares)
	{
		//guarda o tamanho da bota na variavel tamanho.
		printf("Digite o tamanho da %d bota: ",aux+1);
		scanf("%d",&tamanho);
		
		//testa se o tamanho da bota não é valido.
		if(tamanho < 30 || tamanho > 60)
		{
			printf("Tamanho da bota inválido..");
			exit(1);
		}
		
		//guarda a que pé pertence a bota.
		printf("Digite o lado da bota: ");
		scanf("%c",&l);
		
		//testa se o lado do pé colocado é valido.
		l = toupper(l);
		if(l != 'D' && l != 'E')
		{
			printf("");
			exit(1);
		}
		
		//teste para encontrar pares.
		//se o vetor do tamanho da bota for do pe direito incrementa um ao vetor
		if(l == 'D' )
		{
			tamanhod[tamanho]++;
		}
		else
		{
			//se do tamanho esquerdo o mesmo.
			tamanhoe[tamanho]++;
		}
		if(tamanhod[tamanho]  && tamanhoe[tamanho] )
		{
			//se ambos os vetores desse tamanho tiverem invrementados
			//e contabilizado com par de botas validos e seus vetores são decrementados
			tamanhod[tamanho]--;
			tamanhoe[tamanho]--;
			par++;
		}
		aux++;
	}
	
	//mostra os pares.
	printf("O número de pares formados foi : %d",par);
}
