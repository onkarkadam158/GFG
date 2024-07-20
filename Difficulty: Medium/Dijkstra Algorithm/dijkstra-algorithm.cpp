//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
     vector <int> queueSolution(int V, vector<vector<int>> adj[], int S){
        vector<int>vis(V,0),dist(V,1e9);
        queue<int>que;
        dist[S]=0,vis[S]=1;
        que.push(S);
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            for(auto neighbor:adj[curr]){
                int node=neighbor[0],distance=neighbor[1];
                if(!vis[node]){
                    dist[node]=min(dist[node],distance+dist[curr]);
                    vis[node]=1;
                }
            }
        }
        return dist;
    }
    vector <int> priorityQueueSolution(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(V,1e9);
        distance[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int currNode=pq.top().second;
            int currDist=pq.top().first;
            pq.pop();
            for(auto a:adj[currNode]){
                int neighborNode=a[0],dist=a[1];
                if(currDist+dist<distance[neighborNode]){
                    pq.push({currDist+dist,neighborNode});
                    distance[neighborNode]=currDist+dist;
                }
            }
        }
        
        return distance;
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // return queueSolution(V,adj,S);
        
        return priorityQueueSolution(V,adj,S);
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends