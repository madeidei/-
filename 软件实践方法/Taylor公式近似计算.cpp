#include<stdio.h>
 
int main()
{
 
	float s=1,e=2,i=1;
	while(1/i>=1e-6)
	{
        i=i*(i+1);
        e+=s/i;
	}
	printf("e=%f\n",e);
 
}
