#include<bits/stdc++.h>
using namespace std;

void revrec(queue<int> &q){
    if(q.empty())
    return;
    int x = q.front();
    q.pop();
    revrec(q);
    q.push(x);
}
queue<int> rev(queue<int> q)
{
    revrec(q);
    return q;
}

int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}

