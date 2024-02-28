//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int ind,vector<int>&A,vector<vector<int>>&result,vector<int>&temp){
        if(ind==A.size()){
            result.push_back(temp);
            return ;
        }
        solve(ind+1,A,result,temp);
        temp.push_back(A[ind]);
        solve(ind+1,A,result,temp);
        temp.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>>result;
        vector<int>temp;
        // sort(A.begin(),A.end());
        solve(0,A,result,temp);
        
        sort(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends