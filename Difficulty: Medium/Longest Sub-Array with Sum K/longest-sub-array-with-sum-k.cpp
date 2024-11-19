//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0,n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum-k)!=mp.end()){
                count=max(count,i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end()) mp[sum]=i;
        }
        return count;
        
        // long long sum=0;
        // int i=0,j=0,res=0,n=arr.size();
        // for (;j<n;j++){
        //     sum+=arr[j];
        //     if(sum==k){
        //         res=max(res,j-i+1);
        //     }
        //     else if (sum>k){
        //         while(i<j and sum >k){
        //             sum-=arr[i];
        //             i++;
        //         }
        //         if(sum==k) res=max(res,j-i+1);
        //     }
        // }
        // return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends