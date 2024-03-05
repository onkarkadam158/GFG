//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<int>>dir{{0,-1},{0,1},{-1,0},{1,0}};
    int n,m;
    bool check(int i,int j){
        return i>=0 and j>=0 and i<n and j<m;
    }
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        vector<vector<int>>res=matrix;
        n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    int sum=0;
                    for(auto a:dir){
                        int dx=i+a[0],dy=j+a[1];
                        if(check(dx,dy)){
                            res[dx][dy]=0;
                            sum+=matrix[dx][dy];
                        }
                    }
                    res[i][j]=sum;
                }
            }
        }
        matrix=res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends