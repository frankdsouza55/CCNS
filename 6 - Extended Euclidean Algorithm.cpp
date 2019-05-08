//Extended Euclidean Algorithm
#include<iostream>
using namespace std;
int main()
{
    int a,b,x0=1,y0=0,x1=0,y1=1,xi=0,yi=1,r0,r1,ri,q;
    cout<<"\nEnter 2 numbers: ";
    cin>>a>>b;
    r0=a;
    r1=b;
    do
    {
        ri=r0%r1;
        if(ri==0)
            break;
        q=r0/r1;
        xi=x0-q*x1;
        yi=y0-q*y1;
        r0=r1;
        r1=ri;
        x0=x1;
        x1=xi;
        y0=y1;
        y1=yi;
    }while(ri!=0);
    cout<<"\n\ngcd("<<a<<","<<b<<") is : "<<r1;
    cout<<"\nx = "<<xi<<" y = "<<yi;
    return 0;
}
