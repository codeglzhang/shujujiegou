#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef int ElemType;
struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node LNode;
typedef struct Node *LinkedList;

void LinkedListMerge(LinkedList La,LinkedList Lb,LinkedList Lc);
void LinkedListCreatel(LinkedList La,ElemType a[N]);
int main(void) 
{
	ElemType a[N]={1,3,5,7,9},b[N]={2,4,6,8,10};
	LinkedList L1,L2,L3,p;
	L1=(LNode *)malloc(sizeof(LNode));
	if(L1==NULL)
	{
		printf("ÉêÇë¿Õ¼äÊ§°Ü");
		exit(0);
	}
	L2=(LNode *)malloc(sizeof(LNode));
	if(L2==NULL)
	{
		printf("ÉêÇë¿Õ¼äÊ§°Ü");
		exit(0);
	}
	L1->next=NULL;
	L2->next=NULL;
	L3=L1;
	LinkedListCreatel(L1,a);
	LinkedListCreatel(L2,b);
	LinkedListMerge(L1,L2,L3);
	for(p=L3->next;p!=NULL;p=p->next)
		printf("%d ",p->data);
	
	return 0;
}void LinkedListMerge(Listptr La,Listptr Lb,Listptr Lc)
{
	Listptr q1,q2,q3;
	q1=La->next;
	q2=Lb->next;
	Lc=La;
	q3=Lc;
	while(q1!=NULL&&q2!=NULL)
	{
		if(((q1->data).Age)<=((q2->data).Age))
		{
			q3->next=q1;
			q3=q1;
			q1=q1->next;
		}
		else{
			q3->next=q2;
			q3=q2;
			q2=q2->next;
		}		
	}
	if(q1!=NULL)
		q3->next=q1;
	else 
		q3->next=q2;	
	free(Lb);
}


void LinkedListMerge(LinkedList La,LinkedList Lb,LinkedList Lc)
{
	LinkedList pa,pb,pc;
	pa=La->next;
	pb=Lb->next;
	pc=Lc;
	while(pa!=NULL&&pb!=NULL){
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		
	}
	if(pa!=NULL)
		pc->next=pa;
	else
		pc->next=pb;	
}

void LinkedListCreatel(LinkedList L,ElemType a[N])
{
	LinkedList p;
	int i;

	for(i=N-1;i>=0;i--)
	{
		p=(LNode *)malloc(sizeof(LNode));
		if(p==NULL)
		{
			printf("ÉêÇë¿Õ¼äÊ§°Ü");
			exit(0);
		}
		p->next=L->next;
		p->data=a[i];
		L->next=p;
	}
}
