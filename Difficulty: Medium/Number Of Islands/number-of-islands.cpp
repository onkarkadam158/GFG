//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool check(int i,int j,int n,int m){
        return i>=0 and j>=0 and i<n and j<m;
    }
    class DSU{
      public:
        vector<int>parent,size;
        int count=0;
        DSU(int n){
            parent.resize(n,0);
            size.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int getParent(int u){
            if(parent[u]==u) return u;
            return parent[u]=getParent(parent[u]);
        }
        void addNodes(int u,int v){
            int parOfU=getParent(u);
            int parOfV=getParent(v);
            if(parOfU==parOfV) return ;
            if(size[parOfU] < size[parOfV]){
                parent[parOfU] = parOfV;
                size[parOfV]++;
            }   
            else{
                parent[parOfV] = parOfU;
                size[parOfU]++;
            }
        }
        int getIslands(int node){
            int count=0;
            for(int i=0;i<parent.size();i++){
                if(parent[i]==node)count++;
            }
            return count;
        }
    };
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        DSU dsu(m*n);
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>result;
        int count=0;
        for(auto a:operators){
            int u=a[0],v=a[1];
            if(!vis[u][v]){
                int node=u*m+v;
                count++;
                vis[u][v]=1;
                for(auto a:dir){
                    int dx=u+a[0],dy=v+a[1];
                    if(check(dx,dy,n,m)){
                        if(vis[dx][dy]){
                            int adjNode=dx*m+dy;
                            if(dsu.getParent(adjNode)!=dsu.getParent(node)){
                                dsu.addNodes(node,adjNode);
                                count--;
                            }
                        }
                    }
                }
                
            }
            // int islands=dsu.getIslands(node);
            result.push_back(count);
        }
        
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends