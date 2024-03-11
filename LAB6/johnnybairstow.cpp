#include<bits/stdc++.h>

using namespace std;

float root1(float r, float s)
{
    return (r + sqrt(pow(r, 2) + 4 * s)) / 2;
}

float root2(float r, float s)
{
    return (r - sqrt(pow(r, 2) + 4 * s)) / 2;
}

float rmserror(float i1, float i2)
{
    return sqrt(pow(i1, 2) + pow(i2, 2) / 2);
}

void bairstrow(float *temp, float r, float s, int n, int br)
{
    ofstream fkout;
    fkout.open("outputjohnny.txt");
    static int iter = 0;
    iter++;

    float *b1 = new float[n + 1];
    for (int i = n; i >= br; i--)
    {
        if (i == n)
        {
            b1[i] = temp[i];
        }
        else if (i == n - 1)
        {
            b1[i] = temp[i] + b1[i + 1] * r;
        }
        else
        {
            b1[i] = temp[i] + b1[i + 1] * r + b1[i + 2] * s;
        }
    }

    float *c1 = new float[n + 1];
    for (int i = n; i >= br + 1; i--)
    {
        if (i == n)
        {
            c1[i] = b1[i];
        }
        else if (i == n - 1)
        {
            c1[i] = b1[i] + c1[i + 1] * r;
        }
        else
        {
            c1[i] = b1[i] + c1[i + 1] * r + c1[i + 2] * s;
        }
    }

    float ds = ((-b1[0] + (c1[1] / c1[2]) * b1[1]) / (c1[2] - (c1[1] / c1[2]) * c1[3]));
    float dr = ((-b1[1] - c1[3] * ds) / c1[2]);
    float eror = abs((dr / r) * 100);
    float eros = abs((ds / s) * 100);
    r += dr;
    s += ds;

    fkout << "For iter " << iter << endl;
    fkout << "r = " << r << " " << "s = " << s << endl;

    for (int i = 0; i < 3; i++)
    {
        fkout << " b" << i << " = " << b1[i] << endl;
    }

    fkout << endl;
    fkout << "dr:- " << dr << " " << "ds:- " << ds << endl;
    fkout << "eror:- " << eror << " " << "eros:- " << eros << endl;
    fkout << endl;
    float lmt = rmserror(eror, eros);

    if (lmt < 1e-5)
    {
        float ans1 = root1(r, s);
        float ans2 = root2(r, s);
        float ans3 = (-b1[2] / b1[3]);

        fkout << "positive roots obtained are : ";

        if (ans1 > 0)
        {
            fkout << ans1 << " ";
        }
        else if (ans2 > 0)
        {
            fkout << ans2 << " ";
        }
        else if (ans3 > 0)
        {
            fkout << ans3 << " ";
        }

        fkout << endl << endl;
    }
    else
    {
        delete[] b1;
        delete[] c1;
        bairstrow(temp, r, s, n, br);
    }
}

int main()
{
    ifstream fkin;
    fkin.open("inputjohnny.txt");
    int n;
    fkin >> n;

    float r, s;
    fkin >> r >> s;

    float tol = 1e-5;
    float *a = new float[n + 1];

    for (int i = n; i >= 0; i--)
    {
        fkin >> a[i];
    }

    bairstrow(a, r, s, n, 0);

    delete[] a;
    return 0;
}
