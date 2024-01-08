//KUYRUK(QUEUE)----STATÝC UYGULAMA

#include<stdio.h>
#include<stdlib.h>

#define boy 5

int dizi[boy];
int bas=-1,son=-1;       //bas=front    son=rear

void elemanekle(int veri)
{
	if(son==boy-1)
	{
		printf("kuyruk dolu\n");
	}
	
	else
	{
		if(bas==-1)
		bas=0;
		
		son++;
		dizi[son]=veri;
	}
}

void elemancikar()
{
	if(bas==-1 ||bas>son)
	{
		printf("kuyruk bostur\n");
		bas==-1;
		son=-1;
	}
	
	else
	{
		bas=bas+1;
	}
}

void yazdir()
{
	if(bas==-1)
	{
		printf("kuyruk bos\n");
	}
	
	else
	{
		int i;
		for(i=bas;i<=son;i++)
		{
			printf("%d  ",dizi[i]);
		}
	}

}


int main()
{
	int secim,sayi;
	
	while(1)
	{
		printf("\n1--ekle\n");
		printf("2--cikar\n");
		printf("3--yazdir\n");
	scanf("%d",&secim);
	
	switch(secim)
	{
			case 1:
				printf("eklenecek sayi:");
				scanf("%d",&sayi);
				elemanekle(sayi);
				break;
				
			case 2:
			    elemancikar();
			    break;
			
		    case 3:
			    yazdir();
			    break;
				
			
	}
		
	}
	
}



