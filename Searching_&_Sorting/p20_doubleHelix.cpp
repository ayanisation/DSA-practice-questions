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

ll t,n,m,i,j;

int main()
{
   nitro
   while(true){
      cin >> n;
      if(!n) break;
      set<ll>s1,s2;
      loop(i,0,n+1,1){
         if(i==n)
         s1.insert(10001);
         else {
            cin >> j;
            s1.insert(j);
         }
      }
      cin >> m;
      loop(i,0,m+1,1){
         if(i==m)
         s2.insert(10001);
         else {
            cin >> j;
            s2.insert(j);
         }
      }
      map<ll,ll>m;
      j=0;
      for(auto it:s1){
         j+=it;
         if(s2.find(it)!=s2.end()){
            m[it]=j;
            j=0;
         }
      }
      j=0;
      ll sum=0;
      for(auto it:s2){
         j+=it;
         if(m.find(it)!=m.end()){
            sum+=max(j,m[it]);
            j=0;
         }
      }
      cout << sum-10001 << endl;
   }
}