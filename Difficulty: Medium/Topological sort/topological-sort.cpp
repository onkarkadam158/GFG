//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int i,vector<int> adj[],vector<int>& vis,stack<int>& st){
	    vis[i]=1;
	    for(auto a:adj[i]){
	        if(!vis[a]){
	            dfs(a,adj,vis,st);
	        }
	    }
	    st.push(i);
	}
	vector<int> dfsSolution(int V, vector<int> adj[]){
	    
	    vector<int>res;
	    vector<int>vis(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	   // cout<<"stsize"<<st.size();
	    while(!st.empty()){
	       // cout<<st.top()<<" ";
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	}
	//solution 2
	vector<int> kahnsAlgorithmSolution(int V, vector<int> adj[]){
	   vector<int>res;
	   vector<int>indegree(V,0);
	   for(int i=0 ; i<V; i++){
	       for(int j=0;j<adj[i].size();j++){
	           int node=adj[i][j];
	           indegree[node]++;
	       }
	   }
	   queue<int>que;
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0){
	           que.push(i);
	       }
	   }
	   while(!que.empty()){
	       int curr=que.front();
    	   res.push_back(curr);
	       que.pop();
	       for(auto a:adj[curr]){
	           if(indegree[a]>0){
	               indegree[a]--;
    	           if(indegree[a]==0){
    	               que.push(a);
    	           }
	           }
	       }
	   }
	   // for(auto a:res)cout<<a<<" ";
	    return res;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here 
	   // return dfsSolution(V,adj);
	    
	    return kahnsAlgorithmSolution(V,adj);
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends