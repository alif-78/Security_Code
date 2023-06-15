#include<bits/stdc++.h>
using namespace std;
long long int calK (long long int q)
{
    long long int i;
    for (i=2;i<q;i++)
    {
        if ( __gcd(i,q)==1)
        {
            break;
        }
    }
    return i;
}
long long int BigMod(long long int base, long long int power, long long int mod)
{
    if (power==0)
        return 1;
    else if (power % 2 == 1)
    {
        long long int a = base%mod;
        long long int b = (BigMod(base, power-1,mod)) % mod;
        return (a*b)%mod;
    }
    else
    {
        long long int a = (BigMod(base, power/2, mod ))% mod;
        return (a*a)%mod;
    }
}
long long int modularInverse(long long int e, long long int phiN)
{
    long long int d = 2;
    while (1)
    {
        if ((e % phiN)*(d%phiN)%phiN==1)
        {
            return d;
        }
        d++;
    }
}
int main()
{
    long long int q = 19,alpha=2,d=16;
    long long int e = BigMod(alpha,d,q);
    long long int m = 14;
    long long int k = calK(q-1);
    long long int s1 = BigMod(alpha,k,q);
    long long int iK = modularInverse(k,q-1);
    long long int s2 = (iK*(m-d*s1) % (q-1)) + (q-1);
    cout << s2 << endl;
    long long int v1 = BigMod(alpha,m,q);
    cout << "v1: " << v1 << endl;
    long long int v2 = (BigMod(e,s1,q) * BigMod(s1,s2,q)) % q ;
    cout << "v2: " <<v2 << endl;






}
