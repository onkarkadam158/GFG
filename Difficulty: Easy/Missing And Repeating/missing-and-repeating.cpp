//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>bruteforce(vector<int>&arr){
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<int>res(2);
        for(auto a:arr){
            mp[a]++;
            if(mp[a]==2) res[0]=a;
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                res[1]=i;
                return res;
            }
        }
        
        
        return res;
    
    }
    vector<int>optimal(vector<int>&arr){
        int n=arr.size();
        
        vector<int>res(2);
        
        return res;
    
    }
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        return bruteforce(arr);
        // return optimal(arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends