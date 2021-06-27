#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<int,int>>q;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[0].size();j++){
	            if(grid[i][j]){
	                q.push(make_pair(i,j));
	                grid[i][j] = 0;
	            }
	            else grid[i][j] = 501;;
	        }
	    }
	    while(!q.empty()){
	        int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x>0 && grid[x-1][y]>grid[x][y]+1){
                q.push(make_pair(x-1,y));
                grid[x-1][y]=grid[x][y]+1;
            }
            if(x<grid.size()-1 && grid[x+1][y]>grid[x][y]+1){
                q.push(make_pair(x+1,y));
                grid[x+1][y]=grid[x][y]+1;
            }
            if(y>0 && grid[x][y-1]>grid[x][y]+1){
                q.push(make_pair(x,y-1));
                grid[x][y-1]=grid[x][y]+1;
            }
            if(y<grid[0].size()-1 && grid[x][y+1]>grid[x][y]+1){
                q.push(make_pair(x,y+1));
                grid[x][y+1]=grid[x][y]+1;
            }
	    }
	    return grid;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}