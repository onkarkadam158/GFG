//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
     unordered_map<char,int>mp;
    for(auto a:s){
        if(mp.find(a)!=mp.end()) {string s1(1, a); return s1;}
        mp[a]++;
    }
    return "-1";
}