#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void jacobiMethod(vector<vector<double>> &A, vector<double> &B, vector<double> &X, int n, int maxIterations, double tolerance)
{
    vector<double> X_old(n, 0.0);
    int iterations = 0;

    while (iterations < maxIterations)
    {
        bool stop = true;

        for (int i = 0; i < n; i++)
        {
            X_old[i] = X[i];
        }

        for (int i = 0; i < n; i++)
        {
            double sum = B[i];

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum -= A[i][j] * X_old[j];
                }
            }

            X[i] = sum / A[i][i];
        }

        for (int i = 0; i < n; i++)
        {
            if (fabs(X[i] - X_old[i]) > tolerance)
            {
                stop = false;
                break;
            }
        }

        if (stop)
            break;

        iterations++;
    }

    if (iterations == maxIterations)
    {
        cout << "Jacobi method did not converge within the maximum iterations.\n";
    }
    else
    {
        cout << "Jacobi method converged in " << iterations << " iterations.\n";
    }
}

void runjacobiiteration()

{
    int n, maxIterations;
    double tolerance;

    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    vector<double> X(n, 0.0); // Initial guess

    cout << "Enter the coefficients and constants:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
        cin >> B[i];
    }

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;
    cout << "Enter the tolerance for convergence: ";
    cin >> tolerance;

    jacobiMethod(A, B, X, n, maxIterations, tolerance);

    cout << "The solution is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << X[i] << endl;
    }
}