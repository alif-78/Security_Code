#include<bits/stdc++.h>
using namespace std;
long long int BigMod(long long int base, long long int power, long long int mod)
{
    if (power == 0) return 1;
    else if (power % 2 == 1)
    {
        long long int a = base%mod;
        long long int b = (BigMod(base, power-1,mod))%mod;
        return (a*b)%mod;
    }
    else
    {
        long long int a = (BigMod(base,power/2,mod))%mod;
        return (a*a)%mod;
    }
}
int main()
{
    set<int>s;
    long long int p = 19;
    for (int i=2;i<p;i++)
    {
        for (int j=1;j<p;j++)
        {
            s.insert(BigMod(i,j,p));
        }
        if (s.size()==p-1)
        {
            cout << i << endl;
            break;
        }
    }
}
