//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	long long mod=1e9+7;
	long long sumBitDifferences(int arr[], int n) {
	    // code here
	   // vector<long long>temp(32,0);
	   // for(int i=0;i<n;i++){
	   //     long long num=arr[i],ind=0;
	   //     while(num){
	   //         temp[ind]+=num%2;
	   //         num/=2;
	   //         ind++;
	   //     }
	   // }
	   // long long result=0;
	   // for(int i=0;i<32;i++){
	   //     long long temp2=(n-temp[i]);
	   //     temp2=temp[i]*temp2*2;
	   //     result+=temp2;
	   // }
	   // return result;
	      long long ans = 0;
	   
	   for(int i = 0;i<32;i++){
	       
	       long long count = 0;
	       
	       for(int j = 0;j<n;j++){
	           // at each position find the set bit
	           if(arr[j]&(1<<i))count++;
	           
	       }
	       ans+=count*(n-count)*2;
	   }
	   return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends