//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int>mp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
        }
        int temp=INT_MIN;
        string res="";
        for(auto&a:mp){
            if(a.second!=maxi){
                temp=max(temp,a.second);
                res=a.first;
            }
        }
        for(auto&a:mp){
            if(a.second==temp){
                res=a.first;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends