//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int helper(int *dp[],vector<vector<int>> &cost,int mask,int curr_node)
{
    if(dp[curr_node][mask]!=-1)
        return dp[curr_node][mask];
    mask=mask|(1<<curr_node);
    int ans=INT_MAX;
    for(int i=0;i<cost[curr_node].size();i++)
    {
        if(!(mask&(1<<i)))
        ans=min(ans,cost[curr_node][i]+helper(dp,cost,mask,i));
    }
    mask=mask^(1<<curr_node);
    return dp[curr_node][mask]=(ans==INT_MAX?cost[curr_node][0]:ans);
}

int total_cost(vector<vector<int>>cost){
    // Code here
    int *dp[cost.size()];
    for(int i=0;i<cost.size();i++){
        dp[i]=new int[1<<cost.size()];
        memset(dp[i],-1,sizeof(dp[i][0])*(1<<cost.size()));
    }
    int mask=0;
    return helper(dp,cost,0,0);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends