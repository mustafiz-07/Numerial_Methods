#include <bits/stdc++.h>
using namespace std;

int main()
{
    int closeapp = 1;
    do
    {

        cout << "What type of equations you want to solve?" << endl;
        cout << "1. Linear Equation" << endl;
        cout << "2. Non-Linear Equation" << endl;
        cout << "3. Differential Equation" << endl;
        cout << "4. Matrix Inversion" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Which method you want to use?" << endl;
            cout << "1. Jacobi iterative method" << endl;
            cout << "2. Gauss-Seidel iterative method" << endl;
            cout << "3. Gauss elimination" << endl;
            cout << "4. Gauss-Jordan elimination" << endl;
            cout << "5. LU factorization" << endl;
            int methodchoice;
            cin >> methodchoice;
            system("cls");
            switch (methodchoice)
            {
            case 1:
                // runjacobiiteration();
                break;
            case 2:
                // rungausseidel();
                break;
            case 3:
                run_gauss_elimination();
                break;
            case 4:
                run_gauss_jordan_elimination();
                break;
            case 5:
                // run_LU();
                break;
            default:
                break;
            }
            break;

        case 2:
            cout << "Which method you want to use?" << endl;
            cout << "1. Bisection method" << endl;
            cout << "2. False position method" << endl;
            cout << "3. Newton Raphson method" << endl;
            cout << "4. Secant Method" << endl;
            int method;
            cin >> method;
            system("cls");
            if (method == 1)
            {
                // bisection_method();
            }
            else if (method == 2)
            {
                // false_position_method();
            }
            else if (method == 3)
            {
                // newton_raphson_method();
            }
            else
            {
                // secant_method();
            }
            break;
        case 3:
            system("cls");
            rung_kutta();
            break;
        case 4:
            system("cls");
            Inverse_matrix();
            break;
        default:
            break;
        }
        cout << "Want to use the application again?(0/1)";
        cin >> closeapp;
        system("cls");
        if (closeapp == 0)
        {
            cout << "Thanks for using the app" << endl;
        }
    } while (closeapp);
    return 0;
}


