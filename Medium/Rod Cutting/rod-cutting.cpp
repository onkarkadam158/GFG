//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int bruteforce(int ind, int n,vector<int>&prices){
        if(ind==0) {
            return (n/(ind+1))*prices[ind];
        }
        int nottake=bruteforce(ind-1,n,prices);
        int take=0;
        if((ind+1)<=n) take+=prices[ind]+bruteforce(ind,n-(ind+1),prices);
        return max(take,nottake);
    }
    int memoization(int ind, int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==0) {
            return (n/(ind+1))*prices[ind];
        }
        if(dp[ind][n]!=-1) return dp[ind][n];
        int nottake=memoization(ind-1,n,prices,dp);
        int take=0;
        if((ind+1)<=n) take+=prices[ind]+memoization(ind,n-(ind+1),prices,dp);
        return dp[ind][n]=max(take,nottake);
    }
    int tabulation(int N,vector<int>&prices){
        vector<vector<int>>dp(N,vector<int>(N+1,0));
        
        for(int n=0;n<=N;n++) dp[0][n]=n*prices[0];
        
        for(int ind=1;ind<N;ind++){
            for(int n=0;n<=N;n++){
                int nottake=dp[ind-1][n];
                int take=0;
                if((ind+1)<=n) take+=prices[ind]+dp[ind][n-(ind+1)];
                dp[ind][n]=max(take,nottake);
            }
        }
        return dp[N-1][N];
    }
    int tabulationSpaceOptimized(int N,vector<int>&prices){
        vector<int>prev(N+1,0),curr(N+1,0);
        
        for(int n=0;n<=N;n++) prev[n]=n*prices[0];
        curr=prev;
        for(int ind=1;ind<N;ind++){
            for(int n=0;n<=N;n++){
                int nottake=prev[n];
                int take=0;
                if((ind+1)<=n) take+=prices[ind]+curr[n-(ind+1)];
                curr[n]=max(take,nottake);
            }
            prev=curr;
        }
        return prev[N];
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int>prices;
        for(int i=0;i<n;i++)prices.push_back(price[i]);
        
        // bruteforce solution recursive
        // return bruteforce(n-1,n,prices);
        
        
        // memoization solution 
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return memoization(n-1,n,prices,dp);
        
        // tabulation solution
        // return tabulation(n,prices);
        
        
        // tabulation Space Optimized solution
        return tabulationSpaceOptimized(n,prices);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends