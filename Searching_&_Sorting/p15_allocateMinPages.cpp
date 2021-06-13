#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define mod 1000000007
#define loop(i,a, b, c) for (i = a; i < b; i += c)
using namespace std;
using namespace std::chrono;

class Solution{
  public:
    int findPages(ll a[], ll n, ll m) 
    {
        if(m>n)
        return -1;
        ll l = 0,r=0;
        for(ll i=0;i<n;i++){
            l = max(a[i],l);
            r+=a[i];
        }
        if(m==n)
        return l;
        while(l<r){
            ll mid = (l+r)/2,t=m,sum=0;
            for(ll i=0;i<n&&t;i++){
                if(sum+a[i]<=mid){
                    sum+=a[i];
                }else{
                    t-=1;
                    sum=a[i];
                }
            }
            if(!t)
            l=mid+1;
            else
            r=mid;
        }
        return l;
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        ll a[n]
        loop(i,0,n,1);
        cin >> a[i];
        ll m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(a,n,m) << endl;
    }
}