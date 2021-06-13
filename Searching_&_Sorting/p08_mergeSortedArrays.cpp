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

class Solution{
  public:
    void merge(int &arr1, int &arr2, int n, int m) {
	    int i = n-1;
	    int j = 0;
	    while(i>-1&&j<m&&arr1[i]>arr2[j]){
	        swap(arr1[i],arr2[j]);
	        i-=1;
	        j+=1;
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n,m,i;
        cin >> n >> m;
        int arr1[n],arr2[m];
        loop(i,0,n,1);
        cin >> arr1[i];
        loop(i,0,m,1);
        cin >> arr2[i];
        Solution ob;
        ob.merge(arr1,arr2,n,m);
        loop(i,0,n,1);
        cout << arr1[i] << " ";
        loop(i,0,m,1);
        cout << arr2[i] << " ";
        cout << endl;
    }
}