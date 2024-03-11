#include <iostream>
#include <fstream>

using namespace std;

void gaussJordan(double **A, int n, double **A_inv)
{
    double **ABI = new double *[n];
    for (int i = 0; i < n; i++)
    {
        ABI[i] = new double[2 * n];
        for (int j = 0; j < n; j++)
        {
            ABI[i][j] = A[i][j];
            ABI[i][j + n] = (i == j) ? 1 : 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        int p = k;
        double pivot = ABI[k][k];

        if (pivot == 0)
        {
            for (int i = k + 1; i < n; i++)
            {
                if (ABI[i][k] != 0)
                {
                    pivot = ABI[i][k];
                    p = i;
                    break;
                }
            }

            if (p != k)
            {
                for (int i = 0; i < 2 * n; i++)
                {
                    swap(ABI[k][i], ABI[p][i]);
                }
            }
        }

        double denominator = ABI[k][k];

        for (int i = 0; i < 2 * n; i++)
        {
            ABI[k][i] /= denominator;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == k)
            {
                continue;
            }

            double temp = ABI[i][k] / ABI[k][k];

            for (int j = 0; j < 2 * n; j++)
            {
                ABI[i][j] -= temp * ABI[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A_inv[i][j] = ABI[i][j + n];
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] ABI[i];
    }
    delete[] ABI;
}

void multiplyMatrices(double **A, double **B, int n, double **result)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    double **A = new double *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    double **A_inv = new double *[n];
    for (int i = 0; i < n; i++)
    {
        A_inv[i] = new double[n];
    }

    gaussJordan(A, n, A_inv);

    // cout << "Inverse of A:" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << A_inv[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    double **productMatrix = new double *[n];
    for (int i = 0; i < n; i++)
    {
        productMatrix[i] = new double[n];
    }

    double **B = new double *[n];
    for (int i = 0; i < n; i++)
    {
        B[i] = new double[n];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A_inv, B, n, productMatrix);

    cout << "Product of Inverse of A and B:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << productMatrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
        delete[] A_inv[i];
    }

    for (int i = 0; i < n; i++)
    {
        delete[] productMatrix[i];
    }

    delete[] productMatrix;
    delete[] A;
    delete[] A_inv;

    return 0;
}
