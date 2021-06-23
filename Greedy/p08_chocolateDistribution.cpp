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
        ll n,m;
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;i++)
        cin >> a[i];
        sort(a,a+n);
        cin >> m;
        if(m==n)
        cout << a[n-1]-a[0] << endl;
        else
        {
            ll md=1000000000000000000;
            for(ll i=0;;i++)
            {
                if(i+m-1>=n)
                break;
                md=min(md,a[i+m-1]-a[i]);
            }
            cout << md << endl;
        }
    }
}