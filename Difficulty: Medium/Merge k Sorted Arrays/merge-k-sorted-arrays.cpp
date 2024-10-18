//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    #define pii pair<int,pair<int,int>>
    vector<int>bruteforce(vector<vector<int>> arr, int K){
        vector<int>res;
        for(auto a:arr){
            for(auto x:a){
                res.push_back(x);
            }
        }
        sort(res.begin(),res.end());
        return res;    
    }
    vector<int>optimal(vector<vector<int>> arr, int K){
        vector<int>res;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            res.push_back(top.first);
            int i=top.second.first,j=top.second.second;
            j++;
            if(j<arr[i].size()){
                pq.push({arr[i][j],{i,j}});
            }
        }
        return res;
    }
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        return bruteforce(arr,K);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends