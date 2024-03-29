//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int getForAtleastk(int arr[], int n,int k){
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0,j=0;i<n,j<n;j++){
            mp[arr[j]]++;
            if(mp.size()<=k){
                count+=j-i+1;
            }
            else if(mp.size()>k){
                while((mp.size()>k) and i<j){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0) mp.erase(arr[i]);
                    i++;
                }
                if(mp.size()<=k){
                    count+=j-i+1;
                }
            }
        }
        return count;
    }
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)mp[arr[i]]++;
        int k=mp.size();
        return getForAtleastk(arr,n,k)-getForAtleastk(arr,n,k-1);
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends