#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define mod 1000000007
#define loop(i, a, b, c) for (i = a; i < b; i += c)
using namespace std;
using namespace std::chrono;

class Solution
{
    ll merge(ll a[], ll l, ll m, ll r)
    {
        ll c = 0;
        ll n1 = m - l + 1;
        ll n2 = r - m;
        ll a1[n1], a2[n2];
        for (ll i = 0; i < n1; i++)
            a1[i] = a[i + l];
        for (ll i = 0; i < n2; i++)
            a2[i] = a[i + m + 1];
        ll i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (a1[i] <= a2[j])
                a[k++] = a1[i++];
            else
            {
                a[k++] = a2[j++];
                c += n1 - i;
            }
        }
        while (i < n1)
            a[k++] = a1[i++];
        while (j < n2)
            a[k++] = a2[j++];
        return c;
    }

    ll mergeSort(ll a[], ll l, ll r)
    {
        ll c = 0;
        if (l < r)
        {
            ll m = l + (r - l) / 2;
            c += mergeSort(a, l, m);
            c += mergeSort(a, m + 1, r);
            c += merge(a, l, m, r);
        }
        return c;
    }

public:
    ll inversionCount(ll a[], ll n)
    {
        return mergeSort(a, 0, n - 1);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, i;
        cin >> n;
        ll a[n] loop(i, 0, n, 1);
        cin >> a[i];
        Solution ob;
        cout << ob.inversionCount(a, n) << endl;
    }
}