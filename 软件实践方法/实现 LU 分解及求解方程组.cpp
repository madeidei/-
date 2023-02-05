#include<stdio.h>
int main()
{
    float x[4];
    int i;
    float a[4][5]={48,-24,0,-12,4,
                   -24,24,12,12,4,
                   0,6,20,2,-2,
                   -6,6,2,16,-2};
    void lu(float *,int,float[]);
    lu(a[0],4,x);
    for(i=0;i<=3;i++)printf("x[%d]=%f\n",i+1,x[i]);
}
//LU�ֽⷨ
void lu(float *u,int n,float x[])
{
    int i,r,k;
    for(r=0;r<=n-1;r++)
    {
        for(i=r;i<=n;i++)
            for(k=0;k<=r-1;k++)
                *(u+r*(n+1)+i)-=*(u+r*(n+1)+k)**(u+k*(n+1)+i);
            for(i=r+1;i<=n-1;i++)
            {
                for(k=0;k<=r-1;k++)
                    *(u+i*(n+1)+r)-=*(u+i*(n+1)+k)*(*(u+k*(n+1)+r));
                *(u+i*(n+1)+r)/=*(u+r*(n+1)+r);
            }
    }

    for(i=n-1;i>=0;i--)
    {
        for(r=n-1;r>=i+1;r--)
            *(u+i*(n+1)+n)-=*(u+i*(n+1)+r)*x[r];
        x[i]=*(u+i*(n+1)+n)/(*(u+i*(n+1)+i));
    }
}


