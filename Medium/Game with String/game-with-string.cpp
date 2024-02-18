//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int>mp;
        for(auto a:s)mp[a]++;
        priority_queue<int>q;
        for(auto a:mp)q.push(a.second);
        while(!q.empty() and k--){
            int top=q.top();
            q.pop();
            top--;
            q.push(top);
        }
        long long res=0;
        while(!q.empty()){
            int top=q.top();
            q.pop();
            res+=top*top;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends