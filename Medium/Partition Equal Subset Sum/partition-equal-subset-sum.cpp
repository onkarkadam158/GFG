//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool bruteforce(int ind,vector<int>&arr, int sum){
        if(sum==0) return true;
        if(ind==0) return arr[0]==sum;
        
        bool take = false;
        if(sum>=arr[ind]) take=bruteforce(ind-1,arr,sum-arr[ind]);
        
        bool nottake = bruteforce(ind-1,arr,sum);
        return (take or nottake);
    }
    bool Memoization(int ind,vector<int>&arr, int sum,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(ind==0) return arr[0]==sum;
        
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        bool take = false;
        if(sum>=arr[ind]) take=Memoization(ind-1,arr,sum-arr[ind],dp);
        
        bool nottake = Memoization(ind-1,arr,sum,dp);
        return dp[ind][sum]=(take or nottake);
    }
    int tabulation(int n,vector<int>&arr,int sum){
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        for(int ind=0;ind<n;ind++){
            dp[ind][0]=true;
        }
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                
                bool take = false;
                if(target>=arr[ind]) take=dp[ind-1][target-arr[ind]];
                
                bool nottake = dp[ind-1][target];
                dp[ind][target]=(take or nottake);
            }
        }
        return dp[n-1][sum];
    }
    int tabulationSpaceOptimized(int n,vector<int>&arr,int sum){
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(arr[0]>=0 and arr[0]<=sum) prev[arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=sum;target++){
                
                bool take = false;
                if(target>=arr[ind]) take=prev[target-arr[ind]];
                
                bool nottake = prev[target];
                curr[target]=(take or nottake);
            }
            prev=curr;
        }
        return prev[sum];
    }
    int equalPartition(int n, int arr1[])
    {
        // code here
        //basic operation for all types of solutions
        vector<int>arr;
        int sum=0;
        for(int i=0;i<n;i++){ sum+=arr1[i],arr.push_back(arr1[i]);}
        if(sum%2!=0) return false;
        sum=sum/2;
        
        // recursive bruteforce solution 
        // return bruteforce(n-1,arr,sum);
        
        //Memoization solution 
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return Memoization(n-1,arr,sum,dp);
        
        
        //Tabulation solution 
        // return tabulation(n,arr,sum);
        
        
        //Tabulation solution 
        return tabulationSpaceOptimized(n,arr,sum);
    }
};












//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends