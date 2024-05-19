//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long double heapSolution(vector<int> &stations, int k,int n){
        priority_queue<long double>pq;
        for(int i=1;i<n;i++){
            pq.push((stations[i]-stations[i-1])*1.000000);
        }
        while(k--){
            long double top=pq.top();
            
            pq.pop();
            long double temp=top/2.00000000;
            pq.push(temp);
            pq.push(temp);
        }
        return pq.top();
    }
    double bruteforce(vector<int> &stations, int k,int n){
        vector<int>placed(n-1,0);
        for(int j=0;j<k;j++){
            double maxSize=-1,maxInd=-1;
            for(int i=0;i<n-1;i++){
                double diff=stations[i+1]-stations[i];
                double put=double(placed[i]);
                double size=diff/(put+1);
                if(size>maxSize){
                    maxSize=size;
                    maxInd=i;
                }
            }    
            placed[maxInd]++;
        }
        double res=0.0000;
        for(int i=0;i<n-1;i++){
            double diff=stations[i+1]-stations[i];
            double put=double(placed[i]);
            double size=diff/(put+1);
            res=max(res,size);
        }
        return res;
    }
    int getCount(vector<int> &stations, int k,int n,long double mid){
        int count=0;
        for(int i=1;i<n;i++){
            int cnt=(stations[i]-stations[i-1])/mid;
                // cnt = ceil((stations[i]-stations[i-1])/mid) - 1;
                // if(mid*cnt==((stations[i]-stations[i-1])/mid) ){
                //     cnt--;
                // }
            count+=max(0,cnt);
        }
        return count;
    }
    long double binarySearchSolution(vector<int> &stations, int k,int n){
        long double low=0.000000,high=0.0000000,ans=0.000000;
        for(int i=1;i<n;i++) {
            long double temp=(stations[i]-stations[i-1]);
            high=max(high,temp);
        }
        while((high-low) > 1e-6){
            long double mid=(high+low)/2.0;
            int count=getCount(stations,k,n,mid);
            if(count>k){
                low=mid;
            }
            else{
                ans=mid;
                high=mid;
            }
        }
        return ans;
    }
    
    bool isPossible(const vector<int>&s, double mid, int k) {
        int n = s.size();
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            cnt += max(0, (int)((s[i]-s[i-1])/mid));
        }
        return cnt <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        
        // return heapSolution(stations,k,n); //Time O(n*logn + k*log(n+k)) space O(n+k)
        
        // return bruteforce(stations,k,n); //Time O(n*k) polynomial space O(n)
        
        // return binarySearchSolution(stations,k,n); //Time O(n*logn)
        
        double st = 0.0;
        double en = 0.0;
        
        // Find the maximum initial gap
        for (int i = 1; i < n; ++i) {
            en = max(en, (double)(stations[i] - stations[i - 1]));
        }
        double ans = en ;  
        // Binary search for the smallest maximum distance
        while (en - st > 1e-6) {
            double mid = st + (en - st) / 2.0;
            if (isPossible(stations, mid, k)) {
                ans = mid; 
                en = mid;
            } else {
                st = mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends