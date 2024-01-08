#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int sayi;
	node * next;
}node;

void liste_yazdir(node*root){
	while(root->next!=NULL){
	root=root->next;
	if(root==NULL)   break;
	
	printf("%d  ",root->sayi);

}
}

void ekle(node*root,int eklenen,int y){
node*iter=root;
for(int i=0;(iter->sayi!=y);i++)  iter=iter->next;

node*temp=(node*)malloc(sizeof(node));
temp->next=iter->next;
iter->next=temp;
temp->sayi=eklenen;

liste_yazdir(root);
	
}


void liste (node*iter,int sayi){
	while(iter->next!=NULL){
		iter=iter->next;
	}
	
	iter->next=(node*)malloc(sizeof(node));
	iter->next->sayi=sayi;
	iter->next->next=NULL;
	//return  iter->sayi;
}

int main(){
	int dizi[]={2,8,4,6,1,7};
	node *root=(node*)malloc(sizeof(node));
	//root->sayi=NULL;
	root->next=NULL;
	
	for(int i=0;i<6;i++){
		liste(root,dizi[i]);
	}
	
	liste_yazdir(root);
	
	
	//istenilen sayiyi istenilen yere ekleme..
	
	int eklenen,y;
	printf("\neklenecek sayiyi girin..");
	scanf("%d",&eklenen);
	
	printf("%d i hangi sayidan sonra koymak istersiniz..",eklenen);
	scanf("%d",&y);
	
	ekle(root,eklenen,y);
	
	
	
	 
	
	
}
