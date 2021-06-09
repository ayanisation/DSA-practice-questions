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

class Solution {
  public:
    int countSquares(int N) {
        if(ceil(sqrt(N))==floor(sqrt(N)))
        return (int)sqrt(N)-1;
        return (int)sqrt(N);
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countSquares(n) << endl;
    }
}