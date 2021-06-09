#include <bits/stdc++.h>
#include <fstream>
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define mod 1000000007
#define loop(i,a, b, c) for ( i = a; i < b; i += c)
typedef long long int ll;
using namespace std;
using namespace std::chrono;

class Solution{
  public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i,j;
        if(k<=n){
            i=k-1;
            j=0;
        }else{
            i=n-1;
            j=k-n;
        }
        while(i>-1&&arr1[i]>arr2[j]){
            i-=1;
            j+=1;
        }
        j-=1;
        if(j==-1)
        return arr1[i];
        if(i==-1)
        return arr2[j];
        return (max(arr1[i],arr2[j]));
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,m,k,i;
        cin >> n >> m >> k;
        int arr1[n],arr2[m];
        loop(i,0,n,1);
        cin >> arr1[i];
        loop(i,0,m,1);
        cin >> arr2[i];
        Solution ob;
        cout << ob.kthElement(arr1,arr2,n,m,k) << endl;
    }
}