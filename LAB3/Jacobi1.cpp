#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


const int MAX_ITER = 1000;
const double TOLERANCE = 1e-6;

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);
    
    cout << "Enter the matrix A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    
    cout << "Enter the vector b:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<double> x(n);
    cout << "Enter the initial guess for the solution:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<double> x_new(n);
    int iter = 0;
    float t1,t2;
    do
    {
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            t1 = x[i];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
            t2 = (float) x_new[i];

        }

        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += abs(x_new[i] - x[i]);
        }

        if (error < TOLERANCE) {
            cout << "Solution converged after " << iter << " iterations." << endl;
            break;
        }

        x = x_new;
        iter++;
    }
    while (abs(t1-t2) < TOLERANCE);

    cout << "Solution: ";
    for (int i = 0; i < n; ++i) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}