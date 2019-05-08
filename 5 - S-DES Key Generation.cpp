#include<iostream>
using namespace std;
string leftRotate(string x,int p)
{
    string temp=x.substr(0,p);
    return x.substr(p,x.length())+temp;
}
string p8(string x)
{
    string s="";
    s+=x.at(5);
    s+=x.at(2);
    s+=x.at(6);
    s+=x.at(3);
    s+=x.at(7);
    s+=x.at(4);
    s+=x.at(9);
    s+=x.at(8);
    return s;
}
int main()
{
    string key,k1,k2,l,r,t;
    cout<<"\nEnter the 10 bit key: ";
    cin>>key;
    if(key.length() != 10)
    {
        cout<<"\nKey is not 10 bits";
        return 0;
    }
    t=key;
    key.at(0)=t.at(2);
    key.at(1)=t.at(4);
    key.at(2)=t.at(1);
    key.at(3)=t.at(6);
    key.at(4)=t.at(3);
    key.at(5)=t.at(9);
    key.at(6)=t.at(0);
    key.at(7)=t.at(8);
    key.at(8)=t.at(7);
    key.at(9)=t.at(5);
    l=key.substr(0,5);
    r=key.substr(5,5);
    l=leftRotate(l,1);
    r=leftRotate(r,1);
    k1=p8(l+r);
    l=leftRotate(l,2);
    r=leftRotate(r,2);
    k2=p8(l+r);
    cout<<"\n\nK1 = "<<k1<<"\nK2 = "<<k2;
    return 0;
}
/*Inputs
1010000010
*/
