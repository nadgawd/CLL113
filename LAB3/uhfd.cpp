#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double RMSE(const vector<double> &errors) {
    double sum = 0;
    for (const double &error : errors) {
        sum += error * error;
    }
    return sqrt(sum / errors.size());
}

vector<double> jacobi(int n, const vector<vector<double>> &A, const vector<double> &B, vector<double> guess, int &n1) {
    vector<double> ans = guess;
    vector<double> errors(n);
    do {
        n1++;
        guess = ans;
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * guess[j];
                }
            }
            ans[i] = (B[i] - sum) / A[i][i];
        }
        for (int i = 0; i < n; i++) {
            errors[i] = abs(guess[i] - ans[i]);
        }
    } while (RMSE(errors) > 1e-10);
    return ans;
}

vector<double> gauss_seidel1(int n, const vector<vector<double>> &A, const vector<double> &B, vector<double> guess, int &n2) {
    vector<double> ans = guess;
    vector<double> errors(n);
    do {
        n2++;
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
    } while (RMSE(errors) > 1e-10);
    return ans;
}

double SOR(double lambda, double x_old, double x_new) {
    return (lambda * x_new) + ((1.0 - lambda) * x_old);
}

vector<double> gauss_seidel2(int n, const vector<vector<double>> &A, const vector<double> &B, vector<double> guess, double l, int &n3) {
    vector<double> ans = guess;
    vector<double> errors(n);
    do {
        n3++;
        for (int i = 0; i < n; i++) {
            double x_old = ans[i];
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += A[i][j] * ans[j];
                }
            }
            ans[i] = (B[i] - sum) / A[i][i];
            ans[i] = SOR(l, x_old, ans[i]);
            errors[i] = abs(ans[i] - x_old);
        }
    } while (RMSE(errors) > 1e-10);
    return ans;
}

int main() {
    cout << "Enter the number of equations: ";
    int n;
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> B(n);
    vector<double> initial_guess(n);

    cout << "Enter the elements for matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements for matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    cout << "Enter the values for the initial guess:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> initial_guess[i];
    }

    int n1 = 0, n2 = 0, n3 = 0;
    vector<double> X1 = jacobi(n, A, B, initial_guess, n1);
    vector<double> X2 = gauss_seidel1(n, A, B, initial_guess, n2);

    cout << "Enter the value of the weighting factor:" << endl;
    double l;
    cin >> l;

    vector<double> X3 = gauss_seidel2(n, A, B, initial_guess, l, n3);

    cout << "The solution matrix obtained through Jacobi method is:" << endl;
    for (const double &x : X1) {
        cout << x << endl;
    }
    cout << "Number of iterations taken for Jacobi: " << n1 << endl;

    cout << "The solution matrix obtained through Gauss-Seidel method (without SOR) is:" << endl;
    for (const double &x : X2) {
        cout << x << endl;
    }
    cout << "Number of iterations taken for Gauss-Seidel (without SOR): " << n2 << endl;

    cout << "The solution matrix obtained through Gauss-Seidel method (using SOR) is:" << endl;
    for (const double &x : X3) {
        cout << x << endl;
    }
    cout << "Number of iterations taken for Gauss-Seidel (using SOR): " << n3 << endl;

    return 0;
}
