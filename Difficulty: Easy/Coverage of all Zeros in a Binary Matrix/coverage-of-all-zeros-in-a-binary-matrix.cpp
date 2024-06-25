//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int n,m;
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    bool check(int i,int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    int coverage(vector<vector<int>>&mat,int i,int j){
        int sum=0;
        for(auto a:dir){
            int dx=i+a[0],dy=j+a[1];
            if(check(dx,dy)){
                sum+=mat[dx][dy];
            }
        }
        return sum;
    }
    int FindCoverage(vector<vector<int>>&mat){
        // Code here
        n=mat.size(),m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) {
                    count+=coverage(mat,i,j);
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> matrix[i][j];
		Solution obj;
		int ans = obj.FindCoverage(matrix);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends