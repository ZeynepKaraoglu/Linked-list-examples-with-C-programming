//CÝFT YÖNLÜ DOÐRUSAL BAÐLI LÝSTEYE ELEMAN EKLEME/SÝLME

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int veri;
	struct node*next;
	struct node*prev;
}node;

node*root=NULL;
node*iter=NULL;
node*temp=NULL;

void basaekle(int sayi)
{
	
	node*eklenen=(node*)malloc(sizeof(node));
	eklenen->prev=NULL;
	eklenen->next=NULL;
	eklenen->veri=sayi;
	
	if(root==NULL)
	{
		root=eklenen;
		root->next=NULL;
	}
	
	else
	{
		eklenen->next=root;
		root=eklenen;
	}
	
}

void sonaekle(int sayi)
{
	node*eklenen=(node*)malloc(sizeof(node));
	eklenen->veri=sayi;
	eklenen->next=NULL;
	
	if(root==NULL)
	{
		root=eklenen;
		root->next=NULL;
		root->prev=NULL;
	}
	
	else
	{
		
		if(root->next==NULL)
		{
			root->next=eklenen;
			eklenen->prev=root;
		}
		
		else
		{
		iter=root;
		while(iter->next!=NULL)
		{
			iter=iter->next;
		}
		
		iter->next=eklenen;
		eklenen->prev=iter;
	
	}
    }
}

void yazdir()
{
	system("cls");
	iter=root;
	while(iter->next!=NULL)
	{
		printf("%d-> ",iter->veri);
		iter=iter->next;
	}
	    printf("%d",iter->veri);
}


int main()
{
	int secim;
	int sayi;
	
	 while(1)
	 {
	
	printf("\nbasa eleman eklemek icin :1\n");
	printf("sona eleman eklemek icin :2\n");
	printf("bastan eleman silmek icin :3\n");
	printf("sondan eleman silmek icin :4\n");
	printf("listeyi yazdirmak icin:5\n");
	printf("secim yapin..");    scanf("%d",&secim);
	
	
	switch(secim)
	{
		
		case 1:
			printf("basa eklenecek sayi: ");
			scanf("%d",&sayi);
			basaekle(sayi);
			break; 
			
		case 2:
			printf("sona eklenecek sayi: ");
			scanf("%d",&sayi);
			sonaekle(sayi);
			break;
	
		case 5:
		    yazdir();
		    break;	
	}
}
	
}
