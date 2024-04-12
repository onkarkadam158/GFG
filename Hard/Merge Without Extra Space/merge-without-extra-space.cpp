//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
             vector<int>temp;
            int i=0,j=0;
            while(i<n and j<m){
                if(arr1[i]<=arr2[j]){
                    temp.push_back(arr1[i++]);
                }
                else{
                    temp.push_back(arr2[j++]);
                }
            }
            while(i<n){
                temp.push_back(arr1[i++]);
            }
            while(j<m){
                temp.push_back(arr2[j++]);
            }
            for(int i=0;i<n;i++){
                arr1[i]=temp[i];
            }
            for(int i=0;i<m;i++){
                arr2[i]=temp[n+i];
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends