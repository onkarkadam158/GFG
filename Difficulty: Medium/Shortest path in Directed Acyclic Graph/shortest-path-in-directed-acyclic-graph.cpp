//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node,stack<int>&st,vector<int>&visited,vector<vector<pair<int,int>>>&adj){
        visited[node]=1;
        for(auto a:adj[node]){
            if(!visited[a.first]){
                dfs(a.first,st,visited,adj);
            }
        }
        st.push(node);
    }
    vector<int>dfsSolution(int n,vector<vector<pair<int,int>>>&adj){
        vector<int>dist(n,1e9),visited(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,st,visited,adj);
            }
        }
        dist[0]=0;
        while(!st.empty()){
            // cout<<st.top()<<" ";
            int top=st.top();
            st.pop();
            for(auto a:adj[top]){
                dist[a.first]=min(dist[a.first],a.second+dist[top]);
            }
        }
        for(auto &a:dist){
            if(a==1e9) a=-1;
        }
        return dist;
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>>adj(N);
        for(auto a:edges){
            adj[a[0]].push_back({a[1],a[2]});
            // indegree[a[1]]++;
        }
        return dfsSolution(N,adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends