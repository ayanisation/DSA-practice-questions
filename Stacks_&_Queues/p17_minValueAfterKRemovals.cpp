#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minValue(string s, int k){
        map<char,int>m;
        for(int i=0;i<s.length();i++)
        m[s[i]]+=1;
        priority_queue<int>pq;
        for(auto it:m)
        pq.push(it.second);
        while(k){
            int x = pq.top();
            pq.pop();
            pq.push(x-1);
            k-=1;
        }
        int ans = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            ans+=x*x;
        }
        return ans;
    }
};

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        Solution ob;
        cout << ob.minValue(s,k) << "\n";
    }
    return 0;
}