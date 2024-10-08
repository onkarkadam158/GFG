//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        // sort(arr.begin(),arr.end());
        int n=arr.size();
        // return arr[n-1]+arr[n-2];
        
        int firstMax=arr[0];
        for(auto a:arr){
            firstMax=max(firstMax,a);
        }
        int secondMax=-1;
        
        for(auto a:arr){
            if(a!=firstMax){
                secondMax=max(secondMax,a);
            }
        }
        return firstMax+secondMax;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends