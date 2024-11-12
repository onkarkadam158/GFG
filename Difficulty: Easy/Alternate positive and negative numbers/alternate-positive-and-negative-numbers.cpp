//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void bruteforce(vector<int>&arr){
        vector<int>pos,neg;
        for(auto a:arr){
            if(a>=0) pos.push_back(a);
            else neg.push_back(a);
        }
        int i;
        for( i=0;i<min(neg.size(),pos.size());i++){
            arr[i*2]=pos[i];
            arr[i*2+1]=neg[i];
        }
        int index=2*i;
        for(;i<pos.size();i++){
            arr[index++]=pos[i];
        }
        for(;i<neg.size();i++){
            arr[index++]=neg[i];
        }
    }
    void rearrange(vector<int> &arr) {
        // code here0   
        return bruteforce(arr);
        
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends