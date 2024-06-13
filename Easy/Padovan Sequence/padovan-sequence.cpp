//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1e9+7;
    int solve(int n){
        if(n<3) return 1;
        return solve(n-2)%mod+solve(n-3)%mod;
    }
    int memoization(int n,vector<int>&dp){
        if(n<3) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=(memoization(n-2,dp)+memoization(n-3,dp))%mod;
    }
    int tabulation(int n){
        vector<int>dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-2]+dp[i-3])%mod;
        }
        return dp[n]%mod;
    }
    int padovanSequence(int n)
    {
       //code here
    //   return solve(n);//bruteforce 
    
        // vector<int>dp(n+1,-1);
        // return memoization(n,dp);
       
       return tabulation(n);
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends