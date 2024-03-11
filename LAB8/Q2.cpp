#include<bits/stdc++.h>
using namespace std;

vector<double> calcf(const vector<double> &x, double a, double b)
{
    vector<double> fx;
    for (int i=0; i<9; i++)
    {
        double temp = a*x[i]*exp(b*x[i]);
        fx.push_back(temp);
    }
    return fx;
}

vector<double> calcd(const vector<double> &y, const vector<double>  &f)
{
    vector<double> d;
    for (int i=0; i<9; i++)
    {
        double temp = y[i] - f[i];
        d.push_back(temp);
    }
    return d;
}

vector<double> defa(const vector<double> &x, double b)
{
    vector<double> fdasha;
    for (int i=0; i<9; i++)
    {
        double temp = x[i]*exp(b*x[i]);
        fdasha.push_back(temp);
    }
    return fdasha;
}

vector<double> defb(const vector<double> &x, double a, double b)
{
    vector<double> fdashb;
    for (int i=0; i<9; i++)
    {
        double temp = a*x[i]*x[i]*exp(b*x[i]);
        fdashb.push_back(temp);
    }
    return fdashb;
}



vector<vector<double>> trans(const vector<vector<double>> &z)
{
    vector<vector<double>> transz;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(9);
        for (int j=0;j<9;j++)
        {
            temp[j] = 69;
        }
        transz.push_back(temp);
    }
    
    for (int i=0; i<9; i++)
    {
        for (int j=0;j<2;j++)
        {
            transz[j][i] = z[i][j];
        }
    }
    return transz;
}

vector<vector<double>> mult1(const vector<vector<double>> &transposez, const vector<vector<double>> &z)
{
    double res[2][2];
    
    vector<vector<double>> multztz;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(2);
        for (int j=0;j<2;j++)
        {
            temp[j] = 69;
        }
        multztz.push_back(temp);
    }

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<9; k++)
            {
                res[i][j] += transposez[i][k] * z[k][j];
            }
            multztz[i][j] = res[i][j];
        }
    }
    return multztz;
}

vector<vector<double>> mult2(const vector<vector<double>> &transposez, const vector<vector<double>> &D)
{
    double res[2][1];

    vector<vector<double>> multXTY;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(1);
        for (int j=0;j<1;j++)
        {
            temp[j] = 69;
        }
        multXTY.push_back(temp);
    }

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<1; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<9; k++)
            {
                res[i][j] += transposez[i][k] * D[k][j];
            }
            multXTY[i][j] = res[i][j];
        }
    }
    return multXTY;

}

vector<vector<double>> mult3(const vector<vector<double>> inverse, const vector<vector<double>> &multiplyZTD)
{
    double res[2][1];

    vector<vector<double>> multfin;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(2);
        for (int j=0;j<1;j++)
        {
            temp[j] = 69;
        }
        multfin.push_back(temp);
    }

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<1; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<2; k++)
            {
                res[i][j] += inverse[i][k] * multiplyZTD[k][j];
            }
            multfin[i][j] = res[i][j];
        }
    }
    return multfin;

}

// double RMS(const vector<double> &errors) 
// {
//     double sum = 0;
//     for (const double &error : errors) {
//         sum += error * error;
//     }
//     return sqrt(sum / errors.size());
// }

// vector<double> gauss_seidel_wsor(const vector<vector<double>> &A, const vector<double> &B, vector<double> guess) 
// {
//     int n = 2;
//     vector<double> ans = guess;
//     vector<double> errors(n);
//     do {
//         // cout<<RMS(errors)<<endl;
//         for (int i = 0; i < n; i++) {
//             double x_old = ans[i];
//             double sum = 0;
//             for (int j = 0; j < n; j++) {
//                 if (i != j) {
//                     sum += A[i][j] * ans[j];
//                 }
//             }
//             ans[i] = (B[i] - sum) / A[i][i];
//             errors[i] = abs(ans[i] - x_old);
//         }
//     } while (RMS(errors) > 1e-5);
//     return ans;
// }

int main()
{
    // vector<double> guess(2,0);

    double a = 1;
    double b = 1;
    double tol = 1e-10;
    double anew, bnew;
    double m, n;

    vector<double> x
    {
        {0.1, 0.2, 0.4, 0.6, 0.9, 1.3, 1.5, 1.7, 1.8}
    };

    vector<double> y
    {
        {0.75, 1.25, 1.45, 1.25, 0.85, 0.55, 0.35, 0.28, 0.18}
    };

    do
    {vector<double> diffa = defa(x, b);
    vector<double> diffb = defb(x, a, b);

    vector<vector<double>> z;
    for (int i=0; i<9; i++)
    {
        vector<double> col;
        col.push_back(diffa[i]);
        col.push_back(diffb[i]);
        z.push_back(col);
    }

    vector<vector<double>> transposez = trans(z);
    vector<double> f = calcf(x, a, b);
    vector<double> D = calcd(y, f);

    vector<vector<double>> pussD;
    for (int i=0; i<9; i++)
    {
        vector<double> temp(3);
        for (int j=0;j<1;j++)
        {
            temp[j] = 69;
        }
        pussD.push_back(temp);
    }
    for (int i=0; i<9; i++)
    {
        pussD[i][0] = D[i];
    }

    vector<vector<double>> multiplyZTZ = mult1(transposez, z);
    vector<vector<double>> multiplyZTD = mult2(transposez, pussD);

    // vector<double> multiplyZTD;
    // for (int i=0; i<9; i++)
    // {
    //     multiplyZTD[i] = multZTD[i][0];
    // }

    // vector<double> finalans = gauss_seidel_wsor(multiplyZTZ, multiplyZTD, guess);

    float det = multiplyZTZ[0][0]*multiplyZTZ[1][1] - multiplyZTZ[0][1]*multiplyZTZ[1][0];

    vector<vector<double>> inverse
    {
        {(multiplyZTZ[1][1])/det, (-multiplyZTZ[0][1])/det},
        {(-multiplyZTZ[1][0])/det, (multiplyZTZ[0][0])/det}
    };

    vector<vector<double>> finalans = mult3(inverse, multiplyZTD);

    m = abs(finalans[0][0]/a);
    n = abs(finalans[1][0]/b);
    a = a + finalans[0][0];
    b = b + finalans[1][0];

    }
    while(m>tol && n>tol);

    ofstream fkout;
    fkout.open("output2.txt");

    fkout<<"a = "<<a<<endl;
    fkout<<"b = "<<b;

    fkout.close();
}