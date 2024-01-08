//KUYRUK(QUEUE)----DÝNAMÝK UYGULAMA

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int veri;
	struct node*next;
}node;

node*temp=NULL;
node*front=NULL;  //bastaki düðüm
node*rear=NULL;   //son düðüm


void elemanekle(int veri)
{
	node*eleman=(node*)malloc(sizeof(node));
	eleman->veri=veri;
	
	if(front==NULL)
	{
		front=eleman;
		front->next=front;
		rear=eleman;
		rear->next=NULL;
	}
	
	else if(front->next==front)
	{
		rear->next=eleman;
		rear=eleman;
		rear->next=NULL;
		front->next=rear;
	}
	
	else
	{
		rear->next=eleman;
		rear=eleman;
		rear->next=NULL;
	}
}


void elemancikar()
{
	if(front==NULL)
	{
		printf("cikarilacak eleman yok.kuyruk bos\n");
	}
	
	else
	{
		temp=front->next;
		free(front);
		front=temp;
	}
	
}

void yazdir()
{
	system("cls");
	if(front==NULL)
	{
		printf("kuyruk bos\n");
	}
	
	else
	{
		temp=front;
		while(temp->next!=NULL)
		{
			printf("%d  ",temp->veri);
			temp=temp->next;
		}
		    printf("%d  ",temp->veri);
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
