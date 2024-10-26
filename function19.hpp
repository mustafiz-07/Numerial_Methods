#include<bits/stdc++.h>
#define MAX_SIZE 100001
using namespace std;
bool flag=false;
int bn;
double coef[MAX_SIZE];
double x0,x1,x;
int roots;
double fx,fd;
double func_val(double x)
{
    double res = 0;
    int p=0;
    for(int i = bn-1; i >= 0; i--)
        res += coef[i] * pow(x,p++);
    return res;
}
double der_func_val(double x)
{
    double res=0;
    int p=0;
    for(int i=bn-1; i>=0; i--)
    {
        if(p==0)
        {
            p++;
            continue;
        }
        else
        {
            res+=p*coef[i]*pow(x,p-1);
            p++;
        }
    }
    return res;
}
void get_function()
{
    do
    {
        cout<<"Enter the degree of the polynomial:(>0) ";
        cin>>bn;
    }
    while(bn<=0);
    bn++;
    cout<<"Enter the coefficients in decreasing order :";
    for(int i=0; i<bn; i++)
        cin>>coef[i];
    if(bn==2)
    {
        cout<<"Root is: "<<(-coef[1]/coef[0])<<endl;
        flag=true;
        return;
    }
}
void bisection_method()
{
    get_function();
    if(flag) return;
    bool find_root=true;
    do
    {
        double f0,f1,fx,er;
        do
        {
            cout<<"Enter first guess: ";
            cin>>x0;
            cout<<"Enter second guess: ";
            cin>>x1;
            f0=func_val(x0);
            f1=func_val(x1);
            if(f0*f1>0.0)
                cout<<"Wrong Guess!"<<endl;
        }
        while(f0*f1>0.0);
        int step=1;
        cout<<"Enter precision(integer value): ";
        int prec;
        cin>>prec;
        cout<<setprecision(prec)<<fixed;
        cout<<"Enter tolerable error: ";
        cin>>er;
        f0=func_val(x0);
        f1=func_val(x1);
        do
        {
            x=(x0+x1)/2;
            fx=func_val(x);
            cout<<"Iteration: "<<step<<" x:"<<x<<" f(x):"<<fx<<endl;
            step++;
            if(fx*f0<0)
            {
                x1=x;
            }
            else
            {
                x0=x;
            }
        }
        while(fabs(fx)>er);
        cout<<"Root is: "<<x<<endl;
        cout<<"Do you want to find another root?\n1.Yes\t2.No\n";
        int opt;
        cin>>opt;
        if(opt==2)
            find_root=false;
    }
    while(find_root);
}
void false_position_method()
{
    get_function();
    if(flag) return;
    bool find_root=true;
    do
    {
        double f0,f1,fx,er;
        do
        {
            cout<<"Enter first guess: ";
            cin>>x0;
            cout<<"Enter second guess: ";
            cin>>x1;
            f0=func_val(x0);
            f1=func_val(x1);
            if(f0*f1>0.0)
                cout<<"Wrong Guess!"<<endl;
        }
        while(f0*f1>0.0);
        int step=1;
        cout<<"Enter precision(integer value): ";
        int prec;
        cin>>prec;
        cout<<setprecision(prec)<<fixed;
        cout<<"Enter tolerable error: ";
        cin>>er;
        f0=func_val(x0);
        f1=func_val(x1);
        do
        {
            x=(x0*f1-x1*f0)/(f1-f0);
            fx=func_val(x);
            cout<<"Iteration: "<<step<<" x:"<<x<<" f(x):"<<fx<<endl;
            step++;
            if(fx*f0<0)
            {
                x1=x;
            }
            else
            {
                x0=x;
            }
        }
        while(fabs(fx)>er);
        cout<<"Root is: "<<x<<endl;
        cout<<"Do you want to find another root?\n1.Yes\t2.No\n";
        int opt;
        cin>>opt;
        if(opt==2)
            find_root=false;
    }
    while(find_root);
}
void newton_raphson_method()
{
    get_function();
    if(flag) return;
    bool find_root=true;
    do
    {
        cout<<"Enter guess: ";
        cin>>x0;
        cout<<"Enter precision(integer value): ";
        int prec;
        cin>>prec;
        cout<<setprecision(prec)<<fixed;
        cout<<"Enter tolerable error: ";
        double e1,er;
        cin>>er;
        int step=1;
        do
        {
            fx=func_val(x0);
            fd=der_func_val(x0);
            x1=x0-fx/fd;
            e1=abs(x0-x1);//MAE
            x0=x1;
            cout<<step<<" "<<x1<<endl;
            step++;
        }
        while(e1>er);
        cout<<"The roots is: ";
        cout<<x1<<endl;
        cout<<"Do you want to find another root?\n1.Yes\t2.No\n";
        int opt;
        cin>>opt;
        if(opt==2)
            find_root=false;
    }
    while(find_root);
}
void secant_method()
{
    get_function();
    if(flag) return;
    bool find_root=true;
    do
    {
        int step=1;
        double x2,f0,f1,e,f2;
        cout<<"Enter first guess: ";
        cin>>x0;
        cout<<"Enter second guess: ";
        cin>>x1;
        cout<<"Enter precision(integer value): ";
        int prec;
        cin>>prec;
        cout<<setprecision(prec)<<fixed;
        cout<<"Enter tolerable error: ";
        cin>>e;
        int N;
        cout<<"Enter maximum iteration: ";
        cin>>N;
        do
        {
            f0=func_val(x0);
            f1=func_val(x1);
            if(f0==f1)
            {
                cout<<"Math error"<<endl;
                exit(0);
            }
            x2=x1-(x1-x0)*f1/(f1-f0);
            f2=func_val(x2);
            cout<<"Iteration-"<<step<<" x2="<<x2<<" and f(x2)= "<<f2<<endl;
            x0=x1;
            f0=f1;
            x1=x2;
            f1=f2;
            step++;
            if(step>N)
            {
                cout<<"Not Convergent."<<endl;
                exit(0);
            }
        }
        while(fabs(f2)>e);
        cout<<endl<<"Root is: "<<x2<<endl;
        cout<<"Do you want to find another root?\n1.Yes\t2.No\n";
        int opt;
        cin>>opt;
        if(opt==2)
            find_root=false;
    }
    while(find_root);
}
