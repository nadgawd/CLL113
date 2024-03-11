#include<bits/stdc++.h>
#define fl double
#include<fstream> 
#define vi vector<fl>
#define rep(i,j,k) for(int i = j;i<k;i++)
#define int long long int
using namespace std;

fl eval(fl x,fl y)
{
    return (-y*y);
}

fl rooter(fl a, fl b, fl c) 
{
    fl du = b*b - 4*a*c;
    fl r1 = (-b + sqrt(du)) / (2*a);
    return r1;
}


vi elexp(fl x,fl y,fl h)
{
    vi ans(5);
    ans[0] = y;
    rep(i,1,5)
    {
        ans[i] = ans[i-1]+(h*eval(x,ans[i-1]));
    }
    return ans;
}
vi elimp(fl x, fl y, fl h)
{
    vi ans(5);
    ans[0] = y;
    rep(i,1,5)
    {
      ans[i] = rooter(h, 1, (-1*ans[i-1]));  
    }
    return ans;
}

vi cnmeth(fl x,fl y,fl h)
{
    vi ans(5);
    ans[0] = y;
    rep(i,1,5)
    {
        ans[i] =rooter((h/2),1,(-1*(ans[i-1]+((h/2)*eval(x,ans[i-1])))));
    }
    return ans;
}

signed main()
{
    fl x =0;
    fl y = 1;
    vi h(5);
    vi p(5);
    h[0] = 0.1;h[1] = 0.2;h[2] = 0.5;h[3] = 1;h[4] = 2;
    rep(i,0,5)
    {
        // fl temp = x;
        vi ans1 = elexp(x,y,h[i]);
        vi ans2 = elimp(x,y,h[i]);
        vi ans3 = cnmeth(x,y,h[i]);
        cout<<endl<<"----------------------------------------------------------------"<<endl;
        cout<<h[i]<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Euler's Explicit Method:- "<<endl;
        rep(j,0,ans1.size())
        {
            cout<<ans1[j]<<endl;
            // cout<<abs((ans1[j]-ans1[j-1])/ans1[j])*100<<endl;
        }
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Euler's Implicit Method:- "<<endl;
        rep(j,0,ans1.size())
        {
            // cout<<abs((ans2[j]-ans2[j-1])/ans2[j])*100<<endl;
            cout<<ans2[j]<<endl;
        }
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Crank Nicholson's Method:- "<<endl;
        rep(j,0,ans1.size())
        {
            cout<<ans3[j]<<endl;
            // cout<<abs((ans3[j]-ans3[j-1])/ans3[j])*100<<endl;

        }
        cout<<"----------------------------------------------------------------"<<endl;
    }
    

}