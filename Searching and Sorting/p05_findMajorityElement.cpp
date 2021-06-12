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
    int majorityElement(int a[], int size)
    {
        map<int,int>m;
        for(int i=0;i<size;i++)
        m[a[i]]+=1;
        int x = -1;
        for(auto it:m){
            if(it.second>size/2){
                x = it.first;
                break;
            }
        }
        return x;
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
        cout << ob.majorityElement(a,n) << endl;
    }
}