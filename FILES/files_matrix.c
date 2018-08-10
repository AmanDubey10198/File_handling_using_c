/*
 *PROGRAM FOR ADDITTION SUBSTRACTION AND MULTIPLICATION OVER TWO 3D ARRAY
 */
 #include<stdio.h>
 
 void enter_array(int x[3][3]);								/*DECLARATION OF ARRAY FUNCTIONS*/				
 void addition_of_array(int x[3][3],int y[3][3]);
 void substraction_of_array(int x[3][3],int y[3][3]);
 void multiplication_of_array(int x[3][3],int y[3][3]);
 FILE *outp;
 
 int A[3][3],B[3][3];												/*DECLARATION OF 3D ARRAY AND CONSTANT*/
 
 int main()
 {
	 outp=fopen("E://program//distance.out","w");
	printf("\nPROGRAM TO ADD SUBSTRACT AND MULTIPLY TWO 3D ARRAY");
	printf("\nEnter the value for 3x3 A\n");
	enter_array(A);
	printf("\nEnter the value for array 3x3 B\n");
	enter_array(B);
	fprintf(outp,"\nThe ADDITTION of array A and B is:\n");
	addition_of_array(A,B);
	fprintf(outp,"\nThe SUBSTRACTION of array B from A is:\n");
	substraction_of_array(A,B);
	fprintf(outp,"\nThe MULTIPLICATION of array A and B is:\n");
	multiplication_of_array(A,B);
	fclose(outp);
	return 0;
 }

 void enter_array(int x[3][3])										/*DEFINATION OF ENTER ARRAY FUNCTION*/
 
 {
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
 }
 
 void addition_of_array(int x[3][3],int y[3][3])							/*DEFINATION OF ARARY ADDITION FUNCTION*/
 {
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			fprintf(outp,"%d\t",x[i][j]+y[i][j]);
		}
		fprintf(outp,"\n");
	}
 }
 
 void substraction_of_array(int x[3][3],int y[3][3])						/*DEFINATION OF ARRAY SUBSTRACTION FUNCTION*/
 {
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			fprintf(outp,"%d\t",x[i][j]-y[i][j]);
		}
		fprintf(outp,"\n");
	}
 }
 
 void multiplication_of_array(int x[3][3],int y[3][3])						/*DEFINATION OF ARRAY SUBSTRACTION FUNCTION*/
 {
	int i,j,k;
	int c[3][3];
	c[i][j]=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				c[i][j]=c[i][j]+x[i][k]*y[k][j];
			}
			fprintf(outp,"%d\t",c[i][j]);
		}
		fprintf(outp,"\n");
	}
 }
 