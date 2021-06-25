#include<bits/stdc++.h>
using namespace std;

void revrec(queue<int> &qr){
    if(qr.empty())
    return;
    int x = qr.front();
    qr.pop();
    revrec(qr);
    qr.push(x);
}
queue<int> modifyQueue(queue<int> q, int k)
{
    queue<int>qr;
    for(int i=0;i<k;i++){
        qr.push(q.front());
        q.pop();
    }
    revrec(qr);
    while(!q.empty()){
        qr.push(q.front());
        q.pop();
    }
    return qr;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}