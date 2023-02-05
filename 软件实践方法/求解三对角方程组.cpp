#include <iostream> 
#include <iomanip>//����cout����С��
 
using namespace std;
double b[100]; //����ϵ����������Խ���b
double a[100]; //����ϵ�������¶Խ���a
double c[100]; //����ϵ�������϶Խ���c
double L[100]; //�������ľ���L
double U[100]; //�������ľ���U
double Y[100]; //�������Y
double f[100]; //�������f
double x[100]; //���������x
double X_x[100][100];//����������������
void Func_U(double c[], double a[], double b[], int n);//�������U������
void Func_L(double b[], double a[], double U[], int n);//�������L������
void Func_Y(double f[], double a[], double L[], int n);//�������Y������
void Func_x(double U[], double Y[], int n);//����������շ�����Ľ�x���� 
 
int main()
{
    int N; //����������
    cout << "������ϵ������Ľ�����" << endl;
    cin >> N;
    cout << "������ԭʼ��������Խ���b�ϵ�Ԫ��" << endl;
    for (int i = 1; i <= N; i++)
    {
        cin >> b[i];
    }
    cout << "������ԭʼ������¶Խ���a�ϵ�Ԫ��" << endl;
    for (int i = 2; i <= N; i++)
    {
        cin >> a[i];
    }
    cout << "������ԭʼ������϶Խ���c�ϵ�Ԫ��" << endl;
    for (int i = 1; i <= N - 1; i++)
    {
        cin >> c[i];
    }
    cout << "������f����Ԫ��" << endl;
    for (int i = 1; i <= N; i++)
    {
        cin >> f[i];
    }  
    //����Ϊ��ֵģ��
    Func_U(c, a, b, N); //�������U������
    Func_L(b, a, U, N); //�������L������
    Func_Y(f, a, L, N); //�������Y������
    Func_x(U, Y, N); //������ⷽ����Ľ�x����
    for (int i = 1; i <= N; i++)
    {
 
        for (int j = 1; j <= N; j++)
        {
            X_x[i][j] = 0;
        }
    }//���������������LU�ֽ������ص㣬�Ƚ������Ԫ�ظ�ֵΪ0��֮������ֽ����ʱֻҪ���仯��Ԫ�����¸�ֵ������
    for (int i = 2; i <= N; i++)
    {
        X_x[i][i - 1] = a[i];
    }//�����������¶Խ��߸�ֵΪԭʼϵ������Խ���a�ϵĶ�ӦԪ��
    for (int i = 1; i <= N; i++)
    {
        X_x[i][i] = L[i];
    }//�������������Խ��߸�ֵΪ�������L����������Ķ�ӦԪ��
    cout << "���L����" << endl;
    cout << setiosflags(ios::fixed) << setprecision(5);//����������5λС��
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << X_x[i][j] << " ";
        }
        cout << endl;
    }//���L����
    for (int i = 2; i <= N; i++)
    {
        X_x[i][i - 1] = 0;
    }//�����������¶Խ��߸�ֵΪ0
    for (int i = 1; i <= N; i++)
    {
        X_x[i][i] = 1;
    }//�������������Խ��߸�ֵΪ1
    for (int i = 2; i <= N; i++)
    {
        X_x[i - 1][i] = U[i - 1];
    }//�����������϶Խ��߸�ֵΪ�������U����������Ķ�ӦԪ��
    cout << "���U����" << endl;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << X_x[i][j] << " ";
        }
        cout << endl;
    }//���U����
    cout << "���Y����" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << Y[i] << " ";
    }//���Y����
    cout << endl;
    cout << "���x����" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << x[i] << endl;
    }//���x����
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
