//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int fibExpression(int n){
        // code here
        //bruteforce
        
        // vector<int>res;
        // res.push_back(0);
        // res.push_back(1);
        // for(int i=2;i<=n+1;i++){
        //     res.push_back((res[i-1]+res[i-2]));
        // }
        // return res[n+1]*res[n-1]-res[n]*res[n];
        
        //optimal
        if(n%2==0) return 1;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.fibExpression(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends