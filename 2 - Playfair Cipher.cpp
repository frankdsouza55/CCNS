#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string matrix[5][5]={""};
void genMatrix(string key)
{
	string letters="ABCDEFGHIKLMNOPQRSTUVWXYZ";
	transform(key.begin(),key.end(),key.begin(),::toupper);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			if(key!="")
			{
				char c=key.at(0);
				key.erase(key.begin());
				key.erase(remove(key.begin(),key.end(),c),key.end());
				letters.erase(remove(letters.begin(),letters.end(),c),letters.end());
				if(c=='j'||c=='J')
					matrix[i][j]='I';
				else
					matrix[i][j]=c;
			}
			else
			{
				matrix[i][j]=letters.at(0);
				letters.erase(letters.begin());
			}
		}
}
int main()
{
	string key,pText,cText="";
	cout<<"\nEnter the keyword: ";
	getline(cin,key);
	key.erase(remove(key.begin(),key.end(),' '),key.end());
	genMatrix(key);
	cout<<"\nPlayfair MAtrix is\n";
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<"\nEnter plain text: ";
	getline(cin,pText);
    pText.erase( remove( pText.begin(), pText.end(), ' ' ), pText.end() );
    transform(pText.begin(),pText.end(),pText.begin(),::toupper);
	//Encryption
	while(pText!="")
	{
		char p[2];
		int x[2],y[2];
		p[0]=pText.at(0);
		pText.erase(pText.begin());
		if(pText=="" || pText.at(0)==p[0])
			p[1]='X';
		else
			{
				p[1]=pText.at(0);
				pText.erase(pText.begin());
			}
		for(int i=0;i<2;i++)			//Get position of pairs in matrix
			for(int row=0;row<5;row++)
				for(int col=0;col<5;col++)
					if(matrix[row][col].at(0)==p[i])
					{
						x[i]=row;
						y[i]=col;
					}

		if(x[0] == x[1]) //Same row
			cText+= matrix[x[0]][(y[0]+1)%5] + matrix[x[1]][(y[1]+1)%5];
		else if(y[0] == y[1]) //Same col
			cText+= matrix[(x[0]+1)%5][y[0]] + matrix[(x[1]+1)%5][y[1]];
		else
			cText+= matrix[x[0]][y[1]] + matrix[x[1]][y[0]];
	}
	cout<<"\nCipher Text = "<<cText;

	cout<<"\n\nDecryping.....\n";
	pText="";
	while(cText!="")
	{
		string c;
		int x[2],y[2];
		c=cText.substr(0,2);
		cText.erase(0,2);
		for(int i=0;i<2;i++)			//Get position of pairs in matrix
			for(int row=0;row<5;row++)
				for(int col=0;col<5;col++)
					if(matrix[row][col].at(0)==c.at(i))
					{
						x[i]=row;
						y[i]=col;
					}

		if(x[0] == x[1]) //Same row
			pText+= matrix[x[0]][((y[0]-1)%5+5)%5] + matrix[x[1]][((y[1]-1)%5+5)%5];
		else if(y[0] == y[1]) //Same col
			pText+= matrix[((x[0]-1)%5+5)%5][y[0]] + matrix[((x[1]-1)%5+5)%5][y[1]];
		else
			pText+= matrix[x[0]][y[1]] + matrix[x[1]][y[0]];
	}
	cout<<"Plain Text = "<<pText;
	return 0;
}
/*
Input
must see you over cadogan west coming at once
*/
