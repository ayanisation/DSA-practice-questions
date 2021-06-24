#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.length();i++){
            if(s.empty()){
                s.push(x[i]);
                continue;
            }
            char c = s.top();
            if((c=='{'&&x[i]=='}')||(c=='('&&x[i]==')')||(c=='['&&x[i]==']'))
            s.pop();
            else s.push(x[i]);
        }
        if(s.empty())
        return true;
        return false;
    }

};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}