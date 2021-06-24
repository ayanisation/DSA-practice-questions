#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        queue<int>q;
        int ans=0;
        for(int i=0;i<N;i++){
            int f=0;
            int s = q.size();
            for(int j=0;j<s;j++){
                int x=q.front();
                q.pop();
                if(x==pages[i])
                f=1;
                else
                q.push(x);
            }
            if(!f){
                ans+=1;
            }
            q.push(pages[i]);
            if(q.size()>C)
            q.pop();
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
} 