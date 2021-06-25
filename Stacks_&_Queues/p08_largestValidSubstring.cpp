#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        stack <int> st;
        st.push(-1);
        int m=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            st.push(i);
            else{
               if(st.size()>1 && s[st.top()]=='('){
                   st.pop();
                   m = max(m,i-st.top());
               }
               else st.push(i);
            }
        }
        return m;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}