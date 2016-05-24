#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000//表示顶点之间不存在路径 
typedef char VertexType;//定点类型
typedef int EdgeType;//边上的权值 
typedef struct
{
	int u;
	int v;
	int w;
}Edge;
typedef struct node{
	int adjvex;
	struct node *nexttarc;
	int info;
}EdgeNode;

typedef struct vnode
{
	VertexType vexdata;
	EdgeNode *firstarc; 
}VertexNode;
void print_(int P[],VertexType S,VertexNode G[],int n,Edge E[],int e);
void creat_G_E(VertexNode G[],int e,int n,Edge E[]);
int get_number(VertexType i,VertexNode G[]);
void Dijkstra(VertexType s,Edge E[],VertexNode G[],int n,int e,int P[]);	
int main(void){
	int i,n,e;
	printf("请输入顶点数与边数：");
	scanf("%d%d",&n,&e);
	getchar();
	VertexType S;
	Edge E[e];
	int P[n];
	for(i=0;i<e;i++)
		E[i].w=MAX;
	VertexNode G[n];
	creat_G_E(G,e,n,E);
	printf("请输入起点：");
	scanf("%c",&S);
	Dijkstra(S,E,G,n,e,P);

	print_(P,S,G,n,E,e);
	getchar();
	getchar();
	return 0;
}

int get_number(VertexType i,VertexNode G[])
{
	int j=0;
	while(G[j].vexdata!=i)
	{
		j++;
	}
	return j;
}
void creat_G_E(VertexNode G[],int e,int n,Edge E[])
{
	char c;
	VertexType a,b;
	int i=0,k,j,w;
	EdgeNode *s;
	printf("请输入顶点：\n");
	while(i<n){
		printf("NO.%d：",i+1);
		G[i].vexdata=getchar();
		getchar();
		G[i].firstarc=NULL;
		i++;
	}
	printf("请输入边及其权值(如:“CD：5”表示顶点C到顶点D的一条边权值为5)：\n");
	for(k=0;k<e;k++){
		printf("NO.%d:",k+1);
		scanf("%c%c%c%d",&a,&b,&c,&w);
		getchar();
		i=get_number(a,G);
		j=get_number(b,G);
		E[k].u=i;
		E[k].v=j;
		E[k].w=w;
		s=(EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex=j;
		s->nexttarc=G[i].firstarc;
		G[i].firstarc=s;
	}
}
void Dijkstra(VertexType S,Edge E[],VertexNode G[],int n,int e,int P[])
{
	int V=0,U,W,i,min,j,k;
	int s=get_number(S,G);
	int final[n],D[n],C[n][n];
	for(;V<n;V++)
	{
		for(U=0;U<n;U++)
		{
			C[V][U]=MAX;
		}
	}
	for(V=0;V<e;V++)
	{
		j=E[V].u;
		k=E[V].v;
		W=E[V].w;
		C[j][k]=W;
	}
	for(V=0;V<n;V++)
	{
		if(C[s][V]==MAX)
			P[V]=V;
		else
			P[V]=s;		
	}
	
	for(V=0;V<n;V++)
	{
		final[V]=0;
		D[V]=C[s][V];		
	}
	for(i=0;i<n;i++){
		min=MAX;
		for(W=0;W<n;W++)
			if(!final[W])
				if(D[W]<min){
					V=W;
					min=D[W];
				}		
		final[V]=1;
		for(W=0;W<n;W++)
		{
			if(!final[W]&&(min+C[V][W]<D[W]))
			{
				D[W]=min+C[V][W];
				P[W]=V;
			}
		}
	}
	P[s]=s;
}
void print_(int P[],VertexType S,VertexNode G[],int n,Edge E[],int e)
{
	int i=0,j,k=0,s,a[n],C[n][n],weight=0,V=0,U,W,l;
	s=get_number(S,G);
	for(;V<n;V++)
	{
		for(U=0;U<n;U++)
		{
			C[V][U]=MAX;
		}
	}
	for(V=0;V<e;V++)
	{
		j=E[V].u;
		k=E[V].v;
		W=E[V].w;
		C[j][k]=W;
	}
	while(i<n)
	{	
		weight=0;
		if(S!=G[i].vexdata){
			k=0;
			printf("%c到%c的最短路径为:",S,G[i].vexdata);
			j=i;
			while(j!=P[j])
			{
				j=P[j];
				a[k]=j;
				k++;
			}
			k=k-1;
			while(k>=0){
				j=a[k];
				printf("%c,",G[j].vexdata);
				if(k!=0)
				{
					l=a[k-1];
					weight=C[j][l]+weight;			
				}	
				k--;
			}
			j=a[0];
			weight=C[j][i]+weight;
			if(weight<MAX)
				printf("%c,其权值为:%d\n",G[i].vexdata,weight);
			else 
				printf("空\n");		
		}
		i++;
	}
}

