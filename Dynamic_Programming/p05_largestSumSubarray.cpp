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
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin >> a[i];
        } 
        ll ms[n];
        ms[0]=a[0];
        for(ll i=1;i<n;i++)
        ms[i]=max(a[i],a[i]+ms[i-1]);
        sort(ms,ms+n);
        cout << ms[n-1] << endl;
    }
}