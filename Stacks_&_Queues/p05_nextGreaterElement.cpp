#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb       push_back
#define pi       3.1415926535897932384626
#define mod      1000000007
using namespace std;
typedef long long int ll;
int main()
{
    nitro
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll a[n],b[n];
        stack<ll>s;
        for(ll i=0;i<n;i++)
        cin >> a[i];
        for(ll i=n-1;i>=0;i--)
        {
            while(!s.empty()&&s.top()<a[i])
            s.pop();
            b[i] = s.empty()?-1:s.top();
            s.push(a[i]);
        }
        for(ll i=0;i<n;i++)
        cout << b[i] << " ";
        cout << endl;
    }
}