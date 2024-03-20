//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,int n,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(j<0 or j>n-1) return -1e9;
        if(i==(n-1))return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=solve(i+1,j,n,mat,dp);
        int down_right=solve(i+1,j+1,n,mat,dp);
        int down_left=solve(i+1,j-1,n,mat,dp);
        return dp[i][j]=(mat[i][j]+max(down,max(down_right,down_left)));
        
    }
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int result=0;
        for(int j=0;j<n;j++){
            result=max(result,solve(0,j,n,mat,dp));
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends