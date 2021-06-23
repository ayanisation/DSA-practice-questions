#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int n = N/(K+1) + (N%(K+1)>0?1:0);
        int m=0,M=0;
        for(int i=0;i<n;i++)
        m+=candies[i];
        for(int i=N-1;i>=N-n;i--)
        M+=candies[i];
        return {m,M};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}