//TEK YÖNLÜ DAÝRESEL ELEMAN EKLEME/SÝLME

#include<stdio.h>
#include<stdlib.h>                          //DAÝRESEL BAÐLI LÝSTELERDE SON DÜÐÜM NULL'I DEÐÝL ÝLK DÜÐÜMÜ GÖSTERÝR.

typedef struct node{
	int veri;
	struct node*next;
}node;

node*root=NULL;
node*iter=NULL;
node*last=NULL;


void basaekle(int sayi)
{
	node*eklenen=(node*)malloc(sizeof(node));
	eklenen->veri=sayi;
	
	if(root==NULL)
	{
		root=eklenen;
		root->next=root;
	}
	
	else
	{
		iter=root;
		while(iter->next!=root)
		{
			iter=iter->next;
		}
		iter->next=eklenen;
		eklenen->next=root;
		root=eklenen;
	}
}

void sonaekle(int sayi)
{
	node*eklenen=(node*)malloc(sizeof(node));
	eklenen->veri=sayi;
	
	if(root==NULL)
	{
		root=eklenen;
		root->next=root;
	}
	
	else
	{
		iter=root;
		while(iter->next!=root)
		{
			iter=iter->next;
		}
		iter->next=eklenen;
		eklenen->next=root;
	
}
}

void bastansil()
{
	
	if(root==NULL)
	{
		printf("liste bos..");
	}
	
	else
	{
		if(root->next==root)
		{
			free(root);
			root=NULL;
		}
		
		else
		{
			node*temp;
			last=root;
			while(last->next!=root)
			{
				last=last->next;
			}
			temp=root->next;
			free(root);
			last->next=temp;
			root=temp;
		}
	}

}

void sondansil()
{
	if(root==NULL)
	{
		printf("liste bos");
	}
	
	else
	{
		if(root->next==root)
		{
			free(root);
			root=NULL;
		}
		
		else
		{
			node*temp;
			last=root;
			while(last->next->next!=root)
			{
				last=last->next;
			}
			temp=last;
			free(last->next);
			last->next=root;
		}
	}
}

void yazdir()
{
	system("cls");
	iter=root;
	while(iter->next!=root)
	{
		printf("%d->",iter->veri);
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
			
		case 3:
			bastansil();
			break;
			
		case 4:
			sondansil();
			break;
			
		case 5:
		    yazdir();
		    break;	
	}
}
}
