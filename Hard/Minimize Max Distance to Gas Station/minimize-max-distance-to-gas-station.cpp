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
    int getCount(vector<int> &stations, int k,int n, double mid){
        int count=0;
        for(int i=1;i<n;i++){
            count += max(0, (int)((stations[i]-stations[i-1])/mid));
        }
        return count;
    }
    double binarySearchSolution(vector<int> &stations, int k,int n){
        double low=0.0,high=0.0;
        for(int i=1;i<n;i++) {
            high=max(high,(double) (stations[i]-stations[i-1]));
        }
        double ans=high;
        while((high-low) > 1e-6){
            double mid=low+(high-low)/2.0;
            int count=getCount(stations,k,n,mid);
            if(count<=k){
                ans=mid;
                high=mid;
            }
            else{
                low=mid;
            }
        }
        return ans;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        
        // return heapSolution(stations,k,n); //Time O(n*logn + k*log(n+k)) space O(n+k)
        
        // return bruteforce(stations,k,n); //Time O(n*k) polynomial space O(n)
        
        return binarySearchSolution(stations,k,n); //Time O(n*logn)
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