//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int getFloor(int arr[],int n,int x){
    int res=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<=x){
            res=max(res,arr[i]);
        }
    }
    return res;
}
int getCeil(int arr[],int n,int x){
    int res=INT_MAX,found=false;
    for(int i=0;i<n;i++){
        if(arr[i]>=x){
            res=min(res,arr[i]);
            found=true;
        }
    }
    if(!found) return -1;
    return res;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    
    int Floor=getFloor(arr,n,x);
    int Ceil=getCeil(arr,n,x);
    pair<int,int>res;
    res.first=Floor,res.second=Ceil;
    return res;
}