//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N==0) return -1;
        int res=-1,ind=1,count=0;
        while(N){
            if(res==-1 and N%2) res=ind;
            ind++;
            count+=N%2;
            N=N/2;
        }
        if(count>1) return -1;
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends