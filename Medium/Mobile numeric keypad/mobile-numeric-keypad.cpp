//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    #define ll long long
    vector<vector<int>>dir={{0,0},{0,-1},{-1,0},{0,1},{1,0}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<4 and j<3 and !(i==3 and j==0) and !(i==3 and j==2) ;
    }
    long long solve(int i,int j,int n,vector<vector<vector<ll>>>&dp){
        if(n<=1) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        long long sum=0;
        for(auto a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy)){
                sum+=solve(dx,dy,n-1,dp);
            }
        }
        return dp[i][j][n]=sum;
    }
    long long getCount(int n) {
        // Your code goes here
        long long sum=0;
        vector<vector<vector<ll>>>dp(4,vector<vector<ll>>(3,vector<ll>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0; j<3;j++){
                if(!(i==3 and j==0) and !(i==3 and j==2)){
                    sum+=solve(i,j,n,dp);
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends