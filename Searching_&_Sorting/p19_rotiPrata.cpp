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

ll t,p,n,i,j;

int main()
{
   nitro
   cin >> t;
   while(t--){
      cin >> p >> n;
      map<ll,ll>m;
      ll x;
      loop(i,0,n,1){
         cin >> x;
         m[x]+=1;
      }
      ll l=1,r=0;
      auto it = m.begin();
      x = it->first;
      r = ((p*(p+1))/2)*x;
      ll mid=(l+r)/2;
      while(l<r){
         ll x=0;
         for(auto it:m){
            ll a=0,c=0;
            for(i=1;a+(i*it.first)<=mid;i++){
               a+=i*it.first;
               c+=1;
            }
            x+=c*it.second;
         }
         if(x>=p)
         r=mid;
         else
         l=mid+1;
         mid=(l+r)/2;
      }
      cout << mid << endl;
   }
}