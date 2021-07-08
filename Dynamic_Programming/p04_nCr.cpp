#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int nCr(int n, int r){
        if(r==1 || r==n-1)
        return n;
        if(r==0 || r==n)
        return 1;
        int m = 1e9 + 7;
        int a[n+1][r+1];
        memset(a,0,sizeof(a));
        for(int i=0;i<=n;i++)
        a[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=min(i,r);j++)
            a[i][j] = (a[i-1][j-1]+a[i-1][j])%m;
        }
        return a[n][r];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}