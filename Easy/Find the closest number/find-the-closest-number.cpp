//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        if(arr[0]>=k) return arr[0];
        if(arr[n-1]<=k) return arr[n-1];
        int l=1,h=n-2;
        int ans=0;
        int ind=upper_bound(arr,arr+n,k)-arr;
        if(ind==0) return arr[ind];
        if(abs(arr[ind]-k) > abs(arr[ind-1]-k)) return arr[ind-1];
        // while(l<=h){
        //     int mid=(l+h)/2;
        //     if(abs(arr[mid]-k) < abs(arr[mid-1]-k)){
        //         l=mid+1;
        //     }
        //     else{
        //         h=mid-1;
        //     }
            
        // }
        return arr[ind];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends