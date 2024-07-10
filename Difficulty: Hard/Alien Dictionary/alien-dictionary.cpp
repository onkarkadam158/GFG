//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<vector<int>>getAdj(string dict[], int n, int K){
        vector<vector<int>>adj(K);
        for(int i=1;i<n;i++){
            string str1=dict[i-1];
            string str2=dict[i];
            for(int j=0;j<min(str1.size(),str2.size());j++){
                if(str1[j]!=str2[j]){
                    int x=str1[j]-'a',y=str2[j]-'a';
                    adj[x].push_back(y);
                    break;
                }
            }
        }
        return adj;
    }
    void print(vector<vector<int>>&v){
        for(auto &a:v){
            for(auto &x:a){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    string findOrder(string dict[], int n, int K) {
        //code here
        vector<vector<int>>adj=getAdj(dict,n,K);
        // print(adj);
        
        //topo sort algorithm
        vector<int>indegree(K,0);
        for(auto a:adj){
            for(auto x:a){
                indegree[x]++;
            }
        }
        queue<int>que;
        string res="";
        for(int i=0;i<K;i++){
            if(indegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            int curr=que.front();
            que.pop();
            res+=('a'+curr);
            for(auto neighbor:adj[curr]){
                if(indegree[neighbor]>0){
                    indegree[neighbor]--;
                    if(indegree[neighbor]==0){
                        que.push(neighbor);
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends