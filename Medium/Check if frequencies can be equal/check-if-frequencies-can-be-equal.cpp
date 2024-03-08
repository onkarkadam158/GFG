//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool checkIfAllEqual(vector<int>&count){
        unordered_map<int,int>mp;
        for(auto a:count){
            if(a>0){
                mp[a]++;
            }
        }
        return mp.size()==1;
    }
	bool sameFreq(string s)
	{
	    // code here 
	    int n=s.size();
	    vector<int>count(26,0);
	    for(auto a:s) count[a-'a']++;
	    //By not deleting any character check if all are already equal
	    if(checkIfAllEqual(count)) return true;
	    //try deleting one occurence of each charachter and see if all rest becomes equal
	    for(int i=0;i<26;i++){
	        if(count[i]>0){
	            count[i]--;
	            if(checkIfAllEqual(count)){
	                return true;
	            }
	            count[i]++;
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends