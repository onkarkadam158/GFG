//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
         // code here
	    int ind=0,n=arr.size();
	    int low=0,high=n-1,mini=INT_MAX;
	    while(low<=high){
	        int mid=(low+high)/2;
	        //right sorted
	        if(arr[mid]<=arr[high]){
	            if(arr[mid]<mini){
	                mini=arr[mid],ind=mid;
	            }
	            high=mid-1;
	        }
	        else{
	            if(arr[low]<mini){
	                mini=arr[low],ind=low;
	            }
	            low=mid+1;
	        }
	    }
	   return (ind);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends