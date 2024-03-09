//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int findDiff(int arr[], int n) {
        unordered_map<int,int>mp;
        int maxi=0,mini=n;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,mp[arr[i]]);
            mini=min(mini,mp[arr[i]]);
        }
        if(mp.size()==1) return 0;
        return abs(maxi-mini);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n], i;
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.findDiff(arr, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends