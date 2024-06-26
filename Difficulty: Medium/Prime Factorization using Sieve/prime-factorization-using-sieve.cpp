//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve(){}
    void sieve(vector<int>&arr,int n) {
        arr[0]=0,arr[1]=0;
        for(int i=2;i<=sqrt(n);i++){
            if(arr[i]){
                for(int j=i;j*i<=n;j++){
                    arr[i*j]=0;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {
        vector<int>res;
        vector<int> arr(N+1,1);
        sieve(arr,N);
        for(int i=2;i<=N;i++){
            if(arr[i]==1){
                while(N%i==0){
                    res.push_back(i);
                    N=N/i;
                }
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends