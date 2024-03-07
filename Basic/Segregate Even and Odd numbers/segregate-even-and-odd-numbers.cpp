//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int arr[], int n) {
	    // code here
	    int i=0,j=n-1;
	    vector<int>temp;
	    while(i<n){
	        temp.push_back(arr[i++]);
	    }
	    sort(temp.begin(),temp.end());
	    int k=0;
	    for(i=0;i<n;i++){
	        if(temp[i]%2==0) arr[k++]=temp[i];
	    }
	    for(i=0;i<n;i++){
	        if(temp[i]%2!=0) arr[k++]=temp[i];
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends