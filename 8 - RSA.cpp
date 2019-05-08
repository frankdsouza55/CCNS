//RSA - Rivest–Shamir–Adleman
#include<iostream>
#include<math.h>
using namespace std;
int modInv(int a,int m)
{
    ///Returns a value x such that (a*x) % m == 1
	a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
int modular_pow(int base,int exponent,int mod)
{
    ///Returns base^exponent % mod
    if(mod == 1)
        return 0;
    int c=1;
    for(int e=0;e<exponent;e++)
        c = c*base % mod;
    return c;
}
int main()
{
    int p,q,e,d,M,C,n,t;
    cout<<"\nEnter value of p and q: ";
    cin>>p>>q;
    n=p*q;
    t=(p-1)*(q-1);
    cout<<"\nEnter value of e: ";
    cin>>e;
    cout<<"\nEnter message M: ";
    cin>>M;
    d=modInv(e,t);
    cout<<"\nPU=["<<e<<","<<n<<"] & PR=["<<d<<","<<n<<"]";

    //Encryption
    cout<<"\n\nEncrypting....";
    C=modular_pow(M,e,n);
    cout<<"\nCipher text: "<<C;

    //Decryption
    cout<<"\n\nDecrypting....";
    M=modular_pow(C,d,n);
    cout<<"\nMessage: "<<M;
    return 0;
}

/*Input
3 11
7
5

5 11
3
9
*/
