//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int bruteforce(int ind,int w,vector<int>&val,vector<int>&wt){
       if(ind==0){
           return (w/wt[0])*val[0];
       }
       int take=0;
       int nottake=bruteforce(ind-1,w,val,wt);
       if(w>=wt[ind]) take = val[ind]+ bruteforce(ind,w-wt[ind],val,wt);
        
        return max(take,nottake);
    }
    
    int memoization(int ind,int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
       if(ind==0){
           return (w/wt[0])*val[0];
       }
       if(dp[ind][w]!=-1) return dp[ind][w];
       int take=0;
       int nottake=memoization(ind-1,w,val,wt,dp);
       if(w>=wt[ind]) take = val[ind]+ memoization(ind,w-wt[ind],val,wt,dp);
        
        return dp[ind][w]=max(take,nottake);
    }
    
    int tabulation(int n,int W,vector<int>&val,vector<int>&wt){
       vector<vector<int>>dp(n,vector<int>(W+1,0));
       for(int w=0;w<=W;w++){
           dp[0][w]=(w/wt[0])*val[0];
       }
       for(int ind=1;ind<n;ind++){
           for(int w=0;w<=W;w++){
               int take=0;
               int nottake=dp[ind-1][w];
               if(w>=wt[ind]) take = val[ind]+ dp[ind][w-wt[ind]];
                dp[ind][w]=max(take,nottake);
           }
       }
        return dp[n-1][W];
    }
    
    
    
    int tabulationSpaceOptimized(int n,int W,vector<int>&val,vector<int>&wt){
       vector<int>prev (W+1,0),curr(W+1,0);
       for(int w=0;w<=W;w++){
           prev[w]=(w/wt[0])*val[0];
       }
       curr=prev;
       for(int ind=1;ind<n;ind++){
           for(int w=0;w<=W;w++){
               int take=0;
               int nottake=prev[w];
               if(w>=wt[ind]) take = val[ind]+ curr[w-wt[ind]];
                curr[w]=max(take,nottake);
           }
           prev=curr;
       }
        return curr[W];
    }
    int knapSack(int n, int w, int val1[], int wt1[]){
        // code here
        vector<int>val,wt;
        for(int i=0;i<n;i++) val.push_back(val1[i]);
        for(int i=0;i<n;i++) wt.push_back(wt1[i]); 
        
        // bruteforce solution time exponential space O(W) stack space
        // return bruteforce(n-1,w,val,wt);
        
        
        // memoization  solution  time O(N*W) space O(N*W) + O(W) stack space
        // vector<vector<int>>dp(n,vector<int>(w+1,-1));
        // return memoization(n-1,w,val,wt,dp);
        
        
        
        // tabulation  solution time O(N*W) space O(N*W)
        // return tabulation(n,w,val,wt);
        
        // tabulation Space Optimized time O(N*W) space O(W)
        return tabulationSpaceOptimized(n,w,val,wt);
    }
};









//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends