//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        // int mini=min(A,min(B,C));
        // int max=max(A,max(B,C));
        if(A<B){
            if(B<C) return B;
            if(A<C) return C;
            return A;
        }
        else{
            if(A<C) return A;
            if(B<C) return C;
        }
        return B;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}
// } Driver Code Ends