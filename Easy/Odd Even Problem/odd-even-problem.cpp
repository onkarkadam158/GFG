//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string oddEven(string S) {
        // code here
        int x=0,y=0;
        unordered_map<char,int>mp;
        for(auto a:S){
            mp[a]++;
        }
        for(auto a:mp){
            char c=a.first;
            int cnt=a.second;
            if((c-'a'+1)%2==0 and cnt%2==0) x++;
            if((c-'a'+1)%2==1 and cnt%2==1) y++;
        }
        // cout<<(x+y);
        return (x+y)%2==1 ? "ODD":"EVEN";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.oddEven(S) << endl;
    }
    return 0;
}

// } Driver Code Ends