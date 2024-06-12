//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int ithbit=((num>>(i-1))&1);
        int temp=num,temp1=num;
        if(ithbit==0)temp+=pow(2,i-1);
        if(ithbit==1)temp1-=pow(2,i-1);
        cout<<ithbit<<" "<<temp<<" "<<temp1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends