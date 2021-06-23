#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        multimap<int,int>m;
        for(int i=0;i<n;i++)
        m.insert(make_pair(end[i],start[i]));
        int c = 1;
        int f = (m.begin())->first;
        m.erase(m.begin());
        for(auto it:m){
            if(it.second>f){
                c+=1;
                f = it.first;
            }
        }
        return c;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} 