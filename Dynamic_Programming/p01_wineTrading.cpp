#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define loop(i, a, b, c) for (i = a; i < b; i += c)
#define rloop(i, a, b, c) for (i = a; i > b; i -= c)
using namespace std;
using namespace std::chrono;
ll mod = 1000000007;
ll tot = 1000000001;
 
ll t,i,j;
 
int main()
{
   nitro
   while(true){
      ll n;
      cin >> n;
      if(!n) break;
      ll x,sum=0,ans=0;
      loop(i,0,n,1){
          cin >> x;
          sum+=x;
          ans+=abs(sum);
      }
      cout << ans << endl;
   }
}