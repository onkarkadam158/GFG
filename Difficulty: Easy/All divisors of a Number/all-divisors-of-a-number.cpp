//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
	void bruteforce(int n){
	    for(int i=1;i<=n;i++){
	        if(n%i==0 ){
	            cout<<i<<" ";
	        }
	    }
	}
	void optimal(int n){
	    vector<int>res;
	    for(int i=1;i<=sqrt(n);i++){
	        if(n%i==0 ){
	            cout<<i<<" ";
	            if(i!=(n/i))res.push_back(n/i);
	        }
	    }
	    for(int i=res.size()-1;i>=0;i--){
	        cout<<res[i]<<" ";
	    }
	}
    void print_divisors(int n) {
        // Code here.
	   // return bruteforce(n);
	    return optimal(n);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends