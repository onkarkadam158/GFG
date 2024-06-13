//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int bruteforce(int l,int r){
        int ans=0;
        while(l<=r){
            ans=ans^l;
            l++;
        }
        return ans;
    }
    int xorTillN(int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;
    }
    int optimal(int l,int r){
        int ans=0;
        int xorTill_r=xorTillN(r);
        int xorTill_l=xorTillN(l-1);
        return xorTill_r^xorTill_l;
    }
    int findXOR(int l, int r) {
        // complete the function here
        // return bruteforce(l,r);
        
        return optimal(l,r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends