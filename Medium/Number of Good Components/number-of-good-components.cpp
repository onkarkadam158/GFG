//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<int>& vis,vector<vector<int>>& adj,int i,int& nodes,int& edges){
        vis[i]=1;
        nodes++;
        edges+=adj[i].size();
        for(auto curr:adj[i]){
            if(!vis[curr]){
                dfs(vis,adj,curr,nodes,edges);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int V, vector<vector<int>> &Edges) {
        // code here
        vector<vector<int>>adj(V+1);
        for(auto a:Edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        if(V==1) return 1;
        vector<int>vis(V+1,0);
        int count=0;
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                int nodes=0,edges=0;
                dfs(vis,adj,i,nodes,edges);
                if(edges==((nodes*(nodes-1)))){
                    count++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends