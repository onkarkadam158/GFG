//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long res=0;
        int i=31;
        while(x){
            long long temp=1;
            if(x%2) res+=(temp<<i);
            x=x>>1;
            i--;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends