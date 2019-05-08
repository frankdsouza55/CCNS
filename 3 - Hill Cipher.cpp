#include<iostream>
#include<string>
#include<algorithm>
#define N 3
using namespace std;
int modI(int a,int m)
{
	a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n)
{
    int i=0,j=0;
    for (int row = 0; row < n; row++)
        for (int col = 0; col < n; col++)
            //  Copying into temporary matrix only those element which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                // Row is filled, so increase row index and reset col index
                if (j==n-1)
                {
                    j=0;
                    i++;
                }
            }
}
// Recursive function for finding determinant of matrix.  n is current dimension of A[][].
int determinant(int A[N][N], int n)
{
    int D = 0,temp[N][N],sign = 1; // Initialize result
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}
// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(int A[N][N],int adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[N][N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            getCofactor(A, temp, i, j, N);
            sign = ((i+j)%2==0)? 1: -1;
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
}
int main()
{
    string pText="",cText="",pText1="",cText1="";
    int key[N][N],c[N][1],p[N][1],inv[N][N];
    cout<<"\nEnter plain text: ";
    getline(cin,pText);
    pText.erase( remove( pText.begin(), pText.end(), ' ' ), pText.end() );
    transform(pText.begin(),pText.end(),pText.begin(),::toupper);
    while(pText.length()%N != 0)        //append appropriate no of fillers
        pText+="X";
    cout<<"\nEnter NxN key\n";
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>key[i][j];
    pText1=pText;
    while(pText1!="")
    {
        for(int i=0;i<N;i++)
        {
            p[i][0]=pText1.at(0) - 65;
            pText1.erase(pText1.begin());
        }
        for (int i = 0; i < N; i++)
        {
            c[i][0] = 0;
            for (int k = 0; k < N; k++)
                c[i][0] += key[i][k]*p[k][0];
        }
        for(int i=0;i<N;i++)
        {
            c[i][0]=((c[i][0]%26)+26)%26;
            cText+=c[i][0] + 65;
        }
    }
    cout<<"\nPlain Text  = "<<pText;
    cout<<"\nCipher Text = "<<cText;

    cout<<"\n\nDecrypting.....";
	int det=determinant(key,N),adj[N][N],m;
	det=((det%26)+26)%26;
	m=modI(det,26);
	// cout<<"\nDet = "<<det<<"  m = "<<m;
	adjoint(key,adj);
	// cout<<"\nInverse is\n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			inv[i][j]=m*adj[i][j];
			inv[i][j]=((inv[i][j]%26)+26)%26;
			// cout<<inv[i][j]<<" ";
		}
		// cout<<"\n";
	}
	cText1=cText;
	pText="";
    while(cText1!="")
    {
        for(int i=0;i<N;i++)
        {
            c[i][0]=cText1.at(0) - 65;
            cText1.erase(cText1.begin());
        }
        for (int i = 0; i < N; i++)
        {
            p[i][0] = 0;
            for (int k = 0; k < N; k++)
                p[i][0] += inv[i][k]*c[k][0];
        }
        for(int i=0;i<N;i++)
        {
            p[i][0]=((p[i][0]%26)+26)%26;
            pText+=p[i][0] + 65;
        }
    }
    cout<<"\nCipher Text = "<<cText;
    cout<<"\nPlain Text  = "<<pText;
    return 0;
}
/*input
pay more money
17 17 5
21 18 21
2 2 19
*/
