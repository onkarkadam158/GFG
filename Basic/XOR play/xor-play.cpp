//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
	vector<int> xor_play(int n){
	    // code here
	    vector<int>res;
	    if(n==1) return {0};
	    res={1};
	    for(int i=2;i<=sqrt(n);i++){
	        if((n%i)==0){
	            res.push_back(i);
	            if(i!=(n/i))res.push_back(n/i);
	        }
	    }
	    sort(res.begin(),res.end());
	    int temp=res[0];
	    for(int i=1;i<res.size();i++){
	        temp=temp^res[i];
	    }
	    res.push_back(temp);
	    return res;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	vector<int> ans = ob.xor_play(n);
    	for(int i = 0; i < ans.size() - 1; i++)
    		cout << ans[i] <<" ";
    	cout<<"\n";
    	cout<<ans[ans.size() - 1]<<"\n";
    }
	return 0;
}

// } Driver Code Ends