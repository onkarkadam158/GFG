//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string checkFibonacci(int N){
        // code here 
        vector<int>arr;
        arr.push_back(0);
        arr.push_back(1);
        for(int i=2;i<=30;i++){
            arr.push_back(arr[i-1]+arr[i-2]);
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==N) return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.checkFibonacci(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends