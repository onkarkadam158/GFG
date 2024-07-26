//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod=100000 ;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>distance(1e5,1e9);
        queue<pair<int,int>>que;
        que.push({start,0});
        distance[start]=0;
        while(!que.empty()){
            int curr=que.front().first;
            int dist=que.front().second;
            if(curr==end) return dist;
            que.pop();
            for(auto a:arr){
                int num=(a*curr)%mod;
                if(distance[num]>dist+1){
                    distance[num]=dist+1;
                    que.push({num,distance[num]});
                }
            }
            
        }
        if(distance[end]==1e9) return -1;
        return distance[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends