//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string apply(string s){
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') ans+="01";
            else ans+="10";
        }
        return ans;
    }
    char bruteforce(string s,int r,int n){
        while(r--){
            s=apply(s);    
        }
        return s[n];
    }
    char nthCharacter(string s, int r, int n) {
        //code here
        // return bruteforce(s,r,n);
        if(r==0) return s[n];
        char c=nthCharacter(s,r-1,n/2);
        if(n%2==1){
            if(c=='0') return '1';
            else return '0';
        }
        else{
            if(c=='0') return '0';
            return '1';
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends