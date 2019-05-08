#include <iostream>
using namespace std;
string encrypt(string text, int s)
{
	string result="";
	for (int i=0;i<text.length();i++)
	{
	    if(isalpha(text.at(i)))
            if(isupper(text.at(i)))
                result += char(int(text.at(i)+s-65)%26 +65);
            else
                result += char(int(text.at(i)+s-97)%26 +97);
        else
            result+=text.at(i);
	}
	return result;
}
int main()
{
	string text;
	int s;
	cout<<"\nEnter the plain text: ";
	getline(cin,text);
	cout<<"\nShift by: ";
	cin>>s;
	cout<<"\nCipher text: "<<encrypt(text,s);
	cout<<"\nDecrypting....";
	s = s%26;
	cout<<"\nPlain text: "<<encrypt(encrypt(text,s),26-s);
	return 0;
}
