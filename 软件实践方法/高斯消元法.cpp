#include<stdio.h>
#define max 4
int main( )
{
	int i,j,k,sum,L[max][max]={0},U[max][max]={0},
		A[max][max]={4,2,1,5,8,7,2,10,4,8,3,6,12,6,11,20},
        Y[max],X[max],Result[max]={-2,-7,-7,-3};
	//��U��һ����L��һ��
	for(j=0;j<4;j++) U[0][j]=A[0][j];
	for(i=1;i<4;i++) L[i][0]=A[i][0]/U[0][0];
	for(i=0;i<4;i++) L[i][i]=1;//��L�����Խ��ߵĸ�ֵ
	for(i=1;i<4;i++)
		for(j=i;j<4;j++)
		{
			//��U������������
			sum=0;
			for(k=0;k<=i-1;k++)
			sum+=L[i][k]*U[k][j];
			U[i][j]=A[i][j]-sum;
			//��L������������
			sum=0;
			for(k=0;k<=i-1;k++)
				sum+=L[j][k]*U[k][i];
			L[j][i]=(A[j][i]-sum)/U[i][i];
		}
	//��ֵ�����
	printf("A�Ķ�ά����Ϊ��\n");//A�������
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
	printf("L�Ķ�ά����Ϊ��\n");//L�������
	  for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",L[i][j]);
		printf("\n");
	}
	printf("U�Ķ�ά����Ϊ��\n");//U�������
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d\t",U[i][j]);
		printf("\n");
	}
    //���y1,y2,y3,y4
	Y[0]=Result[0]/L[0][0];//���Y[0]
    for(i=1;i<4;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
		    sum+=L[i][j]*Y[j];
		Y[i]=(Result[i]-sum)/L[i][i];
	}
	//����ԭʼ��Ӧ��ֵ
	for(i=0;i<4;i++)
		printf("��������Ӧ��ֵΪ��%d\n",Result[i]);
	//����Y��ֵ
	 printf("\n");
	 for(i=0;i<4;i++)
		printf("Y%d��ֵΪ��%d\n",i+1,Y[i]);
	//���x1,x2,x3,x4
	X[3]=Y[3]/U[3][3];//���X[0]
    for(i=2;i>=0;i--)
	{
		sum=0;
		for(j=3;j>i;j--)
		    sum+=U[i][j]*X[j];
		X[i]=(Y[i]-sum)/U[i][i];
	}
	//���x1,x2,x3,x4
	   printf("\n");
    for(i=0;i<4;i++)
		printf("X%d��ֵΪ��%d\n",i+1,X[i]);
}


