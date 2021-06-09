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
    int minSwaps(vector<int>&nums)
	{
	    map<int,int>m;
	    for(int i=0;i<nums.size();i++)
	    m[nums[i]] = i;
	    int c = 0,i=0;
	    auto it = m.begin();
	    for(;it!=m.end();++it){
	        if(it->first!=nums[i]){
	            m[nums[i]]=it->second;
	            swap(nums[i],nums[it->second]);
	            c+=1;
	        }
	        i+=1;
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
        vector<ll>nums(n);
        loop(i,0,n,1);
        cin >> nums[i];
        Solution ob;
        cout << ob.minSwaps(nums) << endl;
    }
}