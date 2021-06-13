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
    int middle(int A, int B, int C){
        set<int>s;
        s.insert(A);
        s.insert(B);
        s.insert(C);
        return *(++s.begin());
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        Solution ob;
        cout << ob.middle(a,b,c) << endl;
    }
}