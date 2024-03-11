#include <bits/stdc++.h>
using namespace std;
int main()
{
  cout.precision(6);
  double approx_relative_error, true_relative_error, n2 = 0;
  double tolerence = 1e-6;

  double n1 = 0.005000;
  double a = 5.0;
  double sq = sqrt(a);

  int i = 1;
  n2 = (n1 + (a / n1)) / 2;
  while (abs((n1 - n2) / n2) >= tolerence)
  {
    
    approx_relative_error = abs((n2 - n1)) / n2 * 100;
    true_relative_error = abs((n2 - sq)) / sq * 100;
    cout << "for iteration :" << i << endl;
    cout << "square root value of " << a << " is " << n2 << endl;
    cout << "approximate relative error:" << approx_relative_error << endl;
    cout << "true relative error:" << true_relative_error << endl;
    cout << endl;
    n1 = n2;
    n2 = (n1 + (a / n1)) / 2;
    i++;
  }

  return 0;
}