#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define mod 1000000007
#define loop(i,a, b, c) for ( i = a; i < b; i += c)
using namespace std;
using namespace std::chrono;

class Solution{
  public:
    int FindMaxSum(int a[], int n)
    {
        if(n==1)
        return a[0];
        if(n==2)
        return max(a[0],a[1]);
        int x = a[0];
        int y = max(a[0],a[1]);
        int msum;
        for(int i=2;i<n;i++){
            msum = max(x+a[i],y);
            x = y;
            y = msum;
        }
        return msum;
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int a[n];
        loop(i,0,n,1);
        cin >> a[i];
        Solution ob;
        cout << ob.FindMaxSum(a,n) << endl;
    }
}