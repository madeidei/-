
#include <stdio.h>
#include <math.h>

int main ()     
{
	float x,x0, f1, f2;
	printf("请输入一个近似解：\n");
	scanf("%f", &x);
	do
	{
		x0 = x;
		f1 = 2 * x * x * x - 4 * x * x + 3 * x - 6;
		f2 = 6 * x*x - 8 * x + 3;
		x = x - f1 / f2;
	} while (fabs(x - x0) >= 1e-5);
	printf("该方程的近似解为%0.4f\n", x);
	return 0;
}

