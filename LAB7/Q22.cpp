#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> trans(const vector<vector<double>> &X)
{
    vector<vector<double>> transX;
    for (int i=0; i<3; i++)
    {
        vector<double> temp(10);
        for (int j=0;j<10;j++)
        {
            temp[j] = 69;
        }
        transX.push_back(temp);
    }
    
    for (int i=0; i<10; i++)
    {
        for (int j=0;j<3;j++)
        {
            transX[j][i] = X[i][j];
        }
    }
    return transX;
}

vector<vector<double>> mult1(const vector<vector<double>> &transposeX, const vector<vector<double>> &X)
{
    double res[3][3];
    
    vector<vector<double>> multXTX;
    for (int i=0; i<3; i++)
    {
        vector<double> temp(3);
        for (int j=0;j<3;j++)
        {
            temp[j] = 69;
        }
        multXTX.push_back(temp);
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<10; k++)
            {
                res[i][j] += transposeX[i][k] * X[k][j];
            }
            multXTX[i][j] = res[i][j];
        }
    }
    return multXTX;
}

vector<vector<double>> mult2(const vector<vector<double>> &transposeX, const vector<vector<double>> &Y)
{
    double res[3][1];

    vector<vector<double>> multXTY;
    for (int i=0; i<3; i++)
    {
        vector<double> temp(3);
        for (int j=0;j<1;j++)
        {
            temp[j] = 69;
        }
        multXTY.push_back(temp);
    }

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<1; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<10; k++)
            {
                res[i][j] += transposeX[i][k] * Y[k][j];
            }
            multXTY[i][j] = res[i][j];
        }
    }
    return multXTY;

}

double RMS(const vector<double> &errors) 
{
    double sum = 0;
    for (const double &error : errors) {
        sum += error * error;
    }
    return sqrt(sum / errors.size());
}

vector<double> gauss_seidel_wsor(const vector<vector<double>> &A, const vector<double> &B, vector<double> guess) 
{
    int n = 3;
    vector<double> ans = guess;
    vector<double> errors(n);
    do {
        // cout<<RMS(errors)<<endl;
        for (int i = 0; i < n; i++) {
            double x_old = ans[i];
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * ans[j];
                }
            }
            ans[i] = (B[i] - sum) / A[i][i];
            errors[i] = abs(ans[i] - x_old);
        }
    } while (RMS(errors) > 1e-5);
    return ans;
}

int main()
{
    vector<double> gu(3,0);

    vector<vector<double>> X
    {
        {1, 0, 0.4},
        {1, 5, 0.4},
        {1, 10, 0.4},
        {1, 15, 0.4},
        {1, 20, 0.4},
        {1, 0, 0.5},
        {1, 5, 0.5},
        {1, 10, 0.5},
        {1, 15, 0.5},
        {1, 20, 0.5}
    };

    vector<vector<double>> Y
    {
        {50.63},
        {45.31}, 
        {35.63},
        {22.21},
        {27.18},
        {42.40},
        {27.87},
        {26.30},
        {29.60},
        {24.27}
    };

    // vector<vector<double>> Y
    // {
    //     {7.39},
    //     {8.59},
    //     {9.30},
    //     {7.30},
    //     {6.40},
    //     {7.11},
    //     {7.37},
    //     {6.90},
    //     {6.70},
    //     {5.10}
    // };    

    // for(int i=0;i<X.size();i++)
    // {
    //     for(int j=0;j<X[i].size();j++)
    //     {
    //         cout<<X[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    vector<vector<double>> transposeX = trans(X);
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<7;j++)
    //     {
    //         cout<<transposeX[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<double>> multiplyXTX = mult1(transposeX, X);
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<multiplyXTX[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<double>> multiplyXTY = mult2(transposeX, Y);   
    // cout<<multiplyXTY[0][0]<<endl;
    // cout<<multiplyXTY[1][0]<<endl;

    vector<double> pussXTY(3);
    pussXTY[0] = multiplyXTY[0][0];
    pussXTY[1] = multiplyXTY[1][0];
    pussXTY[2] = multiplyXTY[2][0];

    // cout<<inverse[0][0]<<endl;
    // cout<<inverse[0][1]<<endl;
    // cout<<inverse[1][0]<<endl;
    // cout<<inverse[1][1]<<endl;

    ofstream fkout;
    fkout.open("output22.txt");

    vector<double> finalload = gauss_seidel_wsor(multiplyXTX, pussXTY, gu);
    fkout<<"The equation of curve is : "<<finalload[0]<<finalload[1]<<"u"<<finalload[2]<<"w"<<endl;

    fkout.close();
}

