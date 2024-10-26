#include <bits/stdc++.h>
using namespace std;

void partial_pivoting(vector<vector<double>> &A, vector<double> &B, int n)
{
    int maxi = 0;
    for (int j = 1; j < n; j++)
    {
        if (fabs(A[j][0]) > fabs(A[maxi][0]))
        {
            maxi = j;
        }
    }

    swap(A[0], A[maxi]);
    swap(B[0], B[maxi]);
}

void gauss_elimination(vector<vector<double>> A, vector<double> B, vector<double> &X, int n)
{

    partial_pivoting(A, B, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double f = A[j][i] / A[i][i];
            for (int k = i; k < n; k++)
            {
                A[j][k] -= f * A[i][k];
            }
            B[j] -= f * B[i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        X[i] = B[i];
        for (int j = i + 1; j < n; j++)
        {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}

void gauss_jordan_elimination(vector<vector<double>> A, vector<double> B, vector<double> &X, int n)
{
    partial_pivoting(A, B, n);
    for (int i = 0; i < n; i++)
    {
        double div = A[i][i];
        for (int j = 0; j < n; j++)
        {
            A[i][j] /= div;
        }
        B[i] /= div;

        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = A[k][i];
                for (int j = 0; j < n; j++)
                {
                    A[k][j] -= factor * A[i][j];
                }
                B[k] -= factor * B[i];
            }
        }
    }

    X.clear();
    X = B;
}
void Inverse_matrix()
{
    cout << "Give Matrix Dimension(n*n)" << endl;
    int n;
    cin >> n;
    vector<vector<double>> A(n, vector<double>(n));

    vector<vector<double>> I(n, vector<double>(n));

    cout << "Give Input Row-wise" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            I[i][j] = 0;
            if (i == j)
                I[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        double div = A[i][i];
        if (div == 0)
        {
            cout << "Math Error!!!" << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            A[i][j] /= div;
            I[i][j] /= div;
        }
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = A[k][i];
                for (int j = 0; j < n; j++)
                {
                    A[k][j] -= factor * A[i][j];
                    I[k][j] -= factor * I[i][j];
                }
            }
        }
    }
    cout << "Solution: ";
    cout << endl;
    cout << setprecision(3) << fixed;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            cout << I[i][j] << "   ";
        }
        cout << endl;
    }
}
double fun(double x, double y)
{
    return (y * y - x * x) / (y * y + x * x);
}

void rung_kutta()
{
    double n, x0, y0, xn, yn, k1, k2, k3, k4, k;
    cout << "Enter Initial Condition(x0,y0)" << endl;
    cin >> x0;
    cin >> y0;
    cout << "Enter xn =  ";
    cin >> xn;
    cout << "Enter number of steps:  ";
    cin >> n;
    double h = (xn - x0) / n;
    for (int i = 0; i < n; i += 1)
    {
        k1 = h * (fun(x0, y0));
        k2 = h * (fun((x0 + h / 2), (y0 + k1 / 2)));
        k3 = h * (fun((x0 + h / 2), (y0 + k2 / 2)));
        k4 = h * (fun((x0 + h), (y0 + k3)));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        x0 += h;
        y0 = yn;
    }
    cout << xn << " " << yn << endl;
}

void run_gauss_elimination()
{
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    vector<double> X(n, 0.0);

    cout << "Enter the coefficients and constants:\n"
         << "xn  yn  zn  d";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        cin >> B[i];
    }
    gauss_elimination(A, B, X, n);
    cout << "The solution is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << X[i] << "  ";
    }
}
void run_gauss_jordan_elimination()
{
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    vector<double> X(n, 0.0);

    cout << "Enter the coefficients and constants:\n"
         << "xn  yn  zn  d";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        cin >> B[i];
    }
    gauss_jordan_elimination(A, B, X, n);
    cout << "The solution is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << X[i] << "  ";
    }
}

