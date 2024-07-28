//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > arr) {
       // code here
       int n=arr.size();
	    int row=-1,ones=0;
	    for(int i=0;i<n;i++){
	        int left=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	        int right=upper_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
	        int currOnes=right-left;
	        if(currOnes>ones){
	            ones=currOnes;
	            row=i;
	        }
	    }
	    return row;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends