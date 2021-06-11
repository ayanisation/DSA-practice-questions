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
   cin >> n >> m;
   ll a[n],l=0,r=0;
   loop(i,0,n,1){
      cin >> a[i];
      r = max(r,a[i]);
   }
   ll sum=0,mid=(l+r)/2;
   while(l<r){
      sum=0;
      loop(i,0,n,1){
         if(a[i]>mid)
         sum+=(a[i]-mid);
      }
      if(sum==m)
      break;
      if(sum>m)
      l = mid;
      else
      r = mid;
      mid = (l+r)/2;
      if(mid==l)
      break;
   }
   cout << mid << endl;
}