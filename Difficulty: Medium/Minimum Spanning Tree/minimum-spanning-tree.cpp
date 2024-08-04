//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	#define ppii pair<int,pair<int,int>>
	void print(vector<vector<int>>&v){
        for(auto &a:v){
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
	int primsAlgorithm(int V, vector<vector<int>> adj[]){
	    priority_queue<ppii,vector<ppii>,greater<ppii>>que;
	    int sum=0;
	    vector<vector<int>>mst;
	    vector<int>vis(V,0);
	    que.push({0,{0,-1}});
	    while(!que.empty()){
	        auto top=que.top();
	        int wt=top.first,node=top.second.first,parent=top.second.second;
	        que.pop();
	        if(!vis[node]){
	            sum+=wt;
	            vis[node]=1;
	            if(parent!=-1)mst.push_back({node,parent});
	        }
	        else{
	            continue;
	        }
	        for(auto a:adj[node]){
	            int newWt=a[1],newNode=a[0];
	            if(!vis[newNode]){
	                que.push({newWt,{newNode,node}});
	            }
	        }
	       
	    }
	   // print(mst);
	    return sum;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        return primsAlgorithm(V,adj);
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends