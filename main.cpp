#include <bits/stdc++.h>
#include "function73.hpp"
#include "function19.hpp"
#include "function58.hpp"
using namespace std;
#define endl '\n'

int main()
{
    int closeapp = 1;
    do
    {
        cout << "=========================================" << endl;
        cout << "What type of equations you want to solve?" << endl;
        cout << "1. Linear Equation" << endl;
        cout << "2. Non-Linear Equation" << endl;
        cout << "3. Differential Equation" << endl;
        cout << "4. Matrix Inversion" << endl;
        cout << "=========================================" << endl;
        int choice;
        int methodchoice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {

            cout << "=========================================" << endl;
            cout << "Which method you want to use?" << endl;
            cout << "1. Jacobi iterative method" << endl;
            cout << "2. Gauss-Seidel iterative method" << endl;
            cout << "3. Gauss elimination" << endl;
            cout << "4. Gauss-Jordan elimination" << endl;
            cout << "5. LU factorization" << endl;
            cout << "=========================================" << endl;
            cin >> methodchoice;
            switch (methodchoice)
            {
            case 1:
                system("cls");
                runjacobiiteration();
                break;
            case 2:
                system("cls");
                rungausseidel();
                break;
            case 3:
                system("cls");
                run_gauss_elimination();
                break;
            case 4:
                system("cls");
                run_gauss_jordan_elimination();
                break;
            case 5:
                system("cls");
                LU_factorization();
                break;
            default:
                break;
            }
            break;
        }
        case 2:
        {
            cout << "=========================================" << endl;
            cout << "Which method you want to use?" << endl;
            cout << "1. Bi-section method " << endl;
            cout << "2. False position method " << endl;
            cout << "3. Secant method " << endl;
            cout << "4. Newton-Raphson method " << endl;
            cout << "=========================================" << endl;
            int methodchoice;
            cin >> methodchoice;
            switch (methodchoice)
            {
            case 1:
                system("cls");
                bisection_method();
                break;
            case 2:
                system("cls");
                false_position_method();
                break;
            case 3:
                system("cls");
                secant_method();
                break;
            case 4:
                system("cls");
                newton_raphson_method();
                break;
            default:
                break;
            }
        }
        case 3:
        {

        cout << "=========================================" << endl;
            cout << "Which method you want to use?" << endl;
            cout << "1. Runge-Kutta method " << endl;
        cout << "=========================================" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                system("cls");
                rung_kutta();
                break;
            default:
                break;
            }
        }
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
