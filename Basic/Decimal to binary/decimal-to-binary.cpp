//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h>
void toBinary(int N)
{
    // your code here
    vector<int>res;
    while(N){
        res.push_back(N%2);
        N=N/2;
    }
    reverse(res.begin(),res.end());
    for(auto a:res)cout<<a;
        
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends