//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int N, int M, vector<vector<int>> A) {
        // code here
        int ind=0,num=M,flag=false;
        for(int i=0;i<N;i++){
            int temp=0;
            for(int j=0;j<M;j++){
                if(A[i][j]){
                    flag=true;
                }
                temp+=A[i][j];
            }
            if(temp<num){
                num=temp;
                ind=i;
            }
        }
        if(!flag) return 1;
        return ind+1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends