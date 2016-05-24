#include<stdio.h>
#define MAX 20
#define MAX1 100

typedf struct node{
	int adjvex;//邻结点域 
	struct node *nextarc;//链域 
	int info;		//数据域 
}EdgeNode;		//表结点 

typedef struct vnode{
	int vexdata;
	EdgeNode *firstarc;
}VertexNode;
int exchange(char a)
{
	
}
void creat_G(VertexNode G){
	int 
	printf("请输入顶点并以"*"结束：")
	
}


typedef struct
{
	int u;
	int v;
	int weight;
}Edge;
int creat(Edge e[])
{
	int n,i=1;
	printf("请输入顶点数：");
	scanf("%d",&n);
	while(i<=N)
	{
		printf("请输入边的顶点:");
		scanf("%d%d",&(e[i].u),&(e[i].v));
		printf("请输入边的权值：");
		scanf("%d",&(e[i].weight));
		i++;	
	}
	e[i].u=0;
	e[i].v=0;
	e[i].weight=0;
	return n;
}
void sortedge(Edge e[])
{
	int i=1,n,flag;
	Edge f[N+1];
	
	while(i<=N)
	{
		n=1;
		e[0].u=e[n].u;
		e[0].v=e[n].v;
		e[0].weight=e[n].weight;	
		while(n<=N)
		{
			
			if(e[0].weight>=e[n].weight&&e[n].weight!=0)
			{
				e[0].u=e[n].u;
				e[0].v=e[n].v;
				e[0].weight=e[n].weight;
				flag=n;
			} 
			n++;
		}
		while(flag<=N){
			e[flag].u=e[flag+1].u;
			e[flag].v=e[flag+1].v;
			e[flag].weight=e[flag+1].weight;
			flag++;
		}
		f[i].u=e[0].u;
		f[i].v=e[0].v;
		f[i].weight=e[0].weight;
		
		i++;
	}
	i=1;
	while(i<=N){
		e[i].u=f[i].u;
		e[i].v=f[i].v;
		e[i].weight=f[i].weight;
		i++;
	}
	
}
void MinSpanTree_Kruskal(Edge e[],int n)
{
	int i,j=1,k=1,m1,m2,sn1,sn2;
	int vest[MAX];
	for(i=0;i<=n;i++)
		vest[i]=i;
	while(k<n)
	{
		m1=e[j].u;m2=e[j].v;
		sn1=vest[m1];
		sn2=vest[m2];
		if(sn1!=sn2)
		{
			printf("(%d,%d):%d\n",e[j].u,e[j].v,e[j].weight);
			k++;
			for(i=1;i<n+1;i++){ 
				if(vest[i]==sn2)
					vest[i]=sn1;
			}		 
		}
		j++;
	}
}

int main(void){
	printf("请输入边数：");
	scanf("%d",&N);
	int i;
	int n;
	Edge E[N+1];
	n=creat(E);
	
	sortedge(E);

	MinSpanTree_Kruskal(E,n);
	
	return 0;
}
	
	

