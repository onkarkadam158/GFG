//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int prev,int curr,vector<int>&vis,vector<int> adj[]){
        vis[curr]=1;
        for(auto neighbor:adj[curr]){
            if(!vis[neighbor] ){
                if(checkCycle(curr,neighbor,vis,adj)) return true;
            }    
            else if(vis[neighbor] and neighbor!=prev) return true;
        }
        return false;
    }
    bool BFS(int V, vector<int> adj[]){
        
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(-1,i,vis,adj)) return true;
            }
        }
        return false;
    }
    bool DFS(int V, vector<int> adj[]){
        
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(-1,i,vis,adj)) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        return DFS(V,adj);
        
        return BFS(V,adj);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends