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
    float E = 200000000000;
    float I = 0.0003;

    float x[25];
    for (int i =0; i<=24; i++)
    {
        x[i] = i * 0.125;
        // cout<<x[i]<<endl;
    }

    ofstream fkout;
    fkout.open("output2.txt");

    float M[24];
    for (int i=0; i<24; i++)
    {
        M[i] = (calcy(x[i+1]) - calcy(x[i]))*E*I/0.125;
        fkout<<x[i]<<endl;
        fkout<<M[i]<<endl;
        fkout<<endl;
    }

    fkout<<endl;

    float S[24];
    for (int i=0; i<24; i++)
    {
        S[i] = (M[i+1]-M[i])/0.125;
        fkout<<x[i]<<endl;
        fkout<<S[i]<<endl;
        fkout<<endl;
    }
    fkout.close();

}