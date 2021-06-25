#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

void sortrec(stack<int> &s,int t){
    if(s.empty() || t>=s.top()){
        s.push(t);
        return;
    }
    int a = s.top();
    s.pop();
    sortrec(s,t);
    s.push(a);
}
void SortedStack :: sort()
{
    if(s.size()<=1)
    return;
    int t = s.top();
    s.pop();
    sort();
    sortrec(s,t);
}