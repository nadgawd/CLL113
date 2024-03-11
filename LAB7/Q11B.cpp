#include<bits/stdc++.h>
using namespace std;

float ysqr(float y[])
{
    float result = 0;
    for (int i=0; i<7; i++)
    {
        result = result + y[i]*y[i];
    }
    // cout<<"xsqr"<<result<<endl;
    return result;
}

float sumx(float x[])
{
    float res = 0;
    for (int i=0 ; i<7; i++)
    {
        res = res + x[i];

    }
    // cout<<"sumx"<<res<<endl;
    return res;
}

float sumxy(float x[], float y[])
{
    float res = 0;
    for (int i=0; i<7 ; i++)
    {
        res = res + x[i]*y[i];

    }
    // cout<<"sumxy"<<res<<endl;
    return res;
}

float sumy(float y[])
{
    float res=0;
    for (int i = 0; i<7; i++)
    {
        res = res + y[i];
    }
    // cout<<"sumy"<<res<<endl;
    return res;

}

float st(float x[])
{
    float res = 0;
    for (int i = 0; i<7; i++)
    {
        res = res + (x[i]-sumx(x)/7)*(x[i]-sumx(x)/7);

    }
    return res;
}

float sr(float x[], float y[])
{
    float res = 0;
    int n=7;
    float b1 = (n*sumxy(x,y)-sumx(x)*sumy(y))/(n*ysqr(y)-sumy(y)*sumy(y));
    float b0 = sumx(x)/n - b1*sumy(y)/n;
    for (int i=0; i<7; i++)
    {
        res = res + (x[i]-b0-b1*y[i])*(x[i]-b0-b1*y[i]);
    }
    return res;
}

int main()
{
    fstream fkin;
    fkin.open("input11B.txt", ios::in);

    float x[7];
    for (int i=0; i<7; i++)
    {
        fkin>>x[i];
    }


    float y[7];
    for (int i =0; i<7; i++)
    {
        fkin>>y[i];
    }

    fkin.close();

    fstream fkout;
    fkout.open("output11B.txt", ios::out);

    int n=7;
    float b0;
    float b1;

    b1 = (n*sumxy(x,y)-sumx(x)*sumy(y))/(n*ysqr(y)-sumy(y)*sumy(y));
    fkout<<"b1 : "<<b1<<endl;

    b0 = sumx(x)/n - b1*sumy(y)/n;
    fkout<<"b0 : "<<b0<<endl;

    for (int i = 0; i<7; i++)
    {
        float xpre = b0 + b1*y[i];
        // cout<<xpre<<endl;
    }

    float r;
    r = sqrt((st(x) - sr(x,y))/st(x));
    fkout<<"Correlation Coefficient : "<<r;
    fkout.close();
}