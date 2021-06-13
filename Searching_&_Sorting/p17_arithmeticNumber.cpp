#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define mod 1000000007
#define loop(i,a, b, c) for (i = a; i < b; i += c)
using namespace std;
using namespace std::chrono;

class Solution{
  public:
    int inSequence(int A, int B, int C){
        if(C==0){
            if(B==A)
            return 1;
            return 0;
        }
        if(C>0){
            if(B>=A&&(B-A)%C==0)
            return 1;
            return 0;
        }
        if(C<0){
            if(B<=A&&(B-A)%abs(C)==0)
            return 1;
            return 0;
        }
    }
};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        Solution ob;
        cout << ob.inSequence(a,b,c) << endl;
    }
}