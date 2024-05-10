//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    set<vector<int>>result;
    void solve(int ind,int target,vector<int>&arr,vector<int>& temp){
        if(ind<0){
            if(target==0){
                result.insert(temp);
            }
            return ;
        }
        if(target>=arr[ind]){
            temp.push_back(arr[ind]);
            solve(ind-1,target-arr[ind],arr,temp);
            temp.pop_back();
        }
        solve(ind-1,target,arr,temp);
        
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k){
        //code here
        result.clear();
        vector<int>temp;
        sort(arr.rbegin(),arr.rend());
        solve(n-1,k,arr,temp);
        vector<vector<int>>res;
        for(auto &a:result){
            res.push_back(a);
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends