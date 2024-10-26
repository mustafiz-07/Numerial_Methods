#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<double> forward_substitution(vector<vector<double>> &L, vector<double> &b, int n)
{
    vector<double> y(n);
    for (int i = 0; i < n; i++)
    {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
    }
    return y;
}

vector<double> backward_substitution(vector<vector<double>> &U, vector<double> &y, int n)
{
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return x;
}

// LU factorization with partial pivoting
void LU_factorization()
{
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);

    cout << "Enter the coefficients of the variables and constants: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        cin >> B[i];
    }

    vector<vector<double>> L(n, vector<double>(n, 0));
    vector<vector<double>> U(A);

    for (int i = 0; i < n; i++)
    {
        L[i][i] = 1;
    }

    // Partial pivoting and LU decomposition
    for (int i = 0; i < n; i++)
    {
        // Partial pivoting
        int pivot = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(U[j][i]) > fabs(U[pivot][i]))
            {
                pivot = j;
            }
        }

        // Swapping rows if needed
        if (pivot != i)
        {
            swap(U[i], U[pivot]);
            swap(B[i], B[pivot]);
            if (i > 0)
            {
                swap(L[i], L[pivot]);
            }
        }

        // Check for zero pivot to prevent division by zero
        if (fabs(U[i][i]) < 1e-9)
        {
            cerr << "Error: Zero pivot encountered. Cant do LU Decomposition" << endl;
            return;
        }

        // LU Decomposition
        for (int j = i + 1; j < n; j++)
        {
            double factor = U[j][i] / U[i][i];
            L[j][i] = factor;
            for (int k = i; k < n; k++)
            {
                U[j][k] -= factor * U[i][k];
            }
        }
    }

    // Display L and U matrices
    cout << "\nMatrix L:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix U:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // solving L * y = B using forward substitution
    vector<double> y = forward_substitution(L, B, n);

    // solving U * x = y using backward substitution
    vector<double> x = backward_substitution(U, y, n);

    cout << "Solution for all the equations:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
    cout << endl;
}