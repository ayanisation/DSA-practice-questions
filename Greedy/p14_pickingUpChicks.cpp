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
 
ll c,x,i,j;
 
int main()
{
   nitro
   cin >> c;
   loop(x,1,c+1,1){
      ll n,k,b,t;
      cin >> n >> k >> b >> t;
      vector<ll>v(n);
      loop(i,0,n,1)
      cin >> v[i];
      loop(i,0,n,1){
         cin >> j;
         ll p = v[i];
         v[i] = (b-p)/j;
         if((b-p)%j>0)
         v[i]+=1;
      }
      reverse(v.begin(),v.end());
      ll swaps=0,count=0;
      while(true){
         ll p=0;
         for(;p<v.size();p++){
            if(v[p]<=t){
               swaps += p;
               count+=1;
               break;
            }
         }
         if(p==v.size()||count==k)
         break;
         v.erase(v.begin()+p);
      }
      if(count==k)
      cout << "Case #" << x << ": " << swaps << endl;
      else
      cout << "Case #" << x << ": IMPOSSIBLE" << endl;
   }
}