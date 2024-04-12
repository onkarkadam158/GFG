//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool check(int row,int col,int n,vector<vector<int>>&res){
        for(int k=0;k<col;k++){
           if(res[row][k]==1) return false; 
        }
        int i=row,j=col;
        while(i>=0 and j>=0){
            if(res[i][j]==1) return false;
            i--,j--;
        }
        i=row,j=col;
        while(i<n and j>=0 ){
            if(res[i][j]==1) return false;
            i++,j--;
        }
        return true;
    }
        void solve(int col,int n, vector<vector<int>>&res,vector<vector<int>>&result){
        if(col>=n){
            vector<int>temp;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(res[j][i]==1){
                        temp.push_back(j+1);
                    }
                }
            }
            result.push_back(temp);
            return ;
        }
        for(int row=0;row<n;row++){
            if(check(row,col,n,res)){
                res[row][col]=1;
                solve(col+1,n,res,result);
                res[row][col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>res(n,vector<int>(n,0));
        vector<vector<int>>result;
        solve(0,n,res,result);
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends