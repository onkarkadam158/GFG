//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int digSum(int N){
        int sum=0;
        while(N){
            sum+=N%10;
            N=N/10;
        }
        return sum;
    }
    int repeatedSumOfDigits(int N){
        // code here
        while(N/10){
            N=digSum(N);
        }
        return N;
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
        cout << ob.repeatedSumOfDigits(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends