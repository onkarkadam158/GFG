//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int getForAtleastk(string& s, int k){
        int n=s.size(),count=0,size=0;
        vector<int>mp(26,0);
        for(int i=0,j=0;i<n,j<n;j++){
            if(mp[s[j]-'a']==0)size++;
            mp[s[j]-'a']++;
            if(size<=k){
                count+=j-i+1;
            }
            else if(size>k){
                while((size>k) and i<j){
                    mp[s[i]-'a']--;
                    if(mp[s[i]-'a']==0) size--;
                    i++;
                }
                if(size<=k){
                    count+=j-i+1;
                }
            }
        }
        return count;
    }
    long long int substrCount (string s, int k) {
    	//code here.
    	return getForAtleastk(s,k)-getForAtleastk(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends