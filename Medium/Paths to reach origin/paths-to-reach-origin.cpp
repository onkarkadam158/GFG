//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int mod =1000000007;
    int solve(int x,int y){
        if(x==0 and y==0) return 1;
        int a=0,b=0;
        if(x>0) a=solve(x-1,y)%mod;
        if(y>0) b=solve(x,y-1)%mod;
        return (a+b)%mod;
        
    }
    
    int memoization(int x,int y,vector<vector<int>>&dp){
        if(x==0 and y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int a=0,b=0;
        if(x>0) a=memoization(x-1,y,dp)%mod;
        if(y>0) b=memoization(x,y-1,dp)%mod;
        return dp[x][y]=(a+b)%mod;
    }
    int ways(int x, int y)
    {
        //code here.
        // return solve(x,y);
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return memoization(x,y,dp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends