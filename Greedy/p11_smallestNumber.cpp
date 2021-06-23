#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string smallestNumber(int S, int D){
        string ans = "";
        for(int i=1;i<=D;i++){
            if(S>9){
                if(i==D){
                    ans = "-1";
                    break;
                }
                ans = "9"+ans;
                S-=9;
            }
            else if(S==1){
                if(i<D)
                ans = "0"+ans;
                else
                ans = "1"+ans;
            }
            else{
                if(i<D){
                    ans = to_string(S-1) + ans;
                    S=1;
                }
                else
                ans = to_string(S)+ans;
            }
        }
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 