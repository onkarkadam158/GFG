//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
    vector<int> Series(int n) {
        // Code here
        vector<int>res;
        res.push_back(0);
        res.push_back(1);
        for(int i=2;i<=n;i++){
            res.push_back((res[i-1]%mod+res[i-2]%mod)%mod);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends