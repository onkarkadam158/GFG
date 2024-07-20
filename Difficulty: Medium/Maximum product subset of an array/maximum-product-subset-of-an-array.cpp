//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int mod=1e9+7;
    long long int Positive(vector<int>&arr){
        long long int mul=0;
        for(auto a:arr){
            if(a>0) {
                if(mul==0) mul=a;
                else mul=(mul*a)%mod;
            }
        }   
        return mul;
    }
    long long int Negative(vector<int>&arr){
        long long int mul=0;
        for(auto a:arr){
            if(a<0) {
                if(mul==0) mul=a;
                else mul=(mul*a)%mod;
            }
        }   
        return mul;
    }
    int getMinNegative(vector<int>&arr){
        int mini=INT_MAX;
        for(auto a:arr){
            if(a<0){
                mini=min(abs(a),mini);
            }
        }
        return -1*mini;
    }
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int pos=Positive(arr);
        long long int neg=Negative(arr);
        // cout<<pos<<" "<<neg<<endl;
        if(neg==0) return pos;
        if(pos==0 and neg>0) return neg;
        
        if(pos>0 and neg>0) return (pos*neg)%mod;
        
        int minNeg=getMinNegative(arr);
        neg=(neg%mod)/minNeg;
        if(pos==0) return neg;
        return (pos*neg)%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends