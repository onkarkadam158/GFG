//{ Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        // Your code here
        unordered_map<char,int>mp1,mp2;
        for(auto a:s1)mp1[a]++;
        for(auto a:s2)mp2[a]++;
        string res="";
        for(auto a:s1){
            if(mp2.find(a)==mp2.end()){
                res+=a;
            }
        }
        for(auto a:s2){
            if(mp1.find(a)==mp1.end()){
                res+=a;
            }
        }
        if(res.size()==0) return "-1";
        return res;
    }

};

//{ Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}

// } Driver Code Ends