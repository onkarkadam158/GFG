//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &a) {
        // code here
        int n=a.size(),m=a[0].size();
        vector<int>res;
 		int maxrow=n-1,maxcol=m-1,minrow=0,mincol=0;
 		int i=0,j=0,dir=0;
 		while(res.size()<n*m){
 		    switch((dir)%4){
 		        case 0:
 		            for(int k=mincol;k<=maxcol;k++){
 		                res.push_back(a[minrow][k]);
 		            }
 		            minrow++,dir++;
 		        break;
 		        case 1:
 		            for(int k=minrow;k<=maxrow;k++){
 		                res.push_back(a[k][maxcol]);
 		            }
 		            maxcol--,dir++;
 		        break;
 		        case 2:
 		            for(int k=maxcol;k>=mincol;k--){
 		                res.push_back(a[maxrow][k]);
 		            }
 		            maxrow--,dir++;
 		        break;
 		        case 3:
 		            for(int k=maxrow;k>=minrow;k--){
 		                res.push_back(a[k][mincol]);
 		            }
 		            mincol++,dir++;
 		        break;
 		    }
 		}
 		return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends