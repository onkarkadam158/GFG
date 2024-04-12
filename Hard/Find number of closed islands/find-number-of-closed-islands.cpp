//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool check(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    vector<vector<int>>arr={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i,int j,vector<vector<int>>& mat, int n, int m){
        mat[i][j]=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            for(auto a:arr){
                int dx=x+a[0],dy=y+a[1];
                if(check(dx,dy,n,m) and mat[dx][dy]){
                    mat[dx][dy]=0;
                    q.push({dx,dy});
                }
            }
            q.pop();
        }
    }
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        // Code here
        int count=0;
        for(int i=0;i<n;i++){
            if(mat[i][0]) dfs(i,0,mat,n,m);
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]) dfs(i,m-1,mat,n,m);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]) dfs(0,i,mat,n,m);
        }
        for(int i=0;i<m;i++){
            if(mat[n-1][i]) dfs(n-1,i,mat,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    count++;
                    dfs(i,j,mat,n,m);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends