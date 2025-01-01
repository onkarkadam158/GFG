//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& str) {
        // code here
        
        vector<vector<string>>result;
        vector<int>vis(str.size(),0);
        for(int i=0;i<str.size();i++){
            if(!vis[i]){
                string temp=str[i];
                sort(temp.begin(),temp.end());
                vector<string>tres;
                tres.push_back(str[i]);
                for(int j=i+1;j<str.size();j++){
                    string temp2=str[j];
                    sort(temp2.begin(),temp2.end());
                    if(temp==temp2){
                        tres.push_back(str[j]);   
                        vis[j]=1;
                    }
                }
                result.push_back(tres);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends