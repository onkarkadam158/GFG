//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string S) {
        // code here
        vector<string>arr;
        string tmp="";
        for(int i=0;i<S.size();i++){
            if(S[i]=='.'){
                arr.push_back(tmp);
                tmp="";
            }    
            else
                tmp+=S[i];
        }
        if(tmp.size()>0) arr.push_back(tmp);
        tmp="";
        string result="";
        reverse(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            tmp=arr[i];
            result+=tmp+'.';
        }
        result.pop_back();
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends