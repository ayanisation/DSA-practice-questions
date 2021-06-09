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
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll,ll>m;
        ll sum = 0,c=0;
        m[0] = 1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m.find(sum)!=m.end())
            c+=m[sum];
            m[sum]+=1;
        }
        return c;
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        vector<ll>arr(n);
        loop(i,0,n,1);
        cin >> arr[i];
        cout << findSubarray(arr,n) << endl;
    }
}