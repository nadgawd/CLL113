#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> trans(const vector<vector<double>> &X)
{
    vector<vector<double>> transX;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(7);
        for (int j=0;j<7;j++)
        {
            temp[j] = 69;
        }
        transX.push_back(temp);
    }
    
    for (int i=0; i<7; i++)
    {
        for (int j=0;j<2;j++)
        {
            transX[j][i] = X[i][j];
        }
    }
    return transX;
}

vector<vector<double>> mult1(const vector<vector<double>> &transposeX, const vector<vector<double>> &X)
{
    double res[2][2];
    
    vector<vector<double>> multXTX;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(2);
        for (int j=0;j<2;j++)
        {
            temp[j] = 69;
        }
        multXTX.push_back(temp);
    }

    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            res[i][j] = 0;
            for (int k=0; k<7; k++)
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
    double res[2][1];

    vector<vector<double>> multXTY;
    for (int i=0; i<2; i++)
    {
        vector<double> temp(2);
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
            for (int k=0; k<7; k++)
            {
                res[i][j] += transposeX[i][k] * Y[k][j];
            }
            multXTY[i][j] = res[i][j];
        }
    }
    return multXTY;

}

vector<vector<double>> mult3(const vector<vector<double>> inverse, const vector<vector<double>> &multiplyXTY)
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
                res[i][j] += inverse[i][k] * multiplyXTY[k][j];
            }
            multfin[i][j] = res[i][j];
        }
    }
    return multfin;

}

int main()
{
    vector<vector<double>> X
    {
        {1, 1},
        {1, 2},
        {1, 3},
        {1, 4},
        {1, 5},
        {1, 6},
        {1, 7}
    };

    vector<vector<double>> Y
    {
        {0.5},
        {2.5},
        {2.0},
        {4.0},
        {3.5},
        {6.0},
        {5.5}
    };

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
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<2;j++)
    //     {
    //         cout<<multiplyXTX[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<double>> multiplyXTY = mult2(transposeX, Y);   
    // cout<<multiplyXTY[0][0]<<endl;
    // cout<<multiplyXTY[1][0]<<endl;

    float det = multiplyXTX[0][0]*multiplyXTX[1][1] - multiplyXTX[0][1]*multiplyXTX[1][0];

    vector<vector<double>> inverse
    {
        {(multiplyXTX[1][1])/det, (-multiplyXTX[0][1])/det},
        {(-multiplyXTX[1][0])/det, (multiplyXTX[0][0])/det}
    };

    // cout<<inverse[0][0]<<endl;
    // cout<<inverse[0][1]<<endl;
    // cout<<inverse[1][0]<<endl;
    // cout<<inverse[1][1]<<endl;

    fstream fkout;
    fkout.open("output12A", ios::out);

    vector<vector<double>> finalans = mult3(inverse, multiplyXTY);
    fkout<<"a0 = "<<finalans[0][0]<<endl;
    fkout<<"a1 = "<<finalans[1][0]<<endl;

    fkout.close();

}