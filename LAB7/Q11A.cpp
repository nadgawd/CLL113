#include<bits/stdc++.h>
using namespace std;

float xsqr(float x[])
{
    float result = 0;
    for (int i=0; i<7; i++)
    {
        result = result + x[i]*x[i];
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

float st(float y[])
{
    float res = 0;
    for (int i = 0; i<7; i++)
    {
        res = res + (y[i]-sumy(y)/7)*(y[i]-sumy(y)/7);

    }
    return res;
}

float sr(float y[], float x[])
{
    float res = 0;
    int n=7;
    float a1 =  (n*sumxy(x,y) - sumx(x)*sumy(y))/(n*xsqr(x) - sumx(x)*sumx(x));
    float a0 = (sumy(y)/n) - (sumx(x)/n)*a1;
    for (int i=0; i<7; i++)
    {
        res = res + (y[i]-a0-a1*x[i])*(y[i]-a0-a1*x[i]);
    }
    return res;
}

int main()
{
    fstream fkin;
    fkin.open("input11A.txt", ios::in);


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
    fkout.open ("output11A.txt", ios::out);

    int n = 7;
    float a0;
    float a1;

    a1 =  (n*sumxy(x,y) - sumx(x)*sumy(y))/(n*xsqr(x) - sumx(x)*sumx(x));

    fkout<<"a1 : "<<a1<<endl;

    a0 = (sumy(y)/n) - (sumx(x)/n)*a1;

    fkout<<"a0 : "<<a0<<endl;

    for (int i = 0; i<7; i++)
    {
        float ypre = a0 + a1*x[i];
        // cout<<ypre<<endl;
    }

    float r;
    r = sqrt((st(y) - sr(y,x))/st(y));
    fkout<<"Correlation Coefficient : "<<r;

    fkout.close();


}