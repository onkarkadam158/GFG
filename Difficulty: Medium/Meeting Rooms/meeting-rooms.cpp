//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool overlap(int a,int b,int x,int y){
        
        if(a<x and x<b) return true;
        if(a<y and y<b) return true;
        if(x<a and a<y) return true;
        if(x<b and b<y) return true;
        return false;
        
    }
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=1;i<n;i++){
            int a=arr[i][0],b=arr[i][1];
            int x=arr[i-1][0],y=arr[i-1][1];
            
            if(overlap(a,b,x,y)) return false;
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends