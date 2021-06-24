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
      ll n;
      cin >> n;
      ll ones=0;
      vector<ll>v;
      loop(i,0,n,1){
         cin >> j;
         if(j==1) ones+=1;
         else v.pb(j);
      }
      while(ones--)
      cout << "1 ";
      sort(v.begin(),v.end(),greater<ll>());
      if(v.size()==2 && v[0]==3 && v[1]==2)
      cout << "2 3";
      else{
         loop(i,0,v.size(),1)
         cout << v[i] << " ";
      }
      cout << endl;
   }
}