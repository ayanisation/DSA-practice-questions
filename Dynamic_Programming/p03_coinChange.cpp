#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       long long int a[n+1] = {0};
       a[0] = 1;
       for(int i=0;i<m;i++){
           for(int j=S[i];j<n+1;j++)
           a[j] += a[j-S[i]];
       }
       return a[n];
    }
};

int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}