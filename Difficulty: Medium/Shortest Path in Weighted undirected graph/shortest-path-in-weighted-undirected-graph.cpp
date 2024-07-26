//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int>prevNode(n+1,1);
        for(int i=0;i<=n;i++)prevNode[i]=i;
        // for(int i=0;i<adj.size();i++){
        //     cout<<"node "<<i;
        //     for(auto a:adj[i]){
        //         cout<<"{"<<a.first<<", "<<a.second<<"}, ";
        //     }
        //     cout<<endl;
        // }
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>que;
        que.push({0,1});
        dist[1]=0;
        while(!que.empty()){
            int currNode=que.top().second;
            int currDist=que.top().first;
            que.pop();
            for(auto neighbor:adj[currNode]){
                int node=neighbor.first,weight=neighbor.second;
                if(currDist+ weight < dist[node]){
                    dist[node]=currDist+weight;
                    prevNode[node]=currNode;
                    que.push({dist[node],node});
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        // for(auto a:prevNode)cout<<a<<" ";
        // cout<<endl;
        vector<int>path;
        int node=n;
        while(node!=prevNode[node]){
            path.push_back(node);
            node=prevNode[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        // for(auto a:path) cout<<a<<" ";
        // cout<<endl;
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends