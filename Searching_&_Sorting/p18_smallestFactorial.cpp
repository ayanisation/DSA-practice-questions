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

int zeroCount(int a){
    int c=0;
    for(int i=5;i<=a;i*=5)
    c+=a/i;
    return c;
}

class Solution
{
    public:
    int findNum(int n)
    {
        int l=1,r=n*5,ans,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(zeroCount(mid)>=n){
                ans = mid;
                r=mid-1;
            }
            else
            l = mid+1;
        }
        return ans;
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
}