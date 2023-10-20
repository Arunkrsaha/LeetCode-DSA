//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 100


// Returns sum of perimeter of shapes formed with 1s
int findPerimeter(int mat[MAX][MAX], int n,int m);

int main() {
	int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof g);
		int n;
		cin>>n;
		int m;
		cin>>m;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<findPerimeter(g,n,m)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends


/*You are required to complete this method */
int findPerimeter(int mat[MAX][MAX], int n, int m)
{
    //Your code here
    int res = 0;
        
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j] == 1)
            {
                res += (i == 0 || mat[i-1][j] == 0 ? 1 : 0);
                res += (i == n-1 || mat[i+1][j] == 0 ? 1 : 0);
                res += (j == 0 || mat[i][j-1] == 0 ? 1 : 0);
                res += (j == m-1 || mat[i][j+1] == 0 ? 1 : 0);
            }
        }
    }
        
    return res;
}