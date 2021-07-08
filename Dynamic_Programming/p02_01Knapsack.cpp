#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int a[n+1][W+1];
       memset(a,0,sizeof(a));
       for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
               if(wt[i-1]>j)
               a[i][j] = a[i-1][j];
               else
                a[i][j] = max(a[i-1][j],val[i-1]+a[i-1][j-wt[i-1]]);
           }
       }
       return a[n][W];
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        for(int i=0;i<n;i++)
            cin>>val[i];
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}