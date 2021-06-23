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
   cout << endl;
   while(t--){
      ll m,n;
      cin >> m >> n;
      priority_queue<ll>x,y;
      loop(i,0,m-1,1){
         cin >> j;
         x.push(j);
      }
      loop(i,0,n-1,1){
         cin >> j;
         y.push(j);
      }
      ll a=1,b=1,ans=0;
      while(!x.empty() && !y.empty()){
         if(x.top()>=y.top()){
            j = x.top();
            x.pop();
            ans+=(a*j);
            b+=1;
         }else{
            j = y.top();
            y.pop();
            ans+=(b*j);
            a+=1;
         }
      }
      while(!x.empty()){
         j = x.top();
         x.pop();
         ans+=(a*j);
      }
      while(!y.empty()){
         j = y.top();
         y.pop();
         ans+=(b*j);
      }
      cout << ans << endl;
   }
}