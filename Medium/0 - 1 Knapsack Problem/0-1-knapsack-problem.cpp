//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind,int W, int wt[], int val[]){
        if(ind==0){
            if(W>=wt[0]) return val[0];
            return 0;
        }
        int ntake=solve(ind-1,W,wt,val);
        int take=0;
        if(W>=wt[ind]){
            take+=val[ind]+solve(ind-1,W-wt[ind],wt,val);
        }
        return max(ntake,take);
    }
    int memoization(int ind,int W, int wt[], int val[],vector<vector<int>>&dp){
        if(ind==0){
            if(W>=wt[0]) return val[0];
            return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int ntake=memoization(ind-1,W,wt,val,dp);
        int take=0;
        if(W>=wt[ind]){
            take+=val[ind]+memoization(ind-1,W-wt[ind],wt,val,dp);
        }
        return dp[ind][W]=max(ntake,take);
    }
    int tabulation(int n,int W, int wt[], int val[]){
        
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int j=0;j<=W;j++){
            if(j>=wt[0]) dp[0][j]=val[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int w=1;w<=W;w++){
                int ntake=dp[ind-1][w];
                int take=0;
                if(w>=wt[ind]){
                    take+=val[ind]+dp[ind-1][w-wt[ind]];
                }
                dp[ind][w]=max(take,ntake);
            }
        }
        return dp[n-1][W];
    }
    int tabulationSpaceOptimized(int n,int W, int wt[], int val[]){
        
        vector<int>prev(W+1,0),curr(W+1,0);
        for(int j=0;j<=W;j++){
            if(j>=wt[0]) prev[j]=val[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int w=1;w<=W;w++){
                int ntake=prev[w];
                int take=0;
                if(w>=wt[ind]){
                    take+=val[ind]+prev[w-wt[ind]];
                }
                curr[w]=max(take,ntake);
            }
            prev=curr;
        }
        return prev[W];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Your code here
        //recursive bruteforce solution
        // return solve(n-1,W,wt,val);
    
        
        // memoization solution
        // vector<vector<int>>dp(n,vector<int>(W+1,-1));
        // return memoization(n-1,W,wt,val,dp);
        
        // tabulation solution
        // return tabulation(n,W,wt,val);
            
        // tabulation solution
        return tabulationSpaceOptimized(n,W,wt,val);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends