#include<bits/stdc++.h>
using namespace std;
long long int BigMod(long long int base, long long int power, long long int mod)
{
    if (power == 0) return 1;
    else if (power % 2 == 1)
    {
        long long int a = base%mod;
        long long int b = (BigMod(base,power-1,mod))%mod;
        return (a*b)%mod;

    }
    else
    {
        long long int a = (BigMod(base, power/2,mod))%mod;
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
    long long int p = 7907,d=2753,e1=17;
    long long int e2 = BigMod(e1,d,p);
    long long int m1 = 72, m2=74;
    long long int r1 = 4, r2 = 5;
    //encryption
    long long int c11 = BigMod(e1,r1,p);
    long long int c12 = (m1*BigMod(e2,r1,p))%p;
    long long int c21 = BigMod(e1,r2,p);
    long long int c22 = (m2*BigMod(e2,r2,p))%p;
    //decryption
    long long int t11= BigMod(c11,d,p);
    long long int t12 = modularInverse(t11,p);
    long long int rslt1 = BigMod(c12*t12,1,p);
    long long int t21 = BigMod(c21,d,p);
    long long int t22 = modularInverse(t21,p);
    long long int rslt2 = BigMod(c22*t22,1,p);
    cout << "Message1: " << m1 << " Decrypted Message1: " << rslt1 << endl;
    cout << "Message2: " << m2 << " Decrypted Message2: " << rslt2 << endl;
    //Homomorphic
    long long int C1 = c11 * c21;
    long long int C2 = c12 * c22;
    long long t1 = BigMod(C1,d,p);
    long long t2 = modularInverse(t1,p);
    long long rslt = BigMod(C2*t2,1,p);
    cout << "Message: " << m1*m2 << " Decrypted Message: " << rslt << endl;





}
