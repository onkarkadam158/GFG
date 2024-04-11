//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    #define ll long long int
    ll bruteforce(int ind,vector<ll>&coins,int sum){
        if(ind==0){
            return ((sum%coins[ind])==0);
        }
        ll nottake = bruteforce(ind-1,coins,sum);
        ll take =0;
        if(sum>=coins[ind]) take = bruteforce(ind,coins,sum-coins[ind]);
        return nottake + take;
    }
    ll memoization(int ind,vector<ll>&coins,int sum,vector<vector<ll>>&dp){
        if(ind==0){
            return ((sum%coins[ind])==0);
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        ll nottake = memoization(ind-1,coins,sum,dp);
        ll take =0;
        if(sum>=coins[ind]) take = memoization(ind,coins,sum-coins[ind],dp);
        return dp[ind][sum]=(nottake + take);
    }
    ll tabulation(int n,vector<ll>&coins,int SUM){
        vector<vector<ll>>dp(n,vector<ll>(SUM+1,0));
        for(int sum=0;sum<=SUM;sum++){
            dp[0][sum]=((sum%coins[0])==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=SUM;sum++){
                ll nottake = dp[ind-1][sum];
                ll take =0;
                if(sum>=coins[ind]) take = dp[ind][sum-coins[ind]];
                dp[ind][sum]=(nottake + take);
            }
        }
        return dp[n-1][SUM];
    }
    ll tabulationSpaceOptimized(int n,vector<ll>&coins,int SUM){
        vector<ll>prev(SUM+1,0),curr(SUM+1,0);
        for(int sum=0;sum<=SUM;sum++){
            prev[sum]=((sum%coins[0])==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=SUM;sum++){
                ll nottake = prev[sum];
                ll take =0;
                if(sum>=coins[ind]) take = curr[sum-coins[ind]];
                curr[sum]=(nottake + take);
            }
            prev=curr;
        }
        return prev[SUM];
    }
    long long int count(int coin[], int n, int sum) {
        vector<ll>coins;
        for(int i=0;i<n;i++)coins.push_back(coin[i]);
        
        //bruteforce recrsive solution
        // return bruteforce(n-1,coins,sum);
        
        
        // memoization solution solution
        // vector<vector<ll>>dp(n,vector<ll>(sum+1,-1));
        // return memoization(n-1,coins,sum,dp);
        
        // tabulation DP solution 
        // return tabulation(n,coins,sum);
        
        
        // tabulation Space Optimized DP solution 
        return tabulationSpaceOptimized(n,coins,sum);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends