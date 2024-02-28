//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getForAtleastk(vector<int> &arr, int N, int k){
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0,j=0;i<N,j<N;j++){
            mp[arr[j]]++;
            if(mp.size()<=k){
                count+=j-i+1;
            }
            else if(mp.size()>k){
                while((mp.size()>k) and i<j){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0)mp.erase(arr[i]);
                    i++;
                }
                if(mp.size()<=k){
                    count+=j-i+1;
                }
            }
        }
        return count;
    }
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return getForAtleastk(arr,N,k)-getForAtleastk(arr,N,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends