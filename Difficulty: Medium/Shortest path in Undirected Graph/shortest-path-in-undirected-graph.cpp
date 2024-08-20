//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>dist(N,-1),vis(N,0);
        dist[src]=0;
        vector<vector<int>>adj(N);
        for(auto a:edges){
            adj[a[1]].push_back(a[0]);
            adj[a[0]].push_back(a[1]);
        }
        queue<int>que;
        int level=1;
        que.push(src);
        vis[src]=1;
        while(!que.empty()){
           int size=que.size();
           while(size--){
               int curr=que.front();
               que.pop();
               for(auto neighbor:adj[curr]){
                   if(!vis[neighbor]){
                       que.push(neighbor);
                       vis[neighbor]=1;
                       if(dist[neighbor]==-1){
                           dist[neighbor]=level;
                       }
                       else{
                           dist[neighbor]=min(dist[neighbor],level);
                       }
                   }
               }
           }
           level++;
        }
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends