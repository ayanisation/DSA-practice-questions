#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                q.push(make_pair(i,j));
            }
        }
        q.push(make_pair(0,-1));
        while(q.size()>1){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(y==-1){
                q.push(make_pair(x+1,y));
                continue;
            }
            if(x>0 && grid[x-1][y]==1){
                q.push(make_pair(x-1,y));
                grid[x-1][y]=2;
            }
            if(x<grid.size()-1 && grid[x+1][y]==1){
                q.push(make_pair(x+1,y));
                grid[x+1][y]=2;
            }
            if(y>0 && grid[x][y-1]==1){
                q.push(make_pair(x,y-1));
                grid[x][y-1]=2;
            }
            if(y<grid[0].size()-1 && grid[x][y+1]==1){
                q.push(make_pair(x,y+1));
                grid[x][y+1]=2;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return q.front().first;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}