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
    vector<ll> productExceptSelf(vector<ll>& nums, ll n) {
        ll prod = 1,z=0;
        for(ll i=0;i<n;i++){
           if(nums[i]==0)
           z+=1;
           else prod*=nums[i];
        }
        vector <ll> v;
        for(ll i=0;i<n;i++){
            if(nums[i]==0){
                if(z>1) v.push_back(0);
                else v.push_back(prod);
            }
            else{
                if(z>0) v.push_back(0);
                else v.push_back(prod/nums[i]);
            }
        }
        return v;
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        vector<ll>v(n),vec(n);
        loop(i,0,n,1);
        cin >> v[i];
        Solution ob;
        vec = ob.productExceptSelf(v,n);
        loop(i,0,n,1)
        cout << vec[i] << " ";
        cout << endl;
    }
}