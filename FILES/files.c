#include<stdio.h>

int a[10];

int main()
{
	int i;
	FILE *outp;
	
	outp=fopen("E://distance.out","w");
	printf("\nEnter the number in array\n");
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		fprintf(outp,"\n%d",a[i]);
	}
	fclose(outp);
}