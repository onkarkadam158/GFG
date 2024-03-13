//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n=mat.size();
         vector<vector<int>>res(2*n-1);
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 res[i+j].push_back(mat[i][j]);
             }
         }
         vector<int>result;
         for(int i=0;i<2*n-1;i++){
             if(i%2==0){
                 for(int j=res[i].size()-1;j>=0;j--){
                     result.push_back(res[i][j]);
                 }
             }
             else{
                 for(auto a:res[i]){
                     result.push_back(a);
                 }
             }
         }
         return result;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends