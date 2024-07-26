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
        vector<int>dist(V,1e9);
        queue<pair<int,int>>que;
        dist[S]=0;
        que.push({0,S});
        while(!que.empty()){
            int currDist=que.front().first;
            int currNode=que.front().second;
            que.pop();
            for(auto neighbor:adj[currNode]){
                int node=neighbor[0],distance=neighbor[1];
                if(currDist+distance < dist[node]){
                    dist[node]=currDist+distance;
                    que.push({dist[node],node});
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
    vector <int> setSolution(int V, vector<vector<int>> adj[], int S){
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        st.insert({0,S});
        dist[S]=0;
        while(!st.empty()){
            auto curr=*st.begin();
            int currDist=curr.first;
            int currNode=curr.second;
            st.erase(curr);
            for(auto neigh:adj[currNode]){
                int neighNode=neigh[0],neighDist=neigh[1];
                if(currDist+neighDist<dist[neighNode]){
                    if(dist[neighNode]!=1e9) {
                        st.erase({dist[neighNode],neighNode});
                    }
                    dist[neighNode]=currDist+neighDist;
                    st.insert({dist[neighNode],neighNode});
                }
            }
        }
        return dist;
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        return queueSolution(V,adj,S);//does not work
        
        // return priorityQueueSolution(V,adj,S);
        
        return setSolution(V,adj,S);
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