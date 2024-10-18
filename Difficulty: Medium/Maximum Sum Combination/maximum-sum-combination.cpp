//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    #define ppii pair<int,pair<int,int>>
    vector<int> bruteforce(int N, int K, vector<int> &A, vector<int> &B){
        vector<int>arr;
        for(auto a:A){
            for(auto b:B){
                arr.push_back(a+b);
            }
        }
        sort(arr.rbegin(),arr.rend());
        
        vector<int>res;
        for(int i=0;i<K;i++){
            res.push_back(arr[i]);
        }
        return res;
    }
    vector<int> optimal(int N, int K, vector<int> &A, vector<int> &B){
        vector<int>arr;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<ppii>pq;
        
        pq.push({A[N-1]+B[N-1] , {N-1,N-1}});
        vector<int>res;
        set<pair<int,int>>st;
        st.insert({N-1,N-1});
        while(K-- and !pq.empty()){
            auto top=pq.top();
            pq.pop();
            res.push_back(top.first);
            int x=top.second.first,y=top.second.second;
            if(st.find({x-1,y}) == st.end()){
                pq.push({A[x-1]+B[y] , {x-1,y}});
                st.insert({x-1,y});
            }
            if(st.find({x,y-1}) == st.end()){
                pq.push({A[x]+B[y-1] , {x,y-1}});
                st.insert({x,y-1});
            }
            
        }
        return res;
    }
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        // return bruteforce(N,K,A,B); //time O(n^2*log(N^2)) space O(1)
        
        return optimal(N,K,A,B);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends