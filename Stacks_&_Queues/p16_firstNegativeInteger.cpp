#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
    vector<long long>v;
    queue<int>q;
    for(int i=0;i<N;i++){
        if(A[i]<0)
        q.push(i);
        if(i<K-1)
        continue;
        if(!q.empty() && i-q.front()==K)
        q.pop();
        if(q.empty())
        v.push_back(0);
        else
        v.push_back(A[q.front()]);
    }
    return v;
 }

int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}