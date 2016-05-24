#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE  10
typedef char Elemtype;

struct  node{
	Elemtype data[MAXSIZE];
	int length;
	int *p=&length;
	
};

typedef struct node SeqList;

void SeqListInit(SeqList L);									//��ʼ�� 
int SeqListlength(SeqList L);								    //�󳤶� 
Elemtype SeqListGet(SeqList L,int i) ;						   	//ȡԪ�� 
int SeqListLocate(SeqList L,Elemtype);							//��λ���� 
Elemtype SeqListPrior(SeqList L,Elemtype e);					//��ǰ�� 
Elemtype SeqListNext(SeqList L,Elemtype e);						//���� 
void SeqListInsert(SeqList L,int i,Elemtype e);					//ǰ�� 
void SeqListDel(SeqList L,int i);								//ɾ�� 
bool SeqListEmpty(SeqList L);									//�п� 
void SeqListTraverse(SeqList L);								//���� 
void SeqListmakeEmpty(SeqList L);								// �ÿ� 
void SeqListunion1(SeqList La,SeqList Lb);						// �ϲ� 
void SeqListunion2(SeqList La,SeqList Lb);

int main(void)
{
	int i=0,n,x,z,w=3;
	char a='A',b,c,y;
	SeqList La,Lb;
	SeqListInit(La);
	for(;i<=5;i++){
		La.data[i]=a+i;
		La.length++;
	}
	SeqListTraverse(La);
	n=SeqListEmpty(La);
	b=SeqListPrior(La,a+2);
	c=SeqListNext(La,a+2);
	x=SeqListlength(La);
	y=SeqListGet(La,4);
	SeqListDel(La,w);
	z=SeqListlength(La);
	printf("n=%d b=%c c=%c x=%d y=%c z=%d",n,b,c,x,y,z); 
	
	return 0;						
 } 
 
void SeqListInit(SeqList L)					//��ʼ�� 
{
	L.length=0;
} 

int SeqListlength(SeqList L)				//�󳤶� ����L.lenth���棿�� 
{
	return L.length;
}

Elemtype SeqListGet(SeqList L,int i)		//ȡԪ�� 
{
	if(i<=L.length&&i>=1)
		return L.data[i-1];
	else
	{
		printf("i ֵ���Ϸ�");
		exit(0);		//????????
	}	
}
 						   						
int SeqListLocate(SeqList L,Elemtype e)		//��λ���� 
{
	int i=1;
	for(;i<=L.length&&L.data[i-1]!=e;i++)
		;
	if(i<=L.length)
		return i;
	else{
		printf("��Ԫ�ز��ڱ���");
		return 0;	//????????	
	}
}

Elemtype SeqListPrior(SeqList L,Elemtype e)	//��ǰ�� 
{
	int i;
	i=SeqListLocate(L,e);
	if(i==1)
	{
		printf("��һ��Ԫ��û��ǰ��");
		exit(0);
	}
	else
		return L.data[i-2];
}

Elemtype SeqListNext(SeqList L,Elemtype e)	//���� 
{
	int i;
	i=SeqListLocate(L,e);
	if(L.length==i)
	{
		printf("���һ��Ԫ���޺��");
		exit(0);
	}
	else 
		return L.data[i];
}
void SeqListInsert(SeqList L,int i,Elemtype e)	//ǰ�� 
{
	int j;
	if(L.length==MAXSIZE)
	{
		printf("���������޷����в������");
		exit(0);
	}
	if ((i<1)||(i>L.length))
	{
		printf("i ���Ϸ�");
		exit(0);
	}
	for(j=L.length-1;j>=i-1;j--)
		L.data[j+1]=L.data[j];
	L.data[i-1]=e;
	L.length++;	
}
void SeqListDel(SeqList L,int i)			//ɾ�� 
{
	if(i<1||i>L.length+1)
	{
		printf("i���Ϸ�");
		exit(0);
	}
		
	for(;i<=L.length-1;i++)
		L.data[i-1]=L.data[i];
	(*(L.p))--;	
} 

bool SeqListEmpty(SeqList L)				//�п� 
{
	if(L.length==0)
		return 1;
	else
		return 0;	
}

void SeqListTraverse(SeqList L)			  //���� 
{
	int i;
	if(SeqListEmpty)
		printf("�ñ�Ϊ��");
	for(i=0;i<=L.length-1;i++)
		printf("%c",L.data[i]);
}
void SeqListmakeEmpty(SeqList L)		 // �ÿ� 
{
	int i=0;
	for(;L.length>=1;L.length--)
		L.data[L.length]='/0';
}
void SeqListunion1(SeqList La,SeqList Lb)	//ֱ�Ӻϲ�
{
	char x;
	int i=1,j=La.length;
	for(;i<=Lb.length&&j<=MAXSIZE;i++)
	{
		x=SeqListGet(Lb,i);
		if(SeqListLocate==0)
		{
			SeqListInsert(La,j+1,x);
			j++;
		}
	}
}

void SeqListunion2(SeqList La,SeqList Lb)		//����ϲ� Lc�������жϣ� 
{
	SeqList Lc;
	int i=1,j=1,k=0;
	while(i<=La.length&&j<=Lb.length&&k<=MAXSIZE)
	{
		if(SeqListGet(La,i)<=SeqListGet(Lb,j))
		{
			SeqListInsert(Lc,k+1,SeqListGet(La,i));
			i++;
			k++;
		}
		else{
			SeqListInsert(Lc,k+1,SeqListGet(Lb,j));
			j++;
			k++;	
		}
		Lc.length++;
	}
	while(i<=La.length&&k<=MAXSIZE)
	{
		SeqListInsert(Lc,k+1,SeqListGet(La,i));
		k++;
		i++;
	}
	while(j<=Lb.length&&k<=MAXSIZE)
	{
		SeqListInsert(Lc,k+1,SeqListGet(Lb,j));
		j++;
		k++;
	}
}
