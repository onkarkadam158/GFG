//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long bruteforce(vector<int> &arr, int m){
        long count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int res=0;
            for(int j=i;j<n;j++){
                res=res^arr[j];
                if(res==m)count++;
            }
        }
        return count;
    }
    long optimal(vector<int> &arr, int m){
        long count=0;
        int n=arr.size(),res=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<n;i++){
            res=res^arr[i];
            if(mp.find(m^res)!=mp.end()){
                count+=mp[m^res];
            }
            mp[res]++;
        }
        return count;
    }
    long subarrayXor(vector<int> &arr, int m) {
        // code here
        // return bruteforce(arr,m); //time O(N^2) spac O(1)
        
        return optimal(arr,m); //time O(N) spac O(N)
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int m;
        cin >> m;
        cin.ignore(); // Ignore the newline after m

        Solution obj;
        cout << obj.subarrayXor(arr, m) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends