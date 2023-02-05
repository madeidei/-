#include <iostream> 
#include <iomanip>//用于cout保留小数
 
using namespace std;
double b[100]; //定义系数矩阵的主对角线b
double a[100]; //定义系数矩阵下对角线a
double c[100]; //定义系数矩阵上对角线c
double L[100]; //定义拆解后的矩阵L
double U[100]; //定义拆解后的矩阵U
double Y[100]; //定义矩阵Y
double f[100]; //定义矩阵f
double x[100]; //定义求解结果x
double X_x[100][100];//定义输出矩阵的载体
void Func_U(double c[], double a[], double b[], int n);//定义求解U矩阵函数
void Func_L(double b[], double a[], double U[], int n);//定义求解L矩阵函数
void Func_Y(double f[], double a[], double L[], int n);//定义求解Y矩阵函数
void Func_x(double U[], double Y[], int n);//定义求解最终方程组的解x函数 
 
int main()
{
    int N; //定义矩阵阶数
    cout << "请输入系数矩阵的阶数：" << endl;
    cin >> N;
    cout << "请输入原始矩阵的主对角线b上的元素" << endl;
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
    }
    cout << "请输入原始矩阵的下对角线a上的元素" << endl;
    for (int i = 2; i <= N; i++)
    {
        cin >> a[i];
    }
    cout << "请输入原始矩阵的上对角线c上的元素" << endl;
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> c[i];
    }
    cout << "请输入f矩阵元素" << endl;
    for (int i = 1; i <= N; i++)
    {
        cin >> f[i];
    }  
    //以上为赋值模块
    Func_U(c, a, b, N); //调用求解U矩阵函数
    Func_L(b, a, U, N); //调用求解L矩阵函数
    Func_Y(f, a, L, N); //调用求解Y矩阵函数
    Func_x(U, Y, N); //调用求解方程组的解x函数
    for (int i = 1; i <= N; i++)
    {
 
        for (int j = 1; j <= N; j++)
        {
            X_x[i][j] = 0;
        }
    }//建立载体矩阵，由于LU分解矩阵的特点，先将矩阵的元素赋值为0，之后输出分解矩阵时只要将变化的元素重新赋值就行了
    for (int i = 2; i <= N; i++)
    {
        X_x[i][i - 1] = a[i];
    }//将载体矩阵的下对角线赋值为原始系数矩阵对角线a上的对应元素
    for (int i = 1; i <= N; i++)
    {
        X_x[i][i] = L[i];
    }//将载体矩阵的主对角线赋值为调用求解L矩阵函数求出的对应元素
    cout << "输出L矩阵" << endl;
    cout << setiosflags(ios::fixed) << setprecision(5);//输出结果保留5位小数
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << X_x[i][j] << " ";
        }
        cout << endl;
    }//输出L矩阵
    for (int i = 2; i <= N; i++)
    {
        X_x[i][i - 1] = 0;
    }//将载体矩阵的下对角线赋值为0
    for (int i = 1; i <= N; i++)
    {
        X_x[i][i] = 1;
    }//将载体矩阵的主对角线赋值为1
    for (int i = 2; i <= N; i++)
    {
        X_x[i - 1][i] = U[i - 1];
    }//将载体矩阵的上对角线赋值为调用求解U矩阵函数求出的对应元素
    cout << "输出U矩阵" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << X_x[i][j] << " ";
        }
        cout << endl;
    }//输出U矩阵
    cout << "输出Y矩阵" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << Y[i] << " ";
    }//输出Y矩阵
    cout << endl;
    cout << "输出x矩阵" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << x[i] << endl;
    }//输出x矩阵
    return 0;
}
 
void Func_U(double c[], double a[], double b[], int n)
{
    U[1] = c[1] / b[1];
    for (int i = 2; i <= n - 1; i++)
    {
        U[i] = c[i] / (b[i] - a[i] * U[i - 1]);
    }
}
 
void Func_L(double b[], double a[], double U[], int n)
{
    L[1] = b[1];
    for (int i = 2; i <= n; i++)
    {
        L[i] = b[i] - a[i] * U[i - 1];
    }
}
 
void Func_Y(double f[], double a[], double L[], int n)
{
    Y[1] = f[1] / L[1];
    for (int i = 2; i <= n; i++)
    {
        Y[i] = (f[i] - a[i] * Y[i - 1]) / L[i];
    }
}
 
void Func_x(double U[], double Y[], int n)
{
    x[n] = Y[n];
    for (int i = 1; i <= n - 1; i++)
    {
        x[n - i] = Y[n - i] - U[n - i] * x[n + 1 -i ];
    }
}
