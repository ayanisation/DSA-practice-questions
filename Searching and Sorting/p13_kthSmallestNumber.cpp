#include <bits/stdc++.h>
#include <fstream>
typedef long long int ll;
#define nitro ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pi 3.1415926535897932384626
#define mod 1000000007
 using namespace std;
using namespace std::chrono;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        int l,r;
		map<int,int>m;
		for(int i=0;i<n;i++){
			cin >> l >> r;
			if(m.find(l)!=m.end())
			m[l] = max(m[l],r);
			else m[l]=r;
		}
		auto it=m.begin();
		while(it!=m.end()){
			if(++it==m.end()) break;
			auto itn = it;
			--it;
			if(itn->first-it->second<=1){
				it->second=max(it->second,itn->second);
				m.erase(itn);
			}
			else ++it;
		}
		vector<int>v;
		for(auto itr:m){
			for(int i=itr.first;i<=itr.second;i++)
			v.push_back(i);
		}
		int x;
		for(int i=0;i<q;i++){
			cin >> x;
			if(x>v.size())
			cout << "-1" << endl;
			else
			cout << v[x-1] << endl;
		}
    }
}