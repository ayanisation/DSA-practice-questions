#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string a){
		    queue<char>q;
		    int arr[26]={0};
		    string s="";
		    for(int i=0;i<a.length();i++){
		        char c = '#';
		        arr[a[i]-'a']+=1;
		        q.push(a[i]);
		        while(!q.empty()){
		            if(arr[q.front()-'a']==1){
		                c = q.front();
		                break;
		            }
		            q.pop();
		        }
		        s+=c;
		    }
		    return s;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
} 

