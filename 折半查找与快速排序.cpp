#include<stdio.h>

typedef int ktype;
struct node{
	ktype key;
};
typedef struct node etype;
void swap(ktype *i,ktype *j);
ktype zbcz(etype a[],ktype K,int n);
void kspx(etype a[],int left,int right);
void zjpx(etype a[],int i);
int getpivot(etype a[],int left,int right);
int main(void){
	etype a[10];
	int i=1;
	for(;i<=9;i++)
		a[i].key=i;
	a[5].key=20;
	kspx(a,1,9);
	for(i=1;i<=9;i++)
		printf("%d ",a[i].key);
	return 0;
}

ktype zbcz(etype a[],ktype k,int n)
{
	int low=1;
	int high=n;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid].key==k)
			return mid;
		if(a[mid].key>k)
			high=mid-1;
		else 
			low=mid+1;		
	}
	return 0;
}
void kspx(etype a[],int left,int right)
{
	if(left<right){
		int pivot,i,j;
		pivot=getpivot(a,left,right); 
		i=left;
		j=right;
		while(1){
			while(a[i].key<a[pivot].key)
				i++;
			while(a[j].key>a[pivot].key)
				j--;
			if(i<j)	
				swap(&(a[i].key),&(a[j].key));
			else
				break;	
		}
		swap(&(a[i].key),&(a[right].key));
		kspx(a,left,i-1);
		kspx(a,i+1,right);
	}	

}
int getpivot(etype a[],int left,int right){
	int center=(left+right)/2;
	if(a[left].key>a[center].key)
		swap(&(a[left].key),&(a[center].key));
	if(a[left].key>a[right].key)
		swap(&(a[left].key),&(a[right].key));
	if(a[center].key>a[right].key)
		swap(&(a[right].key),&(a[center].key));	
	swap(&(a[center].key),&(a[right].key));	
	return a[right-1].key;
}
void swap(ktype *i,ktype *j)
{
	ktype a;
	a=*i;
	*i=*j;
	*j=a;
}

