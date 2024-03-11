#include<bits/stdc++.h>

using namespace std;

vector<double> calc(vector<double> &xpts, vector<double> &pts)
{
    vector<double> sol(8);
    for (int i = 0; i < 8; i++)
    {
        sol[i] = pts[i];
    }
    for (int i=1; i<8; i++)
    {
        for (int j=7; j>=i; j--)
        {
            sol[j] = (sol[j]-sol[j-1])/(xpts[j]-xpts[j-i]);
        }
    }
    return sol;
}

int main()
{
    double x = 2 * asin(1.0);
    vector<double> xpts(8), pts(8);

    for (int i = 0; i < 8; i++)
    {
        xpts[i] = i * (2 * x) / 7;
        pts[i] = pow(sin(xpts[i]), 2);
    }

    vector<double> sol = calc(xpts, pts);

    ofstream fkout;
    fkout.open("opQ2.txt");

    for (int i = 0; i < 8; i++)
    {
        fkout << "b(" << i-1 << ") : " << sol[i] << endl;
    }

    fkout<<endl;
    fkout.close();
    return 0;
}
