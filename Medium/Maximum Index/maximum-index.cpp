//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        //Bruteforce
        
        // int result=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(a[i]<=a[j]){
        //             result=max(result,(j-i));
        //         }
        //     }
        // }
        // return result;
        
        //Optimal
        vector<int>left(n,0),right(n,0);
        left[0]=a[0];
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1],a[i]);
        }
        right[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],a[i]);
        }
        int result=0;
        int i=0,j=0;
        while(i<n and j<n){
            if(left[i]<=right[j]){
                result=max(result,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends