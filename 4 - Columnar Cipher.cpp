//Columnar cipher
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
void display(string mat[100][9],int noRows, int noCols)
{
    cout<<"\nMatrix is\n";
    for(int i=0;i<noRows;i++)
    {
        for(int j=0;j<noCols;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}
void fillMatE(string mat[100][9],string txt, string key)
{
    for(int i=0;i<100;i++)
        for(int j=0;j<9;j++)
            mat[i][j]="";
    for(int i=0;i<key.length();i++)
        mat[0][i]=key.at(i);
    int i=0,j=0,k=1;
    while(i<txt.length())
    {
        mat[k][j]=txt.at(i);
        j++;
        i++;
        if(j==key.length())
        {
            j=0;
            k++;
        }
    }
}
void fillMatD(string mat[100][9],string txt, string key)
{
    for(int i=0;i<100;i++)
        for(int j=0;j<9;j++)
            mat[i][j]="";
    for(int i=0;i<key.length();i++)
        mat[0][i]=key.at(i);
    int k=0;
    for(int x=1;x<=key.length();x++)
    {
        //find col with key val = x
        int c;
        for(c=0;c<key.length();c++)
            if(mat[0][c] == to_string(x))
                break;
        for(int i=1;i<=txt.length()/key.length();i++)
            mat[i][c]=txt.at(k++);
    }
}
string genTxt(string mat[100][9])
{
    string txt="";
    int x,n;
    for(n=0;mat[0][n]!="";n++);
    for(x=1;x<=n;x++)
    {
        //find col with key val = x
        int c;
        for(c=0;c<n;c++)
            if(mat[0][c] == to_string(x))
                break;
        for(int i=1;mat[i][c]!="";i++)
            txt+=mat[i][c];
    }
    return txt;
}
int main()
{
    string pText="",cText="",matrix[100][9]={""},key="";
    cout<<"\nEnter the plain text: ";
    getline(cin,pText);
    cout<<"\nEnter the key: ";
    cin>>key;
    pText.erase(remove(pText.begin(),pText.end(),' '),pText.end());
    //padding extra chars
    while(pText.length() % key.length() != 0)
        pText+="X";
    int noRows = pText.length() / key.length() +1;

    //filling the encryption matrix
    fillMatE(matrix,pText,key);
    display(matrix,noRows,key.length());
    cText=genTxt(matrix);
    cout<<"\nPlain Text  = "<<pText;
    cout<<"\nCipher Text = "<<cText;

    cout<<"\n\nDecrypting.....";
    fillMatD(matrix,cText,key);
    display(matrix,noRows,key.length());
    cout<<"\nCipher Text = "<<cText;
    cout<<"\nPlain Text  = ";
    for(int i=1;i<noRows;i++)
        for(int j=0;j<key.length();j++)
            cout<<matrix[i][j];
    return 0;
}
/*Inputs
attack postponed until two am
4312567
*/
