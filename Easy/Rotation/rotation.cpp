//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int ans=INT_MAX,ind=0;
	    int low=0,high=n-1;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]<= arr[high]){
	            ans=min(arr[mid],ans);
	            if(arr[ind]>arr[mid]) ind=mid;
	            
	            high=mid-1;
	        }
	        else{
	           ans=min(arr[low],ans);
	           if(arr[ind]>arr[low])ind=low;
	           low=mid+1;
	        }
	    }
	   //cout<<ans<<"\n";
       return (ind);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends