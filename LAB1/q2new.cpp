#include<bits/stdc++.h>
using namespace std;
int main()
{ cout.precision(8);
    float x;
    float c1 = 0;
    float c2=0;
    float tp1;
    float tp2;
    float pie = 2*asin(1);
    x = pow(pie,4)/90;
    cout <<"real value of sum " << x <<endl; 
    for(int i =1;i<=10000; i++)
    {
        c1 = c1 + 1/pow(i,4);
        //cout << c1 << endl;
    }
   
    tp1  = abs((x-c1)/x)*100;
   
    for (int i =10000; i>=1; i --)
    {
        c2 = c2 + 1/pow(i,4);
       // cout << c2 << endl ;
    }
     tp2 = abs((x-c2)/x)*100;
    cout << "value of sum from forward:"<< c1 << endl;
    cout << "value of sum from backward:"<< c2 << endl;
    cout<<"error of sum from forward is:"<<tp1<<endl;
    cout<<"error of sum from backward is:"<<tp2<<endl;
return 0;
}