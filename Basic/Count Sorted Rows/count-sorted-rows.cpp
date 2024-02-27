//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool issortedAscending(vector<int>&arr){
        for(int i=1;i<arr.size();i++){
            if(arr[i]<=arr[i-1]) return false;
        }
        return true;
    } 
    bool issortedDescending(vector<int>&arr){
        for(int i=1;i<arr.size();i++){
            if(arr[i]>=arr[i-1]) return false;
        }
        return true;
    }
    int sortedCount(int N, int M, vector<vector<int>> Mat) {
        // code here
        int count=0;
        for(auto &a:Mat){
            if(issortedAscending(a) or issortedDescending(a)){
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.sortedCount(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends