#include <stdio.h>

 int main(void)
 {
 	int n,i=1;
 	float odd_number,even_number,d;
 	
 	printf("n=");
 	scanf("%d",&n);
 	
 	float a[n];
 	
 	printf("odd_number=");
 	scanf("%f",&odd_number);
 	
 	printf("even_number=");
 	scanf("%f",&even_number);
 	
 	d=2*(even_number-odd_number)/n;
 	
 	a[0]=(odd_number+even_number)/n-(n-1)*d/2;
 	
 	for(;i<=n-1;i++)
 		a[i]=a[0]+i*d;
 		
 	for(i=0;i<=n-1;i++)
	 	printf("%f  ",a[i]);
	
	return 0;	 	
 }
