#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    string pText="",cText="",matrix[100]={""};
    int d,next,c;
    cout<<"\nEnter the plain text: ";
    getline(cin,pText);
    cout<<"\nEnter the depth: ";
    cin>>d;
    pText.erase(remove(pText.begin(),pText.end(),' '),pText.end());
    int j=0,inc=1;
    for(int i=0;i<pText.length();i++)
    {
        matrix[j]+=pText.at(i);
        j+=inc;
        if(j==0)
            inc=1;
        else if(j==d-1)
            inc=-1;
    }
    for(int i=0;i<d;i++)
        cText+=matrix[i];
    cout<<"\nPlain Text  = "<<pText;
    cout<<"\nCipher Text = "<<cText;

    cout<<"\n\nDecrypting.....";
    j=0,inc=1;
    pText="";
    string mat2[100]={""};
    for(int i=0;i<cText.length();i++)
    {
        mat2[j]+="*";
        j+=inc;
        if(j==0)
            inc=1;
        else if(j==d-1)
            inc=-1;
    }
    int k=0;
    for(int i=0;i<d;i++)
    {
        mat2[i]=cText.substr(k,mat2[i].length());
        k+=mat2[i].length();
    }
    j=0,inc=1;
    for(int i=0;i<cText.length();i++)
    {
        pText+=mat2[j].at(0);
        mat2[j].erase(mat2[j].begin());
        j+=inc;
        if(j==0)
            inc=1;
        else if(j==d-1)
            inc=-1;
    }
    cout<<"\nCipher Text = "<<cText;
    cout<<"\nPlain Text  = "<<pText;
    return 0;
}
/*Inputs
meet me after toga party
3
*/
