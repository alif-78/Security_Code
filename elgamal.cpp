//elgamal
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
    long long int p = 7907; //1.select a larger prime
    long long int d = 2753; //2.select a private key
    long long int e1 = 17; //3.select the first encryption key
    long long int e2 = BigMod(e1,d,p);//4.calculate the second encryption key
    cout << "Encryption key e1: " << e1 << endl;
    cout << "Encryption key e2: " << e2 << endl;
    cout << "Decryption key d: " << d << endl;
    long long int r = 4; //5.select a random number
    long long int m = 74; //6.assume the message
    cout << "Message: " << m << endl;
    long long int c1 = BigMod(e1,r,p); //6.calculate first cipher
    long long int c2 = (m*BigMod(e2,r,p))%p;//7.calculate 2nd cipher
    cout << "C1: " << c1 << " C2:" << c2 << endl;
    //Decryption
    long long int t1 = BigMod(c1,d,p);
    long long int t2 = modularInverse(t1,p);
    long long int decryptedMessage = BigMod(c2*t2,1,p);
    cout << "DecryptedMessage: " << decryptedMessage << endl;


}
