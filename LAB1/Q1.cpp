#include <iostream>
#include<iomanip>
#include<math.h>


using namespace std;

int fact(int x)
{   
    int z = 1;
    if ( x == 0)
    {
        return 1;

    }
    else
    {
        for (int i=1;i<=x;i++)
        {
            z = z*i;

        }
    }
    return z;


}
signed main()
{
    cout.precision(9);
    double n = 0.3*3.14159265359;
    double eval = 1.0;
    for (int i = 1; i<=4; i++)
    {
        eval += pow(-1,i)*pow(n,i*2)/fact(i*2);
    }
    cout<<eval<<endl;
    return 0;
}





