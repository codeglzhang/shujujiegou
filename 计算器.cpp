#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 100
struct Num
{
	int data[MAXSIZE];
	int numtop;
};
typedef struct Num NumStack;
struct Mark 
{
	char mark[MAXSIZE];
	int martop;
 };
 typedef struct Mark MarStack;
 NumStack N;
 MarStack M;
int compare(char x);
bool NumStackEmpty(NumStack n);
bool MarStackEmpty(MarStack m);
void NumStackPush(NumStack n,int x);
void MarStackPush(MarStack m,char x);
int NumStackPop(NumStack n);
char MarStackPop(MarStack m);
int NumStackGetPop(NumStack n);
char MarStackGetPop(MarStack m);
void change(char c[2*MAXSIZE]);
char a[2*MAXSIZE];
char b[2*MAXSIZE];
int main(void)
{
	int i=0,j;
	char m='#';
	N.numtop=-1;
	M.martop=-1;
	a[2*MAXSIZE]='#';
	MarStackPush(M,m);
	do{
		i++;
		a[i]=getchar();	
	}while(a[i]!='\n');
	change(a);	

	return 0;
}

int compare(char x)
{
	switch(x)
    { 
		case '+': return 1;break;

		case '-': return 1;break;

		case '*': return 2;break;

		case '/': return 2;break;

		case '(': return 3;break; 

		case ')': return 3;break;
	}
	return -1;
}
void change(char c[2*MAXSIZE])
{
	int i=0;
	MarStack S;
	char ch,ch1;
	while(c[i]!='\n')
	{
		c[i]=ch;
		if(ch!='('&&ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!=')')
			b[i]=ch;
		else if(ch==')')
		{
			ch1=MarStackPop(S);
			while(ch1!='(')
			{
				b[i++]=ch1;
				ch1=MarStackPop(S);
			}
		}
		else 
		{
			ch1=MarStackGetPop(S);
			if(compare(ch)>compare(ch1))
				MarStackPush(S,ch);
			else
			{
				if(MarStackGetPop(S)!='('){
					ch1=MarStackPop(S);
					while(compare(ch)<compare(ch1))
					{
						b[i++]=ch1;
						ch1=MarStackPop(S);
					}
				}
			}
		}
		i++;	
	}
	while(MarStackEmpty(S)!=1)
		b[i++]=MarStackPop(S);
}

bool NumStackEmpty(NumStack n)
{
	if(n.numtop==-1)
		return 1;
	else
		return 0;	
 } 
 bool MarStackEmpty(MarStack m)
{
	if(m.martop==-1)
		return 1;
	else
		return 0;	
 } 
 
void NumStackPush(NumStack n,int  x)
{
 	if(n.numtop==MAXSIZE-1)
	{
	 	printf("栈已满！");
	 	exit(0);
	} 	
 	n.numtop++;
 	n.data[n.numtop]=x;  
}
 
void MarStackPush(MarStack m,char x)
{
 	if(m.martop==MAXSIZE-1)
	{
	 	printf("栈已满！");
	 	exit(0);
	} 	
 	m.martop++;
 	m.mark[m.martop]=x;  
}
 
int NumStackPop(NumStack n)
{
 	int x;
 	if(NumStackEmpty(n)==1)
 	{
 		printf("栈已空，无法进行出栈");
 		exit(0);
	 }
 	else
 	{
 		x=n.data[n.numtop];
 		n.numtop--;
 		return x;
	 }
}
 
char MarStackPop(MarStack m)
{
 	char x;
 	if(MarStackEmpty(m)==1)
 	{
 		printf("栈已空，无法进行出栈");
 		exit(0);
	 }
 	else
 	{
 		x=m.mark[m.martop];
 		m.martop--;
 		return x;
	}
}
 
int NumStackGetPop(NumStack n)
{
	if(NumStackEmpty(n)==1)
	{
 		printf("栈已空，无法进行出栈");
 		exit(0);
	 }
	 else
	 	return n.data[n.numtop];
}

char MarStackGetPop(MarStack m)
{
 	if(MarStackEmpty(m)==1)
 	{
 		printf("栈已空，无法进行出栈");
 		exit(0);
	 }
 	else
 		return m.mark[m.martop];
 } 
