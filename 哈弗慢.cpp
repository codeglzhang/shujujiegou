#include<stdio.h>
#include<string.h>
#define MaxSize 1000

struct TreeNode
{	
	char data;
	int weight;
	int parent;
	int lchild;
	int rchild;
};
typedef struct TreeNode HFTreeNode;

struct CodeNode
{
	char ch;
	char bits[MaxSize+1];
};
typedef struct CodeNode HuffmanCode;

int CreatHuffmanTree(HFTreeNode T[MaxSize],int *q);
int *weight(char a[]);
void selectMin(HFTreeNode T[MaxSize],int n,int *p,int *d);
void CharSetHuffmanEncoding(HFTreeNode T[MaxSize],HuffmanCode H[MaxSize],int n);
void printf_encod(HuffmanCode H[MaxSize]);

int main(void)
{
	int m=0,flag=1,n;
	HFTreeNode T[MaxSize];
	HuffmanCode H[MaxSize];
	int *q;
	char c[MaxSize];
	
	printf("ÇëÊäÈëÓ¢ÎÄ×Ö·û´®£º");
	while (flag){
		c[m++]=getchar();
		if(c[m-1]=='\n'||m>MaxSize)
			flag=0;
	}
	
	q=weight(c);
	n=CreatHuffmanTree(T,q);
	CharSetHuffmanEncoding(T,H,n);
	printf_encod(H);

	return 0;
}

void printf_encod(HuffmanCode H[MaxSize])
{
	int i=0;
	printf("¹þ·òÂü±àÂë£º");
	for(;i<=51;i++)
	{
		if(H[i].bits[0]!='\0')
		{
			printf("%c:%s\n",H[i].ch,H[i].bits);
		}
	 } 
	
}
void CharSetHuffmanEncoding(HFTreeNode T[MaxSize],HuffmanCode H[MaxSize],int n)
{
	int c,p,i;
	char cd[MaxSize+1];
	int start;
	
	cd[MaxSize]='\0';
	for(i=0;i<n;i++){
		H[i].ch=T[i].data;
		start=n;
	
		c=i;
		while((p=T[c].parent)>0)
		{
			if((T[p].lchild)==c)
				cd[--start]='0';
			else
				cd[--start]='1';
			c=p;
				
		}
		strcpy(H[i].bits,&cd[start]);
	}
	
}

int CreatHuffmanTree(HFTreeNode T[MaxSize],int *q)
{
	int i=0,j=0,m,min1,min2,n;
	int *p,*d;
	
	p=&min1;
	d=&min2;
	
	while(i<=25)
	{
		if(q[i]!=0){
			T[j].data=i+'A';	
			T[j].weight=q[i];
			j++;
		}
		i++;
	}
	while(i<=51){
		if(q[i]!=0){
			T[j].data=i-26+'a';
			T[j].weight=q[i];
			j++;
		}
		i++;
	}
	n=j-2;
	m=2*n;
	for(i=0;i<m-1;i++)
	{
		T[i].parent=0;
		T[i].lchild=0;
		T[i].rchild=0;
	}
	for(i=n;i<m-1;i++)
	{
		T[i].weight=0;
	}

	for(i=n;i<m-1;i++)
	{
		selectMin(T,i,p,d);
		T[min1].parent=T[min2].parent=i;
		T[i].lchild=min1;
		T[i].rchild=min2;
		T[i].weight=T[min1].weight+T[min2].weight;
	}
	return n;//·µ»Ø½ÚµãÊý£»	
}
void selectMin(HFTreeNode T[MaxSize],int i,int *p,int *d)
{
	int j,k;
	
	for(j=0;j<=i-1;j++)
	{
		if(T[j].parent==0)
		{
			*p=j;
			break;
		}
	}
	for(k=0;k<=i-1;k++){
		if(T[k].weight<=T[*p].weight&&T[k].parent==0)
			*p=k;
	}
	
	for(j=0;j<=i-1;j++)
	{
		if(T[j].parent==0&&j!=(*p))
		{
			*d=j;
			break;
		}
	}
	for(k=0;k<=i-1;k++){
		if(T[k].weight<=T[*d].weight&&T[k].parent==0&&k!=(*p))
			*d=k;
	}
	 
}

int *weight(char c[])
{
	int flag=1,i=0,b,n=0;
	int a[52]={0};
	
	while(flag)
	{
		b=c[n];
		if(b>=65&&b<=90){		
			i=b-65;
			a[i]++;		
		}
		if(b>=97&&b<=122){
			i=b-71;
			a[i]++;
		}
		if(b=='\n')
			flag=0;
		n++;	
	}
	return a;
}

