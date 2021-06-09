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
    int findPair(int arr[], int size, int n){
    
    multiset<int>s;
    for(int i=0;i<size;i++){
        s.insert(arr[i]);
    }
    vector<int>v;
    for(auto it:s){
        v.push_back(it);
    }
    int i=1,j=0;
    while(i<size){
        if(i==j||v[i]-v[j]<n)
        i+=1;
        else if(v[i]-v[j]>n)
        j+=1;
        else return 1;
    }
    return -1;
}
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int size,n,i;
        cin >> size >> n;
        int a[size];
        loop(i,0,size,1);
        cin >> a[i];
        Solution ob;
        cout << ob.findPair(a,size,n) << endl;
    }
}