//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool check(int n){
        while(n){
            if(n%10==6 or n%10==7 or n%10==8 or n%10==8 or n%10==9 or n%10==0 ) return false;
            n=n/10;
        }
        return true;
    }
    int countNumbers(int N) {
        // code here
        unordered_map<int,int>mp;
        int res=0;
        for(int i=1;i<=N;i++){
            int n=i;
            if(check(n)){
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countNumbers(n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends