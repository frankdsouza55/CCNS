//Rabin Miller Algorithm
//divide (n - 1) by 2 until the result is an odd number , for a total of k divisions.
#include<iostream>
#include<math.h>
#include<ctime>
using namespace std;
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
void rabMil(int a,int q,int n, int k)
{
    ///Outputs whether n is composite or not
    int x=modular_pow(a,q,n);
    if(x == 1)
    {
        cout<<"\n\n"<<n<<" Maybe Prime";
        return;
    }
    for(int j=0;j<k;j++)
    {
        x=modular_pow(a, pow(2,j)*q ,n);
        if(x == n-1)
        {
            cout<<"\n\n"<<n<<" Maybe Prime";
            return;
        }
    }
    cout<<"\n\n"<<n<<" is Composite";
}
int main()
{
    int n,k=0,q,a,ch;
    srand(time(0));
    cout<<"\nEnter value of n: ";
    cin>>n;
    q=n-1;
    do
    {
        q=q/2;
        k++;
    }while(q%2==0);
    cout<<"q = "<<q<<", k = "<<k;
    cout<<"\nPress 0 to generate random value for a: ";
    cin>>ch;
    if(!ch)
    {
        a=rand() %n +1;
        cout<<"\nTaking a => "<<a;
    }
    else
    {
        cout<<"\nEnter value of a: ";
        cin>>a;
    }
    if(n==2)
        cout<<"\n\n"<<n<<" is Prime";
    else if(n%2==0)
        cout<<"\n\n"<<n<<" is Composite";
    else
        rabMil(a,q,n,k);
    return 0;
}
