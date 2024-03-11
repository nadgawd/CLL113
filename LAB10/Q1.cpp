#include<bits/stdc++.h>
using namespace std;

float calcy(float x)
{
    float W0 = 250000;
    float L = 3;
    float E = 200000000000;
    float I = 0.0003;

    float c = W0/(120*E*I*L);
    float y = c*(-5*x*x*x*x+6*L*L*x*x-L*L*L*L);
    return y;
}
int main()
{
    float W0 = 250000;
    float L = 3;
    float E = 200000000000;
    float I = 0.0003;
    float a = 0 ;

    float x[25];
    for (int i =0; i<=24; i++)
    {
        x[i] = i * 0.125;
        // cout<<x[i]<<endl;
    }

    float h[24];
    for (int i=0; i<=23; i++)
    {
        h[i] = (x[i+1]-a)/2;
        // cout<<h[i]<<endl;
    } 

    ofstream fkout;
    fkout.open("output1.txt");

    for(int i=0; i<24; i++)
    {
        float I = (h[i]*(calcy(0) + 4*calcy(h[i])+calcy(x[i+1])))/3;
        fkout<<x[i+1]<<endl;
        fkout<<I<<endl;
        fkout<<endl;

    }

    fkout.close();

}

