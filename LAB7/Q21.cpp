#include<bits/stdc++.h>
using namespace std;

double sumx(double x[])
{
    double res = 0;
    for (int i=0 ; i<10; i++)
    {
        res = res + x[i];

    }
    // cout<<"sumx"<<res<<endl;
    return res;
}

double sumu(double u[])
{
    double res = 0;
    for (int i=0 ; i<10; i++)
    {
        res = res + u[i];

    }
    // cout<<"sumu"<<res<<endl;
    return res;
}

double sumxsqr(double x[])
{
    double res = 0;
    for (int i=0 ; i<10; i++)
    {
        res = res + x[i]*x[i];

    }
    // cout<<"sumxsqr"<<res<<endl;
    return res;
}

double sumusqr(double u[])
{
    double res = 0;
    for (int i=0 ; i<10; i++)
    {
        res = res + u[i]*u[i];

    }
    // cout<<"sumusqr"<<res<<endl;
    return res;
}

double sumxu(double x[], double u[])
{
    double res = 0;
    for (int i=0 ; i<10; i++)
    {
        res = res + x[i]*u[i];

    }
    // cout<<"sumxu"<<res<<endl;
    return res;
}

double sumy(double y[])
{
    double res=0;
    for (int i = 0; i<10; i++)
    {
        res = res + y[i];
    }
    // cout<<"sumy"<<res<<endl;
    return res;

}

double sumxy(double x[], double y[])
{
    double res = 0;
    for (int i=0; i<10 ; i++)
    {
        res = res + x[i]*y[i];

    }
    // cout<<"sumxy"<<res<<endl;
    return res;
}

double sumyu(double y[], double u[])
{
    double res = 0;
    for (int i=0; i<10 ; i++)
    {
        res = res + y[i]*u[i];

    }
    // cout<<"sumxy"<<res<<endl;
    return res;
}

double RMS(const vector<double> &errors) 
{
    double sum = 0;
    for (const double &error : errors) {
        sum += error * error;
    }
    return sqrt(sum / errors.size());
}

vector<double> gauss_seidel_wsor(int n, const vector<vector<double>> &A, const vector<double> &B, vector<double> guess) 
{
    n = 3;
    vector<double> ans = guess;
    vector<double> errors(n);
    do {
        // cout<<RMS(errors)<<endl;
        for (int i = 0; i < n; i++) {
            double x_old = ans[i];
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * ans[j];
                }
            }
            ans[i] = (B[i] - sum) / A[i][i];
            errors[i] = abs(ans[i] - x_old);
        }
    } while (RMS(errors) > 1e-10);
    return ans;
}

int main()
{
    ifstream fkin;
    fkin.open("input21.txt");

    int n = 10;

    double x[10];
    for (int i=0; i<10; i++)
    {
        fkin>>x[i];
    }

    double u[10];
    for (int i=0; i<10; i++)
    {
        fkin>>u[i];
    }
    
    double y[10];
    for (int i=0; i<10; i++)
    {
        fkin>>y[i];
    }



    vector<double> guess(3,1);
    // for(int i = 0;i<3;i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;

    // vector<double> xx;
    // for (int i=0; i<10; i++)
    // {
    //     xx.push_back(x[i]);
    // }

    // vector<double> uu;
    // for (int i=0; i<10; i++)
    // {
    //     uu.push_back(u[i]);
    // }

    // vector<double> yy;
    // for (int i=0; i<10; i++)
    // {
    //     yy.push_back(y[i]);
    // }

    vector<vector<double>> A
    {
        {10, sumx(x), sumu(u)},
        {sumx(x), sumxsqr(x), sumxu(x, u)},
        {sumu(u), sumxu(x, u), sumusqr(u)}
    };

    vector<double> B
    {
        {sumy(y)},
        {sumxy(x, y)},
        {sumyu(y,u)}
    };

    vector<double> Ans = gauss_seidel_wsor(3,A,B,guess);
    // for (int i =0 ; i<3; i++)
    // {
    //     cout<<Ans[i]<<" ";
    // }
    fkin.close();

    ofstream fkout;
    fkout.open("output21.txt");

    fkout<<"The equation of curve is : "<<Ans[0]<<Ans[1]<<"x"<<Ans[2]<<"u"<<endl;

    fkout.close();
}

/*
0 5 10 15 20 0 5 10 15 20
0.4 0.4 0.4 0.4 0.4 0.5 0.5 0.5 0.5 0.5
50.63 45.31 35.63 22.21 27.18 42.40 27.87 26.30 29.60 24.27
7.39 8.59 9.30 7.30 6.40 7.11 7.37 6.90 6.70 5.10
*/