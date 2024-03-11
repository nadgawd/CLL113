#include<bits/stdc++.h>

using namespace std;

vector<double> calcp(vector<double> &xpts, double x)
{
    vector<double> p(8, 1);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i != j)
            {
                p[i] *= ((x - xpts[j]) / (xpts[i] - xpts[j]));
            }
        }
    }
    return p;
}

int main()
{
    double x = 2 * asin(1.0);
    vector<double> xpts(8), pts(8), sol(8);

    for (int i = 0; i < 8; i++)
    {
        xpts[i] = i * (2 * x) / 7;
        pts[i] = pow(sin(xpts[i]), 2);
    }

    for (int i = 0; i < 8; i++)
    {
        vector<double> temp = calcp(xpts, xpts[i]);
        for (int j = 0; j < 8; j++)
        {
            sol[i] += pts[j] * temp[j];
        }
    }

    ofstream fkout;
    fkout.open("opQ1.txt");

    for (int i = 0; i < 8; i++)
    {
        fkout << "actual value at x = " << xpts[i] << " : " << pts[i] <<" vs calculated value at x = "<<xpts[i]<<" : "<<sol[i]<< endl;
    }

    fkout<<endl;
    fkout.close();
    return 0;
}
