#include<bits/stdc++.h>
using namespace std;
long long int findEncryptionKey (long long int phiN)
{
    long long int j = 2;
    while (1)
    {
        if( __gcd(j,phiN) == 1)
        {
            return j;
        }
        j++;
    }
}
long long int lcm (long long int p, long long int q)
{
    long long int lcm = ((p-1)*(q-1))/__gcd(p,q);
    return lcm;
}
long long int piliarL (long long int x, long long int n)
{
    long long int L = (x-1)/n;
    return L;
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
long long int BigMod (long long int base, long long int power, long long int mod)
{
    if (power==0) return 1;
    else if (power % 2 == 1)
    {
        long long int a = base%mod;
        long long int b = (BigMod(base, power-1, mod)) % mod;
        return (a*b)%mod;
    }
    else
    {
        long long int a = (BigMod(base, power/2 , mod)) % mod;
        return (a*a)%mod;
    }
}
int main()
{
    long long int p = 79 , q = 83 , n = p*q;
    long long int lemda = lcm(p,q);
    long long int r = 5;
    long long int temMu = piliarL(BigMod(r,lemda,n*n),n);
    long long int Mu = modularInverse(temMu,n);
    cout << "Public key: (n,r) = (" << n << ","  << r << ")"  << endl;
    cout << "Private key: (lemda,Mu) = (" << lemda << ","  << Mu << ")"  << endl;
    //encrypt
    long long int m = 80;
    cout << "Message:" << m << endl;
    long long int e = findEncryptionKey(n);
    long long int cipher = BigMod(BigMod(r,m,n*n)*BigMod(e,n,n*n),1,n*n);
    cout << "Cipher: " << cipher << endl;
    //decrypt
    long long int t = BigMod(cipher,lemda,n*n);
    long long int t1 = piliarL(t,n);
    long long int message = ((t1 % n) * (Mu % n)) % n;
    cout << "decryptedMessage:" << message << endl;


}
