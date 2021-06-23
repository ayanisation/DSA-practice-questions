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
   cin >> t;
   while(t--){
      ll w,h,n;
      cin >> w >> h >> n;
      vector<ll>x = {0,w+1};
      vector<ll>y = {0,h+1};
      ll a,b;
      loop(i,0,n,1){
         cin >> a >> b;
         x.pb(a);
         y.pb(b);
      }
      sort(x.begin(),x.end());
      sort(y.begin(),y.end());
      ll maxx=0,maxy=0;
      loop(i,1,n+2,1){
         maxx = max(maxx,x[i]-x[i-1]-1);
         maxy = max(maxy,y[i]-y[i-1]-1);
      }
      cout << maxx*maxy << endl;
   }
}