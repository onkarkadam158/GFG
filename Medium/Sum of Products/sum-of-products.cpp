//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long result=0;
        vector<long long int>temp(32,0);
        for(int i=0;i<n;i++){
            int num=arr[i];
            int k=0;
            while(num){
                temp[k++]+=num%2;
                num=num/2;
            }
        }
        for(int i=0;i<32;i++){
            long long count=temp[i];
            count=(count*(count-1))/2;
            result+=pow(2,i)*count;
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends