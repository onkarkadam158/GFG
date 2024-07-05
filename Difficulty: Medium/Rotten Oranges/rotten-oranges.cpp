//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    bool check(int i,int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    bool allRote(vector<vector<int>>& grid){
        for(auto a:grid){
            for(auto x:a){
                // cout<<x<<" ";
                if(x==1) return false;
            }
            // cout<<endl;
        }
        return true;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        n=grid.size(),m=grid[0].size();
        int result=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int ,int >,int >>que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int x=que.front().first.first;
                int y=que.front().first.second;
                int distance=que.front().second;
                result=max(result,distance);
                que.pop();
                for(auto a:dir){
                    int dx=x+a[0],dy=y+a[1];
                    if(check(dx,dy) and grid[dx][dy]==1 and vis[dx][dy]!=2){
                        que.push({{dx,dy},distance+1});
                        vis[dx][dy]=2;
                    }
                }
                grid[x][y]=2;
            }
        }
        if(!allRote(grid)) return -1;
        return result;
    }
};

//{ Driver Code Starts.
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
// } Driver Code Ends