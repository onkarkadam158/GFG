//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>distance(V,1e8);
        distance[S]=0;
        for(int i=0;i<V-1;i++){
            //relaxing the edges v-1 times
            for(auto a:edges){
                int src=a[0],dst=a[1],wt=a[2];
                if(distance[src]!=1e8 and distance[src]+wt<distance[dst]){
                    distance[dst]=distance[src]+wt;
                }
            }
        }
        vector<int>nthDistance=distance;
        for(auto a:edges){
            int src=a[0],dst=a[1],wt=a[2];
            if(nthDistance[src]!=1e8 and nthDistance[src]+wt<nthDistance[dst]){
                nthDistance[dst]=nthDistance[src]+wt;
            }
        }
        for(int i=0;i<V;i++){
            if(nthDistance[i]!=distance[i]){
                return {-1};
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends