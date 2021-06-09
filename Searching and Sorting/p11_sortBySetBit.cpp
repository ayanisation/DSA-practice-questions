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
    void sortBySetBitCount(int &arr, int n)
    {
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            int x = arr[i],c=0;
            while(x){
                c+=x&1;
                x=x>>1;
            }
            m[c].push_back(arr[i]);
        }
        auto it = m.rbegin();
        int j=0;
        for(;it!=m.rend();++it){
            vector <int> v((it->second).begin(),(it->second).end());
            for(int i=0;i<v.size();i++){
                arr[j]=v[i];
                j+=1;
            }
        }
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int arr[n];
        loop(i,0,n,1);
        cin >> arr[i];
        Solution ob;
        ob.sortBySetBitCount(arr,n);
        loop(i,0,n,1)
        cout << arr[i] << " ";
        cout << endl;
    }
}