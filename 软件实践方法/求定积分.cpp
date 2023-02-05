#include <math.h>
#include <stdio.h>
double simpson(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / (2 * n);
    double sum = f(a) + f(b);
    for (int i = 1; i <= n; i++) {
        double x = a + 2 * i * h;
        sum += 2 * f(x);
    }
    
    return sum * h / 3;
}
double ln(double x) {
    return log(x);
}
int main() {
    int n = 10000;
    double a = 0, b = 100;
    double result = simpson(ln, a, b, n);
    printf("lnx在0到100上的定积分的近似值为: %.15lf\n", result);

    return 0;
}

