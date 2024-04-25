//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int maxChars (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << maxChars (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int maxChars (string S)
{
    // your code here
    unordered_map<char,int>mp;
    int res=-1;
    for(int i=0;i<S.size();i++){
        if(mp.find(S[i])!=mp.end()){
            res=max(res,i-mp[S[i]]-1);
        }
        else{
            mp[S[i]]=i;
        }
    }
    
    return res;
}