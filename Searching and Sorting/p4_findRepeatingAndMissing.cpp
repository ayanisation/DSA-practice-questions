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
    int *findTwoElement(int *arr, int n) {
        int B,A;
        int x[n+1] = {0};
        for(int i=0;i<n;i++){
            if(x[arr[i]]!=0)
            B = arr[i];
            x[arr[i]] = arr[i];
        }
        for(int i=1;i<=n;i++){
            if(x[i]==0)
            A = i;
        }
        int *a = new int[2];
        a[1] = A;
        a[0] = B;
        return a;
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
        auto ans = ob.findTwoElement(a,n);
        cout << ans[0] << " " << ans[1] << endl;
    }
}