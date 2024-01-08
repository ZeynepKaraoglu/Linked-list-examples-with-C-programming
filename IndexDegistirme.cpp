#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a;
	node *next;
}node;


void liste_yazdir(node *r){
 while(r!=NULL){
  printf("%d ",r->a);
  r=r->next;
 }
}

void degisim(node*root,int MevcutIndex,int YeniIndex){
	node*iter=root;

	for(int i=0;i<MevcutIndex-2;i++){
		iter=iter->next;
	}
	int sayi;
	sayi=iter->next->a;
	iter->next=iter->next->next;
	node*temp=(node*)malloc(sizeof(node));
	
	iter=root;
	for(int i=0;i<YeniIndex-2;i++){
		iter=iter->next;
	}
	temp->next=iter->next;
	iter->next=temp;
	temp->a=sayi;
	liste_yazdir(root);
	
	

	
}



node *ekle(node*r,int a){
	if(r==NULL){
  r=(node*)malloc(sizeof(node));
  r->next= NULL;
  r->a = a;
  return r;
 }
 
 if(r->a > a){ 
  node * temp = (node*)malloc(sizeof(node));
  temp -> a = a;
  temp -> next = r;
  return temp;
 }
 
 node * iter = r;
 while (iter -> next != NULL && iter ->next-> a < a){
  iter= iter -> next;
 }
 
 node * temp = (node*)malloc(sizeof(node));
 temp -> next = iter -> next;
 iter -> next = temp;
 temp -> a = a;
 return r;
}
	

int main(){
	int sayiDizisi[]= {21,40,30,25,50,24,14,60,3};
	
	node*root;
	root=NULL;
	
	for(int i=0;i<sizeof(sayiDizisi)/4;i++){
		root=ekle(root,sayiDizisi[i]);
	}
	
	printf("Liste: ");
	liste_yazdir(root);
	
	printf("\n");
	
	int MevcutIndex;
	int YeniIndex;
	
	while(1){
	    printf("\ndegistirilecek indexi girin..");
		scanf("%d",&MevcutIndex);
		 
		if(MevcutIndex==-1) break;
		
		printf("kacinci indexe alinacak..");
		scanf("%d",&YeniIndex);
		
	    printf("MevcutIndex=%d ,YeniIndex=%d => ",MevcutIndex,YeniIndex);
	    degisim(root,MevcutIndex,YeniIndex);
	    printf("\n");
	    
	   
		
} 

  printf("\nMevcutIndex=-1 => Islem Tamamlanmistir.");
	
	
	
	
	
}
