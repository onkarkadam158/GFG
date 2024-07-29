//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>>arr={{1,0},{0,-1},{0,1},{-1,0}};
    vector<char>dir={'D','L','R','U'};
    bool check(int i,int j,int n){
        return i>=0 and j>=0 and i<n and j<n;
    }
    void dfs(int row,int col,vector<vector<int>> &mat,string& temp,vector<string> &result,int n,vector<vector<int>> &vis){
        // vis[row][col]=1;
        if(row==(n-1) and col==(n-1)){
            result.push_back(temp);
            return ;
        }
        for(int i=0;i<4;i++){
            int dx=row+arr[i][0],dy=col+arr[i][1];
            if(check(dx,dy,n) and mat[dx][dy]==1 and vis[dx][dy]==0){
                vis[dx][dy]=1;
                temp+=dir[i];
                dfs(dx,dy,mat,temp,result,n,vis);
                temp.pop_back();
                vis[dx][dy]=0;
            }
        }
        // vis[row][col]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>result;
        int n=mat.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        string temp="";
        if(mat[0][0]==1){
            vis[0][0]=1;
            dfs(0,0,mat,temp,result,n,vis);
        }
        // sort(result.begin(),result.end());
        return result;
    }
};

    




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends