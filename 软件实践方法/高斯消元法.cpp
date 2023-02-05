#include<stdio.h>
#define max 4
int main( )
{
	int i,j,k,sum,L[max][max]={0},U[max][max]={0},
		A[max][max]={4,2,1,5,8,7,2,10,4,8,3,6,12,6,11,20},
        Y[max],X[max],Result[max]={-2,-7,-7,-3};
	//求U第一行与L第一列
	for(j=0;j<4;j++) U[0][j]=A[0][j];
	for(i=1;i<4;i++) L[i][0]=A[i][0]/U[0][0];
	for(i=0;i<4;i++) L[i][i]=1;//对L的主对角线的赋值
	for(i=1;i<4;i++)
		for(j=i;j<4;j++)
		{
			//求U的其它行与列
			sum=0;
			for(k=0;k<=i-1;k++)
			sum+=L[i][k]*U[k][j];
			U[i][j]=A[i][j]-sum;
			//求L的其他行与列
			sum=0;
			for(k=0;k<=i-1;k++)
				sum+=L[j][k]*U[k][i];
			L[j][i]=(A[j][i]-sum)/U[i][i];
		}
	//数值的输出
	printf("A的二维数组为：\n");//A数组输出
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
	printf("L的二维数组为：\n");//L数组输出
	  for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",L[i][j]);
		printf("\n");
	}
	printf("U的二维数组为：\n");//U数组输出
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",U[i][j]);
		printf("\n");
	}
    //求解y1,y2,y3,y4
	Y[0]=Result[0]/L[0][0];//求解Y[0]
    for(i=1;i<4;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
		    sum+=L[i][j]*Y[j];
		Y[i]=(Result[i]-sum)/L[i][i];
	}
	//函数原始对应的值
	for(i=0;i<4;i++)
		printf("函数所对应的值为：%d\n",Result[i]);
	//数组Y的值
	 printf("\n");
	 for(i=0;i<4;i++)
		printf("Y%d的值为：%d\n",i+1,Y[i]);
	//求解x1,x2,x3,x4
	X[3]=Y[3]/U[3][3];//求解X[0]
    for(i=2;i>=0;i--)
	{
		sum=0;
		for(j=3;j>i;j--)
		    sum+=U[i][j]*X[j];
		X[i]=(Y[i]-sum)/U[i][i];
	}
	//输出x1,x2,x3,x4
	   printf("\n");
    for(i=0;i<4;i++)
		printf("X%d的值为：%d\n",i+1,X[i]);
}


