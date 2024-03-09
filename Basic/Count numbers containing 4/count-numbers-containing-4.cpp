//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countNumberswith4(int N) {
        // code here
        int count=0;
        for(int i=0;i<=N;i++){
            int n=i;
            while(n){
                if(n%10==4){
                    count++;
                    break;
                } 
                n=n/10;
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
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countNumberswith4(N) << endl;
    }
    return 0;
}
// } Driver Code Ends