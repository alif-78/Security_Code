//RSA
#include<bits/stdc++.h>
using namespace std;
long long int findEncryptionKey (long long int phiN)
{
    long long int j = 20;
    while (1)
    {
        if( __gcd(j,phiN) == 1)
        {
            return j;
        }
        j++;
    }
}
long long int findDecryptionKey(long long int e, long long int phiN) //modularInverse
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
    long long int p = 11,q = 13;
    long long int phiN = (p-1)*(q-1);
    long long int n = p * q;
    long long int e = findEncryptionKey(phiN);
    cout <<"Encryption Key: " << e << endl;
    long long int d = findDecryptionKey(e,phiN);
    cout << "Decryption Key: " << d << endl;
    long long int m = 25;
    cout << "Message: " << m << endl;
    long long int c = BigMod(m,e,n);
    cout << "Cipher: " << c << endl;
    long long int pl = BigMod(c,d,n);
    cout << "Plain text: " << pl << endl;
}

