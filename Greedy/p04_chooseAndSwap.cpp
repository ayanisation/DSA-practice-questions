#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string chooseandswap(string a){
        set<char>st;
        string s="";
        int i;
        for(i=0;i<a.length();i++){
            if(st.find(a[i])==st.end()){
                st.insert(a[i]);
                s+=a[i];
            }
        }
        char x='$',y='$';
        i=0;
        for(auto it:st){
            if(it!=s[i]){
                x=it;
                y=s[i];
                break;
            }
            i+=1;
        }
        if(x=='$')
        return a;
        for(i=0;i<a.length();i++){
            if(a[i]==x)
            a[i]=y;
            else if(a[i]==y)
            a[i]=x;
        }
        return a;
    }
};

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}