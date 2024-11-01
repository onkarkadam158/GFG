//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool check(int i,int j,int n){
        return i>0 and j>0 and i<=n and j<=n;
    }
    vector<vector<int>>arr={{2,1},{2,-1},{1,2},{1,-2},{-2,-1},{-2,1},{-1,2},{-1,-2}};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    vector<vector<int>>mat(n+1,vector<int>(n+1,0));
	    int X=KnightPos[0],Y=KnightPos[1];
	    queue<pair<pair<int,int>,int>>q;
	    q.push({{X,Y},0});
	    mat[X][Y]=0;
	    while(!q.empty()){
	        int x=q.front().first.first,y=q.front().first.second;
	        int d=q.front().second;
	        q.pop();
	        for(auto a:arr){
	           int dx=x+a[0],dy=y+a[1];
	           if(check(dx,dy,n) and mat[dx][dy]==0){
	               q.push({{dx,dy},d+1});
	               if(dx==TargetPos[0] and dy==TargetPos[1]) return d+1;
	               mat[dx][dy]=d+1;
	           }
	        }
	    }
	    return mat[TargetPos[0]][TargetPos[1]];
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends