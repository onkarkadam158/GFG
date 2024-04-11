//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int bruteforce(int ind,vector<int>&arr,int sum){
	    if(ind<0) return sum==0;
	    int ntake=bruteforce(ind-1,arr,sum)%mod;
	    int take=0;
	    if(sum>=arr[ind]) take=bruteforce(ind-1,arr,sum-arr[ind])%mod;
	    return (take+ntake)%mod;
	}
	int memoization(int ind,vector<int>&arr,int sum,vector<vector<int>>&dp){
	   // if(sum==0) return 1;
	   // if(ind==0){
	   //    return (arr[0] == sum) ? 1 : 0;
	   // }
	    if(ind<0) return sum==0;
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int ntake=memoization(ind-1,arr,sum,dp)%mod;
	    int take=0;
	    if(sum>=arr[ind])take = memoization(ind-1,arr,sum-arr[ind],dp)%mod;
	    return dp[ind][sum]=(take+ntake)%mod;
	}
	int TabulationSolution(int n,vector<int>&arr,int sum){
	    vector<vector<int>>dp(n,vector<int>(sum+1,0));
	    for(int ind=0;ind<n;ind++)dp[ind][0]=1;
	    if(arr[0]<=sum) dp[0][arr[0]]=1;
	    
    	for(int ind=1;ind<n;ind++){
    	    for(int target=1;target<=sum;target++){
        	    int ntake=dp[ind-1][target];
        	    int take=0;
        	    if(target>=arr[ind]) take = dp[ind-1][target-arr[ind]];
        	    dp[ind][target]=(take+ntake)%mod;
    	    }
    	 }
	    return dp[n-1][sum]%mod;
	}
	int SpaceOptmizedTabulation(int n,vector<int>&arr,int sum){
	    vector<int>curr(sum+1,0),prev(sum+1,0);
	    prev[0]=curr[0]=1;
	    if(arr[0]<=sum) prev[arr[0]]=1;
	    
    	for(int ind=1;ind<n;ind++){
    	    for(int target=1;target<=sum;target++){
        	    int ntake=prev[target];
        	    int take=0;
        	    if(target>=arr[ind]) take = prev[target-arr[ind]];
        	    curr[target]=(take+ntake)%mod;
    	    }
    	    prev=curr;
    	 }
	    return prev[sum]%mod;
	}
	int perfectSum(int arr1[], int n, int sum)
	{
        // Your code goes here
        vector<int>arr;
        for(int i=0;i<n;i++) arr.push_back(arr1[i]);
        sort(arr.rbegin(),arr.rend());
        
        //bruteforce recursive solution
        // return bruteforce(n-1,arr,sum);
        
        //Memoization solution
        // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        // return memoization(n-1,arr,sum,dp);
        
        //Tabulation Solution
        // return TabulationSolution(n,arr,sum);
        
        
        //SpaceOptmizedTabulation Solution
        return SpaceOptmizedTabulation(n,arr,sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends