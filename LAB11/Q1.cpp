#include<bits/stdc++.h>

using namespace std;

float der(float y)
{
    return -y*y;
}

float shu(float a, float b, float c)
{
    float l = b*b - 4*a*c;
    return (-b + sqrt(l))/(2*a);
}

int main()
{
    ofstream fkout;
    fkout.open("output.txt");
    float h[5] = {0.1, 0.2, 0.5, 1, 2};
    for (int i=0; i<5; i++)
    {
        fkout << "For h="<< h[i] << endl;
        float y[6];
        y[0] = {1};

        fkout<< "By Explicit Euler Method: "<<endl;
        for (int j=0; j<5; j++)
        {
            y[j+1] = y[j] + h[i] * der(y[j]);
            fkout<<y[j+1]<<endl;
            // fkout<<abs(y[j+1]-y[j])*100/y[j+1]<<endl;
        }
        fkout<<endl;

        float z[6];
        z[0] = {1};

        fkout<< "By Crank Nicholson Method: "<<endl;
        for (int j=0; j<5; j++)
        {
            z[j+1] = shu((h[i]/2),1,-1*((y[j]+((h[i]/2)*der(y[j])))));
            fkout<<z[j+1]<<endl;
            // fkout<<abs(z[j+1]-z[j])*100/z[j+1]<<endl;
        }
        fkout<<endl;
        float k[6];
        k[0] = {1};

        fkout<< "By Implicit Euler Method: "<<endl;
        for (int j=0; j<5; j++)
        {
            k[j+1] = shu(h[i], 1, (-1)*y[j]);
            fkout<<k[j+1]<<endl;
            // fkout<<abs(k[j+1]-k[j])*100/k[j+1]<<endl;
        }
        fkout<<endl<<endl<<endl;
    }
    fkout.close();
}