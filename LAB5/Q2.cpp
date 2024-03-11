#include<bits/stdc++.h>
using namespace std;

vector<double> sph(const vector<double>& guess) 
{
    double x = guess[0];
    double y = guess[1];
    double z = guess[2];
    return {x * x + y * y + z * z - 4.0};
}

vector<double> cyl(const vector<double>& guess) 
{
    double x = guess[0];
    double y = guess[1];
    return {x * x + y * y - 1.0};
}

vector<double> ell(const vector<double>& guess) 
{
    double y = guess[1];
    double z = guess[2];
    return {4.0 * y * y + z * z - 4.0};
}

vector<vector<double>> calcjac(const vector<double>& guess) 
{
    double x = guess[0];
    double y = guess[1];
    double z = guess[2];

    vector<vector<double>> jac = 
    {
        {2 * x, 2 * y, 2 * z},
        {2 * x, 2 * y, 0},
        {0, 8 * y, 2 * z}
    };

    return jac;
}

int main() 
{
    fstream fkout;
    fkout.open("outputQ2.txt", ios::out);
    vector<double> guess = {1.0, 1.0, 1.0};
    
    double tol = 1e-6;

    int maxiter = 100;

    for (int iter = 0; iter < maxiter; ++iter) 
    {
        vector<double> sphere = sph(guess);
        vector<double> cylinder = cyl(guess);
        vector<double> ellcylinder = ell(guess);

        double trueerr = sqrt(sphere[0] * sphere[0] + cylinder[0] * cylinder[0] + ellcylinder[0] * ellcylinder[0]);
        double relerr = trueerr / sqrt(guess[0] * guess[0] + guess[1] * guess[1] + guess[2] * guess[2]);

        fkout <<"Iter = "<< iter << " " <<"True Error = "<< trueerr << " " <<"Relative Error = "<< relerr << endl;

        if (trueerr < tol) 
        {
            fkout << "x = " << guess[0] << ", y = " << guess[1] << ", z = " << guess[2] << endl;
            break;
        }

        vector<vector<double>> jaco = calcjac(guess);

        double modj = jaco[0][0] * (jaco[1][1] * jaco[2][2] - jaco[2][1] * jaco[1][2]) - jaco[0][1] * (jaco[1][0] * jaco[2][2] - jaco[2][0] * jaco[1][2]) + jaco[0][2] * (jaco[1][0] * jaco[2][1] - jaco[2][0] * jaco[1][1]);

        vector<vector<double>> invjac = 
        {
            {(jaco[1][1] * jaco[2][2] - jaco[2][1] * jaco[1][2]) / modj, -(jaco[0][1] * jaco[2][2] - jaco[2][1] * jaco[0][2]) / modj, (jaco[0][1] * jaco[1][2] - jaco[1][1] * jaco[0][2]) / modj},
            {-(jaco[1][0] * jaco[2][2] - jaco[2][0] * jaco[1][2]) / modj, (jaco[0][0] * jaco[2][2] - jaco[2][0] * jaco[0][2]) / modj, -(jaco[0][0] * jaco[1][2] - jaco[1][0] * jaco[0][2]) / modj},
            {(jaco[1][0] * jaco[2][1] - jaco[2][0] * jaco[1][1]) / modj, -(jaco[0][0] * jaco[2][1] - jaco[2][0] * jaco[0][1]) / modj, (jaco[0][0] * jaco[1][1] - jaco[1][0] * jaco[0][1]) / modj}
        };

        double dx = -(invjac[0][0] * sphere[0] + invjac[0][1] * cylinder[0] + invjac[0][2] * ellcylinder[0]);
        double dy = -(invjac[1][0] * sphere[0] + invjac[1][1] * cylinder[0] + invjac[1][2] * ellcylinder[0]);
        double dz = -(invjac[2][0] * sphere[0] + invjac[2][1] * cylinder[0] + invjac[2][2] * ellcylinder[0]);

        guess[0] += dx;
        guess[1] += dy;
        guess[2] += dz;
    }

    fkout.close();
}
