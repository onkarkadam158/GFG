//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string reverseString(string s);
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	    {
	        string s;
	        getline(cin,s);
	        cout<<reverseString(s)<<endl;
	    }
}

// } Driver Code Ends


string reverseString(string s)
{
    //code here.
    unordered_map<char,int>mp;
    string res="";
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]!=' ' and mp.find(s[i])==mp.end()){
            res+=s[i];
        }
        
        mp[s[i]]++;
    
        if(res.size()>=26) return res;
        
    }
    return res;
}