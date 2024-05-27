//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int ind,vector<int>&a,int prev, vector<vector<int>>&dp){
        if(ind>=a.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take=solve(ind+1,a,prev,dp);
        int ntake=0;
        if(prev==-1 or abs(a[ind]-prev)==1){
            ntake=1+solve(ind+1,a,a[ind],dp);
        }
        return dp[ind][prev+1]=max(take,ntake);
    }
    int longestSubseq(int n, vector<int> &a) {
        // code here
        int maxi=*max_element(a.begin(),a.end());
        vector<vector<int>>dp(n,vector<int>(maxi+2,-1));
        return solve(0,a,-1,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends