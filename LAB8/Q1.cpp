#include<bits/stdc++.h>
using namespace std;

float xsqr(float x[])
{
    float result = 0;
    for (int i=0; i<5; i++)
    {
        result = result + x[i]*x[i];
    }
    // cout<<"xsqr"<<result<<endl;
    return result;
}

float sumx(float x[])
{
    float res = 0;
    for (int i=0 ; i<5; i++)
    {
        res = res + x[i];

    }
    // cout<<"sumx"<<res<<endl;
    return res;
}

float sumxy(float x[], float y[])
{
    float res = 0;
    for (int i=0; i<5 ; i++)
    {
        res = res + x[i]*y[i];

    }
    // cout<<"sumxy"<<res<<endl;
    return res;
}

float sumy(float y[])
{
    float res=0;
    for (int i = 0; i<5; i++)
    {
        res = res + y[i];
    }
    // cout<<"sumy"<<res<<endl;
    return res;

}

int main()
{
    float c[5] = { 0.5, 0.8, 1.5, 2.5, 4};
    float x[5];
    for (int i=0; i<5; i++)
    {
        x[i] = 1/(c[i]*c[i]);
    }

    // for (int i=0; i<5; i++)
    // {
    //     cout<<x[i]<<endl;
    // }

    float k[5] = {1.1, 2.4, 5.3, 7.6, 8.9};
    float y[5];
    for (int j=0; j<5; j++)
    {
        y[j] = 1/k[j];
    }

    // for (int j=0; j<5; j++)
    // {
    //     cout<<y[j]<<endl;
    // }

    int n = 5;
    float a0;
    float a1;

    a1 =  (n*sumxy(x,y) - sumx(x)*sumy(y))/(n*xsqr(x) - sumx(x)*sumx(x));
    // cout<<a1<<endl;

    a0 = (sumy(y)/n) - (sumx(x)/n)*a1;
    // cout<<a0<<endl;

    for (int i = 0; i<5; i++)
    {
        float yfin = a0 + a1*x[i];
        // cout<<yfin<<endl;
    }

    ofstream fkout;
    fkout.open("output1.txt");

    float final;
    final = 4/(4*a0+a1);
    fkout<<"Kmax = "<<1/a0<<endl;
    fkout<<"Cs = "<<a1/a0<<endl;
    fkout<<"Y at c=2 is "<<final<<endl;

    fkout.close();

}
