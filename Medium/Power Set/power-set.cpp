//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void fun(int ind,string& s,string& temp,vector<string>&res){
	        if(ind>=s.size()){
	            if(temp!="")
	                res.push_back(temp);
	            return ;
	        }
	        temp+=s[ind];
	        fun(ind+1,s,temp,res);
	        temp.pop_back();
	        fun(ind+1,s,temp,res);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>res;
		    string temp="";
		    fun(0,s,temp,res);
		    sort(res.begin(),res.end());
		    return res;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends