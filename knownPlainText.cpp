#include<bits/stdc++.h>
using namespace std;
long long int BigMod(long long int base, long long int power , long long int mod)
{
    if (power==0)
        return 1;
    else if (power % 2 == 1)
    {
        long long int a = base % mod;
        long long int b = BigMod(base, power-1,mod) % mod;
        return (a* b) % mod;
    }
    else
    {
        long long int a = BigMod(base,power/2, mod)% mod;
        return(a*a) % mod;
    }
}
int main()
{
    long long int m=1243,e=7,n=130381;
    long long int c = BigMod(m,e,n);
    int i = 2;
    while (1)
    {
        if (BigMod(c,i,n)==m)
        {
            cout << i << endl;
            break;
        }
        i++;

    }
}
