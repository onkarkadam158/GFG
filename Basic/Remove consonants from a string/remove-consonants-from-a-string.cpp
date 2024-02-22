//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isVowel(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U';
    }
    string removeConsonants(string s){
    //complete the function heredef removeConsonants(s):
        string res="";
        for(auto a:s){
            if(isVowel(a)){
                res+=a;
            }
        }
        if(res.size()==0) return "No Vowel";
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsonants(s) << "\n";
    }
return 0;
}
// } Driver Code Ends