#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int r = 0, c =0 ;
    cin>>r>>c;
    
    double m[r][c];

    int i = 0, j=0;
    while(i<r)
    {
        while(j<c)
        {
            cin>>m[i][j];

            j++;

        }
        i++;
        j = 0;

    }

    cout<<endl;


    
}


