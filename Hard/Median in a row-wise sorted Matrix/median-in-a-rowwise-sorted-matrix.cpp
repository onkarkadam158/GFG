//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int bruteforce(vector<vector<int>> &matrix, int R, int C){
        vector<int>temp;
        for(auto a:matrix){
            for(auto b:a)temp.push_back(b);
        }
        sort(temp.begin(),temp.end());
        return temp[temp.size()/2];
    }
    int getNoOfSmallElementsThanMid(vector<vector<int>> &mat, int r, int c,int mid){
        int sum=0;
        for(int i=0;i<r;i++){
            int temp=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
            sum+=max(temp,0);
        }
        return sum;
    }
    int BinarySearchSolution(vector<vector<int>> &mat, int r, int c){
        int low=1,high=2000;
        for(int i=0)
        while(low<=high){
            int mid=(low+high)/2;
            int noOfSmallElementsThanMid=getNoOfSmallElementsThanMid(mat,r,c,mid);
            if(noOfSmallElementsThanMid <= (r*c)/2){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here          
        
        //TIme O(R*C + R*C*log2(R*C)) space O(R*C) 
        // return bruteforce(matrix,R,C);

        //TIme O(log2(10^9) * r*log(c)) space O(1) 
        return BinarySearchSolution(matrix,R,C);        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends